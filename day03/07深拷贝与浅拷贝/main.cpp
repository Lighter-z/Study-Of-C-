#include <iostream>
#include <string>

using namespace std;

class Person {
public:
	Person() { }
	Person(char *name, int age) {
		p_name = (char *)malloc(strlen(name) + 1);  //+1  是应为有 \0
		strcpy(p_name,name);
		p_age = age;
	}
	/*拷贝构造 系统会提供默认的 但是 是 简单的拷贝构造
	自己提供拷贝构造    原因简单的浅拷贝会释放堆空间两次  导致程序挂掉
	深拷贝*/
	Person(const Person & p) {
		p_age = p.p_age;
		p_name = (char *)malloc(strlen(p.p_name) + 1);
		strcpy(p_name, p.p_name);
	}

	~Person()
	{
		cout << "析构函数" << endl;
		if (p_name != NULL) {
			free(p_name);
			p_name = NULL;
		}
	}

	char *p_name;
	int p_age;
};

void test01() {
	Person p1("敌法",10);

	Person p2(p1);
}

int main() {
	test01();
	return 0;
}

