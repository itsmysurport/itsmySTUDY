#define _CRT_SECURE_NO_WARNINGS
#define QUEUE_SIZE 10000
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int front = 0, rear = 0;
int CircularQueue[QUEUE_SIZE] = { 0 };

int main()
{
	int nInput;
	char* pInput = (char*)malloc(sizeof(char) * 16);
	while (1)
	{
		memset(pInput, 0, sizeof(pInput));
		scanf("%s", pInput);

		if (!(strcmp(pInput, "push")))
		{
			scanf("%d", &nInput);
			if (QueuePush(nInput, CircularQueue, front, rear))
				printf("ERROR\n");
			continue;
		}
		scanf("%d");

		if (!(strcmp(pInput, "pop")))
			QueuePop(CircularQueue, front, rear);
		else if (!(strcmp(pInput, "rear")))
		else if (!(strcmp(pInput, "front")))
		else if (!(strcmp(pInput, "empty")))
		else if (!(strcmp(pInput, "size")))
	}
}

