#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;

};

struct node* newnode(int data){
	struct node* node=(struct node*) malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return(node);	
}

void printPreorder(struct node* node){
	if(node==NULL)
		return ;
	printf("%d",node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}

void printPostorder(struct node* node){
	if(node==NULL)
		return ;
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d",node->data);
}

void printInorder(struct node* node){
	if(node==NULL)
		return ;
	printInorder(node->left);
	printf("%d",node->data);
	printInorder(node->right);
}

int main(){
	struct node* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	printPreorder(root);
	printf("\n");
	printInorder(root);
	printf("\n");
	printPostorder(root);
	printf("\n");
	return 0;
}