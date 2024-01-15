#include<stdio.h>

int fact(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * fact(n-1);
    }
}

int main(){
    int num;
    printf("\n Enter the number that you want to have the factorial : ");
    scanf("%d", &num);

    printf("\n The factorial of the number %d is : %d", num,fact(num));

    return 0;
}