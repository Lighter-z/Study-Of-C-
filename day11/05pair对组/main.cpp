#include <iostream>
#include <string>
using namespace std;

void test01(void) {
	//��һ�ִ�����ʽ
	pair<string, int> p("����", 5);
	cout << "���֣�" << p.first << endl;
	cout << "���䣺" << p.second << endl;

	//pair�ڶ��ִ�����ʽ
	pair<string, int> p2 = make_pair("����", 80);
	cout << "���֣�" << p2.first << endl;
	cout << "���䣺" << p2.second << endl;

}

int main() {
	test01();
	return 0;
}
