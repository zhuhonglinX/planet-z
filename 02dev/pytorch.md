
# PyTorch

## 保存载入模型

载入模型使用 torch.load，返回值是一个 OrderedDict


## clone detach new_tensor 和 copy_

参考博客：https://blog.csdn.net/guofei_fly/article/details/104486708


## pytorch numpy cv2 和 PIL

```python
from PIL import Image
import cv2
import numpy as np
import torch

# 读取图像
pil_img = Image.open(img_path).convert('RGB')
cv_img = cv2.imread(img_path)  # BGR
cv_img = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)  # BGR -> RGB

# Numpy 和 PIL 转换
np_img = np.array(pil_img, dtype=np.float)
pil_img = Image.fromarray(np_img)

# Tensor 和 Numpy 转换
a = np.ones(5)
b = torch.from_numpy(a)

a = torch.ones(5)
b = a.numpy()

# PIL to Tensor
tensor_img = torch.from_numpy(np.array(pil_img))
# Check torchvision.transforms.function.to_tensor
```

## permute

pytorch tensor 将 HWC 格式转换为 CHW 格式

```python
a = a.permute(2, 0, 1).contiguous()
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





