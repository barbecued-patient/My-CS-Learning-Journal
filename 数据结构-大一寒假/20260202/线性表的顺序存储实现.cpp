/*线性表的顺序存储实现
1.2.3是跟着课件写的，4.是自己写的*/

#include <stdio.h>
#include <stdilb.h>
#define MAXSIZE 100
 
typedef struct LNode *List;

struct LNode{
	ElementType Data[MAXSIZE];
	int Last;
};

//1.初始化（建立空顺序表）
List MakeEmpty()
{
	List PtrL;
	PtrL=(List)malloc(sizeof(struct LNode));
	PtrL->Last=-1;   //建立空表 
	return PtrL;
 } 
 
//2.查找
int Find(ElementType x,List PtrL)
{
	int i=0;
	while(i<=PtrL->Last&&PtrL->Data[i]!=x){
		i++;
	}
	if(i>PtrL->Last){
		return -1;
	}else{
		return i;
	}
 } 
 
//3.插入
void Insert(ElementType x,int i, List PtrL)
{
	int j;
	if(PtrL->Last==MAXSIZE-1){   //表空间已满，不能插入 
		printf("表满")；
		return; 
	}
	if(i<1||i>PtrL->Last+2){   //检查插入位置的合法性 
		printf("位置不合法");
		return; 
	}
	for(j=PtrL->Last;j>=i-1;j--){
		PtrL->Data[j+1]=PtrL->Data[j];   //倒序向后移动一位 
		PtrL->Data[i-1]=x;   //插入新元素 
		PtrL->Last++;    //Last仍指向最后一个元素
		return; 
	}
 } 

//4.删除
void Delete(int i,List PtrL)
{
	int j;
	if(i<1||i>PtrL->Last+1){   //插入是+2，删除是+1，体会区别 
		printf("不存在第%d个元素"，i);
		return;   //忘了return 
	}
	for(j=i;j<PtrL->Last;j++){
		PtrL->Data[j-1]=PtrL->Data[j];
	}
	PtrL->Last--;   //这一步也忘了 
	return;
 } 
