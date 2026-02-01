#include <stdio.h>

int pingfang(int n)
{   
    int ret=0;
	for(int i=1;i*i<=n;i++){
		if(i*i==n){
			ret=1;
		}
	}
	return ret;
}

int huiwen(int n) 
{
	int reverse;
	int temp=n;
	int digit;
	for(int i=1;temp>0;i++){
		digit=temp%10;
		reverse=reverse*10+digit;
		temp/=10;
		}
	if(reverse==n){
		return 1;
	}else{
		return 0;
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	if(huiwen(a)&&pingfang(a)){
		printf("Yes");
	}else{
		printf("No");
	}
	return 0;
}
