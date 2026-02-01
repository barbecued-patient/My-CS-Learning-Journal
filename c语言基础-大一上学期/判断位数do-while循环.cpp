#include <stdio.h>
int main()
{
	/*判断位数的while循环里，如果把上面两行删掉，要先检查是否
	符合条件，然后再进入循环，导致了0是0位数。do-while执行完
	一轮后，再回来检查 。*/
	int x;
	scanf("%d",&x);
	int n=0;
	do
	{
		x/=10;
	    n++;
	}while(x>0);
	printf("%d",n);
	 
	return 0;
}
