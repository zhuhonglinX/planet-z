
# C/C++ Dev

> TODO

# Python Dev

## miniconda

[https://docs.conda.io/en/latest/miniconda.html](https://docs.conda.io/en/latest/miniconda.html)

``` bash
conda info --envs
conda list
conda activate base  # base env
conda deactivate
conda create --name <env name> <package> python=<version>
conda env remove -n <env name>
conda install -n <env name> <packages>
conda install pip
conda remove -n <env name> --all
```

## pip

``` bash
pip install -i https://pypi.tuna.tsinghua.edu.cn/simple <package name>
pip install -i https://pypi.douban.com/simple <package name>
```


# ssh 配置

## local machine and remote sever

### sshd in remote sever

```bash
# 查看是否有 ssh 服务
dpkg -l | grep ssh

# 安装 ssh server
sudo apt install openssh-server

# 否启动了 sshd
ps aux | grep sshd

# 手动启动 ssh server
sudo /etc/init.d/ssh start

# sshd 的关闭、重启指令
sudo /etc/init.d/ssh restart
sudo /etc/init.d/ssh stop
```

sshd 配置文件：

```bash
sudo vim /etc/ssh/sshd_config

# 说明
Port 22  # 设置 ssh server 的端口

# TODO
```

### ssh key



## Github or other

### Github

### Gitlab


# Git

# Tmux

# Commands and Tools in Linux

If not specified, the default is in Ubuntu environment.

## 用户相关

查看用户

```bash
cat /etc/passwd
# 各个字段的含义
# 用户名:口令:UID:GID:注释性描述:主目录:登录shell
```

查看组

```bash
cat /etc/group
# 各个字段含义
# 组名:口令:组标识号:组内用户列表
```

添加用户和组

```bash
sudu useradd -m -G [group,] [user]
sudo passwd [usr]  # 修改密码
sudo usermod -a -G [group] [user]
```

修改用户 home 目录

```bash
sudo usermod -m -d /raid/[username] [username]
# m: 在移动之前的主目录到指定目录下，如果没有就创建
# d: 新的主目录地址
```


## 常用命令

### 查看硬盘容量

```bash
df -hl

# 查看当前目录占用空间
du -sh
```

### chown chmod
```bash
chown [-R] <user>:<group> <file>  # 修改所属用户/组
chmod 755 <file> [-R]  # 修改权限
```

### 查看端口占用
```bash
sudo lsof -i:22
netstat -tulpn | grep 22
```

### tar/xz

```bash
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

### scp 传输文件

```bash
# 本地文件传输到远程服务器的 lab 目录下
scp test.zip <user>@<ip>:/home/zhuhl/lab

# 从远程主机复制文件到本地主机
scp <user>@<ip>:/home/zhuhl/lab/test.zip .

# 复制整个文件夹
scp -r dir <user>@<ip>:/home/zhuhl/lab
scp -r <user>@<ip>:/home/zhuhl/lab/dir .

# 指定端口
scp -P <port>  # -P 跟在 scp 后，否则可能出错
```

### watch

```bash
# 查看 GPU 使用情况
watch -n 0.2 nvidia-smi

# MacOS 监控 cpu 风扇等
watch --color -n 1 istats

# 查看用户进程占用
ls -al /proc/ | grep <PID>
```

### wget

```bash
wget <url>
wget -c <url>    # 断点续传
# Ctrl-C 暂停下载，在输入上一条命令恢复（前提是不删除下了一半的文件）

wget -b <url>    # 后台下载
```



