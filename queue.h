
typedef int QueueData;

typedef struct node
{	
	QueueData data;
	struct node *next;
} Node, *NodePtr;

typedef struct queue
{
	NodePtr head;
	NodePtr tail;
	int size;
} QueueType, *QueuePtr;

//Precondition: none
//Postcondition: A queue has been initialized in memory
QueuePtr initQueue();

//Precondition: A queue is initialized and accessible
//Postcondition: (1) Returns true if empty
//				 (2) Returns false if not empty
bool isEmpty(QueuePtr Q);

//Precondition: A queue is initialized and accessible
//Postcondition: An item is added to the tail of the queue
void enqueue(QueuePtr Q, QueueData d);

//Precondition: A queue is initialized and accessible
//Postcondition: (1) An item is removed from the head of the queue
//				 (2) Returns the data that was in that head
QueueData dequeue(QueuePtr Q);

//Precondition: A queue is initialized and accessible
//Postcondition: The data in the head node is returned
QueueData getFront(QueuePtr Q);

//Precondition: A queue is initialized and accessible
//Postcondition: The size of the queue is returned
int getSize(QueuePtr Q);

//Precondition: A queue is initialized and accessible
//Postcondition: Queue has been destroyed
void destroyQueue(QueuePtr Q);
