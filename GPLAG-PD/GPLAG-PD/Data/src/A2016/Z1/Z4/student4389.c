#include <stdio.h>

int main() {
    int n, i, j, k;
    do{
        printf("Unesite broj n: ");
        scanf("%d", &n);
        if(n<=0 || n>50){
            printf("Pogresan unos\n");
        }
    }while(n<=0 || n>50);
    if(n==1){
        printf("***");
    }else{
        for(i=n; i>=1; i--){
            
            for(j=i; j<n; j++){
                printf(" ");
            }
            
            for(j=1; j<=(2*i-1); j++){
                if(i==n && j==(2*i-1)){;}
                else if(j==1 || j==(2*i-1)){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            
            for(k=n-1; k>i; k--){
                printf(" ");
            }
             for(j=i; j<n; j++){
                printf(" ");
            }
            
            for(j=1; j<=(2*i-1); j++){
                if(j==1 || j==(2*i-1)){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}