#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node *NODE;

NODE createnode(int item){
	NODE newnode = (NODE)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

NODE insertleft(NODE root, int item){
	root->left = createnode(item);
	
	return root->left;
}

NODE insertright(NODE root, int item){
	root->right = createnode(item);

	return root->right;
}

void display(NODE root){
	if(root){
		display(root->left);
		printf("%d\t", root->data);
		display(root->right);
	}
}

int countnodes(NODE root){
	if(root == NULL)
		return 0;
	return 1 + countnodes(root->left) + countnodes(root->right);
}

int height(NODE root){
	int leftht, rightht;
	if(root == NULL)
		return 0;
	else{
		leftht = height(root->left);
		rightht = height(root->right);
		if(leftht > rightht)
			return leftht + 1;
		else
			return rightht + 1;
	}
}

int leafnodes(NODE root){
	if(root == NULL)
		return 0;
	else if(root->left == NULL && root->right == NULL)
		return 1;
	else
		return leafnodes(root->left) + leafnodes(root->right);
}

int nonleafnodes(NODE root){
	if(root == NULL)
		return 0;
	else
		return 1 + nonleafnodes(root->left) + nonleafnodes(root->right);
}

void preorder(NODE root){
	if(root){
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
		
int main()
{
    NODE root=NULL;
    root=createnode(45);
    insertleft(root,39);
    insertright(root,78);
    insertleft(root->right,54);
    insertright(root->right,79);
    insertright(root->right->left,55);
    insertright(root->right->right,80);
    printf("\n The tree(inorder) is\n");
    display(root);
    printf("\n");
    printf("\n Preorder is: \n");
    preorder(root);
    printf("\n");
    printf("\n The total number of nodes is %d\n",countnodes(root));
    printf("\n The height of the tree is %d\n",height(root));
    printf("\n The total number of leaf nodes is %d\n",leafnodes(root));
    printf("\n The total number of non-leaf nodes is %d\n",nonleafnodes(root));
    return 0;
}
