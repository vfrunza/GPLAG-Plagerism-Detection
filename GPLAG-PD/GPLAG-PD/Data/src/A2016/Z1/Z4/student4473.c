#include <stdio.h>

int main() {
	int n,i,j;
	printf("Unesite broj n: ");
	scanf ("%d", &n);

	if (n<=0 || n>50){
		do {
			printf ("Pogresan unos");
			printf ("\nUnesite broj n: ");
			scanf ("%d", &n);
		} while (n<0 || n>50);
	}
	if (n==1) { printf ("**");}
	for (i=1;i<=n;i++){
		for (j=1;j<=5+4*(n-2);j++){
		  if ( i==j || i==2*n-j || i==j+2-2*n || j==4*(n-2)+6-i)
		  printf ("*");
		  else printf (" ");}
		printf("\n");}
		
	return 0;
}
