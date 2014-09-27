#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

int main(int argc, char* argv[])
{
	QueuePtr Q;
	char answer = 'n';
	int numIntegers;
	QueueData integer;
	int i = 1;
	int qSize;

	printf("\n----------- Testing initQueue() Function -----------\n");
	printf("\nInitialize a queue? (y/n): ");
	scanf(" %c", &answer);

	if(answer == 'y')
	{
		Q = initQueue();
		printf("\nQueue has been initialized.\n");		
	}
	else
	{
		printf("\nWell... that was boring. Byeybye!\n\n");
		return 0;
	}

	printf("\n----------- Testing isEmpty() Function -----------\n");
	printf("\nTest if queue is empty? (y/n): ");
	scanf(" %c", &answer);

	if(answer == 'y')
	{
		if(isEmpty(Q))
			printf("\nThe queue is empty.\n");
		else
		{
			printf("\nThe queue is not empty.\n");
			printf("There are %d items in the queue.\n", Q->size);
		}

	}

	printf("\n----------- Testing enqueue() Function -----------\n");
	printf("\nAdd items to the queue? (y/n): ");
	scanf(" %c", &answer);

	if(answer == 'y')
	{
		printf("\nHow many items (integers, please) would you like to add to the queue? ");
		scanf("%d", &numIntegers);
		printf("\n");

		for (i = 1; i <= numIntegers; i++)
		{
			printf("Enter integer number %d: ", i);
			scanf("%d", &integer);
			enqueue(Q, integer);
		}
	}

	printf("\nTest if queue is empty? (y/n): ");
	scanf(" %c", &answer);

	if(answer == 'y')
	{
		if(isEmpty(Q))
			printf("\nThe queue is empty.\n");
		else
		{
			printf("\nThe queue is not empty.\n");
			printf("There are %d items in the queue.\n", Q->size);
		}
	}

	printf("\n----------- Testing getFront() Function -----------\n");
	printf("\nCheck the item at the front of the queue? (y/n): ");
	scanf(" %c", &answer);

	if(answer == 'y')
	{
		integer = getFront(Q);
		printf("The item at the front of the queue is: %d\n", integer);
	}

	printf("\n----------- Testing dequeue() Function -----------\n");
	printf("\nRemove items from the queue? (y/n): ");
	scanf(" %c", &answer);

	while (answer == 'y')
	{
		printf("\nHow many items would you like to remove from the queue? ");
		scanf("%d", &numIntegers);
		printf("\n");

		for (i = 0; i < numIntegers; i++)
		{
			integer = dequeue(Q);
			printf("%d removed from queue.\n", integer);
			if(isEmpty(Q))
			{
				printf("Halting further attempts to dequeue.\n");
				break;
			}
		}

		qSize = getSize(Q);
		printf("There are now %d items left in the queue.\n", qSize);
		
		printf("\nRemove items from the queue? (y/n): ");
		scanf(" %c", &answer);
	}

	printf("\nTest if queue is empty? (y/n): ");
	scanf(" %c", &answer);

	if(answer == 'y')
	{
		if(isEmpty(Q))
			printf("\nThe queue is empty.\n");
		else
		{
			printf("\nThe queue is not empty.\n");
			printf("There are %d items in the queue.\n", Q->size);
		}
	}
	printf("\n");

	destroyQueue(Q);
	printf("Queue has been emptied and destroyed. Byebye!\n\n");

	return 0; 
}