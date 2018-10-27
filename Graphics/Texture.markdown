https://github.com/QianMo/Game-Programmer-Study-Notes/tree/master/Content/%E3%80%8AReal-Time%20Rendering%203rd%E3%80%8B%E8%AF%BB%E4%B9%A6%E7%AC%94%E8%AE%B0/Content/BlogPost05

https://blog.csdn.net/silangquan/article/details/14809867

texture sampling,种类，原理,mipmap,Normal Mapping,顶点法线与面法线的作用

https://www.cnblogs.com/rickerliang/archive/2013/03/30/2989941.html

### mipmap

保持采样一致性
1.17 多级渐近纹理 mipmap？有什么优缺点？
为了加快渲染速度和减少图像锯齿，贴图被处理成由一系列被预先计算和优化过的图片组成的文件,这样的贴图被称为 MIP map 或者 mipmap
多级渐进纹理由一组分辨率逐渐降低的纹理序列组成，每一级纹理宽度和高度都是上一级纹理宽度和高度的一半。宽和高不一定相等，也就是说，这些纹理不一定都是正方形。
优点：提高渲染速度，减少图像锯齿
缺点：会增加额外的内存消耗

### filter
https://blog.csdn.net/yingyuewuhen1/article/details/48415373
http://www.mamicode.com/info-detail-1167142.html
https://blog.csdn.net/github_34181815/article/details/79774952