#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
int main()
{
	srand(time(0));
	int number=rand()%100+1;
	int count=0;
	int a=0;
	printf("我已经想好了一个1-100之间的数\n");
	do{
		printf("请猜");
		scanf("%d",&a) ;
	    count++;
		if (a>number){
			printf("大了"); 
		}else if(a<number){
			printf("小了");
		}
	}while(a!=number);//while()里应该是循环的条件
	printf("猜对了,你用了%d次",count);
	return 0;
	 
	  
}
