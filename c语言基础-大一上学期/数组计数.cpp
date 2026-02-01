#include <stdio.h>
int main()
{
	int x;
	int cnt[10]={0};//初始化 
	
	while(scanf("%d",&x)==1&&x!=-1){//必须把scanf放进来，否则不能每次读取一个 
		if(x>=0&&x<=9){
			cnt[x]++;
		}
	}
	for(int i=1;i<10;i++) {
		printf("%d:%d\n",i,cnt[i]);
	}
	return 0;
}
