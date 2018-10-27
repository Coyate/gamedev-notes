• 蒙特卡洛采样
• 间接光照使用余弦加权半球采样
• 直接光照使用立体角采样
• BRDF
• shadow ray
• Intersection
• Russian roulette 
• tent filter 没弄懂
 CUDA Path Tracer
• 学习了 BVH ，parse obj
• CUDA, Thread, Block
• 读取文件的 parser 泛用性太弱（手动读取 obj）
• Precomputed BVH 不支持动态场景，
• Camera，通过光圈和焦距模拟景深
- 交互，GL处理的 callback


minpt: A path tracer in 300 lines of C++

 https://github.com/hi2p-perim/minpt
	• Parallel SAH BVH
	• Area light
	• Texture Mapping
	• Next event estimation
	• GGX
	• glossy BSDF
	• pinhole / realistic camera

	https://github.com/QianMo/Game-Programmer-Study-Notes/tree/master/Content/%E3%80%8AReal-Time%20Rendering%203rd%E3%80%8B%E8%AF%BB%E4%B9%A6%E7%AC%94%E8%AE%B0/Content/BlogPost08

### DOF

https://blog.csdn.net/silangquan/article/details/53750473

### HDR

https://blog.csdn.net/silangquan/article/details/54884807