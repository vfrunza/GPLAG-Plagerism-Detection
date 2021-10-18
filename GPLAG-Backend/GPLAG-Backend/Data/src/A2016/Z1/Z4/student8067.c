#include <stdio.h>

int main() {
	int n,i,j,V;
	 
	do { printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<1||n>50) printf("Pogresan unos\n");
	
	 } while ( n<1 || n>50); 
	 
	if(n==1) {printf("***"); return 0; }
	
	V=4*n-3;
	for(i=0;i<n;i++) {
		for(j=0;j<V;j++){
		if (i==j || i+j==V-1 || j==V/2-i || j==V/2+i  ) printf("*");
		else printf(" ");
		
		}
	    printf("\n");
	
	}
return 0;
}
