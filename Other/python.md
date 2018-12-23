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
- [`types`](#types)
- [错误处理](#%E9%94%99%E8%AF%AF%E5%A4%84%E7%90%86)
  - [异常](#%E5%BC%82%E5%B8%B8)
  - [`assert`](#assert)
  - [`logging`](#logging)
  - [test](#test)
- [.....](#)



## `Python`基础

- 动态语言, 变量类型不固定, 解释器管理内存存储, 变量名只是指针
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

# inside for iteration
for x in [1, 2, 3, 4, 5]:
    pass

it = iter([1, 2, 3, 4, 5])
try:
    x = next(it)
    pass
    except StopIteration:
        break

print('%s, %s' %('asd', '123'))

n = 0
del n # 删除引用

a = 10
b = a // 3.3 # floor divide 取整除

```
</details>


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
- 正向索引从0开始, 负向索引从1开始
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

```

- 单独用索引会有 `out of range` 错误, 用 `slice` 则不会
- 索引正负可混用, 只输出迭代器包围的部分, 迭代器大小不正确则不输出
- `ord()`可以获得字符的整数编码,  `chr()`可以把整数转成字符
- `bytes` 类型, 使用 `encode('codec')` 编码, 使用 `decode('codec')` 解码
    - 对于 `bytes`, `len()` 会计算字节数



### 列表 `list`
有序表, 可以放入任意类型 (可嵌套), `append`, `insert`, `pop`

```python

# list comprehensions
import os
print([name for name in os.listdir('.')])

print([x * x for x in range(2, 10) if x % 2 == 0])
print([m + str(n) for m in 'ABC' for n in range(3)])
L2 = [e.lower() for e in L if isinstance(e, str)]

```

### 元组 `tuple`
- 不可变 (类似于单层 `const`)
- 定义单个元素的元组 t = (1, )


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
  - 函数的默认参数是内存里的变量...最好定义成不变量
- 可变参数
  - 加 `*` 声明可变参数, 也可以给 `list` 和 `tuple` 加 `*` 号变为可变参数传入
  - 加单独的 `*` 会开启命名参数序列, 必须在传参时声明参数名字, 否则会被视为位置参数, 可变参数后的参数默认都为命名参数
- 关键字参数
  - 加 `**` 声明 `keyword` 关键字参数, 这些参数会组装成一个字典
- 函数可以同时传入, 但位置必须为：必选参数（位置参数）、默认参数、可变参数、命名关键字参数和关键字参数。
  - 习惯写法: `*args` 和 `**kw`

<details> <summary> 函数示例 </summary>

```python

# 列表可变参数
nums = [1, 2, 3, 4, 6]
print(kSum(*nums))

# 关键字参数
def kDict(**kw):
    print(kw)

kDict(city = 'beigin', a = '2', _21 = 1)

print()

dicket = {'city' : 'beigin', 'a' : '2', '_21' : 1}
kDict(**dicket)

# 带有所有参数的函数示意

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
# 994 times tailed recursion fibnacci until overflow
print(kTailedFib(1, 1, 994))

# 994 times tailed recursion factor until overflow
print(kFact(1, 995))
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
        yield n0        # 遇到 `yield` 返回, 再次执行时从 yield 开始执行
    return 'Done'

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

- 类内使用 `__` 开头的变量为 `private` 变量, `python` 会更改其名字, 在类外声明会添加新的变量
- `__xxx__` 为特殊变量
- `Duck type`不需要严格的继承体系, 只需要有同名方法

```Python
class Character(object):
    __slots__ = ('skill', 'ability', 'name') # on attrs in slots can be added to instances
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
多继承直接 `MixIn`

- `__str__` 给 `print` 用的
- `__repr__` 给调试输出用的, 一般直接 `__repr__ = __str__`
- `__iter__` 返回一个迭代对象, `for`循环使用该迭代对象的 `__next__` 取值

## `types`

`len(Obj)` 其实调用的是 `Obj.__len__()`, 只要自己写了同名函数, 也可以支持用内置函数调用

`dir(Obj)` 能返回某个对象的所有函数

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