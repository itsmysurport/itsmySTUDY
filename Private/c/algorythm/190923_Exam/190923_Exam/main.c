/*
	오늘의 문제: 1부터 100까지의 자연수 중 소수를 모두 고르시오.
*/

#include <stdio.h>

int main(void)
{
	int i;
	printf("%3d", 2);
	for (i = 3; i <= 100; i += 2)
	{
		if (isThe(i))
			printf("%3d", i);
	}
}

int isThe(int n)
{
	int a;
	if (n == 1)	return 0;
	for (a = 3; a <= (n / 2 + 1); a+= 2)		
	{
		if ( !(n % a))
			return 0;
	}
	return 1;
}
