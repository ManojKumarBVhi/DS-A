//Program to implement stack using an array

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5  //defining the size of the array

int top = -1;
int stack[SIZE];

void push(int item){
  if(top == SIZE-1){
    printf("\n STACK Overflow");
  }
  else{
    top = top+1;
    stack[top] = item;
  }
}

void pop(){
  if(top = -1){
    printf("\n STACK Underflow");
  }
  else{
    int p_item;  //to print popped item
    p_item = stack[top];
    top = top - 1;
    printf("\n The popped element from the stack is : %d", p_item);
  }
}

void display(){
  if(top == -1){
    printf("\n The STACK is Empty");
  }
  else{
    printf("\n The contents of the stack are: ");
    for(int i=top; i>=0; i--){
      printf("%d\n",stack[i]);
    }
  }
}

void display_top(){
  if(top == -1){
    printf("\n The STACK is Empty");
  }
  else{
    printf("\n The top element of the STACK is : %d", stack[top]);
  }
}

int main(){
  int ch,item;
  for(;;){
    printf("\n 1. Push");
    printf("\n 2. Pop");
    printf("\n 3. Dislapy");
    printf("\n 4. Display Top");
    printf("\n 5. Exit");
    printf("\n Enter the option : ");
    scanf("%d", &ch);
    switch(ch){
      case 1: printf("\n Enter the Element that need to be pushed into the stack : ");
              scanf("%d", &item)
              push(item);
              break;
      case 2: pop();
              break;
      case 3: display();
              break;
      case 4: display_top();
              break;
      default: exit(0);
                break;
      }
    }
    return 0;
  }
