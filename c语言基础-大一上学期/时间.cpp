# include <stdio.h>
int main()
{
	int time1=0;
	scanf("%d",&time1);
	int time2=0;
	scanf("%d",&time2);
	int time3=(time1/100)*100+100*(time1%100+time2)/60+(time1%100+time2)%60;
	printf("%d",time3);
	return 0;
}
