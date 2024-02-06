#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 20

struct stack {
    int top;
    char data[SIZE];
};

typedef struct stack STACK;

void push(STACK *s, char item){
    s->top = s->top + 1;
    s->data[s->top] = item;
}

char pop(STACK *s){
    char p_item = s->data[s->top];
    s->top = s->top - 1;
    return p_item;
}

int preced(char symbol){
    switch(symbol){
        case '^': return 5;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 1;
        default : return -1; // Added return statement for the default case
    }
}

void infix_to_postfix(char infix[20], STACK *s){
    char postfix[20], symbol, temp;
    int i, j = 0;
    for(i = 0; infix[i] != '\0'; i++){
        symbol = infix[i];
        if(isalnum(symbol)){
            postfix[j++] = symbol;
        }
        else{
            switch(symbol){
                case '(': push(s, symbol);
                          break;
                case ')': while(s->top != -1 && s->data[s->top] != '('){
                              postfix[j++] = pop(s);
                          }
                          pop(s); // Pop the '('
                          break; 
                case '+':
                case '-':
                case '*':
                case '/':
                case '^': while(s->top != -1 && preced(s->data[s->top]) >= preced(symbol) && s->data[s->top] != '('){  //while stack is not empty AND precedence of top item is greater than precedence of scanned symbol AND top item is not equal to left
                              postfix[j++] = pop(s);
                          }
                          push(s, symbol);
                          break;
            }
        }
    }
    while(s->top != -1){
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    printf("Postfix Expression is: %s", postfix);
}

int main(){
    STACK s;
    s.top = -1;
    char infix[20];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infix_to_postfix(infix, &s);

    return 0;
}
