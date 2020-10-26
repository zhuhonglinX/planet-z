#### 服务器 ssh 配置

ssh 分为客户端和服务端，一般默认安装有客户端，但如果需要 ubuntu 本机开放 ssh 服务，就需要服务端。

首先查看是否安装了 ssh server 服务：

```shell
dpkg -l | grep ssh
```

如果输出没有类似 `openssh-server` 字样的条目，则说明没有安装，于是需要安装 ssh server：

```shell
# 安装 ssh server
sudo apt install openssh-server
```

可以再次使用 `dpkg` 命令查看是否安装成功，ssh server 的进程一般叫做 `sshd`，我们可以查看此时是否启动了该进程：

```shell
ps aux | grep sshd
```

一般安装后会自动启动，如果没有启动就需要手动启动：

```shell
# 手动启动 ssh server
sudo /etc/init.d/ssh start

# 其他关于 sshd 的关闭、重启指令
sudo /etc/init.d/ssh restart
sudo /etc/init.d/ssh stop
```

关于 sshd 配置文件的说明：

```shell
sudo vim /etc/ssh/sshd_config

# 说明
Port 22  # 设置 ssh server 的端口

```

#### 用户组相关

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

#### 添加用户添加组

添加用户和组

```bash
sudu useradd -m -G [group,] [user]

sudo passwd [usr]  # 修改密码

sudo sudo usermod -a -G [group] [user]
```

#### 查看硬盘容量

```bash
df -hl

# 查看当前目录占用空间
du -sh
```

#### 修改用户 home 目录

```bash
sudo usermod -m -d /raid/[username] [username]
```

m：在移动之前的主目录到指定目录下，如果没有就创建。

d：新的主目录地址

#### 查看端口占用
```bash
sudo lsof -i:22
netstat -tulpn | grep 22
```

