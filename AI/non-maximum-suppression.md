# 非极大值抑制

## 介绍



在目标检测的任务中，模型往往是先划定图片中的一些区域，形成一个框，然后判定这个框中是否包含需要检测的物体，那么在这个过程中，会产生同一个物体，有多个框对其预测的情况，这时候我们只需要保留一个预测框即可。如图：

![non-max-suppression](./img/non-max-suppression/non-max-suppression.png)



## 实现步骤

1. 根据所有框的得分大小排序，选择的得分最高的框 Box1
2. 遍历其余的框，和 Box1 进行 IoU 计算，如果 IoU 的值大于一个阈值，则删除这个框
3. 除了之前选择的框以外，剩下的框中再选一个得分最高的，重复步骤2，直到没有其他框的得分小于所选择的框



NMS 在使用的时候，不同的类别要分别进行，例如存在类别（汽车，行人）。那么需要分别对汽车和行人进行NMS。



代码包含 IoU 的计算，可以查看另一篇关于 IoU 说明的文章。这里使用矩阵运算，加快计算速度，而不是单纯调用之前写的 IoU 函数。

```python
def nms(dets, threshold):
  	x1 = dets[:, 0]
    y1 = dets[:, 1]
    x2 = dets[:, 2]
    y2 = dets[:, 3]
    scores = dets[:, 4]
    
    # 每一个候选框的面积，计算上如果 x1 = 4， x2 = 5，我们认为长度是 2，即 5 - 4 + 1，所以要加 1
    areas = (x2 - x1 + 1) * (y2 - y1 + 1)
    # 按照 score 降序排序的
    order = scores.argsort()[::-1]
    
    keep = []
    while order.size > 0:
        i = order[0]
        keep.append(i)  # 保留这个框
        
        # 计算当前概率最大矩形框与其他矩形框的相交框的坐标，得到向量
        xx1 = np.maximum(x1[i], x1[order[1:]])
        yy1 = np.maximum(y1[i], y1[order[1:]])
        xx2 = np.minimum(x2[i], x2[order[1:]])
        yy2 = np.minimum(y2[i], y2[order[1:]])

        # 计算相交框的面积，矩形框不相交时w或h算出来会是负数，用0代替
        w = np.maximum(0.0, xx2 - xx1 + 1)
        h = np.maximum(0.0, yy2 - yy1 + 1)
        inter = w * h
        # 计算重叠度IOU：重叠面积/（面积1+面积2-重叠面积）
        ovr = inter / (areas[i] + areas[order[1:]] - inter)

        # 找到重叠度不高于阈值的矩形框索引
        inds = np.where(ovr <= thresh)[0]
        # 将order序列更新
        order = order[inds + 1]
    return keep
    
```

