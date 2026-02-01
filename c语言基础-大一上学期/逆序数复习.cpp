#include <stdio.h> 
int main()
{
	int x;
	scanf("%d",&x);
	int a=0;
	while(x>0){
		a=x%10;
		x=x/10;
		printf("%d",a);
	}
	while(x>0){
		a=x%10;
		x=x/10;
		printf("%d",a);
	}
	return 0;
}
