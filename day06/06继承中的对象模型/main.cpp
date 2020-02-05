#include <iostream>
#include <string>


using namespace std;

class Base {
public:
	int a_;
protected:
	int b_;
private:
	int c_;
};

//子类中确实继承了  c_  但是编译器 把c_隐藏了  访问不到
class Son1 : public Base {
public:
	int d_;
	void func() {
		b_ = 10;
	}

};

void test01(void) {
	cout << sizeof(Son1) << endl;    //大小为16   私有属性的变量也包含在里面
}

int main(void) {
	test01();
	return 0;
}
