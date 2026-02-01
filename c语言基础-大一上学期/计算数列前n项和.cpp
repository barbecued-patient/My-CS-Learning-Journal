#include <stdio.h> 
int main()
//2/1 3/2 5/3 8/5 13/8...
{
	int n;
	scanf("%d",&n);
	
	double i=1.0;
	double j=2.0;
	double k=0.0; 
	double sum=0.0;
	
	for(int cnt=0;cnt<n;cnt++){
		sum+=j/i;
		k=i;
		i=j;
		j=k+j;
	}
	
	printf("%.2f\n",sum);//这里的f！！！！！还有保留两位小数！！！ 
	return 0;
}
