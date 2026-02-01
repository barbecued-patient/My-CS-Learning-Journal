#include <stdio.h>

int main()
{
	int sum=0;
	int count=0;
	int number;
	do{
		scanf("%d",&number);
		if (number!=-1){
			sum+=number;
			count++;
		}
	} while(number!=-1);//while后面应该是循环的条件 
	printf("平均数是%f\n",1.0*sum/count);//做浮点运算，1.d 改成 f，2.算式里乘以1.0变成浮点运算 
	return 0;
}
//这里其实可以运行了，但是因为number！=1判断了两次，很费，所以还可以改进 

