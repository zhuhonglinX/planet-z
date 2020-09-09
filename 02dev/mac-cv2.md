# opencv python 使用

python 开发环境：Mac os，conda。

虽然使用 conda 可以直接安装 opencv，但是 opencv 库比较通用，所以我打算在系统中安装，然后让所有 conda 虚拟环境的 python 链接系统的 opencv 库。



安装 opencv

```bash
# 目前版本为4.1.2
brew install opencv

# 查看可以安装的版本
brew search opencv

# opencv 将会被安装在 /usr/local/Cellar/ 目录下
```



接下去就是在 python 的 site-packages 目录下链接 opencv 库中的 .so 文件。例如

```bash
ln -s /usr/local/Cellar/opencv/4.1.2/lib/python3.7/site-packages/cv2/python-3.7/cv2.cpython-37m-darwin.so /Users/<username>/miniconda3/envs/ai/lib/python3.7/site-packages
```



完成后测试：

```bash
import cv2
cv2.__version__
```



