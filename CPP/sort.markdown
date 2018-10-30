<details><summary></summary>


```cpp



```

</details>


基本结构体
struct A {
	short a1;
	short a2;
	short a3;
};

struct B {
	long a1;
	short a2;
};

struct K {
	int a;
	char r[7];
	short b;
};

struct A {
	char* cp;
	char c;
	// char[3] pad;
	int x;
};	// 12
struct B {
	int i;
	bool b1;
	bool b2;
};	// 8


位域




虚继承

//sizeof(K) == 16

// 空类型，虚继承的空类的大小
class A { };	// 1
class B { };	// 1
class C : public virtual B {}; // 4
class D : public A, public B {}; // 1
class E { virtual ~E() {} }; // 4
// 虚继承和虚函数都会建立虚表，类中存储指向虚表的指针

联合体

union
{
	unsigned char a;
	unsigned int i;
}u;