#include <stdio.h>
int main()
{//只要超过十位数，就不对了 
	int x; 
	int n=0;
	scanf("%d",&x);
	n++;//n++的作用 
	x/=10;//这两行的必要性：试特殊数字，例如0。 
	while(x>0){
		//printf("hr\n");
		n++;
		x/=10;
		//printf("x=%d,n=%d" ,x,n);可以每一步告诉我结果 
	}
    printf("%d\n",n);
    return 0;
}
