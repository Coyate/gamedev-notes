Buffer种类和区别,early Z,depth test,Alpha blending


### buffer
	• Implementation of "Fast Global Illumination Approximations on Deep G-Buffers" (Mara et. al, 2016) https://github.com/trevor-m/deep-gbuffers

	• G-Buffer的组织 https://blog.csdn.net/spracle/article/details/24540963


1.19 深度缓存算法(zbuffer算法)?
需要一个空间保存每个像素的深度，绘制前初始化所有深度为无限远，绘制时当前片段如果比zbuffer中的值大（说明更远），则跳过此片段，保留原来的渲染结果；否则，绘制此片段，并更新zbuffer。
可以处理对透明物体的消除
算法可以并行
与画家算法不同，不需要对物体排序

光栅化生成的fragment是通过pixel shader执行的，在应用z-buffer时，会发现被先前渲染的fragment所隐藏，那么它接下来在pixel shader都是没有意义的。为了避免这种资源的浪费，许多GPU都会在pixel shader前进行一些merge testing。用z-depth测试可见性，如果需要隐藏，那么cull掉这个fragment，这个功能就叫early-z。Pixel shader可以改变fragment的z-depth或者完全discard掉fragment，如果发现在pixel shader program中存在这些操作，那么就会关闭early-z的功能，这一般会降低管线效率。

帧缓冲器（frame buffer）通常包含一个系统所具有的所有缓冲器，但有时也可以认为是颜色缓冲器和z缓冲器的组合。

&emsp;&emsp; Z-buffer，这些 buffer 又被称为 Frame buffer （帧缓存区）。

这个阶段还可以解决可见性问题。对于几乎所有的硬件来说，这种处理都是基于z-buffer（或者叫depth buffer）算法实现的。


Z-buffer跟Color buffer的大小、形状一样。每一个像素都存储一个z-value，这个z-value是相机到最近的primitive的距离。每次将一个primitive渲染到某个pixel时，需要计算这个pixel对应的primitive的z-value，并与同一个pixel的z-buffer的z-value比较。

如果新的z-value小于z-buffer中的z-value，那么表示这个即将被渲染的primitive距离相机的距离比用于比较的那个z-value对应的primitive更近。这样就使用新的z-value，跟color，替换掉原本同一pixel位置的值。如果大于，那就不管它。


Z缓冲器器和颜色缓冲器形状大小一样，每个像素都存储着一个z值，这个z值是从相机到最近图元之间的距离。

每次将一个图元绘制为相应像素时，需要计算像素位置处图元的z值，并与同一像素处的z缓冲器内容进行比较。

如果新计算出的z值，远远小于z缓冲器中的z值，那么说明即将绘制的图元与相机的距离比原来距离相机最近的图元还要近。这样，像素的z值和颜色就由当前图元对应的值和颜色进行更新。反之，若计算出的z值远远大于z缓冲器中的z值，那么z缓冲器和颜色缓冲器中的值就无需改变。

上面刚说到，颜色缓冲器用来存储颜色，z缓冲器用来存储每个像素的z值，还有其他缓冲器可以用来过滤和捕获片段信息。

&emsp;&emsp;
光栅化生成的fragment是通过pixel shader执行的，在应用z-buffer时，会发现被先前渲染的fragment所隐藏，那么它接下来在pixel shader都是没有意义的。为了避免这种资源的浪费，许多GPU都会在pixel shader前进行一些merge testing。用z-depth测试可见性，如果需要隐藏，那么cull掉这个fragment，这个功能就叫early-z。Pixel shader可以改变fragment的z-depth或者完全discard掉fragment，

如果发现在pixel shader program中存在这些操作，那么就会关闭early-z的功能，这一般会降低管线效率。


&emsp;&emsp; Alpha test

此外，color blending所使用的公式也是一种标志性功能。
如果fragment可见，那么在这个阶段会发生color blending的operation。对于不透明的表面，没有真正的blending，因为fragment只是简单的进行了替换之前存储的color。


比如alpha通道（alpha channel）和颜色缓冲器联系在一起可以存储一个与每个像素相关的不透明值。可选的alpha测试可在深度测试执行前在传入片段上运行。片段的alpha值与参考值作某些特定的测试（如等于，大于等），如果片断未能通过测试，它将不再进行进一步的处理。alpha测试经常用于不影响深度缓存的全透明片段（见6.6节）的处理。

&emsp;&emsp; Stencil test



模板缓冲区（Stencil buffer）用于记录所渲染的primitive位置的离屏（offscreen）buffer。通常一个pixel有8 bits。使用各种方法将Primitive渲染到stencil buffer，而这个buffer中的值可以控制color buffer跟z-buffer的渲染。
  
模板缓冲器（stencil buffer）是用于记录所呈现图元位置的离屏缓存。每个像素通常与占用8个位。图元可使用各种方法渲染到模板缓冲器中，而缓冲器中的内容可以控制颜色缓存和Z缓存的渲染。举个例子，假设在模版缓冲器中绘制出了一个实心圆形，那么可以使用一系列操作符来将后续的图元仅在圆形所出现的像素处绘制，类似一个mask的操作。模板缓冲器是制作特效的强大工具。而在管线末端的所有这些功能都叫做光栅操作（raster operations ，ROP）或混合操作（blend operations）。


&emsp;&emsp;图形处理一般使用双缓冲（double buffering）隐藏屏幕绘制的过程。

而当图元通过光栅化阶段之后，从相机视点处看到的东西就可以在荧幕上显示出来。为了避免观察者体验到对图元进行处理并发送到屏幕的过程，图形系统一般使用了双缓冲（double buffering）机制，这意味着屏幕绘制是在一个后置缓冲器（backbuffer）中以离屏的方式进行的。一旦屏幕已在后置缓冲器中绘制，后置缓冲器中的内容就不断与已经在屏幕上显示过的前置缓冲器中的内容进行交换。注意，只有当不影响显示的时候，才进行交换。

累计缓冲器（accumulation buffer），是1990年，Haeberli和Akeley提出的一种缓冲器，是对帧缓冲器的补充。这个缓冲器可以用一组操作符对图像进行累积。例如，为了产生运动模糊（motion blur.，可以对一系列物体运动的图像进行累积和平均。此外，其他的一些可产生的效果包括景深（e depth of field），反走样（antialiasing）和软阴影（soft shadows）等。


### 延迟渲染 Deferred Rendering
https://github.com/QianMo/Game-Programmer-Study-Notes/tree/master/Content/%E3%80%8AReal-Time%20Rendering%203rd%E3%80%8B%E8%AF%BB%E4%B9%A6%E7%AC%94%E8%AE%B0/Content/BlogPost07
比较
在一个标准的Forward Rendering 的渲染管线里，对于每个光源，必须计算场景中每个顶点的光照（使用Vertex shading）。假设场景中有100个物体，每个物体有1000个顶点，那就差不多有100000个多边形，显卡处理这个量集的定点数是很随意的，但是当把这些多边形发送到fregment shader中进行处理, 在这里的光照计算会消耗大量的性能。



开发者总是试图将更多的光照计算放到Vertex Shader而不是放到fregment shader，这样能够节省很多性能。每一块可见的片段都会进行昂贵的光照的计算，不管它是不是被其他的片段遮挡，度过屏幕的像素是1024 * 768，那么将有将近800000个像素需要渲染，那么渲染的每一帧在都可能在在fregment shader 中进行数百万次，甚至那些经过深度测试已经被遮挡的像素也要被计算，这样将会造成很大的性能浪费。



更可怕的是，当你在场景中再加上一盏灯的时候，那么fragment shader又要为这个光源再重新计算一遍，想像一下一条满是灯光的街道...



Forward Rendering渲染的复杂度可以用O(num_geometry_fragments * num_lights)来表示，可以看出复杂度和集合体的面数还有光源的数量正相关。



一些引擎通过一些算法进行了优化，比如太远处的光源不参与计算，合并光源，或者使用light map(只能是静态)，但是i如果想要实现动态多光源，那就需要一个更好的解决方案。



Deferred Rendering 就是一个很好的解决方案。它能够很好的减少渲染物体的数量，也就是渲染片段的数量，在进行光照计算的时候用的是屏幕上的像素数量，而不是所有片段像素的总和。它的光照渲染的时间复杂度可以用O(screen_resolution * num_lights)来表示，他和场景中物体的数量是无关的，只和光源数量有关。



如何抉择
简单的回答是，如果你使用的是很多动态光源，那么就使用Deferred Rendering，但是它也有一些缺点：

1.需要比较新的显卡，支持多目标渲染；

2.需要很大的显卡带宽，用来传递Buffer；

3.不用处理透明的对象（除非把Forward rendering 和 Deferred rendering结合起来）；

4.没法用传统的抗锯齿方法， 比如MSAA，但是屏幕空间的FXAA是适用的；

5.只能使用一种材质，但是有一种解决方法是Deferred Lighting；

6.阴影的数量还是和光源的数量有关。



如果游戏中没有很多的光源并且需要兼容老的设备，那么最好选择Forward Rendering，然后采用静态的Light map，效果也很不错。

#### TBDR（Tile Based Deferred Rendering，区块延迟渲染）
　TBR虽然比IMR聪明多了，不过还是存在不少缺陷，TBDR（Tile Based Deferred Rendering，贴图延迟渲染）闪亮登场，它跟TBR原理相似，但是使用的是延迟渲染（Deferred Rendering），合并了完美像素，通过HSR（Hidden Surface Removal，隐藏面消除）等进一步减少了不需要渲染的过程，降低了带宽需求。实际上这些改变和PC上的渲染有些相似。



#### AA 抗锯齿

伍-抗锯齿与常见抗锯齿类型总结
抗锯齿（英语：anti-aliasing，简称AA），也译为边缘柔化、消除混叠、抗图像折叠有损，反走样等。它是一种消除显示器输出的画面中图物边缘出现凹凸锯齿的技术，那些凹凸的锯齿通常因为高分辨率的信号以低分辨率表示或无法准确运算出3D图形坐标定位时所导致的图形混叠（aliasing）而产生的，抗锯齿技术能有效地解决这些问题。

下面将常见的几种抗锯齿类型进行总结介绍，也包括RTR3中没有讲到的，最近几年新提出的常见抗锯齿类型。

5.1 超级采样抗锯齿（SSAA）
超级采样抗锯齿（Super-Sampling Anti-Aliasing，简称SSAA）是比较早期的抗锯齿方法，比较消耗资源，但简单直接。这种抗锯齿方法先把图像映射到缓存并把它放大，再用超级采样把放大后的图像像素进行采样，一般选取2个或4个邻近像素，把这些采样混合起来后，生成的最终像素，令每个像素拥有邻近像素的特征，像素与像素之间的过渡色彩，就变得近似，令图形的边缘色彩过渡趋于平滑。再把最终像素还原回原来大小的图像，并保存到帧缓存也就是显存中，替代原图像存储起来，最后输出到显示器，显示出一帧画面。这样就等于把一幅模糊的大图，通过细腻化后再缩小成清晰的小图。如果每帧都进行抗锯齿处理，游戏或视频中的所有画面都带有抗锯齿效果。 超级采样抗锯齿中使用的采样法一般有两种：

OGSS，顺序栅格超级采样（Ordered Grid Super-Sampling，简称OGSS），采样时选取2个邻近像素。

RGSS，旋转栅格超级采样（Rotated Grid Super-Sampling，简称RGSS），采样时选取4个邻近像素。

另外，作为概念上最简单的一种超采样方法，全场景抗锯齿（Full-Scene Antialiasing,FSAA）以较高的分辨率对场景进行绘制，然后对相邻的采样样本进行平均，从而生成一幅新的图像。

5.2 多重采样抗锯齿（MSAA）
多重采样抗锯齿（Multi Sampling Anti-Aliasing，简称MSAA），是一种特殊的超级采样抗锯齿（SSAA）。MSAA首先来自于OpenGL。具体是MSAA只对Z缓存（Z-Buffer）和模板缓存(Stencil Buffer)中的数据进行超级采样抗锯齿的处理。可以简单理解为只对多边形的边缘进行抗锯齿处理。这样的话，相比SSAA对画面中所有数据进行处理，MSAA对资源的消耗需求大大减弱，不过在画质上可能稍有不如SSAA。
https://www.cnblogs.com/ghl_carmack/p/8245032.html

5.3 覆盖采样抗锯齿（CSAA）
覆盖采样抗锯齿（Coverage Sampling Anti-Aliasing，简称CSAA）是NVIDIA在G80及其衍生产品首次推向实用化的AA技术，也是目前NVIDIA GeForce 8/9/G200系列独享的AA技术。CSAA就是在MSAA基础上更进一步的节省显存使用量及带宽，简单说CSAA就是将边缘多边形里需要取样的子像素坐标覆盖掉，把原像素坐标强制安置在硬件和驱动程序预先算好的坐标中。这就好比取样标准统一的MSAA，能够最高效率的执行边缘取样，效能提升非常的显著。比方说16xCSAA取样性能下降幅度仅比4xMSAA略高一点，处理效果却几乎和8xMSAA一样。8xCSAA有着4xMSAA的处理效果，性能消耗却和2xMSAA相同。

5.4 高分辨率抗锯齿（HRAA）
高分辨率抗锯齿方法(High Resolution Anti-Aliasing，简称HRAA)，也称Quincunx方法，也出自NVIDIA公司。“Quincunx”意思是5个物体的排列方式，其中4个在正方形角上，第五个在正方形中心，也就是梅花形，很像六边模型上的五点图案模式。此方法中，采样模式是五点梅花状，其中四个样本在像素单元的角上，最后一个在中心。

5.5 可编程过滤抗锯齿（CFAA）
可编程过滤抗锯齿（Custom Filter Anti-Aliasing，简称CFAA）技术起源于AMD-ATI的R600家庭。简单地说CFAA就是扩大取样面积的MSAA，比方说之前的MSAA是严格选取物体边缘像素进行缩放的，而CFAA则可以通过驱动和谐灵活地选择对影响锯齿效果较大的像素进行缩放，以较少的性能牺牲换取平滑效果。显卡资源占用也比较小。

5.6 形态抗锯齿（MLAA）
形态抗锯齿（Morphological Anti-Aliasing，简称MLAA），是AMD推出的完全基于CPU处理的抗锯齿解决方案。与MSAA不同， MLAA将跨越边缘像素的前景和背景色进行混合，用第2种颜色来填充该像素，从而更有效地改进图像边缘的变现效果。

https://blog.csdn.net/leonwei/article/details/52442642

5.7 快速近似抗锯齿（FXAA）
快速近似抗锯齿(Fast Approximate Anti-Aliasing，简称FXAA) ，是传统MSAA(多重采样抗锯齿)效果的一种高性能近似。它是一种单程像素着色器，和MLAA一样运行于目标游戏渲染管线的后期处理阶段，但不像后者那样使用DirectCompute，而只是单纯的后期处理着色器，不依赖于任何GPU计算API。正因为如此，FXAA技术对显卡没有特殊要求，完全兼容NVIDIA、AMD的不同显卡(MLAA仅支持A卡)和DirectX 9.0、DirectX 10、DirectX 11。

5.8 时间性抗锯齿（TXAA）
时间性抗锯齿（Temporal Anti-Aliasing，简称TXAA），将 MSAA、时间滤波以及后期处理相结合，用于呈现更高的视觉保真度。与CG电影中所采用的技术类似，TXAA集MSAA的强大功能与复杂的解析滤镜于一身，可呈现出更加平滑的图像效果。此外，TXAA还能够对帧之间的整个场景进行抖动采样，以减少闪烁情形，闪烁情形在技术上又称作时间性锯齿。目前，TXAA有两种模式：TXAA 2X和TXAA 4X。TXAA 2X可提供堪比8X MSAA的视觉保真度，然而所需性能却与2X MSAA相类似；TXAA 4X的图像保真度胜过8XMSAA，所需性能仅仅与4X MSAA相当。

5.9 多帧采样抗锯齿（MFAA）
多帧采样抗锯齿（Multi-Frame Sampled Anti-Aliasing，MFAA）是 NVIDIA公司根据MSAA改进出的一种抗锯齿技术。目前仅搭载 Maxwell 架构GPU的显卡才能使用。可以将MFAA理解为MSAA的优化版，能够在得到几乎相同效果的同时提升性能上的表现。MFAA与MSAA最大的差别就在于在同样开启4倍效果的时候MSAA是真正的针对每个边缘像素周围的4个像素进行采样，MFAA则是仅仅只是采用交错的方式采样边缘某个像素周围的两个像素。









### alpha blend

1.8 Alpha 混合的几种方式？
通用公式：
Color = Src *Srcfactor + Dst * Dstfactor
其中Color是混合结果，Src是源颜色向量也就是纹理本来的颜色，Dst是目标颜色向量也就是储存在颜色缓冲中当前位置的颜色向量, srcfactor和dstfactor分别是源因子和目标因子。先进入颜色缓冲区的是目标颜色，比如在红色方块上绘制绿色方块，则红色是Dst，绿色是Src。不同的 factor 导致了不同的混合方式：

注意，颜色常数向量可以用glBlendColor函数分开来设置。OpenGL中使用 void glBlendFunc(GLenum sfactor, GLenum dfactor)设置混合方式，接收两个参数，来设置源（source）和目标（destination）因子。OpenGL为我们定义了很多选项，我们把最常用的列在下面。注意，颜色常数向量[Math Processing Error]C¯constant可以用glBlendColor函数分开来设置。在使用alpha 混合前要开启 glEnable(GL_BLEND);
最常用的混合方式是 glBlendFunc(GL_SRC_ALPHA,  GL_ONE_MINUS_SRC_ALPHA); 

4.请介绍你所有知道的纹理Alpha混合方式，原理(公式).
假设一种不透明东西的颜色是A，另一种透明的东西的颜色是B，那么透过B去看A，看上去的颜色C就是B和A的混合颜色，可以用这个式子来近似，设B物体的透明度为alpha(取值为0-1，0为完全透明，1为完全不透明)

R(C)=alpha*R(B)+(1-alpha)*R(A)
G(C)=alpha*G(B)+(1-alpha)*G(A)
B(C)=alpha*B(B)+(1-alpha)*B(A)

　　R(x)、G(x)、B(x)分别指颜色x的RGB分量。看起来这个东西这么简单，可是用它实现的效果绝对不简单，应用alpha混合技术，可以实现出最眩目的火光、烟雾、阴影、动态光源等等一切你可以想象的出来的半透明效果。

6.1 透明渲染
透明渲染是是图形学里面的常见问题之一，可以从《Real-Time Rendering 3rd》中总结出如下两个算法：

Screen-Door Transparency方法。基本思想是用棋盘格填充模式来绘制透明多边形，也就是说，以每隔一个像素绘制一点方式的来绘制一个多边形，这样会使在其后面的物体部分可见，通常情况下，屏幕上的像素比较紧凑，以至于棋盘格的这种绘制方式并不会露馅。同样的想法也用于剪切纹理的抗锯齿边缘，但是在子像素级别中的，这是一种称为alpha覆盖（alpha to coverage）的特征。screen-door transparency方法的优点就是简单，可以在任何时间任何顺序绘制透明物体，并不需要特殊的硬件支持（只要支持填充模式）。缺点是透明度效果仅在50%时最好，且屏幕的每个区域中只能绘制一个透明物体。

Alpha混合（Alpha Blending）方法。这个方法比较常见，其实就是按照Alpha混合向量的值来混合源像素和目标像素。当在屏幕上绘制某个物体时，与每个像素相关联的值有RGB颜色和Z缓冲深度值，以及另外一个成分alpha分量，这个alpha值也可以根据需要生成并存储，它描述的是给定像素的对象片段的不透明度的值。 alpha为1.0表示对象不透明，完全覆盖像素所在区域; 0.0表示像素完全透明。为了使对象透明，在现有场景的上方，以小于1的透明度进行绘制即可。每个像素将从渲染管线接收到一个RGBA结果，并将这个值和原始像素颜色相混合。


#### 透明排序
要将透明对象正确地渲染到场景中，通常需要对物体进行排序。下面分别介绍两种比较基本的透明排序方法（深度缓存和油画家算法）和两种高级别的透明排序算法（加权平均值算法和深度剥离）。

6.2.1 深度缓存（Z-Buffer）
Z-Buffer也称深度缓冲。在计算机图形学中，深度缓冲是在三维图形中处理图像深度坐标的过程，这个过程通常在硬件中完成，它也可以在软件中完成，它是可见性问题的一个解决方法。可见性问题是确定渲染场景中哪部分可见、哪部分不可见的问题。

Z-buffer的限制是每像素只存储一个对象。如果一些透明对象与同一个像素重叠，那么单独的Z-buffer就不能存储并且稍后再解析出所有可见对象的效果。这个问题是通过改变加速器架构来解决的，比如用A-buffer。A-buffer具有“深度像素（deep pixels）”，其可以在单个像素中存储一系列呈现在所有对象之后被解析为单个像素颜色的多个片段。但需注意，Z-buffer是市场的主流选择。

6.2.2 画家算法（Painter's Algorithm）
画家算法也称优先填充算法，效率虽然较低，但还是可以有效处理透明排序的问题。其基本思想是按照画家在绘制一幅画作时，首先绘制距离较远的场景，然后用绘制距离较近的场景覆盖较远的部分的思想。画家算法首先将场景中的多边形根据深度进行排序，然后按照顺序进行描绘。这种方法通常会将不可见的部分覆盖，这样就可以解决可见性问题。

6.2.3 加权平均值算法（Weighted Average）
使用简单的透明混合公式来实现无序透明渲染的算法，它通过扩展透明混合公式，来实现无序透明物件的渲染，从而得到一定程度上逼真的结果。

6.2.4 深度剥离算法（Depth Peeling）
深度剥离是一种对深度值进行排序的技术。它的原理比较直观，标准的深度检测使场景中的Z值最小的点输出到屏幕上，就是离我们最近的顶点。但还有离我们第二近的顶点，第三近的顶点存在。要想显示它们，可以用多遍渲染的方法。
第一遍渲染时，按照正常方式处理，这样就得到了离我们最近的表面中的每个顶点的z值。在第二遍渲染时，把现在每个顶点的深度值和刚才的那个深度值进行比较，凡是小于等于第一遍得到的z值，把它们剥离，后面的过程依次类推即可。



图6 每个深度剥离通道渲染特定的一层透明通道。左侧是第一个Pass，直接显示眼睛可见的层，中间的图显示了第二层，显示了每个像素处第二靠近透明表面的像素。右边的图是第三层，每个像素处第三靠近透明表面的像素。





























### buffers
帧缓冲(Frame Buffer) 颜色缓冲(Color Buffer) 模板缓冲(Stencil Buffer) 顶点缓冲(Vertice Buffer) 深度缓冲(Depth Buffer)

https://blog.csdn.net/silangquan/article/details/46608915


1.7 OpenGL中有哪几种缓冲？都有什么用？
帧缓冲Frame Buffer, 用于创建零时的渲染上下文，帧缓冲是一些二维数组和OpenG所使用的存储区的集合：颜色缓存、深度缓存、模板缓存和累计缓存。默认情况下，OpenGL将帧缓冲区作为渲染最终目的地。此帧缓冲区完全由window系统生成和管理。这个默认的帧缓存被称作“window系统生成”（window-system-provided）的帧缓冲区。
颜色缓冲 Color Buffer, 包含每个象素的颜色信息。颜色信息可以是颜色索引值(在颜色索引方式下)，也可以是颜色的红、绿、蓝3个分量(在RGBA方式下)，还可以存放表示物体透明程度的Alpha值。
深度缓冲 Depth Buffer, 包含每个象素的深度值。深度值与z坐标有关，描述物体上某点距离观察点的远近，也可以称它为Z缓存(Z Buffer) 。
模板缓冲 Stencil Buffer, 包含物体的模板值。模板值具有屏蔽作用，用于控制绘制的区域，使屏幕上某些区域可画，某些区域不可画。
累积缓存(Accumulation Buffer) 包含颜色信息。其可以合成一系列的绘制结果，实现某些特殊效果。
顶点缓冲 Vertex Buffer, 用于缓存顶点数据
元素缓冲 Element Buffer，用于缓存顶点序号数据






### Really Details

光栅化插值之后 PS 的 normalize，

shadow map / light map, SSAO, Forward / Deferred, Shader Model 一些关键数值与区别， depth write / test
