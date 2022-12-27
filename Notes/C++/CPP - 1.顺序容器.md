## 基础

若不确定容器，那么只使用迭代器，而不使用下标，方便测试与修改
[begin, end)

`赋值`  
类型相同的容器可以作为整体赋值，赋值会使得容器的迭代器，引用，指针失效  

```c++
	vector<const char*> oldstyle;
	list<string> name;
	names = oldstyle; // 不能直接赋值
	names.assign(names.cbeind(), oldstyle.cend()); // 不能assign自己
	names.assign(oldstyle.cbegin(), oldstyle.cend()); 
	
	seq.assign(begin, end);
	seq.assign(il); // seq将替换为il
	seq.assign(n, t); // seq里替换为n个t
```

`Swap`  
`swap(c1, c2);`  
`c1.swap(c2);`  

- 对一般容器进行swap不会使迭代器，引用，指针失效
- 对string，array进行swap会引起指针，引用，迭代器失效
- 对array进行swap会交换内部的元素，时间与长度成正比
- 尽量使用非成员函数般的swap

`访问元素`
| c.begin() | 指向第一个元素的迭代器，指向尾后的迭代器                |
| :-------- | :------------------------------------------------------ |
| c.end()   |                                                         |
| c.front() | 返回首尾元素的引用                                      |
| c.back()  |                                                         |
| c[n]      | 返回下标为n的对象的引用，越界，则行为未定义             |
| c.at(n)   | 返回下标为n的对象的引用，如越界，则抛出out of range异常 |

`插入` 
- array不支持以下操作

|||
| :------------------ | :---------------------------------------------------------------------------------- |
| emplace(p, args)    | 插入在迭代器p指向的元素之前、尾部、头部，调用构造函数直接在容器管理的内存里构造元素 |
| emplace_back(args)  |                                                                                     |
| emplace_front(args) |                                                                                     |
| push_back(args)     | 插入在容器的尾部与头部                                                              |
| push_front(args)    |                                                                                     |
| insert(p, n, t)     | 插入到p指向的元素之前，返回插入后的第一个元素的迭代器，因此可以连续插入             |
| insert(p, b, e)     |                                                                                     |
| insert(p, il)       |                                                                                     |

`删除元素`
|||
| :------------ | :------------------------------------------------ |
| c.pop_front() | 删除首尾元素，若容器为空，则行为未定义            |
| c.pop_back()  |                                                   |
| c.erase(p)    | 返回被删除元素之后的迭代器，若指end，则行为未定义 |
| c.erase(b, e) | 若e为end，则返回end，调用后b==e                   |
| c.clear( )    | 删完，不返回                                      |

`容量调整`
容器有size和capacity两种属性，size为目前已装填的元素的数量，capacity为其的容量，当size填充到等于capacity时，容器会重新分配内存空间，增大capacity来保证能容纳更多元素
|||
| :----- | :----- |
| c.resize(n) |调整c的大小为n个元素，多余的元素被丢掉，新增的元素被值初始化 |
| c.resize(n,t) |   指向被删除的元素的迭代器，指针，引用失效              |
| c.capcity() |返回容器的容量                                               |
| c.reserve(n)    |分配至少能容纳n个元素的内存空间                          |
| c.shrink_to_fit()   |将capacity减少到size同样的大小                       |


`适配器 Adaptor`  
适配器是一种机制，能使某种事物的行为看起来像另外一件事物一样。例如一个stack接受另外一个容器，使得整体看起来像stack。  
顺序容器适配器有：stack, queue, priority_queue，前两者基于deque，后者基于vector  
适配器操作  
::size_type	足以保存当前类型的最大对象的大小  
::value_type	元素类型  
::container_type	实现适配器的容器类型  

stack.top()返回左值引用  


## String

`初始化` 
```c++

string s1(10, 'c');		// 十个c
string s(cp, n)			// 拷贝cp数组中前n个字符
string s(s2, pos2)		// 从s2的下标pos2开始拷贝到末尾，若pos2比s2的size大，或s2末尾没有'\0'，则行为未定义
string s(s2, pos2, len2) // 从s2的下标pos2拷贝len2个字符
```

`修改string`
```c++
s.insert(pos, args);	// 在下标pos之前追加args的内容，返回s的引用
s.append(args); 		// 在s后追加args的内容，返回s的引用
s.substr(pos, n);		// 返回从pos开始的n个字符
s.replace(range, args);	// 将range内的内容替换为args
// range: (b, e), (pos, n)
```


`搜索string`  
搜索到了返回下标，未搜索到返回npos，npos为大于任何有效下标的值，为(unsigned int)(-1)，值为4294967295
```c++
s.find(args);			// 第一次出现
						// args: (c, pos), (s2, pos), (cp, pos),(cp, pos, n)	args中的c为字符，s2为字符字串，pos为开始搜索的下标，cp为指向c风格字符串的指针，n是限定搜索前n个字符

s.rfind(args);			// 最后一次出现，反向搜索
s.find_first_of(args);	// 查找args里任何一个字符第一次或最后一次出现的位置
s.find_last_of(args);
s.find_first_not_of(args);	// 查找第一个或倒数第一个不在args里的字符的位置
s.find_last_not_of(args);

while((pos = string.find_first_not_of(check, pos))) != string::npos) {}
// find的结果和int作比较，或转bool都可能出错，只能用 string::size_type pos比较
```
`字符串比较`  
s.compare(args)	类似于strcmp，根据s等于，大于，小于指定字符串返回0，正数，负数  
s2	将s从pos1开始的字符与s2中pos2开始(指针cp指向)的n2个字符相比较  
pos1, n1, s2  
pos1, n1, s2, pos2, n2  
cp  
pos1, n1, cp  
pos1, n1, cp, n2  

`字符转换`
|||
| :------------------- | :----------------------------------------------------------------------------------------------------------------------------- |
| to_string(val)       | val可以是任何算术类型                                                                                                          |
| stoi(s, p, b)        | 返回string转换为int, long, unsigned long, long long, unsigned long long的值，b表示基数，默认为10，p是size_t类型的下标，默认为0 |
| stol(s, p, b)        |                                                                                                                                |
| stoul, stoll, stoull |                                                                                                                                |
| stof(s, p)           | 返回string转换为float，double，long double类型的值                                                                             |
| stod, stold          |                                                                                                                                |


`需要注意的内容`
1. 用下标访问空string会引发不可预知的结果
1. size() 返回的是 size_type，是一个无符号整型值，不能与int混用及比较
1. 字面值相加是，要保证有一个string对象
	- `"hello" + "," + S2;    // 错误操作，第一个加号运算符两侧没有string对象`
1. 空串当作字面值传参会导致一个编译错误，至少需要传入string("")

`<cctype> 常用字符判断`

|         |            |     |         |            |     |         |          |
| :------ | :--------- | :-- | :------ | :--------- | :-- | :------ | :------- |
| isalnum | 字母加数字 |     | isgraph | 非空白     |     | isdigit | 数字     |
| isalpha | 字母       |     | isspace | 空白       |     | iscntrl | 控制字符 |
| islower | 小写字母   |     | isprint | 可打印字符 |     | toupper |          |
| isupper | 大写字母   |     | ispunct | 标点       |     | tolower |          |

## forward_list

|||
| :-------------------- | :----------------------------------------------------------------------------------------------------------------------------------------- |
| lst.before_begin()    | 首前迭代器（指向链表第一个元素之前的位置）                                                                                                 |
| lst.cbefore_begin()   |                                                                                                                                            |
| insert_after(p, t)    | 在p之后插入元素，返回最后一个插入的迭代器                                                                                                  |
| insert_after(p, n, t) |                                                                                                                                            |
| insert_after(p, il)   |                                                                                                                                            |
| insert_after(p, b, e) |                                                                                                                                            |
| emplace_after(p,args) | 在p之后创建一个元素，返回指向新元素的迭代器，若p为尾后指针则行为未定义                                                                     |
| erase_after(p)        | 删除p之后的元素，删除b之后直到e，返回被删元素之后的迭代器，若不存在这样的元素，则行为未定义，若p指向最后一个元素或尾后迭代器，则行为未定义 |
| erase_after(b, e)     |                                                                                                                                            |

## list专用容器算法
|||
| :--------------------------------------------- | :----------------------------------------------- |
| lst.merge(lst2, comp)                          | 将lst2并入lst，可选comp替代<，并入完后lst2为空   |
| lst.remove(val)                                | 调用erase删除与val相等的元素，可选pred重载==     |
| lst.remove_if(pred)                            |                                                  |
| lst.reverse()                                  | 反转list                                         |
| lst.sort(comp)                                 | 使用<或给定操作排序元素                          |
| lst.unique(pred)                               | 调用erase删除同一个值的连续拷贝，可选pred重载==  |
| lst.splice(args)                               | 把lst2的所有元素插入到p之前或是flst的p之后的地方 |
| flst.splice_after(args)                        | 或是lst2中p2之后元素                             |
| args:(p, lst2), (p, lst2, p2), (p, lst2, b, e) | 或是lst2中b，e指向的元素                         |
