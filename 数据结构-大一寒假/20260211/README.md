一、树的表示
->儿子-兄弟表示法
->二叉树

二、二叉树的存储
1.数组存储-完全二叉树
          ->一般二叉树（空间浪费）
2.链表存储
typedef struct TreeNode *BinTree;
typedef BinTree Position;  //position就是bintree的别名
struct TreeNode{
    ElemenType Data;
    BinTree Left;
    BinTree Right;
}

三、二叉树的递归遍历
1.先序遍历
void PreOrderTraversal (BinTree BT)
{
    if(BT){
        printf("%d",BT->Data);
        PreOrderTraversal (BT->Left);
        PreOrderTraversal (BT->Right);
        }
}
2.中序遍历
void InOrderTraversal (BinTree BT)
{
    if(BT){
        PreOrderTraversal (BT->Left);
        printf("%d",BT->Data);
        PreOrderTraversal (BT->Right);
        }
}
3.后序遍历
void PostOrderTraversal (BinTree BT)
{
    if(BT){
        PreOrderTraversal (BT->Left);
        PreOrderTraversal (BT->Right);
        printf("%d",BT->Data);
        }
}
4.访问的顺序是一样的，区别在于什么时候给print出来

四、二叉树的非递归遍历
void InOrderTraversal (BinTree BT)
{
    BinTree T=BT;  //T是一个与BT同类型的临时指针，初始指向根结点，用于在遍历过程中移动。这样不改变原始根结点BT的值。
    Stack S=CreatStack(MaxSize);
    while(T||!IsEmpty(S)){  //循环条件为“当前处理的结点T不为空 或者 栈S不空”。
        while(T){
            Push(S,T);  //将当前结点T压入栈S。栈保存了从根到当前结点的路径，以便将来回溯时访问该结点的右子树。
            T=T->Left;  //将指针T指向当前结点的左孩子，继续向左探索。当左孩子为空时，内层循环结束。
            }
        if(!IsEmpty(S)){
            T=Pop(S);  //从栈顶弹出一个结点指针，赋给T。弹出的结点就是当前应被访问的根结点
            printf("%5d",T->Data);
            T=T->Right;  将指针T指向当前结点的右孩子。下一轮外层循环将从右孩子开始，重复“一路向左压栈”的过程，从而实现右子树的中序遍历。
            }
      }
}
