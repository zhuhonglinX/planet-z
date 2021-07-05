# tmux

## tmux 命令

```shell
# 安装
sudo apt install tmux

tmux  # 新建无名 session
tmux new -s demo  # 新建名为 demo 的 session

# 在 tmux session 中
tmux detach  # 断开 session，但是 session 在后台执行
# 也可以使用 ctrl+b d 快捷键完成同样的操作

tmux a  # 进入第一个对话
tmux a -t demo  # 进入 demo 对话

tmux ls  # 查看所有 session
# 如果此时在 session 中，使用快捷键 ctrl+b s 查看所有对话，回车进入指定 session

tmux kill-session -t demo  # 关闭 demo 会话
tmux kill-server  # 关闭 tmux 服务，所有 session 都会关闭

```

# tmux 配置

修改 tmux 的相关配置，配置文件路径 `~/.tmux.conf`

## 鼠标支持

```ini
set-option -g mouse on  # tmux version >= 2.1
```

## 生效配置

修改配置后，重启 tmux 生效配置

```shell
tmux kill-server
tmux a
```

但这样会 kill 所有 session，替代方法是：

* 进入 session
* 按下 ctrl+b : 进入命令模式
* 输入 source-file ~/.tmux.conf 回车生效

