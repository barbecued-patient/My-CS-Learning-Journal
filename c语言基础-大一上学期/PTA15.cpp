#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<t;i++){
        int n;
        scanf("%d",&n);
        int sum=0;
        int lastsum=0;
        for(int j=1;j<n;j++){
            int price;
            scanf("%d",&price);
            sum+=price;
        }
        if(sum<100){
            lastsum=sum;
        }else if(sum>=100&&sum<200){
            lastsum=sum-30;
        }else if(sum>=200&&sum<300){
            lastsum=sum-70;
        }else if(sum>=300&&sum<400){
            lastsum=sum-110;
        }else if(sum>=400){
            lastsum=sum-160;
        }
        printf("%d",lastsum);
    }
    return 0;
}
