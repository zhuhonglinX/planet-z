
# PyTorch

## 保存载入模型

载入模型使用 torch.load，返回值是一个 OrderedDict


## np cv 和 PIL

```python
from PIL import Image
import cv2

# 读取图像
img1 = Image.open(img_path).convert('RGB')
img2 = cv2.imread(img_path)  # BGR
img2 = cv2.cvtColor(img2, cv2.COLOR_BGR2RGB)  # BGR -> RGB

# numpy PIL 转换
img3 = np.array(img1, dtype=np.float)
img4 = Image.fromarray(img2)

```

## torch 和 numpy

```python
# torch numpy 转换
import numpy as np
import torch

a = np.ones(5)
b = torch.from_numpy(a)

a = torch.ones(5)
b = a.numpy()
```


## torchvision

### transforms

```python
from torchvision import transforms

transform = transforms.Compose([
	transforms.ToTensor(),
  	transforms.Normalize(mean = (0.5, 0.5, 0.5), std = (0.5, 0.5, 0.5)),
])
```

`ToTensor()` 将 `PIL.Image` 或 `numpy.ndarray` 数据进转化为 `torch.FloadTensor`，并归一化到`[0, 1.0]`。

* 形状为 `[H, W, C]` 的 `numpy.ndarray`，转换成形状为 `[C, H, W]`，取值范围是 `[0, 1.0]` 的`torch.FloadTensor`。
* 取值范围为 `[0, 255]` 的 `PIL.Image`，转换成形状为 `[C, H, W]`，取值范围是 `[0, 1.0]` 的`torch.FloadTensor`





