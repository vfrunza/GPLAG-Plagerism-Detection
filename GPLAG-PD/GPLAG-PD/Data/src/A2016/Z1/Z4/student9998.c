#include <stdio.h>

int main() {
    int n,i,j,k,kol;
    printf("Unesite broj n: ");
    scanf("%d", &n);
    
    while(n<=0 || n>50){
        printf("Pogresan unos\n");
        printf("Unesite broj n: "); scanf("%d", &n);
    }
    
    if(n==1) kol=3*n;
    else kol=4*n-3;
    for(i=0;i<n;i++){
    	for(j=0;j<kol;j++){
    		if(i==j || i+j==kol/2 || i+kol/2==j || i+j==kol-1) printf("*");
    		else  printf(" ");
    	}
    
    	printf("\n");
      }
    
	return 0;
}
