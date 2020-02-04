#include <iostream>

using namespace std;

class ChairMan {
	//1.构造函数私有化
private:
	ChairMan() {
		cout << "创建ChairMan 默认构造函数" << endl;
	}
	ChairMan(const ChairMan &cm) {
		
	}
//public:
	static ChairMan *singleMan;
public:
	//提供get方法访问 主席
	static ChairMan *getInstance() {
		return singleMan;
	}
};

ChairMan *ChairMan::singleMan = new ChairMan;

void test0() {
	//ChairMan::singleMan;        //static ChairMan *singleMan;  为public时候
	//ChairMan::singleMan = NULL;    //当static ChairMan *singleMan为public时候  会有人对其操作，，
	//为了避免这种情况，使得他为私有，通get方法调用
	ChairMan *cm1 = ChairMan::getInstance();
	ChairMan *cm2 = ChairMan::getInstance();
	if (cm1 == cm2) {
		cout << "相同" << endl;  //static 静态变量  共享数据
	}

	//ChairMan *cm3 = new ChairMan(*cm2);   //拷贝构造 是 public 时候
	//if (cm1 == cm3) {
	//	cout << "相同" << endl;
	//}
	//else {
	//	cout << "不相同" << endl;  //为了避免不相同的情况  需要把  拷贝构造  函数私有化
	//}

}

int main() {
	cout << "main调用" << endl;  //创建ChairMan 默认构造函数  优先于  main调用
	test0();
	return 0;
}
