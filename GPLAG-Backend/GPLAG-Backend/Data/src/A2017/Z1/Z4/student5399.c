#include <stdio.h>

int main() {
	int brojRedova = 0;
	int brojKolona = 0;
	int sirina = 0;
	int i, j,k;
	do
	{
		printf("Unesite broj redova: ");
		scanf("%d",&brojRedova);	
	}while(brojRedova < 1 || brojRedova > 10);
	do
	{
	printf("Unesite broj kolona: ");
	scanf("%d", &brojKolona);
	}while (brojKolona < 1 || brojKolona > 10);
	do
	{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sirina);
	}while (sirina < 1 || sirina > 10);
	
	for(i = 0; i < brojRedova +1;i++){
		for(j = 0; j < (sirina*brojKolona + brojKolona+1); j++){
			if(j % (sirina+1) == 0 || j == 0){
				printf("+");
			}else{
				printf("-");
			}
		}
		printf("\n");
		if(i == brojRedova)
			continue;
		for(k = 0; k < (sirina*brojKolona + brojKolona+1); k++){
			if(k % (sirina+1) == 0 || k == 0){
				printf("|");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
