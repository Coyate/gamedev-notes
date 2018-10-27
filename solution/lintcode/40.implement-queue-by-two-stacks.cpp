/*!
*	@brief 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include <memory>
#include <stack>
using namespace std;

class MyQueue {
public:
	MyQueue() {
		// do intialization if necessary
		while (!stack1.empty())
			stack1.pop();
		while (!stack2.empty())
			stack2.pop();
	}

	/*
	* @param element: An integer
	* @return: nothing
	*/
	void push(int element) {
		stack1.push(element);
	}

	/*
	* @return: An integer
	*/
	int pop() {
		if (stack2.empty()) {
			stack1to2();
		}
		auto r = stack2.top();
		stack2.pop();
		return r;
	}

	/*
	* @return: An integer
	*/
	int top() {
		// write your code here
		if (stack2.empty()) {
			stack1to2();
		}
		if (!stack2.empty())
			return stack2.top();
		else
			return -1;
	}

private:
	void stack1to2() {
		int i = 0;
		while (!stack1.empty()) {
			i = stack1.top();
			stack1.pop();
			stack2.push(i);
		}
	}

	stack<int> stack1;
	stack<int> stack2;
};
