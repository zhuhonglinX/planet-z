

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

