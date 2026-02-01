#include <stdio.h> 
int main()
{
	int x;
	int cnt[10]={0};
	
	scanf("%d",&x);
	while(x!=-1){
		cnt[x]++;
		scanf("%d",&x);
	}
	
	for(int i=0;i<10;i++){
		printf("%d:%d\n",i,cnt[i]);
	}
	return 0; 
}
