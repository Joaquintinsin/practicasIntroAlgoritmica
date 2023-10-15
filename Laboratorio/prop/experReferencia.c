#include <stdio.h>

int a;
void a1(int *p1);

int main() {
	a = 4;
	a1(&a);
	return 0;
}

void a1(int *p1){
	*p1 = 10;
	printf("%d \n",a);
}

