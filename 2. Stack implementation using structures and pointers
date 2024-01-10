//Program to implement stack using structures and pointers

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct stack{
    int top;
    int data[SIZE];
};

typedef struct stack STACK;

void push(STACK *s, int item){
    if(s->top == SIZE - 1){
        printf("\n STACK Overflow");
    }
    else{
        s->top = s->top+1;
        s->data[s->top] = item;
    }
}

void pop(STACK *s){
    if(s->top == -1){
        printf("\n STACK Underflow");
    }
    else{
        int p_item;
        p_item = s->data[s->top];
        s->top = s->top - 1;
        printf("\n The popped element from the stack is : %d", p_item);
    }
}

void display(STACK s){
    if(s.top == -1){
        printf("\n The STACK is empty");
    }
    else{
        printf("\n The STACK contents are : \n");
        for(int i=s.top; i>=0; i--){
            printf("%d\n", s.data[i]);
        }
    }
}

void display_top(STACK s){
    if(s.top == -1){
        printf("\n The STACK is Empty");
    }
    else{
        printf("\n The Top Element of the STACK is : %d", s.data[s.top]);
    }
}

int main(){
    STACK s;
    s.top = -1;
    int ch,item;
    for(;;){
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Display");
        printf("\n 4. Display Top");
        printf("\n 5. Exit");
        printf("\n Enter the option : ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("\n Enter the element that need to be pushed into the stack : ");
                    scanf("%d", &item);
                    push(&s, item);
                    break;
            case 2: pop(&s);
                    break;
            case 3: display(s);
                    break;
            case 4: display_top(s);
                    break;
            default: exit(0);
                        break;
        }
    }
    return 0;
}
