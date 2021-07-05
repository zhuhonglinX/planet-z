# 快速上手

## 创建容器

查看 docker 镜像

```bash
docker images
```

以目前新机器中存在的镜像 `nvidia/cuda:10.2-cudnn8-devel-ubuntu18.04` 为例。

从镜像中创建并启动容器：

```bash
# 模板
docker run --runtime nvidia -p <主机端口>:22 -v <主机目录>:<容器目录> --name <容器名> -ti nvidia/cuda:10.2-cudnn8-devel-ubuntu18.04 /bin/bash

# 例子
docker run --runtime nvidia -p 11000:22 -v /raid/zhuhl:/home/zhuhl --name zhuhl-1 -ti nvidia/cuda:10.2-cudnn8-devel-ubuntu18.04 /bin/bash
```

参数介绍：

*  `--runtime nvidia` 表示挂载 GPU
* `--name` 后指定容器的名称，自己定一个名字，比如设定 `zhuhl-1`
* `-p` 表示端口映射，将容器的 `22` 端口映射到主机的 `11000` 端口，目的是为了能够使用 ssh 远程登录容器，注意先确保**主机端口**没有被占用，可以用自己的主机用户ID作为前缀，防止冲突。如用户 1005，映射端口到 `10050-10059`之间，用户 1006 映射端口到 `10060-10069`之间。
* `-v` 表示主机的目录挂载到容器中，比如我把主机中的 `/raid/zhuhl` 目录挂载到容器的 `/home/zhuhl`，这样一些数据集和代码可以放在主机中，不必放入容器。
* `-ti` 和后面的 `/bin/bash` 可以进入终端交互环境中。

输入以上命令后，会创建一个新的容器，并进入容器的 bash 中，然后可以输入 `nvidia-smi` 命令查看是否能够显示 GPU 信息，识别出就 ok 了。

## 从 docker 命令进入或退出容器

在容器终端中按 `Ctrl + d`  退出容器，回到主机的终端，使用 `docker ps -a` 命令可以查看所有容器，如果发现自己的容器的状态是 `Exited(255)` ，可以使用 `docker start <容器名或ID>` 启动容器，此时容器的状态为 `Up`，接着输入以下命令再次进入容器：

```bash
docker exec -ti <容器名> /bin/bash
```

之后再按 Ctrl d 退出，容器会始终在后台运行。

# ssh 远程连接和开发

开启远程容器 ssh 服务的目的：

1. 用本地终端可以直接 ssh 登陆远程容器
2. 可以用 vscode 或者 pycharm 远程开发

## 远程容器 ssh server 配置

先用 `docker exec` 命令进入远程容器，然后设置登陆密码：

```bash
passwd
# 然后输入密码
```

安装 sshd：

```bash
apt update && apt install openssh-server
```

修改sshd配置：

```bash
vim /etc/ssh/sshd_config

# 在配置文件中添加这一行
PermitRootLogin yes
```

创建的容器只有一个 root 用户，因此需要允许root登陆。

启动：

```bash
/etc/init.d/ssh start
```

打开一个本地终端，尝试 ssh 连接远程容器：

```bash
ssh -p <port> root@<ip>
```

ip 是新机器的 ip，用户统一是 root（除非你在容器中新建了用户），连接的端口由 `-p` 指定，使用映射端口（不是22）。

连接出错可以看一下 `/etc/ssh/sshd_config` 的配置是否正确，这个可以参考一般的服务器配置 ssh 登录的教程。成功连接后可以配置 public/private key 方便登陆。

## vscode 配置

参考：

* https://qlzhu.github.io/blog/15892/
* https://zhuanlan.zhihu.com/p/68577071

等

# Docker 的基本命令

```bash
# docker 服务
service docker status
service docker start/stop/restart

# docker registy mirror 大陆加速
vim /etc/docker/daemon.json

# ============ daemon.json =============
{
  "registry-mirrors": ["<url_1>", "<url_2>"]
}
# ======================================

# 大陆 docker mirror 例子
# https://registry.docker-cn.com
# https://dockerhub.azk8s.cn
# https://reg-mirror.qiniu.com

# docker 命令
docker version
docker info
docker images      # 查看镜像
docker ps					 # 查看所有活跃的容器
docker ps -a       # 查看所有容器, -a all
docker system df   # 查看 size 占用

docker rmi <image ID>    # 删除镜像
docker rm <container ID> # 删除容器

# 从 image 创建 container
docker run -ti <image name> /bin/bash

# 挂载硬盘
docker run -ti -v <host path>:<container path> <image name> /bin/bash

# 映射 ssh 端口
docker run -p 10050:22 -dti <image name> /bin/bash

# 使用 gpu
docker run --runtime nvidia -ti <image name> /bin/bash

# Ctrl + D 退出并挂起容器
docker start <container ID>  # 启动容器
# docker attach <container ID>  # 进入容器，退出挂起
docker exec -ti <container ID> /bin/bash  # 进入容器，退出不会挂起

docker stop <container ID>  # 挂起容器

# 不要使用如下的方式导出导入镜像，这会导致无法使用 nvidia gpu
# docker export 容器名称 > 镜像名称.tar
# docker import 镜像名称.tar <image name>:<tag>
# 正确的方式如下
dcoker commit <container ID> <image name>:<tag>
```

