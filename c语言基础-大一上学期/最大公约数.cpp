#include <stdio.h> 
int main()
{
	int a,b;
	int min;//简化运算
	scanf("%d %d",&a,&b) ;

	if(a<b){
		min=a;
	}else{
		min=b;
	}

	int ret=0;
	int i;
	
	for(i=1;i<=min;i++){
		if(a%i==0){
			if(b%i==0){//相等是== 
		       ret=i;
		}
	}//先写循环，再定义变量更直接。 
}
	printf("最大公约数为%d",ret);
	
	return 0;
}
