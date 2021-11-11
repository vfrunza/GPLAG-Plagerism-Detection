#include <stdio.h>

int main() {
 
 int x,i,j; 
 do {
 printf("\nUnesite broj n: "); 
 scanf("%d", &x); 
 if(x<=0 || x>50) printf("Pogresan unos"); }
 while(x<=0 || x>50); 
 if(x==1) printf("***");
 else {
 for(  i=1; i<=x; i++) {
 	for( j=1; j<=(4*x-3); j++) {
 		if((i==j) || (i+j)==2*x || (j-i)==(2*x-2) || (i+j)==(4*x-2))
 		printf("*"); 
 		else printf(" "); 
 	}
 	printf("\n"); 
 }
 }
 return 0; 
} 

