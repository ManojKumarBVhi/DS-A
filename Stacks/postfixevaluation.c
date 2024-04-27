#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define SIZE 20

struct stack{
    int top;
    int data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, int item){
    s->data[++(s->top)] = item;
}

int pop(STACK *s){
    return (s->data[(s->top)--]);
}

int operation(int op1, char symbol, int op2){
    switch(symbol){
        case '+':   return op1+op2;
        case '-':   return op1-op2;
        case '*':   return op1*op2;
        case '/':   if(op2 == 0)
                        printf("Divide by zero error");
                    return op1/op2;
        case '^':   return pow(op1,op2);
    }
}

int postfixevaluation(STACK *s, char postfix[20]){
    int i,result,op1,op2;
    char symbol;
    for(i=0;postfix[i] != '\0'; i++){
        symbol = postfix[i];
        if(isdigit(symbol))
            push(s, symbol-'0');
        else{
            op2 = pop(s);
            op1 = pop(s);
            result = operation(op1,symbol,op2);
            
            push(s,result);
        }
    }
    return pop(s);
}

int main(){
    STACK s;
    s.top = -1;
    char postfix[20];
    printf("Enter the postfix expression : \n");
    scanf("%s",&postfix);
    int result = postfixevaluation(&s, postfix);
    printf("Result is : %d",result);
    return 0;
}
