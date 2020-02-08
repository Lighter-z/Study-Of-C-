#include <iostream>
/*
cin.get()                //读取缓冲区一个字符
cin.get(两个参数)       //不读取换行符
cin.getline()  //读取换行符并扔掉
cin.ignore(n);  忽略   //n 代表忽略的字符数  不写是一个
cin.peek()   偷窥      //  偷看一个字符，然后把数据放回缓冲区
cin.putback(c);  放回   //数据放回缓冲区

//案例1
//判断用户输入的是数字还是字符串？
*/
using namespace std;

void test01(void) {
	char c = cin.get();
	cout << c << endl;
}

//cin.get()   不会把换行符拿走
void test02() {
	char buf[1024];
	cin.get();
	char c = cin.get();
	if (c == '\n') {
		cout << "换行符还在缓冲区" << endl;
	}
	else {
		cout << "换行符不在缓冲区" << endl;
	}
	cout << buf << endl;
}

//cin.getline()   会把换行符读取 并扔掉
void test03() {
	char buf[1024];
	cin.getline(buf,1024);
	char c = cin.get();
	if (c == '\n') {
		cout << "换行符还在缓冲区" << endl;
	}
	else {
		cout << "换行符不在缓冲区" << endl;
	}
	cout << buf << endl;
}

//cin.ignore(n);  忽略   会把前 n 个读取到的字符忽略
//不带参数   忽略一个
void test04() {
	cin.ignore();
	char c = cin.get();
	cout << c << endl;
}

//cin.peek()   偷窥
void test05() {
	//输入as
	char c = cin.peek();  //看一了眼第一个数据 然后又把数据放回 缓冲区 了
	cout << c << endl;  //  打印  a
	c = cin.get();  //  拿到放回去那个数据
	cout << c << endl;  // 打印  a
}

//cin.putback(c);  放回
void test06(void) {
	//输入 hello world 
	char c = cin.get();   //拿到 h
	cin.putback(c);   //又把 h放回缓冲区

	char buf[1024];
	cin.getline(buf, 1024);   //拿到 hello world 
	cout << buf << endl;
}

//案例1
//判断用户输入的是数字还是字符串？
void test07(void) {
	cout << "请输入内容" << endl;
	char c = cin.peek();
	if (c > '0' && c < '9') {
		int num;
		cin >> num;
		cout << "您输入的是数字:" << num << endl;
	}
	else {
		char buf[1024];
		cin >> buf;
		cout << "您输入的是字符串：" << buf << endl;
	}
}

int main(void) {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
}
