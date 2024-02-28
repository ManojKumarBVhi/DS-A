#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
	int cof;
	int po;
	struct node *next;
};

typedef struct node *NODE;

NODE insert(NODE head, int cof, int po){
	NODE newnode = (NODE)malloc(sizeof(struct node));
	newnode->cof = cof;
	newnode->po = po;
	newnode->next = NULL;
	if(head == NULL || po > head->po){
		newnode->next = head;
		head = newnode;
	}
	else{
		NODE temp = head;
		while(temp->next != NULL && temp->next->po >= po){
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
	return head;
}

NODE create(NODE head){
	int n,i;
	int cof,po;
	printf("\n Enter no of terms : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\n Enter coefficient for term %d : ",i+1);
		scanf("%d",&cof);
		
		printf("\n Enter power for term %d: ",i+1);
		scanf("%d",&po);
		
		head = insert(head,cof,po);
	}
	return head;
}

void display(NODE head) {
	NODE temp = head;
	if (temp == NULL) {
		printf("Polynomial is empty\n");
		return;
	}
	while(temp != NULL){
		printf("%dx^%d\n",temp->cof, temp->po);
		temp = temp->next;
	}
}

void multiplypoly(NODE head1, NODE head2){
	NODE ptr1 = head1;
	NODE ptr2 = head2;
	NODE head3 = NULL;
	if(head1 == NULL || head2 == NULL){
		printf("Zero Polynomial");
		return;
	}
	else{
		while(ptr1 != NULL){
			while(ptr2 != NULL){
				head3 = insert(head3, ptr1->cof*ptr2->cof,ptr1->po+ptr2->po);
				ptr2 = ptr2->next;
			}
			ptr1 = ptr1->next;
		}
	display(head3);
	}
}

int main(){
	NODE head1 = NULL;
	NODE head2 = NULL;
	printf("Enter first polynomial : ");
	head1 = create(head1);
	
	printf("Enter second polynomial : ");
	head2 = create(head2);
	
	multiplypoly(head1, head2);
	
	return 0;
}
