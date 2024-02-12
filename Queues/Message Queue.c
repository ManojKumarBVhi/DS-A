#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

struct queue{
  int front, rear;
  char data[SIZE][100];
};

typedef struct queue Q;

void send(Q *q, char item[100]){
  if((q->rear + 1) % SIZE == q->front){
    printf("\n Queue is Full");
  }
  else{
    q->rear = (q->rear + 1) % SIZE;
    strcpy(q->data[q->rear], item);
    if(q->front == -1){
      q->front = q->rear;
    }
  }
}

void receive(Q *q){
  if(q->front == -1){
    printf("\n Queue is empty");
  }
  else{ 
    char p_item[100];
    strcpy(p_item, q->data[q->front]);
    if(q->front == q->rear){
      q->front = q->rear = -1;
    }
    else{
      q->front = (q->rear + 1) % SIZE;
    }
    printf("\n The received message is : %s", p_item);
  }
}

void display(Q q){
  if(q.front == -1){
    printf("\n Queue is Empty");
  }
  else{
    printf("\n Message of Queue are : ");
    for(int i = q.front; i != q.rear; i = (i + 1) % SIZE){
      printf("%s\n",q.data[i]);
    }
    printf("%s\n",q.data[q.rear]);
  }
}

int main(){
  Q q = {-1,-1};
  int ch;
  char item[100];
  for(;;){
    printf("\n 1. Send");
    printf("\n 2. Receive");
    printf("\n 3. Display");
    printf("\n 4. Exit");
    printf("\n Enter your option : ");
    scanf("%d", &ch);
    getchar();
    switch(ch){
      case 1:  printf("\n Enter the message you want to be enqueued into the message queue : ");
               fgets(item, sizeof(item), stdin);
               item[strcspn(item, "\n")] = 0;
               send(&q,item);
               break;
      case 2:  receive(&q);
               break;
      case 3:  display(q);
               break;
      case 4:  printf("\n Thank you for using message queue " );
               exit(0);
               break;
      default: printf("\n Invalid Option");
               break;
    }
  }
}
