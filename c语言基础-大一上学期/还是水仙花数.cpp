#include <stdio.h> 
int main() 
{

	int n;
	scanf("%d",&n);
	int first=1;
	int i=1;
	while(i<n){
		first*=10;
		i++; 
	}
	
	for(int i=first;i<first*10;i++){
		int num=i;
		int sum=0;
		while(num>0){
			int digit=num%10;
			int a=1;
			for(int j=1;j<=n;j++){
				a*=digit;
			}
			num/=10;
			sum+=a;
		}
		if(sum==i){
			printf("%d\n",sum);
	}
}
	return 0;

}
