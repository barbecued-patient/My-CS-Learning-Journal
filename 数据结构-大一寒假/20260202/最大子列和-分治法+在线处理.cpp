/*最大子列和问题 
算法一：分治法-时间复杂度 nlogn
ai生成，只看会，没写*/

#include <stdio.h>
#include <limits.h>

// 辅助函数：求三个数的最大值
int max3(int a, int b, int c) {
    int m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
}

// 分治函数
int maxSubArray(int A[], int left, int right) {
    // 基本情况：只有一个元素
    if (left == right) {
        return A[left];
    }
    
    int mid = left + (right - left) / 2;
    
    // 递归求解左右两部分
    int leftMax = maxSubArray(A, left, mid);
    int rightMax = maxSubArray(A, mid + 1, right);
    
    // 计算跨越中间的最大子段和（必须包含mid和mid+1中的一个）
    // 方法：从中间向左找最大后缀和，从中间向右找最大前缀和
    
    // 向左找最大后缀和
    int leftSum = 0, leftMaxSum = INT_MIN;
    for (int i = mid; i >= left; i--) {
        leftSum += A[i];
        if (leftSum > leftMaxSum) {
            leftMaxSum = leftSum;
        }
    }
    
    // 向右找最大前缀和
    int rightSum = 0, rightMaxSum = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        rightSum += A[i];
        if (rightSum > rightMaxSum) {
            rightMaxSum = rightSum;
        }
    }
    
    // 跨越中间的最大子段和
    int crossMax = leftMaxSum + rightMaxSum;
    
    // 返回三者最大值
    return max3(leftMax, rightMax, crossMax);
}

int main() {
    int N;
    printf("请输入数组长度 N: ");
    scanf("%d", &N);
    
    int A[N];
    printf("请输入 %d 个整数: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    int result = maxSubArray(A, 0, N - 1);
    // 根据题目要求，结果至少为0
    if (result < 0) result = 0;
    printf("最大非负子段和为: %d\n", result);
    
    return 0;
}


