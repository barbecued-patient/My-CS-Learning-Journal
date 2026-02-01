#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() 
{
    srand(time(NULL));
    int random_number = rand() % 100 + 1;//随机生成一个1-100的数，ds搞得 
    int n;
    scanf("%d",&n);//读取限制次数 
    
    int cnt=0;
    int guess;
    do{
    	scanf("%d",&guess);
    	if(guess<0){
    		printf("Gmae Over\n");
    		break;
		}
    	if(guess==random_number){
    		printf("Lucky You!\n");
		}else if(guess<random_number){
			printf("Too Small\n") ;
		}else if(guess>random_number){
			printf("Too Big\n");
		}
		cnt++;
	} while(cnt<3) ;
	
	do{
    	scanf("%d",&guess);
    	if(guess<0){
    		printf("Game Over\n");
    		break;
		}
    	if(guess==random_number){
    		printf("Good Guess\n");
    		break;
		}else if(guess<random_number){
			printf("Too Small\n") ;
		}else if(guess>random_number){
			printf("Too Big\n");
		}
		cnt++;
	} while(cnt<n) ;
	
	if(cnt==n){
		printf("Game over\n");
	}
	
	return 0;
	}
	
	/*大体可以，但有一个逻辑问题，还有一个问题，就是如果一开始我给的初始次数
	限制是2次，那到2次的时候它还在第一个循环里，并不会停止
	ds给的改进是：第一阶段：最多3次猜测，但不能超过总次数n
    int first_phase_limit = (n < 3) ? n : 3; 
    但是我看不懂
	
	简洁代码：
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL));
    int random_number = rand() % 100 + 1;
    int n;
    scanf("%d", &n);
    
    int cnt = 0;
    int guess;
    
    while(cnt < n) 
    {
        scanf("%d", &guess);
        
        if(guess < 0) {
            printf("Game Over\n");
            break;
        }
        
        if(guess == random_number) {
            // 根据猜测次数决定输出消息
            if(cnt < 3) {
                printf("Lucky You!\n");
            } else {
                printf("Good Guess\n");
            }
            break;
        } else if(guess < random_number) {
            printf("Too Small\n");
        } else {
            printf("Too Big\n");
        }
        
        cnt++;
        
        // 检查是否用完所有次数
        if(cnt >= n) {
            printf("Game Over\n");
        }
    }
    
    return 0;
} 
一个循环搞定，因为小于三次和大于三次只有在猜对的时候输出有区别，
把猜对情况合在一起，其它直接else就行了 
