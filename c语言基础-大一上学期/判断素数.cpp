#include <stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	
	int i;
	int isPrime=1;
	for(i=2;i<x;i++){
		if(x%i==0){//i=2的时候已经证明不是素数了，剩下的都浪费了，加break 
		 isPrime=0;
		 break;//break和continue的用法 
		}
	}
	if(isPrime==1){ 
	printf("是素数"); 
	} else{
		printf("不是素数");
	}
	return 0;
}
