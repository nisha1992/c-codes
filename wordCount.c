#include<stdio.h>
char filename[10];
int a,b;
char word[10];
char buffer[255];
int count;

main(){
  
  printf("Enter the filename\n");
	scanf("%s",filename);
	printf("Enter the word\n");
	scanf("%s",word);
	
	FILE *fp = fopen(filename,"r");
	if(fp == NULL)
	printf("file not found");
	while(!feof(fp)){
		fscanf(fp,"%s",buffer);
		if(strcmp(word,buffer) == 0)
		count = count++;
	}
		printf("count=%d\n",count);
	fclose(fp);

}
