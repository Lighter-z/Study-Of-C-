#include <iostream>
#include <string>
using namespace std;
//类是对对象的抽象
//对象是对类的实例
class Student {
public:
	string name;
	int id;

	void SetName(string n) {
		name = n;
	}
	void SetID(int i) {
		id = i;
	}

	void ShowInfo() {
		cout << "姓名：" << name << " 学号：" << id << endl;
	}
};

void test01() {
	Student st;
	st.SetID(10);
	st.SetName("张三");
	cout << st.id << st.name << endl;
	st.ShowInfo();
}

int main() {
	test01();
	return 0;
}
