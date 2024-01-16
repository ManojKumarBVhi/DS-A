#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 20

struct stack{
    int top;
    char data[SIZE];
};

typedef struct stack STACK;

void push(STACK *s, char item){
    s->top = s->top + 1;
    s->data[s->top]= item;
}

char pop(STACK *s){
    char p_item = s->data[s->top];
    s->top = s->top - 1;
    return p_item;
}

int preced(char symbol){
    switch(symbol){
        case '^':   return 5;
        case '*':
        case '/':   return 4;
        case '-':
        case '+':   return 2;
        default:    return -1;
    }
}

void infix_to_prefix(char infix[20], STACK *s){
    char prefix[20], symbol;
    int length = strlen(infix), i, j = 0;

    for(i = length - 1; i >= 0; i--) {
        symbol = infix[i];
        if(isalnum(symbol)) {
            prefix[j++] = symbol;
        }
        else {
            switch(symbol) {
                case ')':   push(s, symbol);// Originally '(', but we're iterating backwards
                            break;
                case '(':   while(s->top != -1 && s->data[s->top] != ')') {
                                prefix[j++] = pop(s);
                            }
                            if (s->top != -1) pop(s); // Pop the ')'
                            break;// Originally ')'
                default:    while(s->top != -1 && preced(s->data[s->top]) >= preced(symbol)) {
                                prefix[j++] = pop(s);
                            } // Operators
                            push(s, symbol);
        }
    }
}

    while(s->top != -1){ // Pop remaining operators from the stack
        prefix[j++] = pop(s);
    }
    prefix[j] = '\0'; // Null-terminate the string

    // Reverse the prefix expression
    for(i = 0; i < j / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[j - i - 1];
        prefix[j - i - 1] = temp;
    }

    printf("\nThe prefix Expression is: %s\n", prefix);
}

int main(){
    STACK s;
    s.top = -1;
    char infix[20];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_to_prefix(infix, &s);

    return 0;
}