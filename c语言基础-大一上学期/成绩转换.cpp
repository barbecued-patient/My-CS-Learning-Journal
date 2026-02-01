#include <stdio.h>
int main()
{
	int score=0;
	scanf("%d",&score);
	int score1=0;
	score1=score/10;
	switch(score1){
	case 10:
	case 9://case 10和case 9可以放到一起！ 
		printf("A");
		break;
	case 8:
	    printf("B");
	    break;
	case 7:
	    printf("C");
	    break;
	case 6:
	    printf("D");
	    break;	
	default:
	    printf("E");
	    break;
	}
	
	return 0;
}

//问题：不符合单一出口原则。字符串？数组？ 
