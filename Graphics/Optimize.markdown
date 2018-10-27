https://github.com/QianMo/Game-Programmer-Study-Notes/tree/master/Content/%E3%80%8AReal-Time%20Rendering%203rd%E3%80%8B%E8%AF%BB%E4%B9%A6%E7%AC%94%E8%AE%B0/Content/BlogPost12

https://zhuanlan.zhihu.com/p/22112254
https://zhuanlan.zhihu.com/p/29270688
https://zhuanlan.zhihu.com/p/33898214
https://zhuanlan.zhihu.com/p/33898208
https://zhuanlan.zhihu.com/p/24392681
https://zhuanlan.zhihu.com/p/38671064
https://zhuanlan.zhihu.com/p/39529241
https://zhuanlan.zhihu.com/p/26832917

项目阶段：建立自动化性能剖析管线，进行每日统计，定义每个步骤的性能消耗

生产阶段：统一美术/音频素材标准，控制模型面数，使用低精度材质，选择恰当的纹理压缩格式；在不需要的贴图部分存储预计算信息，比如查找表

预计算：使用预计算的遮挡剔除，使用烘培光照，反射探针，避免实时计算

CPU 阶段：在 CPU 端先做遮挡剔除，或者用 compute shader 先做一个 pass 的剔除，然后再组织剩下图元放进管线；合并相似物体，使用静态 batch，同样材质和贴图的合并进一个 Drawcall

管线：如果光源较多，采用延迟渲染，根据平台进行 shader 效果分级；开 early-Z

VS 阶段：颜色的计算不一定要使用浮点数，浮点数也尽量低精度；减少复杂计算，例如除法，三角函数可以使用泰勒展开前几项；减少条件分支；避免过早 normalize

PS 阶段
LOD：关闭远处的粒子效果，在远处用低模，使用mipmap，降低或关闭远处的材质采样/过滤；

Profiling找瓶颈，针对瓶颈优化：
内存：降低资源加载
CPU：想办法减少对应的 API call
GPU：查管线，分部分增加管线负载，若帧率降低，则此部分为瓶颈，然后再针对优化，尽量让管线各部分负载均衡