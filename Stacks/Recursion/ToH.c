#include<stdio.h>

void ToH(int n, char source, char temp, char dest){
    if(n == 1){
        printf("\n Move %d disk from %c to %c ", n,source,dest);
    }
    else{
        ToH(n-1,source,dest,temp);
        printf("\n Move %d disk from %c to %c ",n,source,dest);
        ToH(n-1, temp,source,dest);
    }
}

int main(){
    int n;
    char source = 'A', temp = 'B', dest = 'C';
    printf("\n Enter the number of disks : ");
    scanf("%d",&n);
    ToH(n,source,temp,dest);

    return 0;
}
