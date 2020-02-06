#include <iostream>

using namespace std;

class Anmials {
public:
	virtual void sepak() {
		cout << "动物说话" << endl;
	}
	//多态中   普通的析构是不会调用子类的析构的   所以可能会导致释放不干净   
	//利用虚析构解决这个问题
	//~Anmials() {
	//	cout << "Anmials析构" << endl;
	//}

	////虚析构
	//virtual ~Anmials() {
	//	cout << "Anmials析构" << endl;
	//}

	//纯虚析构
	//纯虚析构  与 纯虚函数  不同     
	//不仅需要声明 还有需要实现   （类内声明 类外实现）
 	virtual ~Anmials() = 0;
	//如果类中出现纯虚析构函数  这个类也是 抽象类   该类不能实例化
};

//纯虚析构函数  类内声明  类外实现
 Anmials :: ~Anmials() {
	 cout << "Anmials 纯虚析构析构" << endl;
}

class Cat :public Anmials {
public:
	char * name_;
	Cat(const char * name) {
		this->name_ = new char[strlen(name) + 1];
		strcpy(this->name_,name);
	}
	virtual void sepak() {
		cout << "Cat说话" << endl;
	}
	~Cat()
	{
		cout << "Cat 析构" << endl;
		if (this->name_ != NULL) {
			delete[] this->name_;
			this->name_ = NULL;
		}
	}
};


void test01(void) {
	Anmials * cat = new Cat("Tom");
	cat->sepak();

	delete cat;   //调用的是 anmials 析构  没有释放干净  这时候需要 虚析构

	//抽象类 不能实例化
	//Anmials a;
	//Anmials *an = new Anmials;

}

int main(void) {
	test01();
	return 0;
}