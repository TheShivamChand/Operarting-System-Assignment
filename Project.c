#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
sem_t sema;
int hop=0;
struct traffic
{
int North, South, East, West;
};

void *NorthToEast();
void *NorthToWest();
void *NorthToSouth();
void *SouthToEast();
void *SouthToWest();
void *SouthToNorth();
void *EastToWest();
void *EastToNorth();
void *EastToSouth();
void *WestToEast();
void *WestToNorth();
void *WestToSouth();

int main()
{
	printf("\n\t\t\t****************************************");
	printf("\n\t\t\t*                                      *");
	printf("\n\t\t\t*     Traffic Intersection Problem     *");
	printf("\n\t\t\t*                                      *");
	printf("\n\t\t\t*      Made By- Shivam Chand Deopa     *");
	printf("\n\t\t\t*      Roll No.- B43                   *");
	printf("\n\t\t\t*      Reg No.- 11605417               *");
	printf("\n\t\t\t*      Section- K1607                  *");
	printf("\n\t\t\t****************************************");
	
	struct traffic s,*t;
	t=&s;
	sem_init(&sema,0,1);
	pthread_t v1, v2, v3, v4;
	t->East=0,t->West=1,t->North=2, t->South=3;
A:
while(5>3){
	int src = rand()%4, dest = rand()%4, ch, c;
	if(src==dest)
	goto A;		
	printf("\nYour Source is %d\n", src);
	printf("\nYour Destination is %d\n", dest);
	ch = src;
	sleep(1);
	switch(ch)
	{
	case 0:
		if(src == t->East && dest == t->West)
		{
			pthread_create(&v1, NULL, EastToWest, NULL);
			pthread_join(v1, NULL);
		}
		else if(src == t->East && dest == t->North)
		{
			pthread_create(&v1, NULL, EastToNorth, NULL);
			pthread_join(v1, NULL);
		}
		else if(src == t->East && dest == t->South)
		{
			pthread_create(&v1, NULL, EastToSouth, NULL);
			pthread_join(v1, NULL);
		}
		break;
	case 1:
		if(src == t->West && dest == t->North)
		{
			pthread_create(&v2, NULL, WestToNorth, NULL);
			pthread_join(v2, NULL);
		}
		else if(src == t->West && dest == t->South)
		{
			pthread_create(&v2, NULL, WestToSouth, NULL);
			pthread_join(v2, NULL);
		}
		else if(src == t->West && dest == t->East)
		{
			pthread_create(&v2, NULL, WestToEast, NULL);
			pthread_join(v2, NULL);
		}
		break;
	case 2:	
		if(src == t->North && dest == t->East)
		{
			pthread_create(&v3, NULL, NorthToEast, NULL);
			pthread_join(v3, NULL);
		}
		else if(src == t->North && dest == t->South)
		{
			pthread_create(&v3, NULL, NorthToSouth, NULL);
			pthread_join(v3, NULL);
		}
		else if(src == t->North && dest == t->West)
		{
			pthread_create(&v3, NULL, NorthToWest, NULL);
			pthread_join(v3, NULL);
		}
		break;
	case 3:		
		if(src == t->South && dest == t->West)
		{
			pthread_create(&v4, NULL, SouthToWest, NULL);
			pthread_join(v4, NULL);
		}
		else if(src == t->South && dest == t->East)
		{
			pthread_create(&v4, NULL, SouthToEast, NULL);
			pthread_join(v4, NULL);
		}
		else if(src == t->South && dest == t->North)
		{
			pthread_create(&v4, NULL, SouthToNorth, NULL);
			pthread_join(v4, NULL);
		}
		break;
	case 4:
		exit(0);
	default:
		printf("\nPlease choose a valid choice\n");
	}
hop++;
if(hop==9){
break;}
}
}
void *NorthToEast()
{
sem_wait(&sema);
printf("\nHeading Towards East from North\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}
void *NorthToWest()
{
sem_wait(&sema);
printf("\nHeading Towards West from North\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}
void *NorthToSouth()
{
sem_wait(&sema);
printf("\nHeading Towards South from North\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}

void *SouthToEast()
{
sem_wait(&sema);
printf("\nHeading Towards East from South\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}
void *SouthToWest()
{
sem_wait(&sema);
printf("\nHeading Towards West from South\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}
void *SouthToNorth()
{
sem_wait(&sema);
printf("\nHeading Towards North from South\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}

void *EastToWest()
{
sem_wait(&sema);
printf("\nHeading Towards West from East\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}
void *EastToNorth()
{
sem_wait(&sema);
printf("\nHeading Towards North from East\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}
void *EastToSouth()
{
sem_wait(&sema);
printf("\nHeading Towards South from East\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}

void *WestToEast()
{
sem_wait(&sema);
printf("\nHeading Towards East from West\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}
void *WestToNorth()
{
sem_wait(&sema);
printf("\nHeading Towards North from West\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}
void *WestToSouth()
{
sem_wait(&sema);
printf("\nHeading Towards South from West\n");
printf("\n*****************************");
sleep(1);
sem_post(&sema);
}
