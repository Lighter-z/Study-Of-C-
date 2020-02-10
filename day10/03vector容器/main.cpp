#include <iostream>
//支持随机访问 跳跃式
#include <vector>
//不支持跳跃式访问
#include <list>

using namespace std;
/*
vector<T> v; //采用模板实现类实现 默认构造函数
vector(v.begin(), v.end());  //将v[v.begin(), v.end()]区间中的元素拷贝给本身
vector(n, elm);  //构造函数 将n个elm拷贝给本身
vector(const vector & vec);  //拷贝构造函数

例子：
int arr[] = {1, 1, 2 ,3};
常用赋值操作
vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));  //第一个元素   最后一个元素的下一个位置

常用赋值操作
assign(beg, end);  //将[beg, end]区间中的数据拷贝给本身
assign(n, elm);  //将n个elm拷贝给本身
vector& operator = (const vector & vec);  //重载等号操作符
swap(vec);  //将vec与本身的元素进行互换

大小操作
sizeof();  //返回容器中元素个数
empty();  //判断容器是否为空
resize(int num);  //重新指定容器长度为num  若容器变长，则默认值填充新位置；若容器变短，则末尾超出容器长度的元素被删除
resize(int num, elm);  //重新指定容器长度为num，  若容器变长，则使用elm填充新位置，若容器变短，则删除超出容器长度的元素
capacity();  //容器容量
reserve(int len);  //容器预留len个元素长度，预留位置不初始化，元素不可访问
*/

void test01(void) {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		cout << v.capacity() << endl;  //v.capacity()容器的容量
	}

}

void printVector(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it;
	}
	cout << endl;
}
void test02() {
	vector<int> v1;
	int arr[] = { 10, 20, 30, 40 };

	vector<int> v2(arr, arr + sizeof(arr) / sizeof(arr[0]));//第一个元素  最后一个元素的下一个位置
	vector<int> v3(v2.begin(), v2.end());
	printVector(v2);
	printVector(v3);

	vector<int> v4(5, 40);
	printVector(v4);

	vector<int> v5(v4);
	printVector(v5);

	v5.assign(v2.begin(), v2.end());
	printVector(v5);
	v4.assign(5, 10);
	printVector(v4);

	v3 = v4;
	printVector(v3);
	v2.swap(v3);
	printVector(v2);

	cout << v2.size() << endl;
	vector<int> v6;
	cout << v6.empty() << endl;  //空返回1
	cout << v6.size() << endl;  //0
	cout << "容量：" << v6.capacity() << endl;

	v6.resize(10);
	cout << v6.size() << endl;  //10
	cout << "容量：" << v6.capacity() << endl;
	v6.resize(20, 1);
	printVector(v6);
	
	v6.resize(15, 2);
	printVector(v6);
}

//巧用swap收缩空间
void test03(void) {
	vector<int> v1;
	for (int i = 0; i < 10000; i++) {
		v1.push_back(i);
	}
	cout << "v1的容量：" << v1.capacity() << endl;  //12138
	cout << "v1的大小：" << v1.size() << endl;  //10000

	v1.resize(3);
	cout << "v1的容量：" << v1.capacity() << endl;  //12138
	cout << "v1的大小：" << v1.size() << endl;  //3 
	//大小变小了  容量没有变  会造成资源浪费

	//巧用swap
	vector<int>(v1).swap(v1);
	cout << "v1的容量：" << v1.capacity() << endl;  //3
	cout << "v1的大小：" << v1.size() << endl;  //3 
	/*
	解释：vector<int>(v1).swap(v1);
		vector<int> (v1)//初始换匿名对象
		.swap()  //v1和匿名对象交换指针指向的地址   匿名对象指向v1的地址   v1指向匿名对象的地址
		这行代码结束后 匿名对象就会被回收  之前的12138的空间也就被回收了
	*/

}

/*
vextor数据存储操作
at(int index);  //返回索引index所指向的数据  如果越界，抛出out_of_rang异常
operator[];  //返回index所指向的数据  越界直接报错
front();  //返回容器中第一个数据
back();  //返回容器中最后一个数据

插入和删除操作
insert(const_iterator pos, int count, ele);  //迭代器指向位置pos插入count个元素ele
push_back(ele);  //尾部插入元素ele
pop_back();  //删除尾部最后一个元素
erase(const_iterator start, const_iterator end);  //删除迭代器 start 到 end之间的元素
erase(const_iterator pos);  //删除迭代器指向的元素
clear();//删除容器中所有元素
*/

void test04(void) {
	vector<int> v1;
	v1 = { 1,2,3 };
	
	cout << v1[2] << endl;
	cout << v1.front() << endl;
	cout << v1.back() << endl;

	v1.push_back(10);
	cout << v1.back() << endl;

	v1.insert(v1.begin(),100);
	cout << v1.front() << endl;
	printVector(v1);

	v1.insert(v1.begin(), 2, 100);
	printVector(v1);

	v1.pop_back();
	cout << v1.back() << endl;

	v1.erase(v1.begin());

	v1.erase(v1.begin(), v1.end());

	v1.clear();
}

//逆序遍历
//reverse_iterator  逆序迭代器
void test05(void) {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	//正序遍历
	printVector(v1);

	//逆序遍历
	//reverse_iterator  逆序迭代器
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++) {
		cout << *rit;
	}
	cout << endl;

	//vector迭代器是随机迭代器  支持跳跃式访问
	vector<int>::iterator itBegin = v1.begin();
	itBegin += 3;
	//如果上述写法不报错 则这个迭代器是随机访问迭代器

	//list不是随机迭代器
	list<int> l;
	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}
	list<int>::iterator LitBegin = l.begin();
	//l += 3;
	//报错  list所以不是随机迭代器
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}
