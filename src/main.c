#include "main.h"

void tests()
{
	printf("=== TESTS ===\n");
	my_tab t = my_tnew();
	int a = 1, b = 2;
	my_tadd(t, &a);
	my_tadd(t, &b);
	printf("%d %d\n", *((int*)my_tget(t,0)), *((int*)my_tget(t, 1)));
	printf("%d %d %d\n", *((int*)my_tpop(t)), *((int*)my_tpop(t)), my_tlen(t));
	printf("%d %d\n", *((int*)my_tget(t,0)), *((int*)my_tget(t, 1)));
	printf("=============\n");
}

int main()
{
	tests();
	return 0;
}
