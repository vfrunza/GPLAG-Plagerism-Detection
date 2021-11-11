#include <stdlib.h>
#include <stdio.h>

int main(){
    int n,i,j;
    while (1){
        printf("Unesite broj n: ");
        scanf("%d",&n);
        if(n>0 && n<50) break;
        printf("Pogresan unos\n");
    }
    if (n==1) {printf("***");
    return 0;
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<(4*n);j++){
         if(i==j||j==((2*n)-2-i)||j==((2*n)-2+i)||j==((4*n)-4-i)) printf("*");
         else printf(" ");
        }
        printf("\n");
    }
    return 0;
}