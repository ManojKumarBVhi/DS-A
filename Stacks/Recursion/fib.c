#include<stdio.h>

int fib(int n){
    if(n==0 ){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else{
        return fib(n-2) + fib(n-1);
    }
}

int main(){
    int num;
    printf("\n Enter the number upto which series of fibonacci you want : ");
    scanf("%d", &num);

    for(int i = 0; i <= num; i++ ){
        printf("%d\t",fib(i));
    }

    return 0;
}