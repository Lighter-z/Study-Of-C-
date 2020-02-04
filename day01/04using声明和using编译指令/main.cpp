#include <iostream>

using namespace std;

namespace KingGlory {
	int sunwukongId = 10;
}

void test01(void) {
	int sunwukongId = 20;
	cout << sunwukongId << endl;

	//using声明
	//写了using声明后 下面这行代码说明以后看到的sunwukongId 都是用KingGlory下的数值
	//但是  编译器又有就近原则
	//二义性
	//所以注意避免二义性问题
	//using KingGlory::sunwukongId;
	cout << sunwukongId << endl;  //这样就无法生成了，程序报错，，，，using 声明导致“KingGlory::sunwukongId”的多次声明
}

//using编译指令
namespace LOL {
	int sunwukongId = 40;
}

void test02() {
#if 0
	int sunwukongId = 30;
	//using编译指令
	//就近原则 高于 打开房间
	using namespace KingGlory;  //打开房间
	cout << sunwukongId << endl; 
#else
	//如果打开多个房间，也要避免二义性
	using namespace KingGlory;  //打开房间
	using namespace LOL;  //打开房间
	cout << LOL::sunwukongId << endl;
#endif
}

int main(void) {
	
	test01();
	test02();
	return 0;
}

