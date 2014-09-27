#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
 
int main(void)
{
	time_t start = time(NULL);
	printf("%.2f\n", (double)(time(NULL) - start));
	sleep(3);
	printf("%.2f\n", (double)(time(NULL) - start));
 
  return 0;
}