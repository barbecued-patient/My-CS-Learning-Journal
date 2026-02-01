/*p3代码进化版：将测试时间部分封装成函数
历程如下：1.重复代码太丑陋，故用函数封装
          2.程序运行过快，甚至不到一个CLK_TCK,故让其运行1e7遍，取平均
学到的：1.计算运行时间的代码
        2.如何将函数作为参数来传递(把函数变成一个指针)*/ 
#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
double duration;
#define MAXN 10 /* 多项式最大项数，即多项式阶数+1 */
#define MAXK 1e7 /*一共调用的最大次数*/ 

double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

/* 定义函数指针类型，方便传参 */
typedef double (*FuncPtr)(int, double[], double);
/*步骤1：先看如何声明一个函数指针变量
double (*ptr)(int, double[], double);
解释：ptr是一个指针，指向一个返回double、参数为(int, double[], double)的函数
步骤2：把上面的声明加上typedef
typedef double (*FuncPtr)(int, double[], double);
解释：现在FuncPtr是一个类型名（不是变量名），代表"这种类型的函数指针"*/

/* 计时函数：接受一个函数指针和对应参数，并输出运行时间 */
void measure_time(const char *name, FuncPtr func, int n, double a[], double x) {
    start = clock();
    for(int i=0;i<MAXK;i++){
    	func(n, a, x);
	} 
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK; // 注意：标准是CLOCKS_PER_SEC
    printf("%s:\n", name);
    printf("ticks = %f\n", (double)(stop - start));
    printf("duration = %6.2e\n\n", duration);
}

int main() {
    int i;
    double a[MAXN]; /* 存储多项式的系数 */
    for (i = 0; i < MAXN; i++) a[i] = (double)i;

    /* 调用两次，分别测量f1和f2 */
    measure_time("f1", f1, MAXN - 1, a, 1.1);
    measure_time("f2", f2, MAXN - 1, a, 1.1);

    return 0;
}

/* 下面是两个示例函数，保持原样 */
double f1(int n, double a[], double x) {
    int i;
    double p = a[0];
    for (i = 1; i <= n; i++)
        p += (a[i] * pow(x, i));
    return p;
}

double f2(int n, double a[], double x) {
    int i;
    double p = a[n];
    for (i = n; i > 0; i--)
        p = a[i - 1] + x * p;
    return p;
} 
