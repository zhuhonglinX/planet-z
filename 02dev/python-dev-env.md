# python 开发环境

## miniconda
[安装地址](https://docs.conda.io/en/latest/miniconda.html)

## conda

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

## Jupyter

```shell
jupyter notebook
```

进入 jupyter 后，创建代码段，输入

```python
import sys
sys.executable
# 观察输出的 python 解释器路径是否正确
```

#### Jupyter Kernel

我们使用 conda 安装 python，因此需要让Jupyter找到正确的python解释器路径，即正确的kernel。

```shell
# 1. 进入conda目标环境并安装 ipykernel
conda install ipykernel
# 2. 写入 notebook
python -m ipykernel install --user --name 环境名称 --display-name "kernel 名称"

## 其他查看删除操作
jupyter kernelspec list
jupyter kernelspec remove <kernel 名称>
```


#### 远程Jupyter

有时候需要使用服务器的GPU，因此可以服务器开启Jupyter，然后使用自己的浏览器打开Jupyter。

```shell
# 创建配置文件：~/.jupyter/jupyter_notebook_config.py
jupyter notebook --generate-config

# 打开配置文件并修改配置
c.NotebookApp.open_browser = False
c.NotebookApp.port = 8888 # 指定一个端口，注意服务器的防火墙需要允许这个端口

# 启动服务器 jupyter
jupyter notebook --ip 0.0.0.0
```

启动后使用本地浏览器访问即可。



## pip

``` shell
pip install -i https://pypi.tuna.tsinghua.edu.cn/simple <package name>
pip install -i https://pypi.douban.com/simple <package name>
```

