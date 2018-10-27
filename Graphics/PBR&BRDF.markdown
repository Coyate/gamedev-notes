### PBR
&emsp;&emsp;Physically Based Rendering，是一种遵循物理公式的渲染技术，旨在提供统一的工作流程，在任何光照条件下都表现出物理正确的效果。

&emsp;&emsp;PBR要求 Artist 提供物理正确的 美术素材，灯光信息。算法保证渲染过程符合物理标准。

&emsp;&emsp;PBR分为两种工作流，一种基于金属的，一种基于高光的。金属工作流的基础属性为 base color (albedo), roughness, metallic。高光工作流的基础属性为 diffuse，glossiness，specular。两个工作流共用的为 ambient occlusion，normal，height

#### 基础

&emsp;&emsp;一般情况下，光线投射物体表面，一些被直接反射，为 Specular，另外一些进入物体内部，scattering再反射，称为 Diffuse。

&emsp;&emsp; 材质，分为金属非金属。光线无法进入金属表面，所以金属没有diffuse，全是specular，不同金属有不同的 specular。非金属的 specular 只有强度，没有颜色。

&emsp;&emsp;- 菲涅尔现象：有折射现象发生时，散射和反射会有一定的能量配比，视线垂直表面时，反射很弱，平行时，很强
- 
&emsp;&emsp;specular + diffuse < 入射光强度。specular 与 diffuse 的配比取决于光线与平面的角度。与视角垂直时，几乎没有 specular，与视角平行时，几乎都是 specular，这就是Fresnel现象。美术如果不考虑强度，就会做出不 PBR 的东西。

&emsp;&emsp;光会折射，反射，吸收，散射，除去吸收和散射的部分。
- Reflection：反射角等于入射角
    - 全反射
- Refraction：进入另一个媒介，可能会有吸收
- Abosorbing：光进入非均匀介质后，损失能量，改变方向
- Scattering：光进入非均匀介质后，光改变方向，但不损失能量



https://zhuanlan.zhihu.com/p/42529595
https://zhuanlan.zhihu.com/p/20091064?f3fb8ead20=44d0e4ef145790c113921ea174da514f
https://github.com/QianMo/Game-Programmer-Study-Notes/tree/master/Content/%E3%80%8AReal-Time%20Rendering%203rd%E3%80%8B%E8%AF%BB%E4%B9%A6%E7%AC%94%E8%AE%B0/Content/BlogPost06

#### 金属工作流

&emsp;&emsp;金属的折射波被吸收得较多，所以固有色中没有diffuse


##### Albedo
&emsp;&emsp;固有色。

##### Roughness

##### Metallic

#### 高光工作流
##### Diffuse
&emsp;&emsp;根据microface理论，各种在微表面反射+内部局部散射后得到的结果

##### Specular
&emsp;&emsp;光在表面直接反射的结果

##### Glossiness



#### 共有

##### Ambient Occlusion
&emsp;&emsp;模拟全局光照的部分，只影响 diffuse

##### Normal
&emsp;&emsp;模拟表面细节，影响 Roughness & Glossiness

##### Height
&emsp;&emsp;用于视差映射，增加深度

#### 其他

##### Thickness map
&emsp;&emsp;描述光的吸收与散射，伪SSS


### BRDF


&emsp;&emsp;描述反射属性的函数，只与物体的材质有关，根据入射光与出射光角度，入射光波长，可以计算出射光的波长（颜色）
- 能量守恒
- 交换律
&emsp;&emsp;将BRDF函数做半球积分，就得到了出射光分布，根据入射光角度和波长就可以计算出出射光角度和波长，

&emsp;&emsp;分isotropic，anisotropic两种，真实世界中，大部分的材质都是偏向于各向同性加上一点点的各向异性。



&emsp;&emsp;BRDF公式有三种：
1. 经验公式，Lambert，Phong
2. 数值分析，推导出一个数值函数
3. Data-Driven，通过实验获取

#### Lambert
&emsp;&emsp;纯漫反射模型，各向同性，diffuse遵循Lambert's cosine 法则

c.rgb = (s.Albedo * _LightColor0.rgb * dot(s.Normal, lightDir)) ;

#### Phong

&emsp;&emsp;vertex color = ambient + diffuse + specular + emitted light
- Ambient : 环境光，光源，带有衰减
- Diffuse：漫反射, cos公式计算
- Specular：高光，反射光方向与视角方向的cos，求幂（Gloss）
- Emittion：自发光，固定值



1.13 冯氏光照模型由哪三部分构成？
http://learnopengl-cn.readthedocs.io/zh/latest/02%20Lighting/02%20Basic%20Lighting/
https://blog.csdn.net/silangquan/article/details/45629299

光照要处理的就是光源颜色向量和物体颜色向量的点积。三种光照可以组合使用即 (ambient + diffuse + specular) * objectColor。
环境光  ambient .控制因素是 ambient strength环境光强度，和lightcolor数乘得到ambient环境光。然后在用ambient和物体颜色objectColor点乘。ambient strength由程序员指定。

漫反射 diffuse , 控制因素是 diff 散射因子，也是和lightcolor数乘得到diffuse漫反射光，然后在用diffuse河objectColor点乘。diff散射因子由法线与光线的夹角（点积）得到，漫反射光使物体上与光线排布越近的片段越能从光源处获得更多的亮度。为了更好的理解漫反射光照：
θ越大，光对片段颜色的影响越小，反过来光线越靠近法线，对物体颜色的影响就越大。
float diff = max(dot(norm, lightDir), 0.0); 两个向量之间的角度越大，散射因子就会越小：

镜面反射 specular，控制因素是 spec 反射强度。和环境光照一样，镜面光照(Specular Lighting)同样依据光的方向向量和物体的法向量，但是这次它也会依据观察方向，例如玩家是从什么方向看着这个片段的。镜面光照根据光的反射特性。如果我们想象物体表面像一面镜子一样，那么，无论我们从哪里去看那个表面所反射的光，镜面光照都会达到最大化。
通过反射法向量周围光的方向计算反射向量。然后我们计算反射向量和视线方向的角度，如果之间的角度越小，那么镜面光的作用就会越大。它的作用效果就是，当我们去看光被物体所反射的那个方向的时候，我们会看到一个高光。
https://blog.csdn.net/aquathinker/article/details/8176442
#### Blin-Phong
&emsp;&emsp;一个hack，用halfvector代替反射方向，view + lightDir 中间

#### Cook-Torrence
&emsp;&emsp;将粗糙表面考虑成microfacet，很多小镜面平面的组合。定义了几何衰减系数G，在完全反射，反射被遮挡，到达microfacet被遮挡三种情况下不一样
&emsp;&emsp;定义了目前的BRDF框架，F，G，D，F为菲涅尔项，G与介质密度相关，为阴影遮挡函数，D为微表面法向分布函数

##### GGX
&emsp;&emsp;07年提出，是D函数，拟合效果更加真实，同时可以适用于透明和不透明物体。
https://blog.csdn.net/uwa4d/article/details/72781818