#include <stdio.h>

int main() {
    
    int n, i, j, k=0, l;
    for(;;) {
    printf("Unesite broj n: ");
    scanf("%d", &n);
    if(n>0 && n<51) break;
    printf("Pogresan unos\n"); }
    
    if(n==1) printf("***");
    else {
    k=n*2-2; l=n*4-4;
    for(i=0; i<n; i++) {
        for(j=0; j<n*4-3; j++) {
        
        if(i==j || i+2*n-2==j || j==k || j==l) printf("*");
        else printf(" ");
       
        } printf("\n"); k--; l--;
    }
    }
 return 0;
    
}