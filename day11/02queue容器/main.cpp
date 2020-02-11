#include <iostream>
#include <queue>
using namespace std;
/*
队列 先进先出  不能遍历 没有迭代器
queue构造函数
queue<T> queT;  //采用类模板实现  默认构造函数
queue(const queue & que);  //拷贝构造函数


存取 插入 删除操作
push(elem);  //在队尾添加数据elem
pop();  //删除对头第一个元素
back();  //返回最后一个元素
front();  //返回第一个元素

赋值操作
queue & operator=(const queue & que);  //重载等号运算符

大小操作
empty();  //判断是否为空
size();  //返回队列大小
*/

void test01(void) {
	queue<int> q1;
	q1.push(10);
	q1.push(20);
	q1.push(30);
	q1.push(40);

	cout << "队尾元素：" << q1.back() << endl;

	while (!q1.empty()) {
		cout << "队列大小：" << q1.size() << "  队头元素：" << q1.front() << "队尾元素：" << q1.back() << endl;
		q1.pop();
	}
}

int main() {
	test01();
	return 0;
}
