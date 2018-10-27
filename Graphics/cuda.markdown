最近开始接触Cuda，一个基于GPU的并行计算架构，作为学习用cuda来实现相同的查找问题。只是用并行的方法就不存在了串行的二分查找的问题，最简单粗暴的方式就是利用GPU强大的并行计算能力，将数组arr中的每个元素一次性放到GPU核上进行并行查找，即和目标值val进行比较，那么可以简单的理解为只要比较一次，即在O(1)的时间内就能够得到比较结果（当然没有考虑到调度问题）。

### thread
https://bbs.csdn.net/topics/390880482



Cuda程序设计的基本流程比较简单：

a.分配host（主机端）的基本变量并赋予初始值

b.在device（GPU）上分配空间，利用CudaMalloc

c.将host端的数值拷贝到device端，利用cudaMemcpy

d.调用kernal函数在device进行计算

f.将device端的计算结果拷贝回到host端，并处理结果

https://blog.csdn.net/qq_36387683/article/details/81162425
https://blog.csdn.net/xiaxzhou/article/details/76537473
https://blog.csdn.net/x_shuck/article/details/51683037
### 内存

https://bbs.csdn.net/topics/390873652

### 优化
https://bbs.csdn.net/topics/390870803

https://bbs.csdn.net/topics/390874372
CUDA程序优化 CUDA程序优化应该考虑的点： 精度：只在关键步骤使用双精度，其他部分仍然使用单精度浮点以获得指令吞吐量和精度的平衡； 延迟：需要首先缓冲一部分数据，缓冲的大小应该可以保证每个内核程序处理的一批数据能够让GPU慢负荷工作； 计算量：计算量太小的程序使用CUDA很不合算；当需要计算的问题的计算密集度很低的时候，执行计算的时间远远比IO花费的时间短，整个程序的瓶颈出现在PCI-E带宽上。 优秀的CUDA程序特征： 在给定的数据规模下，选用算法的计算复杂度不明显高于最优的算法； Active warp的数量能够让SM满载，并且active block的数量大于2，能够有效地隐藏访存延迟； 当瓶颈出现在运算指令时，指令流的效率已经过了充分优化； 当瓶颈出现在访问IO时，程序已经选用了恰当的存储器来储存数据，并使用了适当的存储器访问方式，以获得最大带宽； CUDA的编写与优化需要解决的问题： 确定任务中的串行和并行的部分，选择合适的算法； 按照算法确定数据和任务的划分方式，将每个需要实现的步骤映射为一个满足CUDA两层并行模型的内核函数，让每个SM上至少有6个活动warp和至少2个活动block； 在精度不组或者发生一处时必须使用双精度浮点或者更长的整数类型； 优化显存访问：合并采用相同block和grid的kernel；尽力避免将线程私有变量分配到local memory； 优化指令流：在误差可接受的情况下，使用CUDA算术指令集中的快速指令；避免多余的同步；在只需要少量线程进行操作的情况下，使用类似“if threaded的方式，避免多个线程同时运行占用更长时间或者产生错误结果； 资源均衡：调整每个线程处理的数据量，shared memory和register和使用量；通过调整block大小，修改算法和指令以及动态分配shared memory，都可以提高shared的使用效率；register的多少是由内核程序中使用寄存器最多的时刻的用量决定的，因此减小register的使用相对困难；

节约register方法：使用shared memory存储变量；使用括号明确地表示每个变量的生存周期；使用占用寄存器较小的等效指令代替原有指令； 与主机通信优化：尽量减少CPU与GPU间的传输：使用cudaMallocHost分配主机端存储器，可以获得更大带宽；一次缓存较多的数据后再一次传输，可以获得较高的带宽；需要将结果显示到屏幕的时候，直接使用与图形学API互操作的功能；使用流和异步处理隐藏与主机的通信时间；使用zero-memory技术和Write-Combined memory提高可用带宽； 测量程序运行时间： CUDA内核程序的运行时间：可以在设备端测量，也可以在主机端测量； CUDA API的运行时间：只能在主机端测量；使用CUDA runtime API时，会在第一次调用runtime API函数时启动CUDA环境，计时的时候应该避免将这一部分计入，因此在正式测试之前应当首先及你选哪个一侧包含数据输入输出地就爱上你，使得GPU从平时的节能模式进入工作状态，使得测试结果更加可靠； 设备端测量时间： 调用clock（）函数：返回的是GPU的时钟周期，需要除以GPU的运行频率才能得到以秒为单位的时间； 使用CUDA API事件管理功能； 主机端测量时间：使用c标准库中的clock_t()函数测试，由于其精度很低，因此应该运行多次然后求平均运行时间；注意异步函数（比如内核函数和带有asyn后缀的存储器拷贝函数），在GPU上执行完成之前，CPU线程已经得到了它的返回值；从主机测量一系列CUDA调用需要的时间的时候，要首先调用cudaThreadSynchronize()函数等，使得GPU线程执行完毕后，进入CPU线程，从而得到正确的执行效果；在一串流中的第一个流（ID为0的流）的行为总是同步的，因此使用这些函数对0号流进行测时，得到的记过是可靠的。 任务划分原则： 在两次主机—设备通信之间进行尽量多的计算；考虑使用流运算隐藏主机—设备通信时间，通过Pinned memory、zero—copy、write—combined memory等手段提高实际传输带宽； 尽量使得每个block中线程数量是32的整数倍，最好保持在64~256之间，并根据任务的具体情况确定每个维度上的大小，以减少计算访存地址时的整数除法和求模运算； 对一个block的任务进行划分后，再按照block的维度和尺寸要求对grid进行划分：每个block 的访存均匀分布在显存的各个分区中；block 间的负载可以存在一定程度的不均衡； Grid和Block的维度设计： 首先考虑block的尺寸，grid的尺寸一般越大越好； 每个SM中至少要有6个active warp用于隐藏流水线延迟，并且拥有至少2个active block；

计算每个SM上active warp和active block的数量： 确定每个SM使用的资源数量：使用nvcc的—keep编译选项，或者在.cu编译规则（cuda build rule）中选择保留中间文件，得到.cubin文件，用写字板打开后可以看到imem 和reg分别代表内核函数中每个线程使用的local memory和register数量； 根据硬件确定SM上的可用资源：可以用SDK中的deviceQuery 获得每个SM中的资源；根据内核不同，SM上的warp总数上限，block总数上限，寄存器数量，shared memory数量都不同； 每个block中的线程数量不能超过512； 计算每个block使用的资源，并确定active block和active warp数量： e.g. 每个block中有64个线程，每个block使用256 Byte shared memory，8个寄存器文件， 那么：每个人block使用的shared memory： 256 Byte； 每个block使用的寄存器文件数量： 8*64 = 512； 每个block中使用的warp数量：64/32 = 2; 如果在G80/92 GPU中运行这个内核程序： 由shared memory数量限制的active block数量： 16384、256 = 64； 由寄存器数量限制active block数量：8192/512 = 16; 由warp数量限制的active block数量 24/2 = 12; 每个SM中的最大active block数量：8； 这些计算可以由NVIDIA在CUDA SDK中提供的 CUDA occupancy calculator完成； Block 的维度和每个维度上的尺寸的主要作用是避免做整数除法和求模运算，对执行单元效率没有什么显著影响； 计算grid中各个维度上block的数量：grid在x轴上的block数量 = （问题在x轴上的尺寸+每个block在x轴上的尺寸-1）/每个block在x轴上的尺寸； 存储器访问优化： 主机—设备通信优化： 目前一条PCI—E 2.0*16通道的理论带宽是每向8GB/s, 远小于显存和GPU片内存储器带宽； Pinned memory：强制让操作系统在物理内存中完成内存申请和释放工作，不用参会页交换，因此速度比pageable memory快； 声明这些内存会占用操作系统的可用内存，可能会影响到操作系统运行需要的物理内存； 需要合理规划CPU和GPU各自使用的内存，使整个系统达到最优； 异步执行： 内核启动和显存内的数据拷贝（Device to Device）总是异步的；

内存和显存间的数据拷贝函数有异步和同步两个版本： 同步(顺序执行)： cudaMemcpy(a_d,a_h,size,cudaMemcpyHostToDevice); cpuFunction(); 异步(同时执行)： cudaMemcpyAsync（…………）； cpuFunction()； 属于同一个流中的内核启动总是同步的； 如果几次内核启动属于不同的流，那么他们的执行可能是乱序的； 利用异步提高计算效率： 使用流和异步是CPU和GPU同事进行运算； 利用不同流之间的异步执行，使流之间的传输和运算能够同时执行，更好地利用GPU资源； 全局存储器访问优化： 需要考虑half-warp访问的对齐问题，不同的硬件要求不同；（存疑？？？？？？？？） 采用合并访问； 尽量避免间隔访问：比如按列访问矩阵，可以借助shared memory来实现这一点； Shared memory访问优化： 共享存储器被组织为16个可以被同时访问的存贮器模块，称为bank； Bank组织方式：宽度32bit，相邻的32bit字被组织在相邻的bank中，每个bank在每个时钟周期可以提供32bit的带宽； 一个warp被分为两个half-warp进行访问； 避免bank conflict：在SDK中，使用宽度为17或则会threadDim.x+1的行来避免bank conflict；（存疑？？？？？？？？） Shared memory采用了广播机制：在相应一个对同一个地址的读请求时，一个32bit字可以被读取并同时广播给不同的线程； 当一个half-warp中有多个线程读取同一个32bit字地址中的数据时，可以减少bank conflict的数量； 如果half-warp中的线程全都读取同一地址中的数据时，此时完全不会发生bank conflict； 如果half-warp内有多个线程要对同一地址进行读写操作，此时会产生不确定结果，这种情况应该使用shared memory的原子操作； 共享存储器保存着加载kernel时传递过来的参数，以及kernel执行配置参数，如果参数列表很长，应该将其中一部分参数放入constant memory； 使用纹理存储器： 主要用于存放图像和查找表：不用严格遵守合并访问条件，就能达到较高带宽； 对于少量数据的随机访问，效率不会太差；

可以使用线性滤波和自动类型转换等功能调用硬件的不可编程计算资源，不必占用可编程计算单元； 使用常数存储器： 主要用于存放指令中的常数；速度低于shared memory； 指令流优化： 增大吞吐量手段： 避免使用地吞吐量指令； 优化每种类型的存储器，有效利用带宽； 允许线程调度单元精良用多的数学计算来覆盖访存延迟，需要有教导的算术密度； 吞吐量：每个多处理器在一个时钟周期下执行的操作数目； 算术指令：尽量使用单精度浮点单元进行运算，在计算能力小于等于1.2的设备中，每个双精度的变量将会转换成单精度格式，双精度运算也会转为单精度算术运算； 单精度浮点基本算术运算：加，乘，乘加运算的吞吐量是每个时钟周期8个操作； 求导数运算：每个时钟周期2个操作； 单精度除法：每个时钟周期0.88个操作； 单精度浮点倒数平方根：2； 平方根：1； 对数：2； 正弦余弦：参数较大的时候，采用归约操作将x的绝对值减小；有快路径和慢路径（大参数）； 整数算术运算：整数加法（8），乘（2）；除法和取模开销特别大，尽量地避免或者用位运算代替； 比较，min，max：（8）； 位运算（8）； 类型转换（8）； 控制流指令： If, switch, do, for, while 可能引起一个warp线程跳转到不同的分支，严重影响指令吞吐量； 访存指令：包括任何读写memory的指令； 对于local memory只有在register不够用或者编译器无法解析的时候才会发生； 将较大的数据（float，double）拆分成每个线程32bit，或者将多个[u]char,[u]short合并成每个线程32bit的形式访问； 在访问local/global memory时候，会有额外的400~600个时钟周期的访问延迟； 同步指令：_syncthreads()的吞吐量是每时钟周期8个操作；



 (1) CUDA Programming : A Developer's Guide to Parallel Computing with GPUs
  (2) The CUDA Handbook : A Comprehensive Guide to GPU Programming 
  《gpu高性能编程cuda实战》
  《大规模并行处理器编程实战（第2版）》


《CUDA并行程序设计》
《CUDA专家手册》
以及研究CUDA Samples
《深入理解计算机系统》


#### C++ Profiling

控制资源颗粒度，定位内存泄露，c++如何profiling