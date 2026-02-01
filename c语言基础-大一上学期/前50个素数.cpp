#include <stdio.h>
int main()
{
	int x=0;
	int cnt=0;
	int i;
	int isPrime=1;
	for(x=2;cnt<50;x++){
		isPrime=1;
	for(i=2;i<x;i++){
		if(x%i==0){
		isPrime=0;
		break;
		}
	}
	if(isPrime==1){
		cnt++; 
		printf("%d\n",x);
	}

}
	
	return 0;
}
