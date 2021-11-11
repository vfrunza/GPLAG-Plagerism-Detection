#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;

    do{
        printf("Unesite broj n: ");
        scanf("%d",&n);
        if(n<=0||n>50){
            printf("Pogresan unos");
            printf("\n");
        }
    }while(n<=0||n>50);
    
    if(n==1){ printf("**");}

    for(i=0;i<n;i++){
        for(j=0;j<=4*(n-1);j++){
            if(i==j||i+j==2*(n-1)||j-i==2*(n-1)||j+i==4*(n-1)){
                printf("*");
            } else printf(" ");
        }
        printf("\n");
    }
    return 0;
}