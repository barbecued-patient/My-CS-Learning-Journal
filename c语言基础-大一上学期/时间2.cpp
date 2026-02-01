#include <stdio.h>
 
 int main()
 {
 	int time1=0;
 	int time2=0;
 	scanf("%d %d",&time1,&time2);
 	int time3=0;
 	int time4=0;
 	time3=(time1/100)*60+time1%100+time2;
 	time4=(time3/60)*100+time3%60;
 	printf("%d",time4);
 	return 0;
 	
 	
 	
 }
