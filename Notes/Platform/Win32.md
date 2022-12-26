


## 事件驱动编程 Event Driven Programming

- Programs share CPU cycles, memory, monitor screen etc
- Win App don't have direct access to hardware
	○ call ShowWindow -> write Video memory
- Windows manage the presently diated applications and handle the distribution of resources against them


## Unicode Functions
- 16-bit value, use wchar_t to using wide characters, use prefix L before literal characters

|unicode|normal|
|--------------|-------------|
| wcslen       | strlen      |
| wcscpy       | strcpy      |
| wsccmp       | strcmp      |
| std::wstring | std::string |

```c++
const wchar_t* wcstrPtr = L"Hello, World";

```

## 函数调用约定 Calling Convention

|名字|宏|
|------------|-------------|
| WINAPI     |  __stdcall  |
|  APIENTRY  | __stdcall   |
| CALLBACK   | __stdcal    |

`__stdcall` 和 `__cdecl`

 一种函数调用约定( Calling Convention )，约定主要用来决定
 
 1. 参数传递顺序
 2. 调用堆栈由调用函数还是被调用函数清理

 stdcall规定

 1. 参数从右向左压入堆栈（如果是类，最后一个入栈的是*this指针）
 2. 函数由被调用的函数在返回后清除（自动清栈，使用retnX，CPU自动弹出x个字节的空间），编译时必须确定参数个数，调用者必须严格控制参数个数
 3. 函数名在编译时自动加前导的下划线，再加一个@，紧跟参数的尺寸

 __cdecl : C Declaration
 
 1. 参数从右向左压入堆栈
 2. 参数由调用者清除堆栈（手动清栈），被调用函数不会要求调用者传递多少参数，调用者传递数量不同的参数都不会产生编译期错误

 _fastcall， 前两个参数由寄存器传递，其余的由堆栈传递
 _thiscall, this指针放在特定寄存器

## wParam, lParam 参数名字

用于在message传递额外的信息

- WM_SIZE中，wParam为special size标记，例如最大化，最小化，lParam的高位为height，低位为width
- WM_ACTIVATE中，wParam的低位表示active/mouse-active/deactive，lParam为这个window的handle


|       | wParam          | lParam          | LRESULT  |
|--------|-----------------|-----------------|----------|
| OS     | UINT_PTR        | LONG_PTR        | LONG_PTR |
| 16-bit | 16-bit unsigned | 32-bit unsigned |          |
| 32-bit | 32-bit unsigned | 32-bit unsigned |          |
| 64-bit | 64-bit unsigned | 64-bit unsigned |


## Sleep 函数

暂停线程执行，直到以毫秒记的时间结束，参数为0表示直接放弃当前时间片

## 句柄

- 句柄是指向指针的指针，指向的内容是对象内存物理地址的索引

Windows内存管理器会管理各个程序生成的对象（窗口等），由于各种需求，Windows内存管理器需要经常移动各个对象在内存中的位置，所以内存管理器维护了一个句柄表，用来指向对象内存的物理位置，这个句柄表的位置是不变的。