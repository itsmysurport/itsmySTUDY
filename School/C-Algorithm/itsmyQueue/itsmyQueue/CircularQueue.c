#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int QueuePush(int nData, int CircularQueue[], int *front, int *rear)
{
	if ((0 < nData && nData <= 100000))
	{
		*(rear) += 1;
		CircularQueue[*(rear)] = nData;
		return 0;
	}
	else
		return 1;
}

int QueuePop(int CircularQueue[], int* front, int* rear)
{
	printf("%d", CircularQueue[*(front)]);
	*(front) += 1;
}

int IsEmpty()