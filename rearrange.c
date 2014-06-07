#include<stdio.h>
#include<string.h>
#define max 26

struct charFreq {

	char node;
	int f;

};


void swap(struct charFreq *a,struct charFreq *b) {

	struct charFreq *z;
	z = (struct charFreq *)malloc(sizeof(struct charFreq *));
	*z = *a;
	*a = *b;
	*b = *z;

}

void maxheapify(struct charFreq freq[],int i ,int n) {

	int l = 2*i +1;
	int r = 2*i +2;
	int largest = i;
	if(l < n && freq[l].f > freq[i].f)
	largest = l;
	if(r < n && freq[r].f > freq[largest].f)
	largest = r;
	if(largest != i) {
	
		swap(&freq[largest],&freq[i]);
		maxheapify(freq,largest,n);
	
	}

}

void buildHeap(struct charFreq freq[],int n) {

	int i = (n-1)/2;
	while(i >=0) {
	
		maxheapify(freq,i,n);
		i--;
	
	}

}

struct charFreq extractMax(struct charFreq freq[],int h) {
	
	struct charFreq maxNode = freq[0];
	
	if(h >1) {
		freq[0] = freq[h-1];
		maxheapify(freq,0,h-1);
	}
	return maxNode;
}


void rearrange(char *string,int d) {

	struct charFreq freq[max] = {{0,0}};
	int i,j,m=0,k,p;
	j = strlen(string);

	
	for(i=0; i<j; i++) {
	
		char x = string[i];
		if(freq[x-97].node == '\0') {
		
			freq[x-97].node = x;
			m++;
		
		}
		
		(freq[x-97].f)++;	
		string[i] = '\0';
	
	}
	
	buildHeap(freq,max);
	
	for(i=0; i<m; i++) {
	
		struct charFreq y = extractMax(freq,max-i);
		p=i;
		while(string[p] != '\0')
		p++;
		
		for(k=0; k<y.f; k++) {
			
			if( (p + d*k) >= j) {
				printf("cannot rearrange:");
				exit(0);
			}
			string[p+d*k] = y.node;
		
		}
	
	}

}

main() {

	char string[50];
	printf("Enter string:\n");
	scanf("%s",string);
	char *str;
	str = string;
	int d;
	printf("Enter distance:\n");
	scanf("%d",&d);
	rearrange(str,d);
	printf("after rearrangement\t%s\n",str);

}
