## 常见算法

`partition`

- ifLeft可以传入可调用对象
- 使用small (left)来进行交换排序

```c++
swap(A[pivot], A[back]);
small = -1;
for (int i = 0; i <= back; ++i) {
	if(IsLeft(A[i], A[back])) {
		if(i != small) {
			++small;
			swap(A[small], A[i]);
		}
	}
}
	
```

使用双指针
```c++
while(beg != end) {
	if(isLeft && beg != end)
		++beg;
	if(!isLeft && beg != end)
		--end;
	if(beg != end)
		swap(*beg, *end);
}
```


`std::stable_partition`

std::stable_partition is a adaptive algorrithm which contain 2 algorithm as follows:
1. "faster" O(n) std::__stable_partition_adaptive
	- use a buffer to store the elements and replace them all
2. "slower" O(n*logn) std::__inplace_stable_partition
	- use a count to bubble all the non-left elements


`Gcd : Greatest common divisor`

Gcd(a, b) = Gcd(b, a % b);  
在座标里，将点(0, 0)和(a, b)连起来，通过整数座标的点的数目（除了(0, 0)一点之外）就是gcd(a, b)  

`Lowest Common Multiple`
Lcm(a,b) = a * b / gcd(a, b);  


`permutation`
```c++
void Permutation(string &s, size_t sz) {
	if(sz == s.size()) 
		cout << s << endl;
	else {
		for(int i = sz; i < s.size(); ++i) {
			swap(s[i], s[sz]);
			Permutation(s, sz+1);
			swap(s[i], s[sz]);
		}
	}
}
```

`八皇后问题`

Permutation全排列  
	
```c++	
vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7}; // index为横，排列后的为竖行，保证横竖不同行
for(int i = 0; i < vi.size(); ++i) {
	for(int j = 0; j < vi.size(); ++j) {
		if(abs(i - j) != abs(vi[i] - vi[j])) // 判断对角线
			flag = false; 
	}
} 
```



## 位运算
位运算
- 负值采用补码，右移会在高位补1
- 检测最右位为1（某位为1）：a & 0x01 == 1
- (n-1) & (n) 可以消去n的最右位1
	- 判断是否为2的整数次方 ：(n-1) & (n) == 0
	- 计算m与n的二进制位差：异或然后count1



`取平均值`
```c++
int x, int y;
int i = (x & y) + ((x ^ y) >> 1);
// x & y 相同的位保留
// x ^ y 保留不同的位，再右移1位，等于除以2
// 等同于取平均值（相同的位隐式除2）
```

`加法`
```c++
int Add(int a, int b) {
	int sum, carry;
	while(b) {
		sum = a ^ b;
		carry = (a & b) << 1;
		a = sum;
		b = carry;
	}
	return sum;
}
```
异或的可以直接加的位，与后左移的则是进位


`swap`
```c++
int a = 0x09;  // 0x0000 1001
int b = 0xa5;  // 0x1010 0101
int c = a ^ b; // 0x1010 1100
int a ^= c;    // 0x1010 0101
int b ^= c;    // 0x0000 1001
```

`双重取反操作switch`
```c++
int n = 100;
int arr[2] = {0, 0};
arr[!!n] += n; // 在n==0时自动切换到arr[0]，其他时候调用arr[1]
```

`if内变量交给编译器判断`
```c++
char a;
if ( 'c' == a) 
如果将 == 输成 =，编译器会提示常量无法赋值
```	

`求max`
```c++
int max = ((a + b) + abs(a - b)) / 2;
```

`swap`

```c++
	#define swap(a, b)\
	{\
		char tempBuf[10];\
		memcpy(tempBuf, &a, sizeof(a));\
		memcpy(&a, &b, sizeof(b));\
		memcpy(&b, tempBuf, sizeof(b));\
	}
```

`swap2`

```c++
	a = a + b;
	b = a - b;
	a = a - b;
```
`swap3`

```c++
	a = a ^  b;
	b = b ^ a;
	a = a ^ b;
```	
`三数排序`

```c++
If(a>b) swap(a,b);
If(a>c) swap(a,c);
If(b>c) swap(b,c);
```
