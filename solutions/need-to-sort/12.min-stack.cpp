#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
public:
	MinStack() {}

	void push(int number) {
		s.push(number);
		if (m.empty())
			m.push(number);
		else {
			m.push(std::min(m.top(), number));
		}
	}

	int pop() {
		int t = s.top();
		s.pop();
		m.pop();
		return t;
	}

	int min() {
		return m.top();
	}
private:
	stack<int> s;
	stack<int> m;
};