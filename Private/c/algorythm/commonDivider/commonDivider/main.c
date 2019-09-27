#include <stdio.h>

int main(void)
{
	int nNum = 96, nNumm = 36;
	int originNum = nNum, originNumm = nNumm;
	int r;

	while (r = nNum % nNumm)
	{
		nNum = nNumm;
		nNumm = r;
	}
	printf("[The greatest common divisor of %d and %d is] .. : %d \n" ,originNum, originNumm, nNumm);
	printf("[The least common multiple of %d and %d is] .. : %d \n", originNum, originNumm, (originNum * originNumm)/ nNumm);
	/*
	int md = (nNum < nNumm ? nNum : nNumm) / 2;
	int a, nTotal;

	for (a = 1; a <= md; a++)
	{
		if (!(nNum % a) && !(nNumm % a))
			nTotal = a;
	}

	print("[The greatest common divisor of %d and %d is] .. : %d", nNum, nNumm, nTotal);
	*/
}