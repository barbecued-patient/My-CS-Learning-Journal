#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int fact=1;
	int i=1;
	while(i<=n){
		fact*=i;
		i++;
	}
	printf("%d",fact);
	
	return 0;
}

/*这一版是我自己写的，比翁恺少用了一个变量，但造成瑕疵
翁恺：
#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int fact=1;
	int i=1;使用一个单独的计数器，不会改变n，后面还能输出n 
	while(i<=n){
		fact*=i;从1乘到n 
		i++;
	}
	printf("%d",fact);
	
	return 0;
} 
*/
