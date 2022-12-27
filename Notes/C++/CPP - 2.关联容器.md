## 概念
关联容器通过关键字来检索内容的，map是将关键字映射到键值上，set是关键字的集合，map的内部实现是哈希表，set的内部是红黑树

| 有序关联容器       |                                     |
| :----------------- | :---------------------------------- |
| map                | {key, value}                        |
| set                | 只保存关键字                        |
| multimap           | 关键字可重复出现的map               |
| multiset           | 关键字可重复出现的set               |
| 无序集合           |                                     |
| unordered_map      | 使用哈希函数组织的map               |
| unordered_set      | 使用哈希函数组织的set               |
| unordered_multimap | 可重复关键字的使用哈希函数组织的map |
| unordered_multiset | 可重复关键字的使用哈希函数组织的set |

|     | ::key_type | ::mapped_type | value_type (迭代器解引用的类别)   |
| :-- | :--------- | :------------ | :-------------------------------- |
| set | 关键字类型 | 无            | const key_type                    |
| map | 关键字类型 | 关联的类型    | pair<const key_type, mapped_type> |

由于解引用后key_type是const,通常不对关联容器采用泛型算法


### 有序容器
有序容器key排序是严格弱序(strict weak ordering)，可以重载默认的排序函数

```c+++
multiset<Sales_data, decltype(compareISBN)*> bookstore(compareISBN);
multiset<int, greater<int>> s;
```

### 无序容器 Unordered Associative Container
无序容器的性能依赖于哈希函数的质量和桶数量，元素会根据哈希后的值分配到不同的桶中  

| 桶接口               |                                            |
| :------------------- | :----------------------------------------- |
| c.bucket_count()     | 正在用的桶的数目                           |
| c.max_bucket_count() | 最多桶的数目                               |
| c.bucket_size(n)     | 第n个桶里有多少个元素                      |
| c.bucket(k)          | 关键字为k的元素在那个桶中                  |
| 桶迭代器             |                                            |
| local_iterator       | 可以用来访问桶中元素的迭代器               |
| const_iterator       |                                            |
| begin(n), end(n)     | 桶n的首部和尾后                            |
| cbegin(n), cend(n)   |                                            |
| 哈希策略             |                                            |
| c.load_factor()      | 桶的平均元素数量，返回float                |
| c.max_load_factor()  | 试图维护的桶的平均大小，返回float          |
| c.rehash(n)          | 重组存储，使得 bucket_count >= n           |
|                      | bucket_count> size / max_load_factor       |
| c.reserve(n)         | 重组存储，使得c可以保存n个元素且不必rehash |


使用标准库的hash<key_type>生成每个元素的哈希值，hash位于 <type_traits>
```c++
size_t hasher(const string &s) {
	return hash<string>()(s);
}
bool eqOp(const string &lhs, const string &rhs) {
	return lhs == rhs;
}
using SD_multiset = unordered_multiset<string, decltype(hasher)*, decltype(eqOP)*>;
SD_multiset sdSet(42, hasher, eqOp); // 桶大小，hash函数，相等函数
// 如果容器的元素类型定义了==运算符，则定义容器时不用放入重载的==运算符
```

## map

又称作关联数组 assiciative array

| map<key_type, mapped_type> | map<string, size_t> wordcount;                       |
| :------------------------- | :--------------------------------------------------- |
|                            |                                                      |
| mapName[key]               | 在map里查找key的值，返回mapped_type的左值            |
| ++word_count[word];        | 若key没在map中，下标运算符会创建一个新元素，值初始化 |
| *map_iter                  | 解引用，得到一个pair<const key_type, mapped_type>    |
|                            |                                                      |


通用操作
|              |                     |                                                                      | map                      | set                     | 说明，multi附加说明                         |
| :----------- | :------------------ | :------------------------------------------------------------------- | :----------------------- | :---------------------- | :------------------------------------------ |
| 插入操作     | c.insert(v);        | p是指向从某处开始搜索的迭代器                                        | map.insert(make_pair()); | set.insert(beg, end);   | insert和emplace都只当关键字不在集合中才插入 |
|              | c.insert(b, e);     | 返回新插入元素的迭代器                                               | map.insert({word, 1});   | set.insert({1, 2, 3…}); |                                             |
|              | c.insert(il);       |                                                                      |                          |                         |                                             |
|              | c.insert(p, v);     |                                                                      |                          |                         |                                             |
| 构造插入操作 | c.emplace(args);    | 返回一个pair，包含一个指向插入元素的迭代器和判断插入是否成功的bool值 |                          |                         | multi始终都会插入                           |
|              | c.emplace(p, args); | pair<it, bool>                                                       |                          |                         |                                             |
| 删除操作     | c.erase(k);         | k:返回删除元素的数量，size_t                                         |                          |                         |                                             |
|              | c.erase(p);         | p:返回被删元素之后的迭代器或者end()                                  |                          |                         |                                             |
|              | c.erase(b, e);      | b,e:返回e                                                            |                          |                         |                                             |
|              |                     |                                                                      |                          |                         |                                             |


其他操作
|||
| :--------------- | :--------------------------------------------------------------------------- |
| c.at(k)          | 等同于下标运算符，但要是k不在c中，则返回一个out of range 日常                |
| c.find(k)        | 返回关键字为k的迭代器                                                        |
| c.count(k)       | 计数                                                                         |
| c.lower_bound(k) | 第一个关键字不小于k的元素的迭代器                                            |
| c.upper_bound(k) | 第一个关键字大于k的元素的迭代器                                              |
| c.equal_range(k) | 返回一个pair，为关键字等于k的元素的范围迭代器，若都不存在，则返回一对c.end() |

