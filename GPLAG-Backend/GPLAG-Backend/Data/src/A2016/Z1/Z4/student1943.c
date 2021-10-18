#include <stdio.h>

int main() {
	int i=0,j=0;
	int n;
	int a=0;
	printf("Unesite broj n: ");
	for(;;) {
	scanf("%d",&n);
	if(n<=0 || n>50) { printf("Pogresan unos\n");
	                   printf("Unesite broj n: ");
	                   continue; 
	}
	break;
	}
	if(n==1) {  printf("***"); return 0; }
	a=n+3*(n-1);
	
	for(i=0;i<n;i++) {
		for(j=0;j<=a;j++) {
			if(i==j) printf("*");
			else if( i!=n-1 && i+j==a/2) printf("*");
			else if(i!=0 &&  i+a/2==j) printf("*");
			else 	if(i!=n-1 && i+j==a-1 ) printf("*");
			else printf(" "); 
		}
		printf("\n");
	}
	
	
	return 0;
}
