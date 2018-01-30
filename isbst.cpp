#include<iostream>
using namespace std;

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

int isBST(struct node* root, struct node *l=NULL, struct node *r=NULL){
	if(root==NULL)
		return 1;
	if(l!=NULL && root->key<l->key)
		return 0;
	if(r!=NULL && root->key>r->key)
		return 0;
	return (isBST(root->left,l,root) && isBST(root->right,root,r));
}

int main(){
	struct node* root=NULL;
	root=newNode(4);
	root->left=newNode(2);
	root->right=newNode(5);
	root->left->left=newNode(1);
	root->left->right=newNode(3);
	if(isBST(root))
		printf("IS BST");
	else
		printf("IS NOT BST");
}