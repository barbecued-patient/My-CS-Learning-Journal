#include <stdio.h> 
#define SIZE 10
int main(void)
{
   int a[SIZE], i, p, num; 
   char s[10];

   // 往数组中前SIZE-1个元素赋值 
   printf("input %d numbers\n", SIZE-1); 
   for(i=0; i<=SIZE-2; i++) 
      scanf("%d",&a[i]);

	//输出数组
   printf("before insert, the array is:\n");  	
   for(i=0; i<=SIZE-2; i++)
      printf("%d\t", a[i]); 
      
 // 读入要插入的元素以及位置下标 
   fflush(stdin);	//清空键盘缓冲区 
   printf("input number to add:\n"); 
   scanf("%d", &num); 
   printf("input position(<=%d):\n", SIZE-2); 
   scanf("%d",&p);   
   
   //插入 元素
   for(i=SIZE-2; i>=p; i--) //下标为SIZE-2～p的数组元素依次后挪 
	   a[i+1]=a[i];
   a[p]=num; //插入num到下标为p的数组元素中 

// 读入要删除的元素下标 
   printf("\ninput number position to delete:\n"); 
   scanf("%d", &p); 
   
   for(i=p+1; i<=SIZE-1; i++) //下标为p+1～SIZE-1的数组元素依次前挪
	   a[i-1]=a[i]; 
   printf("after delete, the array is:\n"); 	   
   for(i=0; i<=SIZE-2; i++)
        printf("%d\t", a[i]);	  

    return 0;						
} 


