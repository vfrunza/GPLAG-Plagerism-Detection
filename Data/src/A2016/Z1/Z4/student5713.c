#include<stdio.h>
int n, i, j;
int main(){
    do {
        printf("Unesite broj n: ");
        scanf("%d", &n);
        if(n<=0 || n>50) {printf("Pogresan unos\n"); continue;}
    } while (n<=0 || n>50);
    
    if(n==1) {printf("***"); return 0;}
    for(i=1; i<=n; i++){
        for(j=1; j<=4*n-3; j++){
            if(i==j || i+j==2*n || i+j==4*n-2 || j-i==2*n-2) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}