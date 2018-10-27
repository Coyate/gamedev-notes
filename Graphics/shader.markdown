
1.5 三种着色器分别有什么用？完成了什么过程？
顶点着色器。计算顶点的位置，并将顶点投影在二维屏幕上。
几何着色器。将形状（图元）划分为更多的形状（图元），影响后序的插值结果。
片段着色器。根据顶点着色器和几何着色器的输出插值，计算每一个片元的颜色。之后进行测试和混合后生成最终的像素。

### shading language

1.11 GLSL数据传递有几种方式？
uniform变量, uniform变量是外部application程序传递给（vertex和fragment）shader的变量。因此它是application通过函数glUniform**（）函数赋值的。在（vertex和fragment）shader程序内部，uniform变量就像是C语言里面的常量（const ），它不能被shader程序修改。

attribute变量, attribute变量是只能在vertex shader中使用的变量。（它不能在fragment shader中声明attribute变量，也不能被fragment shader中使用）。一般用attribute变量来表示一些顶点的数据，如：顶点坐标，法线，纹理坐标，顶点颜色等。在application中，一般用函数glBindAttribLocation（）来绑定每个attribute变量的位置，然后用函数glVertexAttribPointer（）为每个attribute变量赋值。

varying(in/out)变量，varying变量是vertex和fragment shader之间做数据传递用的。一般vertex shader修改varying变量的值，然后fragment shader使用该varying变量的值。因此varying变量在vertex和fragment shader二者之间的声明必须是一致的。application不能使用此变量。


每个可编程着色阶段拥有两种类型的输入：

uniform输入，在一个draw call中保持不变的值（但在不同draw call之间可以更改）；

varying输入，shader里对每个顶点和像素的处理都不同的值。纹理是特殊类型的uniform输入，曾经一直是一张应用到表面的彩色图片，但现在可以认为是存储着大量数据的数组。


niform变量

uniform变量是外部application程序传递给（vertex和fragment）shader的变量。因此它是application通过函数glUniform**（）函数赋值的。在（vertex和fragment）shader程序内部，uniform变量就像是C语言里面的常量（const ），它不能被shader程序修改。

attribute变量
attribute变量是只能在vertex shader中使用的变量。（它不能在fragment shader中声明attribute变量，也不能被fragment shader中使用）
一般用attribute变量来表示一些顶点的数据，如：顶点坐标，法线，纹理坐标，顶点颜色等。
在application中，一般用函数glBindAttribLocation（）来绑定每个attribute变量的位置，然后用函数glVertexAttribPointer（）为每个attribute变量赋值。

varying变量
varying变量是vertex和fragment shader之间做数据传递用的。一般vertex shader修改varying变量的值，然后fragment shader使用该varying变量的值。因此varying变量在vertex和fragment shader二者之间的声明必须是一致的。application不能使用此变量。



1.18 片段和像素的区别 ? 
片段是渲染一个像素需要的全部信息，所有片段经过测试与混合后渲染成像素。
片段是三维顶点光栅化后的数据集合，还没有经过深度测试，而像素是片段经过深度测试、模板测试、alpha混合之后的结果
片段的个数远远多于像素，因为有的片段会在测试和混合阶段被丢弃，无法被渲染成像素。
