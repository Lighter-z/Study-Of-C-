#include <stdio.h>

int main(void) {
	
	extern const int a;  //  ���߱��������ⲿ���� test.c�ж���   
	printf("a = %d\r\n", a);

	return 0;
}
