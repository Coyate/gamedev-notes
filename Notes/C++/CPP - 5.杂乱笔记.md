## IO库

### IO类

|||
| :------- | :--------- |
| iostream | 流读写     |
| fstream  | 文件读写   |
| sstream  | string读写 |

- IO类不能拷贝与赋值，传递时指针只能通过引用传递，不能const
- 读写一个IO对象会改变其状态

||||||
| :-- | :-------------- | :-------------------------- | :---------------- | :------- |
|     | stream::iostate | 完整的状态字节              | ::setstate(flags) | 设置状态 |
|     | ::rdstate()     | 返回状态                    | ::good()          |          |
|     | ::badbit        | 崩溃                        | ::bad()           |          |
|     | ::failbit       | 操作失败（类型错误）        | ::fail()          |          |
|     | ::eofbit        | 文件尾（也会将failbit置位） | ::eof()           |          |
|     | ::goodbit       | 未错误                      | ::clear()         |          |

while(cin >> word) // 等同于 while(cin.good()) {cin >> word;} 




`IO对象的操作符`

||||
| :-- | :-------- | :--------------------- |
|     | endl      | 刷新并换行，endline    |
|     | ends      | 刷新并加空，endspace   |
|     | flush     | 刷新                   |
|     | unitbuf   | 不缓冲，每次操作都刷新 |
|     | nounitbuf | 缓冲                   |

- 一个IO对象的缓冲区满了或被刷新了才会打印
	- 程序结束，main函数return
	- 用endl显式刷新
	- 置位流内部的unitbuf位会让流变成默认写入立即刷新的状态（cerr就是）
	- 被关联的流读写，列入cin和cerr关联到了cout，读写前两个就会刷新cout
		- in.tie(&o); //输入关联到输出流，每个流最多关联到一个流，但可以被关联多次
		- x.tie(); // 返回已关联流的指针
	- 程序崩溃时，不会刷新缓冲区


### 文件输入输出 fstream

```c++
fstream fstrm(s, mode); //以mode打开文件s，s为文件路径，c风格字符串或string
```

|||
| :----- | :--------------------------- |
| in     | 以读方式打开                 |
| out    | 以写方式打开                 |
| app    | 每次写操作前定位到文件末尾   |
| ate    | 打开文件后立即定位到文件末尾 |
| trunc  | 截断文件                     |
| binary | 以二进制方式打开IO           |

```c++
if(fstrm) {} // 读入成功判断，IO最好都养成判断的习惯
```

当一个fstream销毁时，close函数会自动调用

string流  
|||
| :--------------- | :------------ |
| istringstream(s) | s为一个string |
| ostringstream(s) |               |






## 一些零散概念

`字面值 Literal`   
1. 十进制默认带符号，过大编译器会提示出错
2. 八进制，十六进制有无符号均可以
3. 浮点型以小数点或E/e标识



字面值的前缀后缀问题
字符串，char用前缀，其他的用后缀

|          |                      |       |                    |
| :------- | :------------------- | :---- | :----------------- |
| L'a      | wchar_t              | 42ULL | unsigned long long |
| u8"h"    | utf-8, char          | 1E-3F | float              |
| 3.14159L | long double          |       |                    |
| u'a'     | unicode 16, char16_t |       |                    |
| U'a'     | unicode 32, char32_t |       |                    |


标识符  

用户标识符不能有连续两个下划线，也不能用一个下划线连着大写字母开头


## 一些奇怪的技巧

```c++
const double p1 = acos(-1.0);

printf("%d\n", sqrt(-10)); // 0
printf("%f\n", sqrt(-10)); // -NAN(ind)

printf("%%d");

pritnf("%52f", 1.0); //...

floor(x + 0.5);
```

`-2147483648~2147483647`

`%lld, %I64d`

terminal
创建文件：freopen("test.txt", "w", stdout) 

batch
r是数据生成器，a，b是输出，对比两个程序的结果

```bat
@echo off
:again
r > input
a < input > output.a
b < input > output.b
fc output.a output.b > nul
if not errorlevel 1 goto again
```
%random% 是windows自带的随机生成器，0~32767


```c++
// 输入输出框架
while(scanf("%d", &x)) {}
while(cin >> x) {}

// 重定向文件到stdin/out
freopen("input.txt", "r", stdin);
freopen("output.txt", "r", stdout);

// 使用文件输入输出
FILE *fin, *fout;
fin = fopen("data.in", "rb");
fout = fopen("data.out", "wb");

while(fscanf(fin, "%d", x)) {}

fprintf(fout, "%d %d %.3f\b", min, max, (double)s/n);

fclose(fin);
fclose(fout);

// 文件重定向
fin = stdin;
fout = stdout;

```

## 精度问题

```c++
double d1, d2;
if(d1 == d2)
if(d1 - d2 < 1E-6 && d2 - d1 < 1E-6)

// 传入unsigned int k;
for(int i = 0; i < k - 1; ++i) // k-1会是unsigned的最大值
```


大数问题
- 采用字符串大数
- 采用二进制大数

```c++
const double pi = 3.141592653589793
const double pi = acos(-1.0)
```

## 数学问题

Fibonacci  
Fibonacci 可以转换为矩阵  
[ f(n)	f(n-1) ]	=	[ 1 1] (_^(n−1))   
[ f(n-1)	f(n-2) ]		[ 1 0]  
Fibonacii还可以运用在跳台阶，铺格子  


a^n  可以转换为  
a^n=a^(n/2)∗a^(n/2)，当n为偶数时  
a^n=a^((n−1)/2)∗a^((n−1)/2)∗a ，当a为奇数时  
