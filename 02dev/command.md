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



