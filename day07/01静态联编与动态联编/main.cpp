#include <iostream>

//静态多态：  函数重载
//动态多态：  虚函数继承
//静态联编：  编译阶段绑定地址
//动态联编：  地址晚绑定，运行时候绑定地址
//多态： 父类的引用或者指针，指向子类

using namespace std;

//静态联编
class Animal1 {
public:
	void speak(void) {
		cout << "动物说话" << endl;
	}
};

class Cat :
	public Animal1 {

public:
	void speak(void) {
		cout << "猫说话" << endl;
	}
};

//动态联编
class Animal2 {
public:
	virtual void speak(void) {
		cout << "动物说话" << endl;
	}
};

class Dog :
	public Animal2 {
public:
	void speak(void) {
		cout << "狗说话" << endl;
	}
};

class Sheep :
	public Animal2 {
public:
	void speak(void) {
		cout << "羊说话" << endl;
	}
};

// 静态联编   
//调用doSpeak   doSpeak函数地址早都绑定好了    （在编译阶段就确定好了地址）      //早绑定     静态联编   
void doSpeak1(Animal1 & animal) {
	animal.speak();
}

//调用cat.speak()  就不能提前绑定函数，要在运行时候再去确定要绑定函数地址
//动态联编  doSpeak()函数改为虚函数   在父类上声明虚函数（virtual）  发生了多态  
//多态： 父类的引用或者指针，指向子类
void doSpeak2(Animal2 & animal) {     //Animal2 & animal = cat
	animal.speak();
}


void test01(void) {
	Cat cat;
	Dog dog;
	Sheep sheep;
	//如果发生了继承  编译器允许发生类型转换
	doSpeak1(cat);   //猫说话
	doSpeak2(dog);   //狗说话
	doSpeak2(sheep);  //羊说话

	//父类指针指向子类
	Animal2 *animal = new Dog;
	animal->speak();
}

int main(void) {
	test01();
	return 0;
}