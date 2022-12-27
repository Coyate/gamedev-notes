## 泛型算法 Generic Algorithm


泛型算法是针对template编写的算法，可以对任何类型的容器进行操作，主要在<algorithm> <numeric> 头文件中
- 泛型算法不改变底层容器的大小（没用插入迭代器的情况下）
- 可以改变元素值，可以移动元素

| 谓词              |
| :---------------- |
| unaryPred         |	一元谓词，接受一个参数的操作
| binaryPred        |	二元谓词，接受二个参数的操作
| unaryOp，binaryOp |	一元，二元运算符
| comp              |	二元谓词，用做比较操作


`泛型算法迭代器类别`
| 类别                   | 读写情况 | 扫描 | 增减 | 支持运算符                               | 例子                                                               | 算法               |
| :--------------------- | :------- | :--- | :--- | :--------------------------------------- | :----------------------------------------------------------------- | :----------------- |
| 输入迭代器             | 只读     | 单遍 | 递增 | ==, !=, ++, *, ->                        | istream_iterator                                                   | find, accumulate   |
| input iterator         |          |      |      |                                          |                                                                    |                    |
| 输出迭代器             | 只写     | 单遍 | 递增 | *, ++                                    | ostream_iterator                                                   | copy中第三个迭代器 |
| output iterator        |          |      |      |                                          |                                                                    |                    |
| 前向迭代器             | 可读写   | 多遍 | 递增 | 支持输入输出迭代器的操作                 | forward_list的迭代器                                               | replace            |
| forward iterator       |          |      |      |                                          |                                                                    |                    |
| 双向迭代器             | 可读写   | 多遍 | 递增 | 支持前向迭代器的操作，--                 | 除forward_list的标准库容器迭代器                                   | reverse            |
| bidirectional iterator |          |      | 递减 |                                          |                                                                    |                    |
| 随机访问迭代器         | 可读写   | 多遍 | 递增 | <, <=, >, >=, +, +=, -, -=, a-b, iter[n] | 可以常量时间访问元素, array, deque, string, vector, 内置数组的指针 | sort               |
| random access iterator |          |      | 递减 |                                          |                                                                    |                    |
|                        |          |      |      |                                          |                                                                    |                    |


`泛型算法结构`

|||
| :------------------------------ | :------------------------------------------------------------- |
| alg(beg, end, args)             | beg和end表示操作的输入范围                                     |
| alg(beg, end, dest, args)       | dest表示输出目的范围，算法假定如果要写入，写入多少个都是安全的 |
| alg(beg, end, beg2, args)       | beg2，接受第二个输入范围，假定beg2开始范围和beg到end一样大     |
| alg(beg, end, beg2, end2, args) |                                                                |
| alg(beg, end, comp/pred)        | 用comp或者pred重复                                             |


### `迭代器 <iterator>`


1. 使用 != 进行比较，不能使用 > <
2. 增删从其都会使已有的迭代器失效
3. const_iterator只读，对象为常量时，begin()和end()会自动返回const_iterator (应该主动使用 cbegin() 和 cend() )
4. 若容器内为其他类，调用类成员需要使用成员调用符号 it->member();
5. 迭代器可以与 size_type 进行算术运算，如想减会得到结果为 difference_type 的无符号整形数
6. 解引用一个迭代器，或调用front或back时检查其中是否有元素
if(!empty())


`插入迭代器 Insert Iterator`

```c++
copy(vec.begin(), vec.end(), inserter(lst, lst.begin()));
```

|||
| :---------------- | :------------------------------------ |
| it = t            | 在it指定的当前位置插入值t             |
| back_inserter     | 一个使用push_back插入的迭代器         |
| front_inserter    | 一个使用push_front插入的迭代器        |
| inserter          | 使用insert的迭代器，将c插入到iter之前 |
| inserter(c, iter) |                                       |

`流迭代器 Stream Iterator`  
iostream迭代器，有istream_iterator, ostream_iterator  

```c++
	istream_iterator<int> in(cin), eof; // eof，空的流迭代器，可以当尾后迭代器使用
	cout << accumulate(in, eof, 0) << endl; // 累计输入之和
```

- istream_iterator允许懒惰求值，标准库保证在第一次解引用迭代器之前，流读取数据的操作已经完成了（具体何时不明）
- ostream迭代器，对迭代器使用赋值运算符等于 << 到输出流，必须初始化，不允许为空

```c++		
ostream_iterator<in> out_iter(cout, " "); // 每个元素后多打印" "
for(auto e : vec)
	*out_iter++ = e; // 元素写入到cout，该语句等于 out_iter = e;
cout << endl;
copy(vec.begin(), vec.end(), out_iter); // 直接输出到cout
```

`反向迭代器 Reverse Iterator`
从尾元素往首元素移动的迭代器，递增往前移，递减往后移
c.rbegin()	尾部，倒数第一个
c.crbegin()
c.rend()	首前，正数第一个之前
c.crend()

`移动迭代器 Move Iterator`
不拷贝其中的元素，而是移动

make_move_iterator() 右值迭代器

## 泛型算法库

| 简单查找算法                     | 要求 输入迭代器 input iterator      |
| :------------------------------- | :---------------------------------- |
| find(beg, end, val)              | 查找 element == val                 |
| find_if(beg, end, unaryPred)     | 查找 unaryPred(element) == true     |
| find_if_not(beg, end, unaryPred) | 查找 unaryPred(element) == false    |
|                                  | 没找到则返回end                     |
| count(beg, end, val)             | 计数 element == val                 |
| count_if(beg, end, unaryPred)    | 计数 unaryPred(element) == true     |
|                                  |                                     |
| all_of(beg, end, unaryPred)      | unaryPred对所有元素成功则返回true   |
| any_of(beg, end, unaryPred)      | unaryPred对任一元素成功则返回true   |
| none_of(beg, end, unaryPred)     | unaryPred对全部元素不成功则返回true |


| 查找重复值的算法                           | 要求 前向迭代器 forward iterator |
| :----------------------------------------- | :------------------------------- |
| adjacent_find(beg, end)                    | 找第一对重复元素                 |
| adjacent_find(beg, end, binaryPred)        | binaryPred 替代 ==               |
|                                            |                                  |
| search_n(beg, end, count, val)             | 找有count个相等元素的子序列      |
| search_n(beg, end, count, val, binaryPred) | binaryPred 替代 ==               |
	

| 查找子序列的算法                                  | 要求前向迭代器 forward iterator              |
| :------------------------------------------------ | :------------------------------------------- |
| search(beg1, end1, beg2, end2)                    | 找第二个范围在第一个范围的位置               |
| search(beg1, end1, beg2, end2, binaryPred)        | binaryPred 替代 ==                           |
|                                                   |                                              |
| find_first_of(beg1, end1, beg2, end2)             | 第二个范围 任意元素 在第一个范围出现的位置   |
| find_first_of(beg1, end1, beg2, end2, binaryPred) | binaryPred 替代 ==                           |
|                                                   |                                              |
| find_end(beg1, end1, beg2, end2)                  | 找第二个范围在第一个范围内最后一次出现的位置 |
| find_end(beg1, end1, beg2, end2, binaryPred)      | binaryPred 替代 ==                           |
	
| 二分搜索算法                       | 要求前向以上的迭代器 forward iterator                                   |
| :--------------------------------- | :---------------------------------------------------------------------- |
| lower_bound(beg, end, val)         | 第一个小于等于val的元素                                                 |
| lower_bound(beg, end, val, comp)   | comp 替换 ==                                                            |
|                                    |                                                                         |
| upper_bound(beg, end, val)         | 第一个大于等于val的元素                                                 |
| upper_bound(beg, end, val, comp)   | comp 替换 ==                                                            |
|                                    |                                                                         |
| equal_range(beg, end, val)         | 返回一个pair，first与second分别存有lower_bound与upper_bound返回的迭代器 |
| equal_range(beg, end, val, comp)   | comp 替换 ==                                                            |
|                                    |                                                                         |
| binary_search(beg, end, val)       | 返回bool值，序列里是否有等于val的元素                                   |
| binary_search(beg, end, val, comp) | comp 替换 ==                                                            |


| 其他只读算法                           | 要求输入迭代器 input iterator                                 |
| :------------------------------------- | :------------------------------------------------------------ |
| for_each(beg, end, unaryOP)            | 对每个成员做 unaryOp                                          |
|                                        |                                                               |
| mismatch(beg1, end1, beg2)             | 返回第一个不匹配的pair，都不匹配则是一个end与等长位置的迭代器 |
| mismatch(beg1, end1, beg2, binaryPred) | binaryPred 替代 ==                                            |
|                                        |                                                               |
| equal(beg1, end1, beg2)                | 判断两个序列是否相等                                          |
| equal(beg1, end1, beg2, binaryPred)    | binaryPred 替代 ==                                            |
	

| 只写不读的算法             | 要求输出迭代器 output iterator          |
| :------------------------- | :-------------------------------------- |
| fill(beg, end, val)        | 给序列里的值都赋予val                   |
| fill_n(dest, cnt, val)     | 从dest开始的cnt个值赋予val              |
| generate(beg, end, Gen)    | Gen()是一个可调用对象，生成不同的返回值 |
| generate_n(dest, cnt, Gen) | fill和generate都返回void                |


| 写入算法                                            | 要求输入迭代器 input iterator     |
| :-------------------------------------------------- | :-------------------------------- |
| copy(beg, end, dest)                                | 从输入范围拷贝到输出              |
| copy_n(beg, n, dest)                                | 从输入范围拷贝前n个元素到输出     |
| copy_if(beg, end, dest, unaryPred)                  | 拷贝满足unaryPred的元素           |
|                                                     |                                   |
| move(beg, end, dest)                                | 移动                              |
|                                                     |                                   |
| transform(beg, end, dest, unaryOp)                  | 对元素使用unaryOp，然后存入dest中 |
| transform(beg, end, beg2, dest, binaryOp)           | 对两个输入序列的元素使用binaryOp  |
|                                                     | E                                 |
| replace_copy(beg, end, dest, old_val, new_val)      | 全部拷贝，指定值替换              |
| replace_copy_if(beg, end, dest, unaryPred, new_val) | 全部拷贝，满足unaryPred的替换     |
|                                                     |                                   |
| merge(beg1, end1, beg2, end2, dest)                 | 两输入必须有序，合并，使用<       |
| merge(beg1, end1, beg2, end2, dest, comp)           | comp 替换 <                       |


| 写入的算法                               | 要求前向迭代器 forward iterator |
| :--------------------------------------- | :------------------------------ |
| iter_swap(iter1, iter2)                  | 交换两个迭代器的元素            |
| swap_ranges(beg1, end1, beg2)            | 交换两个范围的元素，不能有重叠  |
|                                          |                                 |
| replace(beg, end, old_val, new_val)      | 替换给定值                      |
| replace_if(beg, end, unaryPred, new_val) | 替换满足unrayPred的元素为给定值 |
	


| 写入的算法                         | 要求双向迭代器 bidirectional iterator                                              |
| :--------------------------------- | :--------------------------------------------------------------------------------- |
| copy_backward(beg, end, dest)      | dest为尾后迭代器，倒着拷贝或移动，若为空，返回dest，否则返回*beg拷贝或移动到的位置 |
| move_backward(beg, end, dest)      |                                                                                    |
|                                    |                                                                                    |
| inplace_merge(beg, mid, end)       | 将beg到mid 和 mid到end的两个有序子序列合并，返回void，写入到原序列中，使用<        |
| inplace_merge(beg, mid, end, comp) | comp 替换 <                                                                        |
	

| 排序算法                        | 要求随机访问迭代器 random access iterator |
| :------------------------------ | :---------------------------------------- |
| sort(beg, end)                  | 使用<排序                                 |
| sort(beg, end, comp)            | comp 替代 <                               |
| stable_sort(beg, end)           | 保持原有顺序排序                          |
| stable_sort(beg, end, comp)     | comp 替代 <                               |
|                                 |                                           |
| is_sorted(beg, end)             | 有序则返回true                            |
| is_sorted(beg, end, comp)       | comp 替代 <                               |
| is_sorted_until(beg, end)       | 查找初始最长有序子序列，返回其尾后迭代器  |
| is_sorted_until(beg, end, comp) | comp 替代 <                               |


| 排序算法                                            | 要求随机访问迭代器 random access iterator                          |
| :-------------------------------------------------- | :----------------------------------------------------------------- |
| partial_sort(beg, mid, end)                         | 将序列前mid-beg个元素放在前面                                      |
| partial_sort(beg, mid, end, comp)                   | comp 代替 <                                                        |
|                                                     |                                                                    |
| partial_sort_copy(beg, end, destBeg, destEnd)       | 排序输入范围的元素，然后尽量往输出范围放                           |
| partial_sort_copy(beg, end, destBeg, destEnd, comp) | comp 代替 <                                                        |
|                                                     |                                                                    |
| nth_element(beg, nth, end)                          | nth是迭代器，序列会划分为比nth小的和比nth大的，返回nth划分后的位置 |
| nth_element(beg, nth, end, comp)                    | comp 代替 <                                                        |
	


| 通用重排算法                               | 要求输出迭代器 output iterator                                                                             |
| :----------------------------------------- | :--------------------------------------------------------------------------------------------------------- |
| remove(beg, end, val)                      | 把要val挪到容器后面，返回删除后的序列的尾后迭代器                                                          |
| remove_if(beg, end, unaryPred)             | 删除满足unaryPred的元素                                                                                    |
| remove_copy(beg, end, dest, val)           | 删除后的存入dest                                                                                           |
| remove_copy_if(beg, end, dest, unaryPred)  | 删除满足unaryPred的元素后存入dest                                                                          |
|                                            |                                                                                                            |
| unique(beg, end)                           | 重排序列，把相邻的重复元素只剩下一个，多余的放到容器不重复序列的后面，返回不重复的元素序列的最后一个迭代器 |
| unique(beg, end, binaryPred)               | binaryPred 替代 ==                                                                                         |
| unique_copy(beg, end, dest)                | 重排覆盖后的存入dest                                                                                       |
| unique_copy_if(beg, end, dest, binaryPred) | binaryPred 替代 ==                                                                                         |
|                                            |                                                                                                            |
| rotate(beg, mid, end)                      | beg, mid, end -> mid, end, beg, mid – 1，返回beg                                                           |
| rotate_copy(beg, mid, end, dest)           | 旋转后的存入dest                                                                                           |
|                                            |                                                                                                            |

| 重排算法                     | 要求双向迭代器 birectional iterator |
| :--------------------------- | :---------------------------------- |
| reverse(beg, end)            | 翻转序列，返回void                  |
| reverse_copy(beg, end, dest) | 翻转后存入dest                      |


| 重排算法                        | 要求随机访问迭代器 random access iterator                   |
| :------------------------------ | :---------------------------------------------------------- |
| random_shuffle(beg, end)        | 猴排，返回void                                              |
| random_shuffle(beg, end, rand)  | rand为可调用对象，接受整型值，返回0到此值得均匀分布随机整数 |
| shuffle(beg, end, Uniform_rand) | Uniform_rand必须满足均匀随机数生成器的要求                  |


| 排列算法                                     | 要求双向迭代器 bidirectional iterator                         |
| :------------------------------------------- | :------------------------------------------------------------ |
| 字典递增序列                                 | abc, acb, bac, bca, cab, cba                                  |
| next_permutation(beg, end)                   | 将序列排成字典序下个排列，如果已经最大，则重排为最小的排列    |
| next_permutation(beg, end, comp)             |                                                               |
|                                              |                                                               |
| prev_permutation(beg, end)                   | 将序列排成字典序上个排列，如果已经最小，则重排为最大的排列    |
| prev_permutation(beg, end, comp)             | comp 替换 ==                                                  |
|                                              |                                                               |
| is_permutation(beg1, end1, beg2)             | 如果beg2的元素是输入范围的一个排列，则返回true，不然返回false |
| is_permutation(beg1, end1, beg2, binaryPred) | binaryPred 替换 ==                                            |


| 集合算法，都可以用comp替换<                          | 要求输出迭代器 output iterator             |
| :--------------------------------------------------- | :----------------------------------------- |
| includes(beg, end, beg2, end2)                       |                                            |
| includes(beg, end, beg2, end2, comp)                 | comp 替换 <                                |
|                                                      |                                            |
| set_union(beg, end, beg2, end2, dest)                | 求并集，创建有序序列                       |
| set_intersection(beg, end, beg2, end2, dest)         | 求交集，创建有序序列                       |
| set_difference(beg, end, beg2, end2, dest)           | 对第一个序列有第二个没有的元素创建有序序列 |
| set_symmetric_difference(beg, end, beg2, end2, dest) | 对只出现在一个序列中的元素创建有序序列     |


| 最大最小值算法           |                         | 要求输入迭代器 input iterator           |
| :----------------------- | :---------------------- | :-------------------------------------- |
| min(val1, val2)          | min(init_list)          | 返回最小值                              |
| min(val1, val2, comp)    | min(init_list, comp)    | comp 替换 <                             |
|                          |                         |                                         |
| max(val1, val2)          | max(init_list)          | 返回最大值                              |
| max(val1, val2, comp)    | max(init_list, comp)    | comp 替换 <                             |
|                          |                         |                                         |
| minmax(val1, val2)       | minmax(init_list)       | 返回一个pair，first最小值，second最大值 |
| minmax(val1, val2, comp) | minmax(init_list, comp) | comp 替换 <                             |


| 最大最小值算法                                        | 要求输出迭代器 output iterator                                                                       |
| :---------------------------------------------------- | :--------------------------------------------------------------------------------------------------- |
| min_element(beg, end)                                 | 返回最小值的迭代器                                                                                   |
| min_element(beg, end, comp)                           | comp 替换 <                                                                                          |
|                                                       |                                                                                                      |
| max_element(beg, end)                                 | 返回最大值的迭代器                                                                                   |
| max_element(beg, end, comp)                           | comp 替换 <                                                                                          |
|                                                       |                                                                                                      |
| minmax_element(beg, end)                              | 返回一个pair，first为最小值的迭代器，second为最大值的迭代器                                          |
| minmax_element(beg, end, comp)                        | comp 替换 <                                                                                          |
|                                                       |                                                                                                      |
| lexicographical_compare(beg1, end1, beg2, end2)       | 比较两个序列，根据第一对不相等元素的大小返回值，若小于返回true，若长度不等，则较短序列在字典序中更小 |
| lexicographical_compare(beg1, end1, beg2, end2, comp) | comp 替换 <                                                                                          |


| 数值算法<numeric>                                     | 要求输入迭代器 input iterator                                                   |
| :---------------------------------------------------- | :------------------------------------------------------------------------------ |
| accumulate(beg, end, init)                            | 累积和，初值由init指定，返回类型等同于init类型，binaryOp 替换 +                 |
| accumulate(beg, end, init, binaryOp)                  | 若容器为double类型，将累计和设为0（不是0.0），则会将和累计到int上…              |
|                                                       |                                                                                 |
| inner_product(beg1, end1, beg2, init)                 | 求内积，对应元素乘积之和，binOp1 替换 +， binOp2 替换 *                         |
| inner_product(beg1, end1, beg2, init, binOp1, binOp2) |                                                                                 |
|                                                       |                                                                                 |
| partial_sum(beg, end, dest)                           | dest中新元素的值等于该位置与之前位置所有元素的累积和，返回dest，binaryOp 替换 + |
| partial_sum(beg, end, dest, binaryOp)                 |                                                                                 |
|                                                       |                                                                                 |
| adjacent_difference(beg, end, dest)                   | dest中新元素的值等于输入范围中该元素与前一个位置之差，binaryOp 替换 -           |
| adjacent_difference(beg, end, dest, binaryOp)         |                                                                                 |
|                                                       |                                                                                 |
| iota(beg, end, val）                                  | 将val，val + 1, val + 2….写入序列                                               |
