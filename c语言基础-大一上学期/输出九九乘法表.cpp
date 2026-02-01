#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			printf("%d×%d=%d",j,i,i*j);//不用再定义k=i*j 
			if(i*j<10) {
				printf("  ");//对齐 
			}else{
				printf(" ");//对齐 
			}
		}
		printf("\n");
	}
	return 0;
}
