#include <iostream>
#include <string>

//真正开发中 开闭原则
//对扩展开放  对修改关闭

//多态
//结构性好   利于后期维护扩展  可读性高
//效率低 发生多态 内部结构复杂

using namespace std;
class Calculator {
private:
	int value1;
	int value2;
public:
	void setValue(int a, int b) {
		this->value1 = a;
		this->value2 = b;
	}
	int getResult(string opera) {
		if (opera == "+") {
			return this->value1 + this->value2;
		}
		else if (opera == "-") {
			return this->value1 - this->value2;
		}
	}
};

void test01(void) {
	Calculator c1;
	c1.setValue(10, 10);
	cout << c1.getResult("+") << endl;
	cout << c1.getResult("-") << endl;

}

//利用多态实现：
class AbstrictCalculator{
public:
	//虚函数
	//virtual int getResult() { return 0; }

	//纯虚函数：
	//1、如果父类中有了纯虚函数  子类继承父类必须实现纯虚函数！！！
	//2、如果父类中有了纯虚函数   父类就不能实例化对象！！！！！
	//3、这个类有了纯虚函数   就成为了  抽象类   （抽象类不允许实例化对象）
	virtual int getResult() = 0;

	void setValue(int a, int b) {
		this->value1 = a;
		this->value2 = b;
	}
	int getValue1() {
		return value1;
	}
	int getValue2() {
		return value2;
	}
private:
	int value1;
	int value2;
};

class AddCalculator : public AbstrictCalculator {
public:
	//1、如果父类中有了纯虚函数  子类继承父类必须实现纯虚函数！！！
	virtual int getResult() {        //virtual  可写可不写
		
		return getValue1() + getValue2();
	}
};

class SubCalculator : public AbstrictCalculator {
public:
	virtual int getResult() {        //virtual  可写可不写

		return getValue1() - getValue2();
	}
};

void test02(void) {
	AbstrictCalculator * abc = new AddCalculator;
	abc->setValue(20,20);
	cout << "多态" << endl;
	cout << abc->getResult() << endl;

	delete abc;
	abc = new SubCalculator;
	cout << abc->getResult() << endl;

	//2、如果父类中有了纯虚函数   父类就不能实例化对象！！！！！
	//AbstrictCalculator *a = new AbstrictCalculator;
}



int main(void) {
	test01();
	test02();
	return 0;
}