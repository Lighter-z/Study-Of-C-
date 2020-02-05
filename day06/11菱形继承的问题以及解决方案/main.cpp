//菱形继承会出现 继承空间重复 造成浪费
//       动物
// 羊            骆驼
//       羊驼
//羊 与 骆驼 都继承的有 age 
//羊驼继承时候 会继承两次 age  造成空间浪费

//菱形 解决方案：虚继承   virtual
//操作的是共享的一份数据
#include <iostream>
#include "SheepTuo.h"

using namespace std;

void test01() {
	SheepTuo st;
	st.Sheep::age_ = 10;
	st.Tuo::age_ = 20;
	cout << st.Sheep::age_ << endl;
	cout << st.Tuo::age_ << endl;

	//虚继承后 没有二义性问题了
	//可以直接以下操作
	cout << st.age_ << endl;

}

int main() {
	test01();
	return 0;
}


