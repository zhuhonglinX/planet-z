# Git 使用

## ssh配置

```shell
ssh-keygen -t rsa -C "youremail@example.com"
```

默认会在 `~/.ssh` 目录下生成 `id_rsa` 和 `id_rsa.pub` 文件, 个人习惯, 我将其放入单独的目录中, 管理 ssh key.

```shell
cd ~/.ssh
mkdir github  # 创建 github 目录
mv id_rsa github  # 把私钥移动到 github 目录中

cat id_rsa.pub
# 打印出公钥内容配置你的 github 账户的 ssh key 中.
# 路径大致: Setting -> SSH Keys -> New SSH key
```

配置完成后需要修改 config 文件, 目的在于指明 ssh key 的路径

```shell
vim ~/.ssh/config
```

在 config 文件中输入以下内容

```yaml
Host github.com
    HostName github.com
    User git
    IdentityFile ~/.ssh/github/id_rsa
```

这时可以测试如下命令

```shell
# 测试连接, 类似以下输出表示成功
ssh -T git@github.com
>> Hi xxx! You've successfully authenticated, but GitHub does not provide shell access.
```

如果失败, 出现类似 ```Bad owner or permissions``` 的权限问题, 进行如下步骤即可

```
chmod 600 ~/.ssh/config
chown $USER ~/.ssh/config
```

## git

一些指令

```shell
git status
git add <file>
git commit -m "placeholder"
git remote add origin git@github.com:zhuhonglinX/tf_example.git
git push -u origin master

git fetch origin master:tmp  # fetch 远程 origin master 到本地 tmp 分支
git diff tmp  # 查看本地 master 和 tmp 不同
git merge tmp  # 合并 tmp 分支
git pull  # fetch 加 merge
```

## 分支

```shell
git checkout -b <branch name>  # 创建分支
git checkout <branch name>  # 切换分支
```


## gitignore

```yaml
# 忽略所有 .pt 文件
*.pt
# 但不忽略 last.pt 文件
!last.pt
# 忽略 .vscode 目录
.vscode/
# 只忽略根目录下的 .txt 文件
/*.txt

```

