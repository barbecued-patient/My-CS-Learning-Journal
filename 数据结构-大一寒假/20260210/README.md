哨兵的核心作用
1. 减少比较操作
无哨兵：每次循环需要检查两个条件

是否到达数组末尾（边界检查）
当前元素是否等于目标值
有哨兵：每次循环只需检查一个条件

当前元素是否等于目标值
传统顺序查找（无哨兵）
c
int seq_search(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {      // 每次循环比较 i < n
        if (arr[i] == key) {       // 每次循环比较 arr[i] == key
            return i;              // 找到，返回下标
        }
    }
    return -1;                     // 未找到
}
每次迭代需要2次比较

使用哨兵的顺序查找
c
int seq_search_sentinel(int arr[], int n, int key) {
    int i = 0;
    arr[n] = key;                  // 设置哨兵
    
    while (arr[i] != key) {        // 只需要1次比较
        i++;
    }
    
    // 检查找到的是不是哨兵
    if (i < n) {
        return i;                  // 在有效位置找到
    } else {
        return -1;                 // 找到的是哨兵，说明不存在
    }
}
每次迭代只需要1次比较
