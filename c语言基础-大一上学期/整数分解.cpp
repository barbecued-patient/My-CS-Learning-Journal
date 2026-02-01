#include <stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int t=x;//如果第一个while循环就用x，那x就被消耗掉了，要引入t来辅助。 
	int mask=1; 
	while(t>9){
		t/=10;
		mask*=10;
	}//若用do-while，则个位数时mask也循环一次，等于10，故应先判断后循环。 
	
	//指数函数int mask=pow(10,cnt-1);
	
	do{
		int d=x/mask;
		printf("%d",d);
		if (mask>0){
			printf(" ");
		}
		x%=mask;
		mask/=10;
	}while(mask>0);
	
	
	return 0;
}
