#include<stdio.h>

typedef struct tree *treeNode;
struct tree {

	int data;
	treeNode left;
	treeNode right;

};

treeNode temp = NULL;

void addNode(treeNode *head,int data) {

	if((*head) == NULL) {
	
		temp = (struct tree*)malloc(sizeof(struct tree*));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		*head = temp;
		return;
	
	}
	
	else if (data < (*head)->data) {
	
		addNode(&(*head)->left,data);
	
	}
	
	else {
	
		addNode(&(*head)->right,data);
	
	}
	

}

void displayTree(treeNode head) {

	if(head) {
		
		displayTree(head->left);
		printf("%d\n",head->data);
		displayTree(head->right);
	}

}

void printnodeAtK(treeNode head,int k,int h) {

	if(head == NULL) {

		return;
	
	}
	
	else if(k == h) {
	
		printf("\n%d\n",head->data);		
	
	}
	
	else {
	
		printnodeAtK(head->left,k,h+1);
		printnodeAtK(head->right,k,h+1);
	
	}
	
}

main() {
	
	treeNode root = NULL;
	int j,n,data,k;
	printf("Enter the no of nodes in a tree:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	
	for(j = 0;j < n;j++) {
	
		scanf("%d",&data);
		addNode(&root,data);
	
	}
	printf("display tree:\n");	
	displayTree(root);
	printf("Enter the value of k:\n");
	scanf("%d",&k);
	printf("nodes at distance k:");
	printnodeAtK(root,k,0);
}
