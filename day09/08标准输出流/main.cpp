#include <iostream>
#include <iomanip>
/*
cout.flush()//刷新流缓冲区  Linux下有效
cout.put()   //向缓冲区写字符
cout.write()  //从buf中写num个字节到当前输出流中
*/
using namespace std;

void test01(void) {
	cout.put('c');
	cout.put('a') << endl;
	cout.put('a').put('b') << endl;

	char buf[1024] = "hello world";
	cout.write(buf, strlen(buf));
}

void test02(void) {
	int num = 10;
	cout.width(20);//增加空格
	cout.fill('/');//空格用 / 代替
	cout.setf(ios::left);//设置格式  输入内容做到对齐
	cout.unsetf(ios::dec);//卸载十进制
	cout.setf(ios::hex);//安装十六进制
	cout.setf(ios::showbase);//强制输出整数基数0  0x


	cout << num << endl;
}

int main(void) {
	//test01();
	test02();
	return 0;
}
