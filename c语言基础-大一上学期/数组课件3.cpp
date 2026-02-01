#include <stdio.h> 
int main()
{
	int response[40];
	int frequency[10]={0};
	int rating;
	
	for(int i=0;i<40;i++){
		scanf("%d",response[i]);
		
	for(int i=0;i<40;i++){
		++frequency[response[i]];
	}
	
	for(rating=1;rating<=10;rating++){
		printf("%d %d",rating,frequency[rating]);
	}
	}
	return 0;
}
