#include <stdio.h>
int main()
{
	int M,N;
	scanf("%d %d",&M,&N);
	
	int cnt=0;
	int sum=0; 
	for(int i=M;i<=N;i++) {
		int panduansushu=1;
		for(int j=2;j<M-1;j++){ 
			if(i%j==0){
				panduansushu=0;
				break;
			}
		}
		if(panduansushu==1){
			cnt++;
			sum+=i;
		}
	}
	printf("%d %d",cnt,sum);
	
	return 0;
}
