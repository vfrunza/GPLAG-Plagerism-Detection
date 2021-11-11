#include <stdio.h>

int main() {
	int n,r,k;
	
	/*Unos broja n*/
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	/*Pogresan unos ako broj nije u intervalu*/
	
	while(n<=0 || n>50) {
	printf("Pogresan unos");
	printf("\nUnesite broj n: ");
	scanf("%d", &n);}
	
	if(n==1) {
	printf ("***");
	return 0; }
	
	/*Petlja za izvrsenje zadatka*/
	
	r=0;
	while (r<n) {
		for(k=0; k<4*n-3; k++) {
		if (r==k || 2*n-2-r==k) {
		printf("*");}
		else if (2*n-2+r==k || 4*n-4-r==k) {
		printf("*");}
		else
		{printf(" ");}
		
	}
	r++;
		printf("\n");}
	
	return 0;
}
