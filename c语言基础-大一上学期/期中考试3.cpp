#include <stdio.h> 
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int cnt=0;
	for(int i=0;i<=n-3*m;i++){
		for(int j=0;j<=n-3*m-i;j++){
			int k= n-3*m-i-j;
				if(i<=j&&j<=k){
					cnt++;
				}
			}
		}
	printf("%d",cnt);
	return 0;
}
