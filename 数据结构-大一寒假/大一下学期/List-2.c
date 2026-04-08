/*练习：读入一批整数{17,19,47,-1} ，以负数结束。将输入的数据组成先进后出的链表 。
*/

//这个程序为啥给我一直自动暂停啊，我一直在哭

#include<stdio.h>
#include<stdlib.h>

struct listNode{
    int data;
    struct listNode *nextPtr;
};

typedef struct listNode LISTNODE;
typedef struct listNode *LISTNODEPTR;

LISTNODEPTR createFILOList(void)
{
    int num;
    LISTNODEPTR headPtr=NULL;
    LISTNODEPTR currentPtr=NULL;

    printf("请输入一串数字(以-1结尾)\n");
    scanf("%d",&num);
    while(num!=-1){
        currentPtr=(LISTNODEPTR)malloc(sizeof(LISTNODE));
        if(currentPtr==NULL){
            printf("内存申请失败");
            exit(1);
        }
        currentPtr->data=num;
            currentPtr->nextPtr=headPtr;
            headPtr=currentPtr;
        
        scanf("%d",&num);
    }
    return headPtr;
}

//deepseek
void printList(LISTNODEPTR head) {
    LISTNODEPTR p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->nextPtr;
    }
    printf("\n");
}

//deepseek
// 释放链表所有结点的内存
void freeList(LISTNODEPTR head) {
    LISTNODEPTR p = head;
    while (p != NULL) {
        LISTNODEPTR temp = p;   // 暂存当前结点
        p = p->nextPtr;         // 移动到下一个结点
        free(temp);             // 释放当前结点
    }
}

//主函数
int main()
{
    printf("程序开始\n");
    LISTNODEPTR headPtr = NULL;          // 定义头指针，初始为空
    headPtr = createFILOList();          // 调用函数，得到建好的链表
    printf("链表内容：");
    printList(headPtr);                  // 输出
    
    freeList(headPtr);                   // 释放内存
    
    return 0;
}