/*线性表的链式存储实现
不要求物理上相连，通过链建立逻辑关系*/
 
#include <stdio.h>
#include <stdlib.h>
#define MAXN 100;

typedef struct LNode *List;
struct LNode{
	ElementType Data;
	List Next;
};

struct LNode L;
List PtrL;

//1.创建空链表
//简单到感觉啥事都没干，与顺序表做一个对比 
List MakeEmpty(){
	List L = NULL;  // 头指针为空表示空链表
    return L;
} 

//2.求表长---遍历 
int Length(List PtrL){
	List p=PtrL;
	int j=0;
	while (p){   //当p不为NULL时继续循环 
		p=p->Next;   //NEXT是一个指针哈！ 
		j++;
	}
	return j;
}

//3.查找（1）按序号查找
List FindKth(int K,List PtrL){
    List p=PtrL;
	int i=1;
	while(p!=NULL&&i<K){
		p=p->Next;
		i++;
	} 
	if(i==K) return p;  //找到第K个，返回指针
	else return NULL; 
} 

//3.查找 （2）按值查找 
List Find(ElementType x,List PtrL){
	List p=PtrL;
	while(p!=NULL&&p->Data!=x){
		p=p->Next;
	}
	return p;
}

//4.插入
List Insert(ElementType X,int i,List PtrL){
	List p,s;
	if(i==1){   //新节点插在表头 
		s=(List)malloc(sizeof(struct LNode));
		s->Data=x;
		s->Next=PtrL;
		return s;
	}
	p=FindKth(i-1,PtrL);   //查找第i-1个节点 
	if(p==NULL){   //第i-1个节点不存在 
		printf("参数i错");
		return NULL; 
	}else{
		s=(List)malloc(sizeof(struct LNode));   //申请新节点 
		s->Data=x;
		s->Next=p->Next;
		p->Next=s;
		return PtrL;
	}
} 

//5.删除
List Delete(int i,List PtrL){
	List p,s;
	if(i==1){   //删除节点在表头 
		s=PtrL;
		if(PtrL!=NULL) PtrL=PtrL->Next;   //直接挪头节点 
		else return NULL;
		free(s);
		return PtrL;
	}
	p=FindKth(i-1,PtrL);   //查找第i-1个节点 
	if(p==NULL){   //第i-1个节点不存在 
		printf("第%d个节点不存在",i-1);
		return NULL; 
	}else if(p->Next==NULL){
		printf("第%d个节点不存在",i);
	}else{
		s=p->Next;
		p->Next=s->Next;
		free(s);
		return PtrL;
	}
} 
 
