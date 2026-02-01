#include <stdio.h>

int subRemainder(int num,int k)
{
	int sub1,sub2,sub3;
	sub1=num/100;
	sub3=num%1000;
	sub2=(num%10000)/10;
	if(sub1%k==sub2%k&&sub2%k==sub3%k){
		return 1;
	}else{
		return 0;
	}
}

int main()
{
	int a,b,k,i;
	scanf("%d%d%d",&a,&b,&k);
	for(i=a;i<=b;i++){
		if(subRemainder(i,k)){
			printf("%d\n",i);
		}
	}
	return 0;
}
