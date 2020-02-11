#include <iostream>
#include <stack>
using namespace std;
/*
栈 先进后出  不能遍历 没有迭代器
stack构造函数
stack<T> s;  //stack采用类模板  默认构造
stack(const stack & stk);  //拷贝构造函数

赋值操作
stack& operator=(const stack & stk);  //重载等号操作符

数据存取操作
push(elem);  //向栈顶添加数据
pop();  //删除栈顶数据
top();  //返回栈顶数据

stack大小操作
empty();  //判断栈是否为空
size();  //返回栈的大小
*/

void test01(void) {
	stack<int> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);

	while (s1.empty() != true) {
		cout << "栈大小：" << s1.size() << " " << "栈顶数据：" << s1.top() << endl;
		s1.pop();
	}
	cout << "栈大小：" << s1.size() << endl;
}

int main() {
	test01();
	return 0;
}
