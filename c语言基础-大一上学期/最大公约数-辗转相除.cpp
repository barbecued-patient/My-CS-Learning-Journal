#include <stdio.h>
int main()
{
	int a,b;
	int c=1;
	scanf("%d %d",&a,&b);
	if(b==0){//我老把等于写成赋值，==和=不要再搞混! 
		printf("最大公约数是%d",a);
	}else{
		while(c>0){
		c=a%b;
		a=b;
		b=c;
		}
		printf("最大公约数是%d",a);
	}
	return 0;
}
