# IoU

## 简单介绍

目标检测评价体系中，使用 IoU（Intersection over Union）来评价模型预测框和真实框之间的吻合程度。



如图：

![IoU示例图](./img/IOU/iou.png)



IoU 的值始终是小于等于 1 的，当预测框和真实框大小一样、位置相同时，IoU就达到了最大值 1 。所以目标检测其中有一个目标就是最大化 IoU



## 代码

我们先假定使用四个值来表示一个框，$(x_1, y_1, x_2, y_2)$，分别代表框左上角和右下角的坐标。

接着使用 $(xi_1, yi_2, xi_2, yi_2)$ 表示两个框的交集。

```python
def iou(box1, box2):
    """
    Arguments:
    box1 -- first box, list object with coordinates (x1, y1, x2, y2)
    box2 -- second box, list object with coordinates (x1, y1, x2, y2)
    """
		
    # 计算交集面积大小
    xi1 = max(box1[0],box2[0])
    yi1 = max(box1[1],box2[1])
    xi2 = min(box1[2],box2[2])
    yi2 = min(box1[3],box2[3])
    inter_area = abs((yi2-yi1)*(xi2-xi1))  
	
  	# 计算并集面积大小
    box1_area = abs((box1[1]-box1[3])*(box1[0]-box1[2]))
    box2_area = abs((box2[1]-box2[3])*(box2[0]-box2[2]))
    union_area = box1_area+box2_area-inter_area

    iou = inter_area*1.0/union_area
    return iou
```

