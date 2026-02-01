#include <stdio.h>

int main()
{
	int sum=0;
	int count=0;
	int number;
	
	scanf("%d",&number);
	while(number!=-1) {
		sum+=number;
		count++;
		/*如果单纯这样的话就死循环了，因为 我们注意到，
	在while循环中，我们使用了一个条件：number != -1。
	但是，在循环内部，我们并没有更新number的值。
也就是说，如果第一次输入的number不是-1，那么循环条件
一直满足，会一直执行循环体，而循环体内并没有再次读取
输入，所以number的值不会改变，导致死循环。正确的做法
是在循环体内也需要读取下一个数字，以便在下次循环条件
判断时能够根据新的输入决定是否继续循环。
修改方法：在循环体内添加scanf语句，让每次循环都能读取
一个新的数字。
1.用哪个循环？2.循环的条件是什么？*/
    scanf("%d",&number);
	}
		
	printf("平均数是%f\n",1.0*sum/count);
	return 0;
}
