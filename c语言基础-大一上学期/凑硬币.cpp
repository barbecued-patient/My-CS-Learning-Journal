#include <stdio.h>
int main()
{
	int x;
	int one,two,five;
	int exit=0;
	scanf("%d",&x);
	for(one=1;one<x*10;one++){
		for(two=1;two<x*10/2;two++){
			for(five=1;five<x*10/5;five++){
				if(one+two*2+five*5==x*10){
					printf("可以用%d个一角加%d个2角加%d个5角得到%d元\n",one,two,five,x);
					exit=1; 
					break;
				}
			}
			if(exit==1)break;
		}
		if(exit==1)break;
	}
	return 0;
}
/*就是说如果我想让他只生成一种方案就行，
那在printf后加break?.不行 ，因为break只能跳出一个循环
那在所有循环里都加break?也不行，因为外层循环直接跳出。
故引入变量exit 
“接力break”*/
