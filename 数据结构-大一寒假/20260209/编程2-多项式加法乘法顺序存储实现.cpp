//顺序存储
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 2001

typedef struct Poly{
	int coef[MAXSIZE*2];
	int minExp;
    int maxExp;
}*Polynomial;

//创建空表
Polynomial CreatPoly()
{
	Polynomial p=(Polynomial)malloc(sizeof(struct Poly));
	for(int i=0;i<MAXSIZE*2;i++){
        p->coef[i]=0;
    }
    p->maxExp=-2000;
    p->minExp=2000;   //这里要反着赋值
	return p;
 } 

//读取多项式
Polynomial ReadPoly()
{
    Polynomial p=CreatPoly();
    int n,coef,exp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&coef,&exp);
        if(coef!=0){
            p->coef[exp+MAXSIZE]=coef;
            if(exp>p->maxExp) p->maxExp=exp;
            if(exp<p->minExp) p->minExp=exp;
        }
    }
    return p;
}

//多项式加法
Polynomial AddPoly(Polynomial p1,Polynomial p2)
{
    Polynomial result=CreatPoly();
    
    int minExp=(p1->minExp<p2->minExp)?p1->minExp:p2->minExp;
    int maxExp=(p1->maxExp>p2->maxExp)?p1->maxExp:p2->maxExp;

    result->maxExp=-2000;
    result->minExp=2000;

    for(int exp=minExp;exp<=maxExp;exp++){
        int idx=exp+MAXSIZE;
        int sum=p1->coef[idx]+p2->coef[idx];
        if(sum!=0){
            result->coef[idx]=sum;
            if(exp>result->maxExp) result->maxExp=exp;
            if(exp<result->minExp) result->minExp=exp;
        }
    }
    return result;
}

//多项式乘法
Polynomial MulPoly(Polynomial p1,Polynomial p2)
{
    Polynomial result=CreatPoly();

    result->maxExp=-2000;
    result->minExp=2000;

    for(int exp1=p1->minExp;exp1<=p1->maxExp;exp1++){
        int idx1=exp1+MAXSIZE;
        if(p1->coef[idx1]==0) continue;
        
        for(int exp2=p2->minExp;exp2<=p2->maxExp;exp2++){
            int idx2=exp2+MAXSIZE;
            if(p2->coef[idx2]==0) continue;
            
            int newCoef=p1->coef[idx1]*p2->coef[idx2];
            int newExp=exp1+exp2;
            
            result->coef[newExp+MAXSIZE]+=newCoef;

            if(newExp>result->maxExp) result->maxExp=newExp;
            if(newExp<result->minExp) result->minExp=newExp;
        }
    }
    return result;
}

//检查是否是零多项式
int IsZeroPoly(Polynomial p)
{
    for(int exp=p->minExp;exp<=p->maxExp;exp++){
        if(p->coef[exp+MAXSIZE]!=0) return 0;
    }
    return 1;
}

//打印多项式
void PrintPoly(Polynomial p)
{
    if(IsZeroPoly(p)){
        printf("0 0\n");
        return;
    }
    int first=1;   //这个first定义很巧妙，目的是防止最后输出空格
    for(int exp=p->maxExp;exp>=p->minExp;exp--){
        int idx=exp+MAXSIZE;
        if(p->coef[idx]!=0){
            if(!first){
                printf(" ");
            }
            printf("%d %d",p->coef[idx],exp);
            first=0;
        }
    }
    printf("\n");
}

//释放多项式内存
void FreePoly(Polynomial p)
{
    free(p);
}

//主函数
int main()
{
    Polynomial p1=ReadPoly();
    Polynomial p2=ReadPoly();
    Polynomial sum=AddPoly(p1,p2);
    Polynomial mul=MulPoly(p1,p2);
    PrintPoly(mul);
    PrintPoly(sum);
    FreePoly(p1);
    FreePoly(p2);
    FreePoly(mul);
    FreePoly(sum);
    return 0;
}
