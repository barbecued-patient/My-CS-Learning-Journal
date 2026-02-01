#include <stdio.h> 
int main()
{
	int x;
	scanf("%d",&x);
	int first=1;
	int i=1;
	while(i<x){
		first*=10;
		i++;
	}
	for(int i=first;i<first*10;i++){
		int num=i;
		int sum=0;
		while(num>0){
			int digit=num%10;
			int a=1;
			for(int cnt=0;cnt<x;cnt++){
				a*=digit;
			}
			sum+=a;
			num/=10; 
		}
		if(sum==i){
			printf("%d\n",sum);
		}
		
	}
	
	return 0;
}
