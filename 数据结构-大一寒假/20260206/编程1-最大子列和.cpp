/*方法一：遍历两次(n2)
#include <stdio.h>
#include <stdlib.h>
int main()
{
    //输入
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //遍历
    int MaxSubarraySum=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum>MaxSubarraySum) MaxSubarraySum=sum;
        }
    }
    printf("%d\n",MaxSubarraySum);
    return 0;
}*/



/*方法二：分治法(nlogn)
#include <stdio.h>

//辅助函数：求三个数最大值
int max3(int a,int b,int c)
{
    int max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    return max;
}

//分治函数
int MaxSubarraySum(int a[],int left,int right)
{
    //如果只有一个数
    if(left==right) return a[left];

    //左右两边分别递归求解
    int mid=left+(right-left)/2;
    MaxSubarraySum(a,left,mid);  //MaxSubarraySum(a[],left,mid);是错误的！
    MaxSubarraySum(a,mid+1,right);

    //跨越中间的最大子列和
    //左边
    int leftSum=0;
    int leftSumMax=0;
    for(int i=mid;i>=left;i--){
        leftSum+=a[i];
        if(leftSum>leftSumMax) leftSumMax=leftSum;
    }
    //右边
    int rightSum=0;
    int rightSumMax=0;
    for(int i=mid+1;i<=right;i++){
        rightSum+=a[i];
        if(rightSum>rightSumMax) rightSumMax=rightSum;
    }
    int crossMax=leftSumMax+rightSumMax;
    return max3(crossMax,leftSumMax,rightSumMax);
}

//主函数
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int result=MaxSubarraySum(a,0,n-1);
    if(result<0) result=0;
    printf("%d\n",result);
    return 0;
}*/



//方法三：在线处理
#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int sum=0;
    int MaxSubarraySum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>MaxSubarraySum){
            MaxSubarraySum=sum;
        }else if(sum<0){
            sum=0;
        }
    }
    printf("%d\n",MaxSubarraySum);
    return 0;
}
