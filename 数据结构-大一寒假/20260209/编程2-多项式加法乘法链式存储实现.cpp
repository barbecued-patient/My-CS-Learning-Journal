//链式存储
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
};
//这里必须先定义一个PolyNode类型的指针变量叫Polynomial，因为下面结构体要用

//创建新节点函数
Polynomial CreateNode(int coef,int expon)
{
    Polynomial p=(Polynomial)malloc(sizeof(struct PolyNode));
    p->coef=coef;
    p->expon=expon;
    p->link=NULL;
    return p;
}

//加入新节点
void Attach(int coef,int expon,Polynomial *pRear)
{
    Polynomial p=CreateNode(coef,expon);
    (*pRear)->link=p;
    *pRear=p;
}

//读取多项式
Polynomial ReadPoly()
{
    Polynomial p,rear,t;
    int n,coef,expon;
    scanf("%d",&n);
    p=(Polynomial)malloc(sizeof(struct PolyNode));
    p->link=NULL;
    rear=p;
    for(int i=0;i<n;i++){
        scanf("%d %d",&coef,&expon);
        Attach(coef,expon,&rear);
    }
    t=p;
    p=p->link;
    free(t);   //这里不是太理解
    return p;
}

//多项式相加
Polynomial AddPoly(Polynomial p1,Polynomial p2)
{
    Polynomial t1=p1,t2=p2;
    Polynomial p=(Polynomial)malloc(sizeof(struct PolyNode));//创建临时头节点
    Polynomial rear=p;//尾指针
    while(t1&&t2){//当两个多项式都有剩余项
        if(t1->expon==t2->expon){//指数相同
            int sumcoef=t1->coef+t2->coef;
            if(sumcoef!=0){//系数和不为零才录入
                Attach(sumcoef,t1->expon,&rear);
            }
            t1=t1->link;
            t2=t2->link;
        }else if(t1->expon>t2->expon){//t1指数大
            Attach(t1->coef,t1->expon,&rear);
            t1=t1->link;
        }else{//t2指数大
            Attach(t2->coef,t2->expon,&rear);
            t2=t2->link;
        }
    }
    //处理剩余项
    while(t1){
        Attach(t1->coef,t1->expon,&rear);
        t1=t1->link;
    }
    while(t2){
        Attach(t2->coef,t2->expon,&rear);
        t2=t2->link;
    }
    Polynomial t=p;
    p=p->link;
    free(t);
    return p;
}

//多项式乘法
Polynomial MulPoly(Polynomial p1,Polynomial p2)
{
    if(!p1||!p2){  //有一个多项式为空，返回空多项式
        return NULL;
    }

    Polynomial t1=p1,t2=p2;
    //创建临时头节点
    Polynomial p=(Polynomial)malloc(sizeof(struct PolyNode));
    p->link=NULL;
    Polynomial rear=p;

    //先用p1的第一项乘以p2的每一项，建立初始结果
    while(t2){
        int newcoef=t1->coef*t2->coef;
        int newexpon=t1->expon+t2->expon;
        if(newcoef!=0){
            Attach(newcoef,newexpon,&rear);
        }
        t2=t2->link;
    }
    t1=t1->link;

    //逐项相乘并合并
    while(t1){
        t2=p2;
        rear=p;  //每次从头开始找插入位置
        while(t2){
            int newcoef=t1->coef*t2->coef;
            int newexpon=t1->expon+t2->expon;
            
            if(newcoef==0){  //系数为0跳过
                t2=t2->link;
                continue;
            }
            
            //在结果多项式中寻找插入位置
            Polynomial pre=rear;  //前驱节点
            Polynomial cur=pre->link;  //当前节点
            
            //寻找插入位置：按指数降序排列
            while(cur&&cur->expon>newexpon){
                pre=cur;
                cur=cur->link;
            }
            
            if(cur&&cur->expon==newexpon){  //指数相同
                cur->coef+=newcoef;  //合并系数
                if(cur->coef==0){  //系数为0
                    pre->link=cur->link;  //删除节点
                    free(cur);
                }
            }else{  //插入新节点
                Polynomial newnode=CreateNode(newcoef,newexpon);
                newnode->link=cur;
                pre->link=newnode;
                rear=newnode;  //更新rear
            }
            
            t2=t2->link;
        }
        t1=t1->link;
    }
    
    //跳过临时头节点
    Polynomial temp=p;
    p=p->link;
    free(temp);
    
    return p;
}

// 打印多项式
void PrintPoly(Polynomial p){
    if(!p){
        printf("0 0\n");
        return;
    }

    int first=1;
    while(p){
        if(!first){
            printf(" ");
        }
        printf("%d %d",p->coef,p->expon);
        first=0;
        p=p->link;
    }
    printf("\n");
}

// 释放多项式内存
void FreePoly(Polynomial p){
    Polynomial t;
    while(p){
        t=p;
        p=p->link;
        free(t);
    }
}

//主函数
int main()
{
    Polynomial p1,p2,sum,mul;
    p1=ReadPoly();
    p2=ReadPoly();
    mul=MulPoly(p1,p2);
    sum=AddPoly(p1,p2);
    PrintPoly(mul);
    PrintPoly(sum);
    return 0;
}
