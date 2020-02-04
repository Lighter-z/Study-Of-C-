#include <stdio.h>

int main(void) {
	
	extern const int a;  //  告诉编译器在外部定义 test.c中定义   
	printf("a = %d\r\n", a);

	return 0;
}
