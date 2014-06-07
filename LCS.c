#include<stdio.h>
#include<string.h>

int max(int a,int b) {

	if(a>b)
	return a;
	else
	return b;

}

void printLCS(char *arg[],int m,int n) {

	int i,j;	
	int output[m + 1][n + 1];
	
	for( i=0; i<m+1; i++ ) {
	
		for( j=0; j<n+1; j++ ) {
		
			if( i==0 || j==0 )
			output[i][j] = 0;
			
			else if(arg[1][i-1] == arg[2][j-1]) {
			
				output[i][j] = output[i-1][j-1] +1;
			
			}
			
			else {
			
				output[i][j] = max(output[i-1][j],output[i][j-1]);
			
			}
			
		}
	
	} 
	
	int index = output[m][n];
	char resultLCS[index+1];
	resultLCS[index] = '\0';
	int x = m,y = n;
	while(x > 0 && y > 0) {
	
		if(arg[1][x-1] == arg[2][y-1]) {
		
			resultLCS[index - 1] = arg[1][x-1];
			x--;
			y--;
			index--;
		
		}
		
		else if(output[x-1][y] > output[x][y-1]) {
		
			x--;
		
		}
		
		else {
		
			y--;
		
		}
	
	}
	
	printf("LCS is %s\n", resultLCS);

} 

main(int argc,char *arg[]) {

	int m,n;
	m = strlen(arg[1]);
	n = strlen(arg[2]);

	printLCS(arg,m,n);	

}
