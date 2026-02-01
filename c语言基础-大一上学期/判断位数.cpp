#include <stdio.h>
int main()
{
	int x;
	int n=1;
	
	scanf("%d",&x);
	
	if(x>999){//用大于判断从高处往低处走 
		n=4;
	}else if(x>99){
		n=3;
	}else if(x>9){
		n=2;
	}else if(x>0){
		n=1;
	}
	
	printf("%d",n);
	
	return 0;
}
