#include <stdio.h>
 
 int main()
 {
 	int a=0;
 	scanf("%d",&a);
 	int b=0;
 	b=a/100+(a/10%10)*10+(a%10)*100;
 	printf("%d",b);
 	return 0;
 	
 }
