#include <stdio.h>

int main() {
	int i, j, n, x;
	unos:
	printf("Unesite broj n: ");
	scanf("%d", &n);
	if(n<1 || n>50){ printf ("Pogresan unos\n"); goto unos;}
	
	if (n==1)printf ("***");
	else {
		x=n+(n-1)*3;
	for (i=1; i<=n; i++){
		
		for(j=1;j<=x;j++){
			if(j==i||j==(x/2)+i||j==x-i+1 ||j==(x/2)+2-i) printf("*");
			else printf (" ");
	
		}	
		printf("\n");
	}
	}
	return 0;
}
