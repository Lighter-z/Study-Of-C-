#include <stdio.h>

//1.全局变量检测增强
int a;
int a = 10;

//2.函数检测增强，参数类型检测增强，返回值增强
//不会出现报错
int getRect(w, h) {
	
}

void test02(void) {
	getRect(1, 2, 3);
}

//3.类型转换增强
void test03(void) {
	char *p = malloc(sizeof(64));//malloc返回值是 void *类型
}

//4.struct增强
struct Person{
	int m_age;
	//void addAge();//c语言中不能在结构体中增加函数
};

void test04(void) {
	struct Person p; //必须使用struct声明
}

//5.bool 布尔类型  c中没有
//bool a;

//6.三目运算符
//c++中返回的是变量
//c返回的是值
void test06(void) {
	int a = 10;
	int b = 20;
	
	printf("三目运算符 %d\r\n", a > b ? a : b);

	//c语言模仿c++
	*(a > b ? &a : &b) = 100;
	printf("c语言模仿c++三目运算符 a = %d b = %d\r\n", a,b);
}

//7.const增强   全局的受到保护不能像局部一样去修改
const int a_07 = 10;
void test07(void) {
	//a_07 = 100;  //报错 不能修改

	const int b = 10;      //伪常量
	//int m_b[b]; //不能用来初始化数组

	//b = 100;//报错 不能修改

	//绕过编译器 通过指针可以修改  这种方法只能修改局部的
	int *p = (int *)&b;
	*p = 200;
	printf("*p = %d \r\n  b = %d \r\n",*p,b);
}

int main(void) {
	test06();
	test07();
	return 0;
}
