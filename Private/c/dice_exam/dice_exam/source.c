#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	int naCount[6] = { 0, };
	double fTable = 0, fVariance = 0, fStandard = 0;
	int nSettings, i = 0;
	srand(time(NULL));
	
	printf("[O]Input >> ");
	scanf("%d", &nSettings);

	while (i < nSettings)
	{
		int nNum = (rand()%6) +1;
		
		switch (nNum)
		{
		case 1:
			naCount[0]++;	break;
		case 2:
			naCount[1]++;	break;
		case 3:
			naCount[2]++;	break;
		case 4:
			naCount[3]++;	break;
		case 5:
			naCount[4]++;	break;
		case 6:
			naCount[5]++;	break;
		default:
			break;
		}
		i++;
	}

	printf("***\t\t\t\t***\n");
	for (int a = 0; a < 6; a++)	printf("%d\t", naCount[a]);
	putchar('\n');

	for (int a = 0; a < 6; a++)
	{
		fTable += ((a+1) * ((double)naCount[a] / (double)nSettings));
	}
	printf("Expectation: %f\n", fTable);
	for (int a = 0; a < 6; a++)
	{
		fVariance += (pow(((double)a + 1 - fTable), 2) * ((double)naCount[a] / (double)nSettings));
	}
	printf("Variance: %f\n", fVariance);

	fStandard = sqrt(fVariance);
	printf("Standard: %f\n", fStandard);
}