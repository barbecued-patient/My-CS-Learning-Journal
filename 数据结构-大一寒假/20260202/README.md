一、最大子列和问题
1.分治法：时间复杂度nlogn
2.在线处理：时间复杂度n


二、引子：多项式表示
1.数组结构
  struct PolyTerm {
    int coef;
    int expon;
};
2.链表
  struct PolyNode {
    int coef;
    int expon;
    struct PolyNode *link;
};
3.数组存储VS链表存储
比较维度	    数组存储（结构体数组）             	链表存储
内存连续性	  连续存储，所有元素在内存中相邻	      非连续存储，节点分散在内存各处
大小调整	    固定大小或需要重新分配+复制	        动态增删，不需要整体重新分配
内存开销	    每个元素：系数 + 指数（无指针开销）	每个节点：系数 + 指数 + 指针（有额外指针开销）
访问方式	    随机访问，O(1)访问第k个元素	        顺序访问，O(k)访问第k个元素
插入/删除	    需要移动后续元素，O(n)	              只需修改指针，O(1)（找到位置需要O(n)）
缓存友好性	  高，连续内存，缓存命中率高	          低，节点分散，缓存不友好
内存管理	    简单，一次性分配/释放	              复杂，需要逐个节点分配/释放


三、线性表
1.顺序存储
2.链式存储

四、广义表
1.
typedef struct GNode *GList;
struct GNode{
    int Tag;   //标志域：0表示结点是单元素，1表示节点是广义表
    union{
        ElementType Data;
        GList SubList;   //定义一个叫Sublist的变量，类型是GList
        }URegion;   // union名字叫URegion
        GList Next;
};

2.tag作用：
//Tag = 0：这是一个原子节点
if (node->Tag == 0) {
    // 使用 URegion.Data 存储原子值
    ElementType value = node->URegion.Data;
}

// Tag = 1：这是一个子表节点  
if (node->Tag == 1) {
    // 使用 URegion.SubList 指向子表
    GList sublist = node->URegion.SubList;
}

3.Union的作用
union {
    ElementType Data;   // 占一块内存
    GList SubList;      // 也占同一块内存
} URegion;
// 内存布局：
// 当 Tag=0 时：URegion 这块内存存储 Data（原子值）
// 当 Tag=1 时：URegion 这块内存存储 SubList（指针）
// 两者共用同一块内存，节省空间！


五、多重链表
e.g.矩阵->十字链表
每个结点通过两个指针域，把同行、列串起来（right，down）
head&term结点

