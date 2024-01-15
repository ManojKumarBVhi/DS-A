#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

struct stack{
  int top;
  float data[SIZE];
};

typedef struct stack STACK;

void push(STACK *s, float item){
    if(s->top == SIZE - 1){
        printf("\n Overflow");
    }
    else{
        s->top = s->top + 1;
        s->data[s->top] = item;
    }
}

float pop(STACK *s){
    if(s->top == -1){
        printf("\n Underflow");
    }
    else{
        float p_item = s->data[s->top];
        s->top = s->top - 1;
        return p_item;
    }
}

float operation(char symbol,float opnd1,float opnd2){
    switch(symbol){
        case '+':  return opnd1+opnd2;
        case '-':  return opnd1-opnd2;
        case '*':  return opnd1*opnd2;
        case '/':  if(opnd2==0){
                    printf("\n Division by zero error");
                    exit(0);
                    }
                    else{
                        return opnd1/opnd2;
                    }
        default:  printf("\n Error\n");
                exit(0);
    }
}

float prefixeval(char prefix[]){
    STACK s;
    s.top = -1;

    int length;
    char symbol;
    float opnd1,opnd2,result,digit;
    length = strlen(prefix);

    for(int i = length - 1; i >= 0; i--){
        symbol = prefix[i];
        if(symbol >= '0' && symbol <= '9'){
            digit = (float)(symbol-'0');
            push(&s,digit);
        }
        else{
            opnd1 = pop(&s);
            opnd2 = pop(&s);
            result = operation(symbol,opnd1,opnd2);
            push(&s,result);
        }
    }
    result = pop(&s);
    if(s.top != -1){
        printf("\n Error");
        exit(0);
    }
    else{
        return result;
    }
}

int main(){
  char prefix[100];
  printf("\n Enter the prefix expression: ");
  scanf("%s",&prefix);
  
  float result;
  result = prefixeval(prefix);
  printf("\n Result is : %f",result);

  return 0;
}
