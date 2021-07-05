# Deep Learning Framework Exploration-基础ch1

## 正向传播

如图：

![](./imgs/bp-1.png)

假设一个简单 3 层全连接网络结构，输入用 $ x $ 表示，上标 $ (l) $ 表示第 $ l $ 层神经元，每一层的输出用符号 $ y $ 表示，权重用符号 $ w $ 表示，部分连接线路没有画出来。暂时忽略偏置和激活函数。

第一层的参数表示如下：
$$
\begin{bmatrix}
w_{11}^{(1)} & w_{12}^{(1)} & w_{13}^{(1)} \\
w_{21}^{(1)} & w_{22}^{(1)} & w_{23}^{(1)} \\
\end{bmatrix}
$$
第一层神经元的值为：
$$
\begin{bmatrix}
y_{1}^{(1)} & y_{2}^{(1)} & y_{3}^{(1)}
\end{bmatrix}
=
\begin{bmatrix}
x_1 & x_2
\end{bmatrix}
\times
\begin{bmatrix}
w_{11}^{(1)} & w_{12}^{(1)} & w_{13}^{(1)} \\
w_{21}^{(1)} & w_{22}^{(1)} & w_{23}^{(1)} \\
\end{bmatrix}
$$
以此类推，第二层的参数和神经元值为：
$$
\begin{bmatrix}
w_{11}^{(2)} & w_{12}^{(2)} & w_{13}^{(2)} \\
w_{21}^{(2)} & w_{22}^{(2)} & w_{23}^{(2)} \\
w_{31}^{(2)} & w_{32}^{(2)} & w_{33}^{(2)} \\
\end{bmatrix}
$$

$$
\begin{bmatrix}
y_{1}^{(2)} & y_{2}^{(2)} & y_{3}^{(2)}
\end{bmatrix}
=
\begin{bmatrix}
y_{1}^{(1)} & y_{2}^{(1)} & y_{3}^{(1)}
\end{bmatrix}
\times
\begin{bmatrix}
w_{11}^{(2)} & w_{12}^{(2)} & w_{13}^{(2)} \\
w_{21}^{(2)} & w_{22}^{(2)} & w_{23}^{(2)} \\
w_{31}^{(2)} & w_{32}^{(2)} & w_{33}^{(2)} \\
\end{bmatrix}
$$

第三层的参数和神经元为：
$$
\begin{bmatrix}
w_{11}^{(3)} & w_{12}^{(3)} & w_{13}^{(3)} \\
w_{21}^{(3)} & w_{22}^{(3)} & w_{23}^{(3)} \\
w_{31}^{(3)} & w_{32}^{(3)} & w_{33}^{(3)} \\
\end{bmatrix}
$$

$$
\begin{bmatrix}
y_{1}^{(3)} & y_{2}^{(3)} & y_{3}^{(3)}
\end{bmatrix}
=
\begin{bmatrix}
y_{1}^{(2)} & y_{2}^{(2)} & y_{3}^{(2)}
\end{bmatrix}
\times
\begin{bmatrix}
w_{11}^{(3)} & w_{12}^{(3)} & w_{13}^{(3)} \\
w_{21}^{(3)} & w_{22}^{(3)} & w_{23}^{(3)} \\
w_{31}^{(3)} & w_{32}^{(3)} & w_{33}^{(3)} \\
\end{bmatrix}
$$

第三层为最后一层，进入 $loss$ 函数进行运算：
$$
L = f(y_{1}^{(3)}, y_{2}^{(3)}, y_{3}^{(3)})
$$


上述过程就是整个正向传播的过程用矩阵运算的表示结果。



## 反向传播

还是使用之前的例子，网络结构如图：

![](./imgs/bp-1.png)



由梯度下降的公式得：
$$
w = w -\alpha \frac{\partial L}{\partial w}
$$
需要对每一个权重计算 ${\partial L}/{\partial w}$。可以先看公式推导，首先计算第三层（最后一层的梯度），如图：


$$
\frac{\partial L}{\partial w_{11}^{(3)}} = \frac{\partial L}{\partial y_{1}^{(3)}} \cdot \frac{\partial y_{1}^{(3)}}{\partial w_{11}^{(3)}} = \frac{\partial L}{\partial y_{1}^{(3)}} \cdot y_{1}^{(2)}
$$
同理得到其他第三层的梯度：
$$
\frac{\partial L}{\partial w_{12}^{(3)}} = \frac{\partial L}{\partial y_{2}^{(3)}} \cdot y_{1}^{(2)}
$$

$$
\frac{\partial L}{\partial w_{13}^{(3)}} = \frac{\partial L}{\partial y_{3}^{(3)}} \cdot y_{1}^{(2)}
$$

$$
\frac{\partial L}{\partial w_{21}^{(3)}} = \frac{\partial L}{\partial y_{1}^{(3)}} \cdot y_{2}^{(2)}
$$

以次类推，得到第三层所有权重的梯度值，假设我们用符号 $g_{ii}^{(l)}$ 表示 $l$ 层的权重们的梯度值，用矩阵表示结果：
$$
\begin{bmatrix}
g_{11}^{(3)} & g_{12}^{(3)} & g_{13}^{(3)} \\
g_{21}^{(3)} & g_{22}^{(3)} & g_{23}^{(3)} \\
g_{31}^{(3)} & g_{32}^{(3)} & g_{33}^{(3)} \\
\end{bmatrix}
=
\begin{bmatrix}
\frac{\partial L}{\partial y_{1}^{(3)}} \cdot y_{1}^{(2)} &  \frac{\partial L}{\partial y_{2}^{(3)}} \cdot y_{1}^{(2)} & \frac{\partial L}{\partial y_{3}^{(3)}} \cdot y_{1}^{(2)} \\
\frac{\partial L}{\partial y_{1}^{(3)}} \cdot y_{2}^{(2)} & \frac{\partial L}{\partial y_{2}^{(3)}} \cdot y_{2}^{(2)} & \frac{\partial L}{\partial y_{2}^{(3)}} \cdot y_{2}^{(2)} \\
\frac{\partial L}{\partial y_{1}^{(3)}} \cdot y_{3}^{(2)} & \frac{\partial L}{\partial y_{2}^{(3)}} \cdot y_{3}^{(2)} & \frac{\partial L}{\partial y_{3}^{(3)}} \cdot y_{3}^{(2)} \\
\end{bmatrix}
$$
化简表达式：
$$
\begin{bmatrix}
g_{11}^{(3)} & g_{12}^{(3)} & g_{13}^{(3)} \\
g_{21}^{(3)} & g_{22}^{(3)} & g_{23}^{(3)} \\
g_{31}^{(3)} & g_{32}^{(3)} & g_{33}^{(3)} \\
\end{bmatrix}
=
\begin{bmatrix}
y_{1}^{(2)} \\
y_{2}^{(2)} \\
y_{3}^{(2)}
\end{bmatrix}
\times
\begin{bmatrix}
\frac{\partial L}{\partial y_{1}^{(3)}} &
\frac{\partial L}{\partial y_{2}^{(3)}} &
\frac{\partial L}{\partial y_{3}^{(3)}}
\end{bmatrix}
$$


同理计算第二层的梯度：
$$
\begin{bmatrix}
g_{11}^{(2)} & g_{12}^{(2)} & g_{13}^{(2)} \\
g_{21}^{(2)} & g_{22}^{(2)} & g_{23}^{(2)} \\
g_{31}^{(2)} & g_{32}^{(2)} & g_{33}^{(2)} \\
\end{bmatrix}
=
\begin{bmatrix}
y_{1}^{(1)} \\
y_{2}^{(1)} \\
y_{3}^{(1)}
\end{bmatrix}
\times
\begin{bmatrix}
\frac{\partial L}{\partial y_{1}^{(2)}} &
\frac{\partial L}{\partial y_{2}^{(2)}} &
\frac{\partial L}{\partial y_{3}^{(2)}}
\end{bmatrix}
$$
上式中，$\partial L / \partial y_1^{(2)}$、$\partial L / \partial y_2^{(2)}$、$\partial L / \partial y_3^{(2)}$ 明显需要计算，我们进一步写出其表达式，例如：
$$
\frac{\partial L}{\partial y_{1}^{(2)}} = \frac{\partial L}{\partial y_1^{(3)}} \cdot w_{11}^{(3)} + \frac{\partial L}{\partial y_2^{(3)}} \cdot w_{12}^{(3)} + \frac{\partial L}{\partial y_3^{(3)}} \cdot w_{13}^{(3)}
$$
显然，第二层梯度需要计算的 $\frac{\partial L}{\partial y_1^{(3)}}$，$\frac{\partial L}{\partial y_2^{(3)}}$，$\frac{\partial L}{\partial y_3^{(3)}}$ 在第三层的计算梯度的时候已经计算过了，因此，只需要将计算的值保存下来就可以直接利用了，我们假定后一层传递过来的信息用符号 $t$ 表示，即 $\frac{\partial L}{\partial y} \to t$。如下图，对于第二层的参数来说，计算其梯度需要后一层传递过来的信息 $t^{(2)}$ ，以及该层原本的输入值 $y^{(1)}$。

![](./imgs/bp-2.png)

我们可以写出 $t$ 的传播计算公式，对于第三层得到的 $t^{(3)}$ ，由于直接接的损失函数，所以直接计算梯度就可以：
$$
t^{3} = 
\begin{bmatrix}
t_1^{(3)} &
t_2^{(3)} &
t_3^{(3)}
\end{bmatrix}
=
\begin{bmatrix}
\frac{\partial L}{\partial y_{1}^{(3)}} &
\frac{\partial L}{\partial y_{2}^{(3)}} &
\frac{\partial L}{\partial y_{3}^{(3)}}
\end{bmatrix}
$$
第二层的 $t^{(2)}$，单独看 $t_{1}^{(2)}$：
$$
t_{1}^{(2)} = t_1^{(3)} \cdot w_{11}^{(3)} + t_2^{(3)} \cdot w_{12}^{(3)} + t_3^{(3)} \cdot w_{13}^{(3)}
$$
因此，整个$t^{(2)}$ 表达如下：
$$
t^{(2)} =
\begin{bmatrix}
t_1^{(2)} &
t_2^{(2)} &
t_3^{(2)}
\end{bmatrix}
=
\begin{bmatrix}
t_1^{(3)} &
t_2^{(3)} &
t_3^{(3)}
\end{bmatrix}
\times
\begin{bmatrix}
w_{11}^{(3)} & w_{12}^{(3)} & w_{13}^{(3)} \\
w_{21}^{(3)} & w_{22}^{(3)} & w_{23}^{(3)} \\
w_{31}^{(3)} & w_{32}^{(3)} & w_{33}^{(3)} \\
\end{bmatrix}^T
$$
同理得到 $t^{(1)}$ 的表达式：
$$
t^{(1)} =
\begin{bmatrix}
t_1^{(1)} &
t_2^{(1)} &
t_3^{(1)}
\end{bmatrix}
=
\begin{bmatrix}
t_1^{(2)} &
t_2^{(2)} &
t_3^{(2)}
\end{bmatrix}
\times
\begin{bmatrix}
w_{11}^{(2)} & w_{12}^{(2)} & w_{13}^{(2)} \\
w_{21}^{(2)} & w_{22}^{(2)} & w_{23}^{(2)} \\
w_{31}^{(2)} & w_{32}^{(2)} & w_{33}^{(2)} \\
\end{bmatrix}^T
$$
这样完成整个反向传播的链路

