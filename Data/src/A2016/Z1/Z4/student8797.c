#include <stdio.h>

int main() {
	int n;
	int i;
	int j;
	int k;
	int h;
	int g;
	int l;
	int p;
	int a;
	int b;
	
	do{
	
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if (n<1 || n>50) printf("Pogresan unos\n"); 
	
	} while (n<1 || n>50);
	
	
	
	
	if (n==1) printf("***");
	else{
	printf("*"); for (i=0; i<(2*n-3); i++) printf(" "); printf("*"); for(j=0; j<(2*n-3); j++) printf(" "); printf("*\n"); 
	
	for(k=1; k<=(n-2); k++){
	                         
	                       for (h=1;  h<(k+1);          h++)   printf(" ");   printf("*");
	                       for (g=0;  g<(2*n-3-2*k);    g++)   printf(" ");   printf("*");
	                       for (l=0;  l<(2*k-1);        l++)   printf(" ");   printf("*");
	                       for (p=0;  p<(2*n-3-2*k);    p++)   printf(" ");   printf("*\n");
	                       
	
                          }
    for(a=0; a<(n-1); a++) printf(" "); printf("*"); for(b=0; b<(2*n-3);b++) printf(" "); printf("*");                      

	} return 0;
}
