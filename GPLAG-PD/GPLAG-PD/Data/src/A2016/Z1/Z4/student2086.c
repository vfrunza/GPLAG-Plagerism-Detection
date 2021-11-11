#include <stdio.h>
int main() {
	int x, y, n;
	do {printf("Unesite broj n: "); 
		scanf("%d", &n);
	if (n<=0 || n>50){
		printf ("Pogresan unos \n");
	} if (n==1){printf("***"); return 0;}
	} while (n<=0 || n>50);
	for(x=0;x<n;x++){
		for(y=0;y<4*n;y++){
			if ((x==y) || (y==2*n-x-2) || (y==4*n-x-4) || (y==2*n+x-2))printf("*"); else printf(" ");
		} printf("\n");}
	return 0;
}
