#include <stdio.h>

int main() {
    int n,i,j;
    printf("Unesite broj n: ");
    scanf("%d",&n);
    if(n==1) printf("**");
    while(n<=0 || n>50){
        printf("Pogresan unos\n");
        printf("Unesite broj n: ");
        scanf("%d",&n);
        }
	for(i=0; i<n; i++) {
	    for(j=0; j<(4*n-1); j++) {
	      if(i==j) 
	      printf("*");
	      else if(j==((2*n)-i-2))
	      printf("*");
	      else if(j==(2*n)+i-2) 
	      printf("*");
	      else if(j==((4*n-1)-i)-3)
	      printf("*");
	      else printf(" ");
	      }
	    printf("\n");
	}
	
	return 0;
}