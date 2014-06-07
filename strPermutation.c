#include<stdio.h>
int count;
void swap(char *a,char *b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *a,int i,int j){
	int n;
	if( i == j){
		printf("%s\n",a);
		count ++;
	}
	
	else{
		for(n = i ; n <= j;n++) {
		
			swap( (a+i),(a+n) );
			permute( a, i+1, j);
			swap( (a+i),(a+n) );
		}
	}
}

main(){

	char a[4];
	printf("Enter the string\n");
	scanf("%s",a);
	permute(a,0,3);
	printf("%d",count);
	
}
