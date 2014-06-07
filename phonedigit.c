#include<stdio.h>
#include<string.h>

const char phoneBook[10][5] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};

void printStrings(int number[],int curr,int n,char output[]) {
	int i;
	if( curr == n) {
	
		printf("%s\n",output);
		return;
	
	}
	
	for(i = 0 ; i < strlen(phoneBook[number[curr]]);i++) {
	
		output[curr] = phoneBook[ number[curr] ] [i];
		printStrings(number,curr+1,n,output);
		if (number[curr] == 0 || number[curr] == 1)
		return;
	
	} 

}

main() {

	int n,i;
	printf("Enter the no of digits:\n");
	scanf("%d",&n);
	int number[n];
	char output[n+1];
	output[n] = '\0';
	printf("Enter the number:\n");
	for(i =0 ;i<n;i++) {
	
		scanf("%d",&number[i]);
	
	}
	
	printStrings(number,0,n,output);
	
	

}
