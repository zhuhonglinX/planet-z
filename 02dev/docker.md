# docker

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
docker ps -al      # check container, -a all, -l latest
docker system df   # check all size

docker rmi <image ID>    # delete image
docker rm <container ID> # delete container

# 从 image 创建 container
docker run -ti <image name> /bin/bash
docker rum -ti -v <host path>:<container path> <image name> /bin/bash

# 使用 gpu
docker run --runtime nvidia -ti <image name> /bin/bash

# Ctrl + D 退出并挂起容器
# Ctrl + P Ctrl + Q 退出容器
docker start <container ID>
docker attach <container ID>  # 进入容器，退出挂起
docker exec -ti <container ID> /bin/bash  # 进入容器，退出不会挂起

docker stop <container ID>  # 挂起容器

```