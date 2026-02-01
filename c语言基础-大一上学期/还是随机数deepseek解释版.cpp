#include <stdio.h>      // 引入标准输入输出库，提供printf等函数
#include <stdlib.h>     // 引入标准库，提供rand()和srand()函数
#include <time.h>       // 引入时间库，提供time()函数

int main()              // 主函数，程序入口点
{
    srand(time(0));     // 用当前时间初始化随机数生成器
                        // time(0)返回当前时间戳，确保每次运行程序时种子不同
    
    int a = rand();     // 生成一个随机整数（范围通常是0到RAND_MAX）
    
    printf("%d\n", a % 100); // 打印随机数除以100的余数，即0-99之间的数
                        // 注意：这不是严格的"两位随机数"，因为可能包含一位数
    
    return 0;           // 程序正常结束
}
