#include <iostream>
#include <string>
using namespace std;
//���ǶԶ���ĳ���
//�����Ƕ����ʵ��
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
		cout << "������" << name << " ѧ�ţ�" << id << endl;
	}
};

void test01() {
	Student st;
	st.SetID(10);
	st.SetName("����");
	cout << st.id << st.name << endl;
	st.ShowInfo();
}

int main() {
	test01();
	return 0;
}
