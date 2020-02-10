#include <iostream>
#include <string>
//vector容器
#include <vector>
//使用系统算法头文件
#include <algorithm>
using namespace std;

//迭代器 遍历功能 用指针理解
//普通指针也是一种迭代器
void test01(void) {
	int array[5] = { 1,3,5,7,9 };
	int *p = array;
	
	for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) {
		//cout << array[i] << endl;
		cout << *(p++) << endl;
	}

}

//for_each()的回调函数
void myPrint(int v) {
	cout << v << endl;
}

//vector容器
void test02(void) {
	//创建容器
	vector<int> v; //声明一个容器   这个容器中存放int类型数据 对象名称是v
	//尾插法  向容器中插入数据
	v.push_back(0);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//迭代器
	vector<int>::iterator itBegin = v.begin();//itBegin指向 v容器中的起始位置
	vector<int>::iterator itEnd = v.end();//itEnd指向 v容器中最后一个位置的下一个位置

	//第一种遍历方法
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}
	
	//第二种遍历方法
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
	//	cout << *it << endl;
	//}

	//第三种  利用算法遍历
	for_each(v.begin(), v.end(), myPrint);  // myPrint回调函数
}

//-----------------------------------操作自定义数据类型
class Person {
public:
	int age_;
	string name_;
	Person() {};
	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}
};

void myPringPerson(Person & p) {
	cout << p.name_ << " " << p.age_ << endl;
}

void test03(void) {
	vector<Person> vp;
	Person p1("张三", 55);
	Person p2("李四", 8);
	Person p3("王五", 5);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);

	//for (vector<Person>::iterator it = vp.begin(); it != vp.end(); it++) {
	//	cout << (*it).name_ << " " << it->age_ << endl;
	//}

	for_each(vp.begin(), vp.end(), myPringPerson);
}

void myPringPerson04(Person * p) {
	cout << p->name_ << " " << p->age_ << endl;
}
void test04(void) {
	vector<Person *> vp;
	Person p1("张三", 55);
	Person p2("李四", 8);
	Person p3("王五", 5);

	vp.push_back(&p1);
	vp.push_back(&p2);
	vp.push_back(&p3);

	//for (vector<Person * >::iterator it = vp.begin(); it != vp.end(); it++) {
	//	cout << (*it)->name_ << " " << (*it)->age_ << endl;
	//}

	for_each(vp.begin(), vp.end(), myPringPerson04);
}

//容器嵌套容器
void test05(void) {
	vector<vector<int>> v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	for (int i = 0; i < 5; i++) {
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 20);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator vit = it->begin(); vit != (*it).end(); vit++) {
			cout << *vit << endl;
		}
	}
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}
