#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int fact=1;
	int i=1;
	for(i=1;i<=n;i++){//初始动作；循环继续的条件；循环每轮要做的动作 
		fact*=i;
	}	
	/*总结
语句	位置	职责	类比
i++	for 的括号 () 内	控制循环流程：为下一次循环做准备	工人送走产品，清空工作台
fact *= i	for 的循环体 {} 内	实现核心功能：完成本轮循环的具体任务	工人组装产品
所以，它们一个在括号里，一个在括号外，不是因为谁更重要，而是因为它们承担着不同的职责。
这种语法规则是为了让代码结构更加清晰和严谨。*/


	printf("%d",fact);
	
	return 0;
}

//for==while
//for中每一个表达式可以省略：for(;条件;)
/*tips for loops:
1.如果有固定次数：用for
2.如果必须执行一次，用do-while
3.其他情况：用while 
