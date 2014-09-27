#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

QueuePtr initQueue()
{
	QueuePtr qp = (QueuePtr)malloc(sizeof(QueueType));
	qp->head = NULL;
	qp->tail = NULL;
	qp->size = 0;
	return qp;
}

bool isEmpty(QueuePtr Q)
{
	if (Q->head == NULL)
		return true;
	else
		return false;
}

void enqueue(QueuePtr Q, QueueData d)
{
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np->data = d;
	np->next = NULL;

	if(isEmpty(Q))
	{
		Q->head = np;
		Q->tail = np;
		Q->size = 1;
	}
	else
	{
		Q->tail->next = np;
		Q->tail = np;
		++Q->size;
	}
}

QueueData dequeue(QueuePtr Q)
{
	QueueData dequeuedDataHolder = NULL;

	if (!isEmpty(Q))
	{
		dequeuedDataHolder = Q->head->data;
		NodePtr temp = Q->head;
		Q->head = Q->head->next;
		--Q->size;

		if(Q->head == NULL)
		{
			Q->tail = NULL;
			Q->size = 0;
		}

		free(temp);
		return dequeuedDataHolder;
	}
	else
		printf("\t(Queue is already empty)\n\n");

	return dequeuedDataHolder;
}

QueueData getFront(QueuePtr Q)
{
	if(Q->head == NULL)
	{
		Q->tail = NULL;
		Q->size = 0;
		return 0;
	}
	else
		return Q->head->data;
}

int getSize(QueuePtr Q)
{
	if(Q->head == NULL)
	{
		Q->tail = NULL;
		Q->size = 0;
	}
	return Q->size;
}

void destroyQueue(QueuePtr Q)
{
	if(isEmpty(Q))
	{
		Q->tail = NULL;
		free(Q);
		return;
	}
	else
	{
		while(Q-> head != NULL)
		{
			dequeue(Q);
		}
		
		free(Q);
		return;
	}
}