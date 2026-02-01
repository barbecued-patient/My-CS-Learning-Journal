#include <stdio.h> 
int main()
{
	int n1;
	scanf("%d",&n1);
	int max=n1;
	for(int i=1;i<=9;i++){
		int n2;
		scanf("%d",&n2);
		if(max<n2){
			max=n2;
		}
	}
	printf("%d",max);
	return 0;
}
