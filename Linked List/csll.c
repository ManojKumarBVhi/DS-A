#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node *NODE;

NODE append(NODE head, int item){
	NODE newnode = (NODE)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("Insufficient Memory");
		free(newnode);
		exit(0);
	}
	newnode->data = item;
	newnode->next = NULL;
	
	if(head == NULL){
		head = newnode;
		newnode->next = head;
	}
	else{
		NODE temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = head;
	}
	return head;
}

NODE insert_first(NODE head, int item){
	NODE newnode = (NODE)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("\n Insufficient Memory");
		exit(0);
	}
	newnode->data = item;
	newnode->next = NULL;
	
	if(head == NULL){
		newnode->next = head;
		head = newnode;
	}
	else{
		NODE temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = head;
		head = newnode;
	}
	return head;
}

NODE insert_last(NODE head, int item){
	NODE newnode = (NODE)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("\n Insufficient Memory");
		free(newnode);
		exit(0);
	}
	newnode->data = item;
	newnode->next = NULL;
	if(head == NULL){
		head = newnode;
		newnode->next = head;
	}
	else{
		NODE temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = head;
	}
	return head;
}

NODE insert_after(NODE head, int search, int item){
	NODE newnode = (NODE)malloc(sizeof(struct node));
	if(newnode == NULL){
		printf("\n Insufficient Memory");
		free(newnode);
		exit(0);
	}
	
	newnode->data = item;
	newnode->next = NULL;
	
	if(head == NULL){
		printf("\n Empty List");
		free(newnode);
		exit(0);
	}
	else{
		NODE temp = head;
		while(temp != NULL){
			if(temp->data == search){
				newnode->next = temp->next;
				temp->next = newnode;	
				
				if(temp->next == head){
					head = newnode;
				}
				
				return head;
			}
			else{
				temp = temp->next;
			}
		}
		printf("%d element not found in the list ",search);
		free(newnode);
		return head;
	}
}

/*
void display_last(NODE head){
	NODE temp = head;
	while(temp->next != head){
		temp = temp->next;
	}
	printf("%d",temp->data);
}
*/

void display_list(NODE head){
	if(head == NULL){
		printf("\n Empty List");
		exit(0);
	}
	else{
		NODE temp = head;
		while(temp->next != head){
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("%d\t", temp->data);
	}
}

int main(){
	int ch,item,search;
	NODE head = NULL;
	for(;;){
		printf("\n 1. Append");
		printf("\n 2. Insert First");
		printf("\n 3. Insert Last");
		printf("\n 4. Insert After");
		printf("\n 5. Insert Before");
		printf("\n 6. Delete First");
		printf("\n 7. Delete First");
		printf("\n 8. Delete Last");
		printf("\n 9. Delete After");
		printf("\n 10. Delete Before");
		printf("\n 11. Display List");
		printf("\n 12. Exit");
		printf("\n Enter your option : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\n Enter the element to be appended into the list : ");
				scanf("%d",&item);
				head = append(head,item);
				break;
			case 2:	printf("\n Enter the element to be inserted at the beginning of the list : ");
				scanf("%d",&item);
				head = insert_first(head,item);
				break;
			case 3:	printf("\n Enter the element to be inserted at last of the list : ");
				scanf("%d",&item);
				head = insert_last(head,item);
				break;
			case 4:	printf("\n After which element you want to insert the list : ");
				scanf("%d",&search);
				printf("\n Enter the element to be inserted to be inserted : ");
				scanf("%d",&item);
				head = insert_after(head,search,item);
				break; 
			case 11: display_list(head);
				 break;
			case 12: printf("\n Thank You");
				 exit(0);
				 break;
			/*case 13: display_last(head);
				 break;*/
			default: printf("\n Invalid Option");
				 exit(0);
		}
	}
	return 0;
}
