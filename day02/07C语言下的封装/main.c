#include <stdio.h>
#include <string.h>
struct Person {
	char name[64];
	int age;
};

void PeopleEat(struct Person *p) {
	printf("%s³Ô·¹\r\n",p->name);
}

void test01() {
	struct Person p1;
	
	strcpy(p1.name,"ÕÅÈı");

	PeopleEat(&p1);
}

int main() {
	test01();
	return 0;
}
