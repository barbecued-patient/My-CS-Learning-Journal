#include <stdio.h>
int main()
{
	int x=100;
	
	int i;
	int isPrime=1;
	for(x=100;x>0;x--){
		isPrime=1;
	for(i=2;i<x;i++){
		if(x%i==0){
		isPrime=0;
		break;
		}
	}
	if(isPrime==1){
		printf("%d\n",x);
	}

}
	
	return 0;
}
