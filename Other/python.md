---
layout: post
title: "Python基础"
date: 2018-12-23 12:23:30
update: 
categories: Python
img:
---


- [img:](#img)
- [`Python`基础](#python%E5%9F%BA%E7%A1%80)
  - [命名空间](#%E5%91%BD%E5%90%8D%E7%A9%BA%E9%97%B4)
  - [作用域](#%E4%BD%9C%E7%94%A8%E5%9F%9F)
- [数据类型](#%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B)
  - [str](#str)
  - [列表 `list`](#%E5%88%97%E8%A1%A8-list)
  - [元组 `tuple`](#%E5%85%83%E7%BB%84-tuple)
  - [字典 `dict`](#%E5%AD%97%E5%85%B8-dict)
  - [集合 `set`](#%E9%9B%86%E5%90%88-set)
  - [枚举 `Enum`](#%E6%9E%9A%E4%B8%BE-enum)
- [函数](#%E5%87%BD%E6%95%B0)
  - [函数基础](#%E5%87%BD%E6%95%B0%E5%9F%BA%E7%A1%80)
  - [函数传参](#%E5%87%BD%E6%95%B0%E4%BC%A0%E5%8F%82)
  - [函数调用栈](#%E5%87%BD%E6%95%B0%E8%B0%83%E7%94%A8%E6%A0%88)
- [语法特性](#%E8%AF%AD%E6%B3%95%E7%89%B9%E6%80%A7)
- [面向对象](#%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1)
  - [类成员](#%E7%B1%BB%E6%88%90%E5%91%98)
  - [继承](#%E7%BB%A7%E6%89%BF)
- [`types`](#types)
- [错误处理](#%E9%94%99%E8%AF%AF%E5%A4%84%E7%90%86)
  - [异常](#%E5%BC%82%E5%B8%B8)
  - [`assert`](#assert)
  - [`logging`](#logging)
  - [test](#test)
- [.....](#)
- [文件操作](#%E6%96%87%E4%BB%B6%E6%93%8D%E4%BD%9C)



## `Python`基础

- 动态语言, 变量类型不固定, 解释器管理内存存储, 变量名只是名字 (引用)
- 赋值语句被用来将名字绑定或者重绑定给其他值
- ipython下最后的运算结果会给 _
- `python` 源文件默认 `utf-8` 编码
  -  `unicode` 汉字两字节, `uft-8` 英文1字节, 汉字3字节, 生僻字4-6字节, `ASCII` 是`utf-8 `的一部分

<details> <summary> 基础语句 </summary>

```python
#!/use/bin/env python3
# -*- coding: utf-8 -*-

name =  input('name=') # input返回的是字符串, 需要用 int() 转换为 str

print('Sector %d, %d' % (1, 2)) # 使用占位符输出
print('{0}2{1:.1f}'.format(1, 3)) # python3

# for 循环
for name in names:
    print(name) 

for i  in range(101): # 0- 100
    sum += i

for w in words[:]: # traverse a copy of words
    pass

# inside for iteration
for x in [1, 2, 3, 4, 5]:
    pass

it = iter([1, 2, 3, 4, 5])
try:
    x = next(it)
    pass
    except StopIteration:
        break

# while else

n = 0
while n < 3 :
    print("%d is less than 3" % n)
    n += 1
else:
    print("%d is not less than 3" % n) # 循环结束时运行, for 循环也可以使用

# ternary if

# v = value if condition else other

# x or y 
# equals
# if bool(x) then x else y


print('%s, %s' %('asd', '123'))

n = 0
del n # 删除引用

a = 10
b = a // 3.3 # floor divide 取整除

```
</details>

<details> <summary> 运算符优先级  </summary>


| 运算符 (优先级递增)               | 描述        |
|-------------------|-----------|
| lambda            | Lambda表达式 |
| or                | 布尔“或”     |
| and               | 布尔“与”     |
| not x             | 布尔“非”     |
| in, not in         | 成员测试      |
| is, is not         | 同一性测试     |
| <, <=, >, >=, !=, ==   | 比较        |
| |                 | 按位或       |
| ^                 | 按位异或      |
| &                 | 按位与       |
| <<, >>             | 移位        |
| +, -               | 加法与减法     |
| *, /, %             | 乘法、除法与取余  |
| +x, -x             | 正负号       |
| ~x                | 按位翻转      |
| **                | 指数        |
| x.attribute       | 属性      |
| x[index]          | 索引        |
| x[index:index]    | 切片       |
| f(arguments...)   | 函数调用      |
| (experession,...) | 绑定或元组   |
| [expression,...]  | 列表      |
| {key:datum,...}   | 字典      |
| 'expression,...'  | 字符串转换     |

</details>

### 命名空间
命名空间 `namespace` 是名字到对象的映射, 通过 `dict` 管理

常见命名空间有:
- `built-in` 内置命名空间 : 包括内置函数, 内置异常, 在解释器启动时创建, 推出时销毁
- 全局命名空间 : 包括模块中的名字, 比如类, 函数, 导入的模块, 模块被解释器读入时创建, 解释器推出时销毁
- 局部命名空间
  - 函数的命名空间 : 函数调用过程中的名字, 函数参数, 函数体内定义的名字, 函数被调用时创建, 函数返回或有未捕获的异常时销毁
  - 类的命名空间 : 类定义开始时的命名空间, 解释器读到类定义时创建, 类定义结束后销毁 
  - 一个对象的属性集合也构程一个命名空间

### 作用域
作用域是一块代码区域, 在这个区域中, 相关命名空间中的名字可以直接访问
  - 直接访问 : `name`, 在命名空间中搜索 
  - 间接访问 : `objname.attr`, 先在命名空间内搜索 `objname`, 再访问其属性 
同一个代码区域可能存在多个命名空间, 而命名空间又是动态产生的


`LEGB` : Python 查找变量的顺序
- `Local` : 局部
- `Enclosing` : 闭包函数外的函数
- `Global` : 全局
- `Builtin` : 内置

- `if`, `while`, `try` 不会引入新的作用域, 其内部变量和外部作用域一致, `module`, `class`, `def`, `lambda` 会引入新的局部作用域
- 可以在 `Local` 作用域通过 `global`, `non-local` 来使用 `Global` 和 `Enclosing` 作用域的变量

<details> <summary> 作用域 </summary>

```python
print(int(2.3)) # builtin >>> 2

g_n = 10 # global

if g_n == 10:
    g_c1 = 20 # global
else :
    g_c2 = 10 # global but not defined in the program

def outer():
    e_count = 1 # Enclosing / Local
    def inner():
        nonlocal e_count # use enclosing variable
        l_sum = 0 # local

print(g_c1) # >>> 20
# print(g_c2) # name `g_c2` is not defined

def useGlobal():
    global g_n
    print(g_n) # >>> 10
    g_n = 1.33
    print(g_n) # >>> 1.33

useGlobal()
```
</details>

<details> <summary> 作用域的坑  </summary>

```python
class Test(object):
    i = 1 # 类定义结束就无法直接访问, 除非间接访问 Test.i
    def test_print(self):
        print(i)

t = Test()
i = 2
t.test_print() # >>> 2


class Test(object):

    a = 1
    b = [a + i for i in range(10)]
    # NameError: name 'a' is not defined
    # list comprehension 创建了局部作用域
    print(b)

    def test(self):
        pass


```
</details>


> Python 函数体代码会进行预编译, 变量的作用域是静态的, 预编译时就能够确定变量的作用域, 但变量名的查找是动态发生的

<details> <summary> 生命周期 </summary>

```python
# 生命周期
v = 300
def f():
    print(v) # Unbound Local Error : local variable 'v' referenced before assignment
    v = 200 
f()

print(v)
```
</details>

- [ ] 垃圾回收 (引用计数, 分代回收)

## 数据类型

- `int` 型, 长度与机器位数相关, python 会将超出范围的 `int` 型转为整形
  - 整数池：`[-5, 257)` 范围内的整数缓存在整数池中, 不会频繁释放
- `float` 型, 默认 8 字节
- `complex`, 复数, `1 + 2j`
- `bool`型, `True` or `False`

### str

- 字符串不可变！
  - `s.replace('a', 'A')` 会生成新的字符串
- 单引号字符串中可以夹杂双引号, 双引号可以夹杂单引号
- 正向索引从 `0` 开始, 负向索引从 `-1` 开始
- 相邻字符串会自动连接到一起, 不能连接表达式

```python
# 三引号跨行输入
s = ''' 
Marvlous
Bravo
Excellent
'''

s1 = r'\n\t\v\b' # 原始字符串
s2[a:b] # [a:b) slice
len(s) 

print("{1} {0} {1}".format("foo", "bar")) # >>> bar foo bar

```

- 单独用索引会有 `out of range` 错误, 用 `slice` 则不会
- 索引正负可混用, 只输出迭代器包围的部分, 迭代器大小不正确则不输出
- `ord()`可以获得字符的整数编码,  `chr()`可以把整数转成字符
- `bytes` 类型, 使用 `encode('codec')` 编码, 使用 `decode('codec')` 解码
    - 对于 `bytes`, `len()` 会计算字节数



### 列表 `list`
有序表, 可以放入任意类型 (可嵌套), `append`, `insert`, `pop`
- `list` 的 `append` 方法可改变外部全局变量的值


```python

# list comprehensions
import os
print([name for name in os.listdir('.')])

print([x * x for x in range(2, 10) if x % 2 == 0])
print([m + str(n) for m in 'ABC' for n in range(3)])
L = [(x,y,z) for x in range(1,30) for y in range(x,30) for z in range(y,30) if x**2 + y**2 == z**2]
L2 = [e.lower() for e in L if isinstance(e, str)]
```

### 元组 `tuple`
- 不可变 (类似于单层 `const`)
- 定义单个元素的元组 t = (1, )

`list` 和 `tuple` 的区别

- `tuple` 基本等于 `const list`
- `tuple` 的存储空间会比 `list` 小 (T(n))
- `tuple` 常用来存储不同类型的数据, `list` 通常存同类型的数据

### 字典 `dict`

- `dict` 的 `key` 是不可变对象, `list` 不能作为key
- `dict` 的 `item` 是一个 `tuple`, `t[0]` 为 `key`, `t[1]` 为 `value`

<details> <summary> 字典示例 </summary>

```python
L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]

def by_name(t):
    return t[0]

# sorted function 
print(sorted(L, key = by_name))

d =  {'Kwei' : 0, 'Kwei' : 55, 'Mac' : '88'} # 只有一个 'Kwei'

d =  {'Kwei' : 0, 'Porter' : 55, 'Mac' : '88'}
d['k'] = 0 # 新建了一个 item

if 'Kwei' in d:
    d['Kwei'] = 100

d[d.get('a', 'Default Value')] = 99 # 可返回默认值的取值
d.pop('Default Value')

for key in dic:
    print(key)

for value in dic.values():
    print(value)

for key, value in dic.items():
    print(key + " : " + value)

for i, value in enumerate(dic.values()):
    print(i, ' : ', value)

```

</details>


### 集合 `set`

```python
s = set([0, 1, 1])
s.add('asd')
s.remove(1)
s2 = set(['asd', 2])
print(s & s2)
```

### 枚举 `Enum`

```Python
from enum import Enum
Day = Enum('Day', ('Mon', 'Tue', 'Wed', 'Tur', 'Fri', 'Sun', 'Sat'))

class Weekday(Enum):
    Sun = 0
    Mon = 1
    Tue = 2
    Wed = 3
    Tur = 4
    Fri = 5
    Sat = 6
    
for name, member in Weekday.__members__.items():
    print(name, ' -> ', member, '->', member.value)
```

## 函数

### 函数基础

- 没有 `return` 语句的函数返回 `None`, 没有返回值的 `return` 返回 `None`
- 多值返回的是 `tuple`
- 可变对象传入函数时, 若再函数内部改变了, 外部会被改变
- 若为不可变对象传入函数, 修改时会进行重绑定

```python
def another_abs(x):
    if x >= 0 :
        return x

if another_abs(-1) == None:
    print("None can be detected")

def nop():
    pass # 占位符
```

### 函数传参

- 位置参数：一般的参数
- 默认参数：带有默认值
  - 函数的默认参数是内存里的变量...最好定义成不变量 (C++ 的默认参数也是夹带的)
- 可变参数
  - 加 `*` 声明可变参数, 也可以给 `list` 和 `tuple` 加 `*` 号变为可变参数传入
  - 加单独的 `*` 会开启命名参数序列, 必须在传参时声明参数名字, 否则会被视为位置参数, 可变参数后的参数默认都为命名参数
- 关键字参数
  - 加 `**` 声明 `keyword` 关键字参数, 这些参数会组装成一个字典
- 函数可以同时传入, 但位置必须为：必选参数（位置参数）、默认参数、可变参数、命名关键字参数和关键字参数
  - 习惯写法: `*args` 和 `**kw`

<details> <summary> 函数示例 </summary>

```python

# 列表可变参数

def kSum(*numbers):
    sum = 0
    for num in numbers:
        if not isinstance(num, (int, float)):
            raise TypeError('Wrong operand type')
        sum += num * num 
    print('%d nums have been calculated' % len(numbers))
    return sum

nums = [1, 2, 3, 4, 6]
print(kSum(*nums))

# 关键字参数
def kDict(**kw):
    for k in kw:
        print(k)
    print(kw)

kDict(city = 'beigin', a = '2', _21 = 1)
dicket = {'city' : 'beigin', 'a' : '2', '_21' : 1}
kDict(**dicket)

# 命名关键字参数
def kNamedDict(*, Beijing, Guangzhou):
    print(Beijing, Guangzhou)

kNamedDict(Beijing = 'foo', Guangzhou = 'bar')

# 位置参数, 默认参数, 变长参数
def kMultiply(x, y = 1, *args):
    multi = x * y
    for n in args:
        multi *= n
    return multi


# 带有所有参数的函数示例

def f1(a, b, c=0, *args, **kw):
    print('a =', a, 'b =', b, 'c =', c, 'args =', args, 'kw =', kw)

def f2(a, b, c=0, *, d, **kw):
    print('a =', a, 'b =', b, 'c =', c, 'd =', d, 'kw =', kw)

# 在函数调用的时候, Python解释器自动按照参数位置和参数名把对应的参数传进去
f1(1, 2)                # a = 1 b = 2 c = 0 args = () kw = {}
f1(1, 2, c=3)           # a = 1 b = 2 c = 3 args = () kw = {}
f1(1, 2, 3, 'a', 'b')   # a = 1 b = 2 c = 3 args = ('a', 'b') kw = {}
f1(1, 2, 3, 'a', 'b', x=99) # a = 1 b = 2 c = 3 args = ('a', 'b') kw = {'x': 99}
f2(1, 2, d=99, ext=None)    # a = 1 b = 2 c = 0 d = 99 kw = {'ext': None}

# 通过一个tuple和dict, 你也可以调用上述函数：
args = (1, 2, 3, 4)     # kw = {'d': 99, 'x': '#'}
f1(*args, **kw)         # a = 1 b = 2 c = 3 args = (4,) kw = {'d': 99, 'x': '#'}
args = (1, 2, 3)        # kw = {'d': 88, 'x': '#'}
f2(*args, **kw)         # a = 1 b = 2 c = 3 d = 88 kw = {'x': '#'}

```

</details>

### 函数调用栈

待写
尾递归：函数返回时只调用自身, 这样可以只用一个栈帧就可以计算递归函数

<details> <summary> 尾递归实验次数 </summary>

```python
def kTailedFib(n0, n1, k):
    if k == 0:
        return n1
    return kTailedFib(n1, n0 + n1, k - 1)

# 994 times tailed recursion fibnacci until overflow
print(kTailedFib(1, 1, 994))

def kFact(product, k):
    if k == 1:
        return product
    return kFact(product * k, k - 1)

# 994 times tailed recursion factor until overflow
print(kFact(1, 995))

def kHanoi(n, a = 'A', b = 'B', c = 'C'):
    if n == 1:
        print(a, ' --> ', c)
    else:
        kHanoi(n - 1, a, c, b)
        kHanoi(1, a, b, c)
        kHanoi(n - 1, b, a, c)
```
</details>

<details> <summary> 内置函数 </summary>

```python

# eval : execute string expression
x = 7
print(eval( '3 * x' ))
print(eval('pow(2,2)'))

# input

# python 2.x
# input() = eval(raw_input(prompt))
# raw_input directly return a str

# python 3.x 
# input() only return str

# print
# print(*objects, sep=' ', end='\n', file=sys.stdout)
# sep : seprate

# execfile('hello.py')
# exec
s = 'print("foobar")'
exec(s)
# __import__ : import a mudule
# __import__('a') # >>> import 'a.py'
# reload(module)



# ord : return decimal number of a char
print(ord('a')) # >>> 97
# chr : return a char of a decimal number
print(chr(65)) # >>> 'A'
# bin : return binary
print(bin(10)) # >>> 0b1010
# hex : return hexadecimal
print(hex(10)) # >>> 0xa 
# oct : reutrn octodecimal
print(oct(10)) # >>> 0o12
# id : return memory address of a object
print(hex(id(0))) # 0xaddr
# hash : return hash value of a object
print(hash('1')) # >>> 447530370
# repr : return a str by the intepretion format of a objet
print(repr({'a' : 'rookie'})) # >>> {'a' : 'rookie'}
# complex([real[, imag]]) : return a complex
print(complex(1, 2)) # >>> 1 + 2j
# bytearray
print(bytearray([1,2,3])) # >>> bytearray(b'\x01\x02\x03')
# forzenset([iterable]) : return a const set

# divmod : div & mod
print(divmod(10, 3)) # >>> (3, 1)
# pow(x, y, z) : (x^y) % z
print(pow(2, 100, 99)) # >>> 34
# sum(iterable[, start])
print(sum([1, 2, 5], 9)) # >>> 17
# min, max, round



# enumerate
for i, e in enumerate([1, 2, 3]):
    print("%d, %d" %(i, e))
# iter : create a iterable object
it = iter([1, 5, 3])
# next(iterator[, default])
print(next(it)) # >>> 1
print(next(it)) # >>> 5
# sotred : sort a iterable
print(sorted([1, 5, 3])) # >>> [1, 3, 5]

# slice(start, stop[, step]) : return a slice object
sli = slice(3)
print([1, 2, 4, 5, 0][sli]) # >>> [1, 2, 4]

# zip 
la = [1, 2, 3]
lb = [4, 5, 6]
zipped = zip(la, lb) # >>> [(1, 4), (2, 5), (3, 6)]
zip(*zipped) # >>> [(1, 2, 3), (4, 5, 6)]

# xrange() : return a generator
# list(xrange(0, 6))

# all : non 0, '', False, None
# any : only ↑
all([0, 1, 2, 3]) # >>> false



# type : return type of a object
# ininstance : consider inheritance
# issubclass(class, classinfo)
# callable(obj) : return true if obj is function, class, class instance with __call__ function
class A(object):
    pass
print(callable(A)) # >>> ture


# dir() : return attr list of this module
# dir([ ]) : return attr list of `list`
# vars([object]) : return dict contains objects's attr & attr value
# globals : return a list of global variables
# locals : return a list of local variables
```
</details>


## 语法特性

<details> <summary> 生成器 generator </summary>

```python
g = (x * x for x in range(100) if x % 2 == 1)

print(next(g))
print(next(g))
print(next(g))

g = (x * x for x in range(20) if x % 2 == 1)

for i, n in enumerate(g):
    print(i, ' : ', n)

# 函数生成器

def kFibG(k):
    n0, n1 = 0, 1
    while k >= 0:
        n0, n1 = n1, n0 + n1
        k -= 1
        yield n0 # 遇到 `yield` 返回, 再次执行时从 yield 开始执行
    return 'The iteration is over'

def kYanghuiTriangle(k):
    L = [1]
    while k > 0:
        yield(L)
        T = L[:]    
        T.append(0)
        L = [T[i - 1] + T[i] for i in range(len(T))]    # minus index...
        k -= 1
    return 'The iteration is over'

```
</details>       

<details> <summary> map, reduce, lambda  </summary>

```python
from functools import reduce

DIGITS = {0:'0', 1:'1', 2:'2', 3:'3', 4:'4', 5:'5', 6:'6', 7:'7', 8:'8', 9:'9'}

def kInt2str(num):
    def int2list(n):
        L = []
        while n > 0:
            L.insert(0, n % 10)
            n //= 10
        return L
    def digit2char(i):
        return DIGITS[i]
    def addChar(x, y):
        return x + y
    return reduce(addChar, map(digit2char, int2list(num)))

CHARS = {v : k for k, v in DIGITS.items()}

def kStr2int(s):
    def char2digit(c):
        return CHARS[c]
    def bitSum(x, y):
        return x * 10 + y
    return reduce(bitSum, map(char2digit, s))

def kStr2intLambda(s):
    return reduce( lambda x, y : x * 10 + y, map(lambda c : CHARS[c], s))
```
</details>

<details> <summary> 迭代器 Iterator  </summary>

```python
from collections import Iterable
from collections import Iterator
isinstance(g, Iterable) # list, tuple, dict, set, str, generator, yield
isinstance(g, Iterator) # generator, yield, a data-stream like formula

isinstance(iter([]), Iterator)
isinstance(iter('abc'), Iterator)


```
</details>


<details> <summary> 过滤器 Filter </summary>

```python
# function filter sequence

def oddgen():
    n = 3
    while True:
        yield n
        n += 2

def indivisible(n):
    return lambda x : x % n > 0

def primes():
    yield 2
    it = oddgen()
    while True:
        n = next(it)
        yield n
        it = filter(indivisible(n), it)

for n in primes():
    if n < 1000:
        print(n)
    else:
        break
```
</details>

<details> <summary> 闭包 Closure </summary>

```python
# def square():
#     def f(j):
#         def g():
#             return j * j
#         return g
#     ls = []
#     for i in range(1, 4):
#         ls.append(f(i))
#     return ls

# l1, l2, l3 = square()

# print(l1())
# print(l2())
# print(l3())

# def createCounter():
#     def num_iter():
#         i = 1
#         while True:
#             yield i
#             i += 1
#     g = num_iter()
#     def counter():
#         return next(g)
#     return counter

# def createCounter():
#     l = [0]
#     def counter():
#         l[0] += 1
#         return l[0]
#     return counter

def createCounter():
    l = 0
    def counter():
        nonlocal l  # get non-local variable
        l += 1
        return l
    return counter
```
</details>


<details> <summary> 修饰器 Decorator  </summary>

```python
def log(func):
    def wrapper(*args, **kw):
        for n in args:
            print(n)
        print('Call %s' % func.__name__)
        return func(*args, **kw)
    return wrapper

@log
def printDate(n):
    print('2018-12-29 % d' % n)

# printDate = log(printDate)

printDate(10)
```
</details>


## 面向对象

> `Duck Type`, 有同样的一组方法, 就认为是同一种类型

内置函数在操作对象时, 只要对象有相应的方法, 就可以操作, 例如`len(Obj)` 调用了是`Obj.__len__()`, 只要写了相应的协议方法, 就可以支持用内置函数调用


- 类协议 : `__init__`
- 序列协议 : `__len__`, `__getitem__`
- 容器协议 : `__delitem__`, `__setitem__`, `__iter__`, `__reversed__`
- 类型转换协议 : `__str__`, `__int__`, `__float__`, `__repr__`, `__long__`, `__nonzero__`
- 比较协议 : `__eq__`, `__ne__`, `__lt__`, `__gt__`
- 数值协议 : `__add__`(+), `__sub__`(-),  (运算符都有相应的协议, 类似于运算符重载)
- 可调用协议 : `__call__`
- 哈希协议 : `__hash__`

### 类成员

变量
- 普通变量 : 方法内创建, 需要加 `self.`
- 静态变量 : 类内创建, 类共有
- 类内使用 `__` 开头的变量为 `private` 变量, `python` 会更改其名字(可能为`_classname__membername`)
- `__xxx__` 为特殊成员, 保留不用

方法
- 实例方法 : 第一参数约定为 `self`, 用来传递实例(和类)的属性和方法, 只能由实例对象调用
- 类方法 : 使用装饰器 `@classmethod` 创建, 第一个参数约定为 `cls`, 用来传递类的属性和方法(不能传实例的属性和方法), 实例对象和类对象都可以调用
- 静态方法 : 使用装饰器 `@staticmethod` 创建, 无默认参数, 函数体中不能使用类或实例的任何属性和方法, 实例对象和类对象都可以调用

> 类方法和静态方法可以用来实现不同的构造函数

<details> <summary> 类成员 </summary>

```python

class Fighter(object):
    # static member
    numOfFighter = 0
    def __init__(self, name):
        # member
        self.name = name
        # private member, its name will be changed to '__Charater__weight' by intepretor
        self.__weight__ = 1
    # method
    def attack(self):
        pass
    
    # class method, called by class
    @classmethod
    def addFighter(cls):
        pass
    
    # static method, called by class
    @staticmethod
    def count():
        pass



class Date(object):
    def __init__(self, day, month, year):
        self.day = day
        self.month = month
        self.year = year
    
    @classmethod
    def create_from_str(cls, str):
        day, mouth, year = map(int, str.split('-'))
        date = cls(day, mouth, year)
        return date

d = Date.create_from_str('24-12-2018')

```
</details>



属性 `property`
- 属性是通过 `@property` 装饰器修饰过的方法, 使用起来就像变量一样
  - `@property` : 获取
  - `@name.setter` : 修改
  - `@name.deleter` : 删除
  - 可以使用 `name = property(fget, fset, fdel, doc)` 创建静态字段属性
- [ ] `setattr`, `hasattr`, `delattr`, `getattr`

<details> <summary> 属性 </summary>

```python
class Character(object):
    __slots__ = ('skill', 'ability', 'name') # only attrs which in slots can be added to instances
    Name = 'Super Smash Bros'
    def __init__(self, name):
        self.name = name

Kirby = Character('Kirby')
print(Kirby.name)
print(Kirby.Name) # Be careful. Don't use similar name for class attr and instance attr

# property
class Character(object):    
    @property # getter method
    def name(self):
        return self.__name

    @name.setter
    def name(self, value):
        self.__name = value

# special method
class Fib(object):
    def __init__(self):
        self.__a = 0
        self.__b = 1
    
    def __iter__(self):
        return self
    
    def __next__(self):
        self.__a, self.__b = self.__b, self.__a + self.__b
        if self.__b > 10000:
            raise StopIteration
        return self.__b

    def __getitem__(self, i):
        if isinstance(i, int):
            a, b = 0, 1
            for k in range(i):
                a, b = b, a + b
            return b
        if isinstance(i, slice):
            pass # process slice, return a list

    def __getattr__(self, attr): # process attrs without definition
        if attr == 'grade':
            return 99
        raise AttributeError('\'Student\' don\'t have attr \'%s\'' % attr)

    def __call__(self, n):
        return self.__getitem__(n) # callable(obj) could be used to call a object as a function

# Chain call
class Chain(object):
    def __init__(self, path = ''):
        self.__path = path

    def __getattr__(self, attr):
        # pass
        return Chain('%s/%s' %(self.__path, attr))
    
    def __str__(self):
        return self.__path
    __repr__ = __str__

print(Chain().users.friend.foo.bar)
```
</details>

特殊成员
- `__init__` : 构造方法
- `__del__` : 垃圾回收时触发
- `__call__` : 调用方法
- `__dict__` : 类或对象的所有成员
- `__doc__` : 描述信息
- `__module__` : 当前对象的模块
- `__class__` : 类名
- `__getitem__`, `__setitem__`, `__delitem__` 用于索引操作, 获取, 赋值, 删除
- `__getslice__`, `__setslice__`, `__delslice__` 用于切片操作
- `__iter__` : 返回 `iterabale`, 用于迭代
- `__new__`, `__metaclass`__ : 
- 

<details> <summary> 特殊成员 </summary>

```python
class Foo:
    """ 类的描述 """

    def func(self):
        pass

print(Foo.__doc__)

```
</details>



### [继承](https://www.cnblogs.com/crazyrunning/p/7095014.html)

- 在声明类时将其他类型放到括号里既可以继承其他类型的方法与成员
- 子类重写父类方法只是把同名属性名绑定到了不同的函数对象上, 实际上是没有重写 (`override`) 的
- 可以用 `super` 委托调用父类方法
  - `super` 的查找是通过继承树
  - 继承树方法的搜索通过 `MRO (Method Resolution Order)` 进行, 类的 `__mro__` 属性会返回方法搜索顺序, 在通过 `object` 继承的新式类中, `mro` 的搜索是通过广度优先搜索进行的 (从左到右)
  - `mro` 本质上是将继承树变成继承链表, 以保证任何祖先类的方法只被执行一次
    - `mro` 会因为继承树的更改而变动, 也就是说, 父类可能因为新的子类的 `mixin` 而调用了同级类的新代码
  - `super` 的实践建议 : 设计好整个体系之后, 再写 `super` 相关的方法...
  - 通过 `super` 调用的方法链必须一直到根类, 且方法参数与调用参数必须完全匹配

<details> <summary> 钻石继承 </summary>

```python
class D(object):
    def __init__(self, d):
        self.d = d

class B(D):
    def __init__(self, b, c, d):
        super(B, self).__init__(c, d)
        self.b = b

    
class C(D):
    def __init__(self, c, d):
        super(C, self).__init__(d)
        self.c = c

class A(B, C):
    def __init__(self, a, b, c, d):
        super(A, self).__init__(b, c, d)
        self.a = a


f = A(1, 2, 3, 4)
print(A.__mro__) # A -> B -> C -> D -> o
print(B.__mro__) # C -> D -> o
print(C.__mro__) # D -> o
print(D.__mro__) # o
```
</details>

## `types`




```Python

from types import MethodType


if not hasattr(obj, 'name'):
    setattr(obj, 'name', 'Link')
print(getattr(obj, 'skill')) # AttributeError
print(getattr(obj, 'Website', 404)) # Default return value

def readImage(fp):
    if hasatte(fp, 'read'):
        return readData(fp)
    return None
```

```Python
# Create dynamic type

def fn(self, name = 'Hell'):
    print('Hello ', name)


test = type('Hello', (object, ), {'hello' : fn})

print(type(test)) # type

h = test()
h.hello()

```

## 错误处理


### 异常

g = kFibG(1)
while True:
    try:
        x = next(g)
        print('g: ', x)
    except StopIteration as e:
        print('Generator return value', e.value)
        break

- `TypeError`
- `ValueError`
- `StopIteration`
- `AttributeError`
- `ZeroDivisionError`
- `AssertionError`
- `IOError`



```Python
import logging

try:
    r = 10 / int('a')
    r = 10 / 0
except ValueError as e:
    logging.exception(e)
except ZeroDivisionError as e:
    logging.exception(e) # Exception call stack
else: # non-exception
    pass
finally: # doing with or without exception throwed
    pass
print('END')


try:
    r = 10 / 0
except ZeroDivisionError as e:
    logging.exception(e)
    raise 
    # raise ValueError('Zero value')
```


### `assert`

assert type(s) == int, 'not a int'
python -O err.py

### `logging`

```python
import logging

n = 0

logging.info('n = %d' % n) # Get exception name

logging.basicConfig(level=logging.INFO) # Get exception call stack, there are 4 levels in logging : debug, info, warning, error

```

### test

$ python -m unittest mydict_test
.....
----------------------------------------------------------------------
Ran 5 tests in 0.000s

OK

## 文件操作

- [ ] `open`
- [ ] `file`