#include <stdio.h> 
int main()
{
	int x;
	scanf("%d",&x); 
	int digit;
	
	while(x>0){
		digit=x%10;
		x/=10;
		printf("%d",digit);
	}
	
	
	return 0;
}
