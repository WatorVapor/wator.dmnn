# wator
Deep Learning Base On CephFS.

Train Visual Cortex V1.

用无标签数据初级视觉皮层简单训练方法。

－》已知是简单皮层细胞只对线段倾斜的有感应。
 －》对每个功能住来说，简单细胞数量有限。
  －》每个简单细胞对应感应的倾斜角应该是有个刻度范围。
   －》180度除简单皮层细胞的个数就是，这个刻度A。

无标签的任意一张图片。
任意切出倾斜检测候补大小切出来一块。（10x10？）
 －》如果他能 引起一个简单细胞激活。
  －》把它旋转刻度A，必定引起对应另一个倾斜角的简单细胞被激活。
   －》旋转完180度。必定所有简单细胞都被激活一次。

？初始训练：
 －》人工制作的图像进行阶段图形。（RGB）
 －》人工制图像一色图像（RGB）


训练网络：
 输入
   10x10 100pix灰度图像。全链接网络。输出网络
 输出
   倾斜数。或者 无倾斜（抑制，无边缘）。

训练过程：
 －》一张有倾斜图片的第一次前传播的结果是。
   ［1，0，0，0，0］
 －》本图片的一次翻转的后。期望的结果。
   ［0，1，0，0，0］

