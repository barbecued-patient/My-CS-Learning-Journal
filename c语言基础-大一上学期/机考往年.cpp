#include<stdio.h>
#include<math.h>

int main()
{
	int l,c;
	scanf("%d %d",&l,&c);
	printf("*");
	for(int m=1;m<=c;m++)
	  printf("--+--*");
	printf("\n");
	for(int i=1;i<=2*l;i++)
	{
		printf("*");
		for(int k=1;k<=c;k++)
		  printf("  *  *");
		printf("\n");
		printf("*");
		for(int j=1;j<=c;j++)
		  printf("--+--*");
		printf("\n");
	}
	return 0;
}
