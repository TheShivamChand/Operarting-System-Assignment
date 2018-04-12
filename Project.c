#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t p;
int initiala,initialb,finala,finalb;

void *cara()
{
	
	pthread_mutex_lock(&p);
	
	initiala=rand()%4;
	
	finala=rand()%4;
	
	printf("\n\nInitial: %d",initiala);
	printf("\nFinal: %d",finala);
	
	if((initiala==initialb||finala==finalb)||(initiala==initialb||finala!=finalb)||(initiala==finalb||initialb==finala))
	{
		printf("\nSecond Car is entering Critical section");
		sleep(1);
	}
	else
	{
		printf("\nBoth cars are going to collide");
	}
	pthread_mutex_unlock(&p);
}

void *carb()
{
	pthread_mutex_lock(&p);
	
	initialb=rand()%4+1;
	
	finalb=rand()%4+1;
	
	printf("\n\n\nInitial: %d",initialb);
	printf("\nFinal: %d",finalb);
	
	if((initiala==initialb || finala==finalb)||(initiala==initialb||finala!=finalb)||(initiala==finalb|| initialb==finala))
	{
		printf("\nFirst Car is entering Critical section");
		sleep(1);
	}
	else
	{
		printf("\nBoth cars are going to collide");
	}
	pthread_mutex_unlock(&p);
}

char intro()
{
	printf("Operating Systems Assignment");
}
int main()
{
	intro();
	//system("cls");
	printf("\n\t\t\t****************************************");
	printf("\n\t\t\t*                                      *");
	printf("\n\t\t\t*                                      *");
	printf("\n\t\t\t*     Traffic Intersection Problem     *");
	printf("\n\t\t\t*                                      *");
	printf("\n\t\t\t*                                      *");
	printf("\n\t\t\t****************************************");
	
	pthread_mutex_init(&p,NULL);
	pthread_t x,y;
	pthread_create(&x,NULL,&cara,NULL);
	pthread_create(&y,NULL,&carb,NULL);
	pthread_join(x,NULL);
	pthread_join(y,NULL);
	
}
