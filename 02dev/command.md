# 命令记录

## tar

```shell
# 压缩目录 dir
tar -czvf test.tar.gz ./dir

# 解压 test.tar.gz
tar -xzvf test.tar.gz

# 列出压缩文件内容
tar -tzvf test.tar.gz 

-c 压缩
-x 解压
-z gzip 格式
-v 显示过程
-f 后接tar档案名
```



## watch

```shell
# 查看 GPU 使用情况
watch -n 0.2 nvidia-smi

# MacOS 监控 cpu 风扇等
watch --color -n 1 istats

# 查看用户进程占用
ls -al /proc/ | grep <PID>
```



## wget

```shell
wget <url>
wget -c <url>    # 断点续传
# Ctrl-C 暂停下载，在输入上一条命令恢复（前提是不删除下了一半的文件）

wget -b <url>    # 后台下载
```



## docker

```shell
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
docker images      # check image
docker ps -al      # check container
docker system df   # check all size

docker rmi <image ID>    # delete image
docker rm <container ID> # delete container

# 从 image 创建 container
docker run -ti <image name> /bin/bash
docker rum -ti -v <host path>:<container path> <image name> /bin/bash

# Ctrl + D 退出并挂起容器
# Ctrl + P Ctrl + Q 退出容器
docker start <container ID>
docker attach <container ID>  # 进入容器，退出挂起
docker exec -ti <container ID> /bin/bash  # 进入容器，退出不会挂起

```


