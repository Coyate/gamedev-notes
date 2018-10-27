### U3D 执行顺序

|名字|时间|次数|功能
| :-:| :-:| :-:| :-:|
| Reset() | 添加脚本时|一次|编辑器控制，或手动点reset时
| Awake() | 对象实例化时|一次 |非活动则不调用，用于设置脚本间的引用，在每个物体间的调用顺序随机
| OnEnable()|Awake() 之后| 一次|对象被启用后调用|
| Start() |Awake() 之后，第一帧Update之前|每帧一次|脚本实例被启用时调用，可以延迟初始化，调整初始化顺序
| Update() |Start() 之后|每帧执行一次|更新逻辑，控制，动画
| FixedUpdate() |(可能在Start()之前先执行)|每帧执行多次(0.02s)|不需要乘 deltatime，处理 Rigidbody / 物理效果，通过 Fixed Timestep 设置频率
| LateUpdate()| 所有Update()调用之后|每帧一次|第三人称 camera 
| Coroutine | | | 协程在Update返回之后调用，协程可以暂停执行，等给定的 Instruction 完成后再执行
| Rendering|
|OnPreCull()|↓|一次|剔除之前
|OnBecameVisible(Invisible)()|↓|一次|可见/不可见时
|OnWillRenderObject|↓|一次|若对象可见，对每个摄像机调用一次
|OnPreRender|↓|一次|渲染场景之前
|OnRenderObject|↓|一次|常规场景渲染完成后调用
|OnPostRender|↓|一次|渲染完成后调用
|OnRenderImage(ProOnly)|↓|一次|postprocessing时调用
|OnGUI|↓|每帧多次|响应GUI，Layout->Repaint->键盘/鼠标
|OnDrawGizmos|↓|一次|画Gizmos时用
|OnDestroy| | 一次| 销毁对象的时候调用
|OnApplicationQuit()||一次|应用退出时调用


### Unity3d
unity里面的函数调用顺序（awake。。。。。直到lateUpdate
Unity的fixedUpdate和Update的区别，各自的使用场景？
Unity的协程。


unityGI（5.0自带的光照系统，一个LIGHTING Probe+refection Probe事实全局光，注意只是支持静态物体）
DrawCall多少为好，怎么样减少？（150以下..减小就是答游戏优化的种种
drawcall 优化







#### 垂直同步


#### NPR



