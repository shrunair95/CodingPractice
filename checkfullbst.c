#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	struct node *left, *right;
};

struct node* newNode(int k){
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->key=k;
	node->left=node->right=NULL;
	return node;
}

int isFull(struct node* n){
	if(n==NULL)
		return 1;
	if(n->left==NULL && n->right==NULL)
		return 1;
	if((n->left) && (n->right))
		return(isFull(n->left) && isFull(n->right));
	return 0;
}

int main(){
	struct node* root=NULL;
	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->left->left->left=newNode(6);
	if(isFull(root))
		printf("FULL");
	else
		printf("NOT FULL");
}