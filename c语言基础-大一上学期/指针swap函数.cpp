#include <stdio.h>

void swap(int *pa,int *pb){
	int t=*pa;
	*pa=*pb;
	*pb=t;
}

int main() 
{
	int a;
	int b;
	scanf("%d %d",&a,&b);
	swap(&a,&b);
	printf("%d %d",a,b);
	return 0;
}

//之前说过，不用指针变量是不能做swap函数的，原因是swap需要返回多个值 
