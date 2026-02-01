#include <stdio.h>
int main()
{
	int a[10];
	for(int i=0;i<9;i++) {
		scanf("%d",&a[i]);
	}
	
	int n,p;
	scanf("%d %d",&n,&p);
	for(int j=8;j>=p-1;j--){
	    a[j+1]=a[j];
	}
	a[p-1]=n;
	for(int j=0;j<10;j++){
		printf("%d ",a[j]);
	}
	
	int q;
	scanf("%d",&q);
	for(int k=q-1;k<9;k++){
		a[k]=a[k+1];
	}
	a[9]=0;
	for(int k=0;k<10;k++){
		printf("%d ",a[k]);
	}
	
	return 0;
}
