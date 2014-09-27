#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "queue.h"

struct runway
{
	bool vacant; 
	int timeTilVacant;
	QueueData planeUsing;
};
typedef struct runway Runway;

int main(int argc, char* argv[])
{
	int i = 0;
	const int MAX = 1000;
	int numPlanesAirQ;
	int numPlanesGroundQ;
	
	QueuePtr airQ;
	QueuePtr groundQ;
	QueueData airplane;
	Runway runway;
	
	double arrivalAirProb;
	double arrivalGroundProb;
	int timeDuration;
	double randomAir; 
	double randomGround;
	int randomID;
	time_t start;

	srand(time(NULL));

	printf("\n          AIRPORT QUEUE SIMULATION\n");
	printf("====================================================\n");
	printf("\n1. Set the air arrival probablility\n");
	printf("   Enter decimal between 0 and 1: ");
	scanf("%lf", &arrivalAirProb);

	printf("\n2. Set the ground arrival probablility\n");
	printf("   Enter decimal between 0 and 1: ");
	scanf("%lf", &arrivalGroundProb);

	printf("\n3. Set the duration of the simulation\n");
	printf("   Enter integer (seconds) between 1 and 20: ");
	scanf("%d", &timeDuration);
	printf("\n====================================================\n");

	// initialize an air Queue
	airQ = initQueue();

	//initialize a ground Queue
	groundQ = initQueue();

	//initialize the runway
	runway.vacant = true;
	runway.timeTilVacant = 2;
			
	start = time(NULL);

	for (i = 0; i < timeDuration; i++)
	{
		printf("------------- Elapsed time: %.2f seconds -----------\n\n", (double)(time(NULL) - start));

		sleep(1);

		randomAir = (double)(rand() % MAX) / MAX;
		randomGround = (double)(rand() % MAX) / MAX;
		
		//one plane may or may not join the AIR queue
		if(randomAir < arrivalAirProb)
		{
			randomID = rand() % 999;
			airplane = randomID;
			enqueue(airQ, airplane);
			printf("Flight no. %d joined the AIR queue.\n", airplane);
		} 

		//a second plane may or may not join the AIR queue
		if(randomAir < arrivalAirProb*arrivalAirProb)
		{
			randomID = rand() % 999;
			airplane = randomID;
			enqueue(airQ, airplane);
			printf("Flight no. %d joined the AIR queue.\n", airplane);
		} 

		//one plane may or may not join the GROUND queue
		if(randomGround < arrivalGroundProb)
		{
			randomID = rand() % 999;
			airplane = randomID;
			enqueue(groundQ, airplane);
			printf("Flight no. %d joined the GROUND queue.\n", airplane);
		}
		
		printf("\n");

		numPlanesAirQ = getSize(airQ);
		airplane = getFront(airQ);
		printf("%d flights waiting in the air \n", numPlanesAirQ); 
		//printf("\tNext to land: Flight no. %d\n", airplane);
		
		numPlanesGroundQ = getSize(groundQ);
		airplane = getFront(groundQ);
		printf("%d flights waiting on the ground.\n", numPlanesGroundQ); 
		//printf("\tNext to take off: Flight no. %d\n", airplane);

		printf("\n");

		// if the runway is empty
		if(runway.vacant == true)
		{ 
			// if there is nothing in the air queue
			if(isEmpty(airQ) && !isEmpty(groundQ))
			{
				airplane = dequeue(groundQ);
				runway.vacant = false;
				runway.planeUsing = airplane;
				printf("Flight no. %d is taking off\n", airplane);
				printf("2 seconds until runway vacancy...\n");
				sleep(runway.timeTilVacant);
				runway.vacant = true;
				printf("\n\t\t\t\tRunway is now vacant.\n");
			}
			else if (!isEmpty(airQ))
			{	
				airplane = dequeue(airQ);
				runway.vacant = false;
				runway.planeUsing = airplane;
				printf("Flight no. %d is landing\n", airplane);
				printf("2 seconds until runway vacancy...\n");
				sleep(runway.timeTilVacant);
				runway.vacant = true;
				printf("\n\t\t\t\tRunway is now vacant.\n");
			}
			else if(!isEmpty(airQ) && isEmpty(groundQ))
			{
				runway.vacant = true;
				printf("The runway is vacant.\n");
			}	

		printf("\n");

		numPlanesAirQ = getSize(airQ);
		airplane = getFront(airQ);
		printf("%d flights waiting in the air \n", numPlanesAirQ); 
		//printf("\tNext to land: Flight no. %d\n", airplane);
		
		numPlanesGroundQ = getSize(groundQ);
		airplane = getFront(groundQ);
		printf("%d flights waiting on the ground.\n", numPlanesGroundQ); 
		//printf("\tNext to take off: Flight no. %d\n", airplane);

		printf("\n");	
		}
	}

	destroyQueue(airQ);
	destroyQueue(groundQ);

	return 0; 
}