#include <stdio.h>
#include <string.h>
struct Person {
	char name[64];
	int age;
};

void PeopleEat(struct Person *p) {
	printf("%s�Է�\r\n",p->name);
}

void test01() {
	struct Person p1;
	
	strcpy(p1.name,"����");

	PeopleEat(&p1);
}

int main() {
	test01();
	return 0;
}
