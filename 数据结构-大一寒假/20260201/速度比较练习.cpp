#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start,stop;
double duration;
#define MAXN 10
#define MAXK 1e7

double f1(int,double[],double);
double f2(int,double[],double);

typedef double(*FuncPtr)(int,double[],double);

void measure_time(const char*name,FuncPtr func,int n,double a[],double x){//char*name因为是个字符串 
	start=clock();
	for(int i=0;i<MAXK;i++){
		func(n,a,x);
	}
	stop=clock();
	duration=(double)(stop-start)/CLK_TCK;
	printf("%s:\n",name);
	printf("ticks=%f\n",(double)(stop-start)/1e7);
	printf("duration = %6.2e\n\n", duration/1e7);
}

int main(){
	int i;
	double a[MAXN];
	for(int i=0;i<MAXN;i++){
		a[i]=(double)i;
	}
	
	measure_time("f1", f1, MAXN - 1, a, 1.1);
    measure_time("f2", f2, MAXN - 1, a, 1.1);
}

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
