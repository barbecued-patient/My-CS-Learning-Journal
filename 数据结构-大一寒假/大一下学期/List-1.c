/*例1、读入一批数，以-1结束。将输入的数据组成先进先出的链表并输出，最后释放链表。 
要求：设计一个函数LISTNODEPTR createFIFOList(void)；
函数功能：读入一批数（以－1结束），将输入的数组成先进先出的链表，并返回指向链表头结点的指针。

步骤	你写什么	为什么
1	函数头 LISTNODEPTR createFIFOList(void)	按题目要求
2	定义 num, headPtr, lastPtr, currentPtr	需要存数据、记头、记尾、临时结点
3	初始化 headPtr=NULL, lastPtr=NULL	空链表
4	读第一个数	循环条件需要
5	while(num!=-1)	直到输入结束标志
6	malloc 新结点	堆上创建，函数返回后仍存在
7	检查 malloc	防止崩溃
8	填数据，nextPtr=NULL	结点内容初始化
9	判断是否第一个结点	决定是改头指针还是尾指针的 next
10	更新 lastPtr	保持尾指针指向最后一个结点
11	读下一个数	继续循环
12	返回 headPtr	主函数需要头指针
*/

#include<stdio.h>
#include<stdlib.h>

//定义结构体
struct listNode{
    int data;
    struct listNode *NextPtr;
};

//两个别名：结点和指向结点的指针
typedef struct listNode LISTNODE;
typedef struct listNode *LISTNODEPTR;

//函数本体
LISTNODEPTR createFIFOList(void){
    //定义数据类型
    int num;
    LISTNODEPTR headPtr=NULL;
    LISTNODEPTR lastPtr=NULL;
    LISTNODEPTR currentPtr=NULL;

    //读第一个数 循环条件需要
    printf("请输入整数(-1结束)\n");
    scanf("%d",&num);
    while(num!=-1){
        currentPtr=malloc(sizeof(LISTNODE));

        //检查内存是否分配成功
        if(currentPtr==NULL){
            printf("内存分配失败");
            exit(1);//标准库函数：退出函数调用
        }

        //填充新数据
        currentPtr->data=num;
        currentPtr->NextPtr=NULL;

        //加入链表
        if(headPtr==NULL){
            headPtr=currentPtr;
            lastPtr=currentPtr;
        }else{
            lastPtr->NextPtr=currentPtr;
            lastPtr=currentPtr;//这两行有一个先后关系的！
        }

        //读取下一个数，以便判断循环
        scanf("%d",&num);
    }
    return headPtr;
}

//deepseek
void printList(LISTNODEPTR head) {
    LISTNODEPTR p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->NextPtr;
    }
    printf("\n");
}

//deepseek
// 释放链表所有结点的内存
void freeList(LISTNODEPTR head) {
    LISTNODEPTR p = head;
    while (p != NULL) {
        LISTNODEPTR temp = p;   // 暂存当前结点
        p = p->NextPtr;         // 移动到下一个结点
        free(temp);             // 释放当前结点
    }
}

//主函数
int main()
{
    LISTNODEPTR headPtr = NULL;          // 定义头指针，初始为空
    headPtr = createFIFOList();          // 调用函数，得到建好的链表
    printf("链表内容：");
    printList(headPtr);                  // 输出
    
    freeList(headPtr);                   // 释放内存
    
    return 0;
}