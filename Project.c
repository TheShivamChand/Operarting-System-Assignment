#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<conio.h>

pthread_mutex_t p;
int initial1,initial2,final1,final2;

/*void *cara
{
	
}

void *carb
{
	
}*/

char intro()
{
	printf("Operating Systems Assignment");
}
int main()
{
	
	intro();
	getch();
	printf("\n\t\t\t****************************************");
	printf("\n\t\t\t*                                      *");
	printf("\n\t\t\t*                                      *");
	printf("\n\t\t\t*     Traffic Intersection Problem     *");
	printf("\n\t\t\t*                                      *");
	printf("\n\t\t\t*                                      *");
	printf("\n\t\t\t****************************************");
	
	pthread_t x,y;
	pthread_create(&x,NULL,&cara,NULL);
	pthread_create(&y,NULL,&carb,NULL);
	pthread_join(x,NULL);
	pthread_join(y,NULL);
	
}
