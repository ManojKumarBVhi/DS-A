#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
	char data;
	struct node *left;
	struct node *right;
};

typedef struct node *NODE;

struct stack{
	int top;
	NODE data[10];
};

typedef struct stack STACK;

int preced(char item){
	switch(item){
		case '^': return 5;
		case '*':
		case '/': return 3;
		case '+':
		case '-': return 1;
	}
}

void preorder(NODE root){
	if(root){
		printf("%c\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(NODE root){
	if(root){
		inorder(root->left);
		printf("%c\t",root->data);
		inorder(root->right);
	}
}

void postorder(NODE root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("%c\t",root->data);
	}
}

void push(STACK *s, NODE temp){
	s->top = s->top + 1;
	s->data[s->top] = temp;
}

NODE pop(STACK *s){
	return (s->data[(s->top)--]);
}

NODE createnode(char item){
	NODE temp = (NODE)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

NODE createExpTree(char exp[20]){
	STACK tree, operator;
	tree.top = -1;
	operator.top = -1;
	char symbol;
	int i;
	NODE temp, t, l, r;
	
	for(i=0;exp[i] != '\0';i++){
		symbol = exp[i];
		temp = createnode(symbol);
		if(isalnum(symbol))
			push(&tree, temp);
		else{
			if(operator.top == -1)
				push(&operator, temp);
			else{
				while(operator.top != -1 && preced((operator.data[operator.top])->data) >= preced(symbol)){
					t = pop(&operator);
					r = pop(&tree);
					l = pop(&tree);
					t->right = r;
					t->left = l;
					push(&tree,t);
				}
				push(&operator, temp);
			}
		}
	}
	
	while(operator.top != -1){
		t = pop(&operator);
		r = pop(&tree);
		l = pop(&tree);
		t->right = r;
		t->left = l;
		push(&tree, t);
	}
	
	return pop(&tree);
}

int main(){
	NODE root = NULL;
	char exp[20];
	printf("Read Expression \n");
	scanf("%s",exp);
	root = createExpTree(exp);
	printf("\n Inorder :: ");
	inorder(root);
	
	printf("\n Preorder :: ");
	preorder(root);
	
	printf("\n Postorder :: ");
	postorder(root);
	
	return 0;
}
