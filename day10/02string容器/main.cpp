#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/*
string   构造函数
string() 创建一个空的字符串  例如 string str;
string(const string & str)  使用一个string对象初始化另一个string对象
string(congst char * s)  使用字符串s初始化
string(int n, char c)  使用n个字符初始化

基本赋值操作 
string& operator=(const char * s)  //char *类型字符串赋值给当前字符串
string& operator=(const string &s)  //把字符串s赋值给当前字符串
string& operator(char c)  //字符赋值给当前字符串
string& assign(const char * s)  //把字符串s赋值给当前字符串
string& assign(const cahr *s,int n) //把字符串s前n个字符赋值给当前字符串
string& assign(const string s)  //把字符串s赋值给当前字符串
string& assign(int n, char c)  //把n个字符c赋值给当前字符串
string& assign(const string &s, int start, int n)  //把s从start开始n个字符赋值给字符串
*/

/*
string 存取字符串
char& operator[](int n)  //通过[] 的方法获取字符
char& at(int n)  //通过at方法获取字符
[]与at区别：
[]访问越界会直接挂掉，at会抛出异常
*/

void test01(void) {
	string str1;//默认构造
	string str2(str1);//拷贝构造
	string str3 = str1;//拷贝构造另一种写法
	string str4("sss");//使用字符串初始化
	string str5 = "dddd";//使用字符串初始化
	string str6(10, 'a');//使用n个字符初始化

	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;

	//基本赋值
	cout << "------基本赋值------" << endl;
	str1 = "wer";
	str2 = str4;
	cout << str1 << endl;
	cout << str2 << endl;

	str3.assign("hello,world", 5);
	str4.assign(str1);
	str5.assign(5,'b');
	str6.assign("hello,world", 5, 10);
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;
}

/*
string 存取字符串
char& operator[](int n)  //通过[] 的方法获取字符
char& at(int n)  //通过at方法获取字符
[]与at区别：
[]访问越界会直接挂掉，at会抛出异常
*/
void test02() {
	string str1 = "abcdefg";
	cout << str1[3] << endl;
	cout << str1.at(3) << endl;
	cout << "------赋值------" << endl;
	str1[3] = 'a';
	cout << str1[3] << endl;
	cout << str1.at(3) << endl;
	//[]与at区别
	//[]访问越界会直接挂掉，at会抛出异常
	try {
		//cout << str1[10] << endl;    //直接挂掉
		cout << str1.at(10) << endl;
	}
	catch (out_of_range & e) {
		cout << e.what() << endl;
	}
	catch (...) {
		cout << "------越界异常------" << endl;
	}
}

/*
string拼接操作
string& operator+=(const string & str);//重载操作符+=
string& operator+=(const cahr * str);//
string& operator+=(const char c);
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const cahr *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string & s); //同 operator+=
string& append(const string & s,int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n,char c);//在当前字符串结尾添加n个字符c

string查找和替换
int find(const string & str, int pos = 0) const  //查找字符串str第一次出现的位置，从pos开始查找
int find(const cahr *s, int pos = 0) const  //查找s第一次出现的位置，从pos开始查找
int find(const char *s, int pos, int n) const  //从pos位置开始查找s的前n个字符第一次出现的位置
int find(const char c, int pos = 0) const  //查找字符c第一次出现的位置
int rfind(const string & str,int pos = npos) const  //查找str最后一次出现的位置 从pos开始
int rfind(const char * s, intn pos = npos) const  //查找s最后一次出现的位置 从pos开始查找
int rfind(const char *s, int pos, int n) const  //从pos开始查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0)const  //查找字符c最后一次出现位置
string& replace(int pos, int n, const string & str);  //替换从pos开始n个字符为str
string& replace(int pos, int n, const char *s);  //替换从pos开始的n个字符为字符串s
*/

//find从左往右找
//rfind从右往左找
void test03() {
	string s1 = "hello";
	string s2 = s1 + "world";
	cout << s2 << endl;

	s2.append(5, 'b');
	cout << s2 << endl;

	//find查找
	int index = s1.find("llo");  //找不到返回-1  find从左往右找
	cout << index << endl;     //  2
	index = s1.rfind("llo");  //找不到返回-1  从右往左找
	cout << index << endl;    //  2
	//替换
	s2.replace(3, 5, "555");
	cout << s2 << endl;

}
/*
string 比较操作
compare函数在>时返回1  <时返回-1  ==时返回0
比较区分大小写 比较时参考字典(ASIII表)顺序 排在前面的小
大写的A比小写的a小
int compare(const string & s) const;//与字符串s比较
int compare(const string char *) const
*/
void test04() {
	string s1 = "abc";
	string s2 = "1bc";
	if (s1.compare(s2) == 0) {
		cout << "相等" << endl;
	}
	else if (s1.compare(s2) == 1) {
		cout << "s1大于s2" << endl;
	}
	else {
		cout << "s1小于s2" << endl;
	}
}

/*
string substr(int pos = 0, int n = npos) const  //返回由pos开始的n个字符组成的字符串
*/
void test05(void) {
	string s1 = "abc";
	string s2 = s1.substr(1, 3);
	cout << "s2 = " << s2 << endl;

	string email = "mingzhao@163.com";
	int pos = email.find("@");
	string userName = email.substr(0, pos);
	cout << userName << endl;
}

/*
string插入和删除操作
string& insert(int pos. const char * s);  //插入字符串
string& insert(int pos, const string & str);  //插入字符串
string& insert(int pos, int n, char c);  //在指定位置插入n个字符 c
string& erase(int pos, int n = npos);  //删除从Pos开始的n个字符
*/
void test06(void) {
	string s1 = "0123456789";
	s1.insert(10, "abcd");
	cout << s1 << endl;
	s1.insert(14, "efg");
	cout << s1 << endl;
	s1.erase(10, 7);
	cout << s1 << endl;
}

/*
string 和 c-style字符串转换
*/

void func(string str)
{
	cout << str << endl;
}

void func2(char * str)
{
	cout << str << endl;
}

void test07() {
	string s1 = "123";

	const char * p = s1.c_str();
	cout << p << endl;

	string s2(p);
	cout << s2 << endl;
	//func2(s2);  //报错  不能string 隐式类型转换 char *

	func(p);//隐式类型转换为string
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
}
