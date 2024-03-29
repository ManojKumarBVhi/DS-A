#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE append(NODE head,int item){
    NODE newnode = (NODE)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("\n Insufficient Memory");
        exit(0);
    }

    newnode->data = item;
    newnode->next = NULL;
    
    if(head == NULL){
        head = newnode;

        return head;
    }
    else{
        NODE temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

NODE insert_first(NODE head,int item){
    NODE newnode = (NODE)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("\n Insufficient Memory");
        exit(0);
    }
    newnode->data = item;
    newnode->next = head;

    head = newnode;
    
    return head;
}

NODE insert_last(NODE head,int item){
    NODE newnode = (NODE)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("\n Insufficient memory");
        exit(0);
    }
    newnode->data = item;
    newnode->next = NULL;
    if(head == NULL){
        return newnode;
    }
    else{
        NODE temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

NODE search(NODE head, int item){
  NODE temp = head;
  while(temp != NULL){
    if(temp->data == item){
      return temp;
    }
    temp = temp->next;
  }
  printf("\n Element not found");
  return NULL;
}

NODE insert_after(NODE head,int search, int item){
  NODE newnode = (NODE)malloc(sizeof(struct node));
  if(newnode == NULL){
    printf("\n Insufficient memeory");
    exit(0);
  }
  if(head == NULL){
    printf("\n Empty list");
    free(newnode);
    exit(0);
    return NULL;
  }
  NODE temp = head;
  while(temp != NULL){
    if(temp->data == search){
      newnode->data = item;
      newnode->next = temp->next;
      temp->next = newnode;

      return head;
    }
    temp = temp->next;
  }
  printf("\n %d is not found in the list",search);
  free(newnode);
  return head;
}

NODE insert_before(NODE head, int search, int item){
	NODE newnode = (NODE)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->next = NULL;
	if(head == NULL){
		printf("\n Empty list");
		free(newnode);
		exit(0);
	}
	if(head->data == search){
		newnode->next = head;
		head = newnode;
		
		return head;
	}
	else{
		NODE prev = NULL;
		NODE temp = head;
		while(temp != NULL && temp->data != search){
			prev = temp;
			temp = temp->next;
		}
		newnode->next = prev->next;
		prev->next = newnode;
				
	}
	return head;
}
		
NODE delete_first(NODE head){
    if(head == NULL){
        printf("\n Empty list");
        exit(0);
    }
    else if((head->next == NULL)){
        printf("\n Deleted element is : %d",head->data);
        free(head);
        return NULL;
    }
    else{
        NODE first = head;
        head = first->next;
        printf("\n Deleted node is : %d",first->data);
        free(first);
        printf("\n");
    }
    return head;
}

NODE delete_last(NODE head){
    if(head == NULL){
        printf("\n Empty list");
        exit(0);
    }
    else if(head->next == NULL){
        printf("\n Deleted element is : %d",head->data);
        free(head);
        return NULL;
    }
    else{
        NODE temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        printf("\n Deleted node is : %d",temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
    return head;
}

//delete at specific point to be implemented.
NODE delete_after(NODE head, int search){
    if(head == NULL){
        printf("\n Empty List");
        return NULL;
    }
    NODE temp = head;
    while(temp->next != NULL){
        if(temp->data == search){
            NODE todelete = temp->next;
            if(todelete == NULL){
                return head;
            }
            temp->next = todelete->next;
            printf("\n Deleted node is : %d",todelete->data);
            free(todelete);
            return head;
        }
        temp = temp->next;
    }
    printf("\n %d is not available in the list",search);
    return head;
}

NODE delete_before(NODE head, int search){
	NODE ptr1 = NULL;
	int del_item;
	if(head == NULL){
		printf("\n Empty List");
		return NULL;
	}
	if(head->next != NULL && head->next->data == search){
		del_item = head->data;
		ptr1 = head;
		head = head->next;
		printf("\n Deleted node is : %d",del_item);
		free(ptr1);
		return head;
	}
	if(head->data == search){
		printf("\n No node before %d node",search);
		return head;
	}
	else{
		NODE temp = head;
		NODE ptr2 = NULL;
		while(temp!= NULL && temp->data != search){
			ptr2 = ptr1;
			ptr1 = temp;
			temp = temp->next;
		}
		ptr2->next = temp;
		free(ptr1);
	}
	return head;
}
	
void display_list(NODE head){
    if(head == NULL){
        printf("\n Empty list");
        exit(0);
    }
    else{
        NODE temp = head;
        while(temp->next != NULL){
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("%d\t",temp->data);
    }
}

NODE reverse(NODE head){
	if(head == NULL){
		printf("Empty List");
		exit(0);
	}
	else{
		NODE prev = NULL;
		NODE next = NULL;
		NODE current = head;
		while(current != NULL){
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	return head;
}

int main(){
    int ch,item,search;
    NODE head = NULL;
    for(;;){
        printf("\n 1. Append the element");
        printf("\n 2. Insert element at first");
        printf("\n 3. Insert Element at last");
        printf("\n 4. Insert after specific place");
        printf("\n 5. Insert before specified place");
        printf("\n 6. Delete first element");
        printf("\n 7. Delete last element");
        printf("\n 8. Delete after specific place");
        printf("\n 9. Delete before specific place");
        printf("\n 10. Display the list");
        printf("\n 11. Reverse the list");
        printf("\n 12. Exit");
        printf("\n Enter your option : ");
        scanf("%d",&ch);
            switch(ch){
                case 1: printf("\n Enter the element to be appended to the list : ");
                        scanf("%d",&item);
                        head = append(head,item);
                        break;
                case 2: printf("\n Enter the element to be inserted at first : ");
                        scanf("%d",&item);
                        head = insert_first(head,item);
                        break;
                case 3: printf("\n Eenter the element to be inserted at last : ");
                        scanf("%d",&item);
                        head = insert_last(head,item);
                        break;
                case 4: printf("\n Enter the key item to be search to insert after that element : ");
                        scanf("%d",&search);
                        printf("\n Enter the element to be inserted : ");
                        scanf("%d",&item);
                        head = insert_after(head,search,item);
                        break;
                case 5: printf("Enter the element to search to insert before : ");
                	scanf("%d",&search);
                	printf("Enter a the element to insert : ");
                	scanf("%d",&item);
                	head = insert_before(head,search,item);
                        break;
                case 6: head = delete_first(head);
                        break;
                case 7: head = delete_last(head);
                	break;
                case 8: printf("\n Enter the searching item : ");
                        scanf("%d",&search);
                        head = delete_after(head,search);
                        break;
                case 9: printf("\n Enter the searching element : ");
                	scanf("%d", &search);
                	head = delete_before(head,search);
                	break;
                case 10: display_list(head);
                         break;
                case 11: head = reverse(head);
                	 break;
                case 12: printf("\n Thank you");
                         exit(0);
                default: printf("\n Invalid Option");
                         exit(0);
          }
     }
     return 0;
}
