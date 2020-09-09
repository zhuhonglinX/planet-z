# PyTorch 使用

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

