#include <stdio.h>

int main() {
	int i,j,n;
	int broj_kolona;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	/*Provjera da li je broj koji unesemo prirodan ili veci od 50*/
	while(n > 50 || n <= 0){
		printf("Pogresan unos\n");
		printf("Unesite broj n: ");
		scanf("%d", &n);
	}
	if(n==1)
		printf("***");
	else {
		broj_kolona = n+3*(n-1);
	
	for(i = 1;i <= n;i++){
		for(j = 1;j <= broj_kolona;j++){
			if (j==i || j==(broj_kolona/2)+i || j==broj_kolona-i+1 || j==(broj_kolona/2)+2-i)
				printf("*");
			else printf(" ");
			}
			printf("\n");
		}
		
	}
	return 0;
}
