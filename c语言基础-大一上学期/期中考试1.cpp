#include <stdio.h> 

int isrun(int x)
{
	int ret=1;
	if(x%4!=0){
		ret=0;
	}else if(x%100!=0){
		ret=1;
	}else if(x%400==0){
		ret=1;
	}
	return ret;
}

int maxgong(int n,int m)
{
	/*15 9
	15/9=1...6
	9/6=1...3
	6/3=2...0
	
	24 16
	24/16=1...8
	16/8=0
3
2008 2012
2000 2003
1900 2000 */
	int t=0;
	while(m%n!=0){
		t=m%n;
		m=n;
		n=t;
	}
	return n;
	}

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(isrun(a)&&isrun(b)){
			printf("%d",maxgong(a,b));
		}else{
			printf("no");
		}
	}
	return 0;
}
