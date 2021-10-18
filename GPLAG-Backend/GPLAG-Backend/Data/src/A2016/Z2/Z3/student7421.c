#include <stdio.h>

int main() {
	char matrica [20][20];
	int i= 0, j = 0, x_koordinata, y_koordinata;
	int broj_tacaka;
	for(; i < 20; ++i)
		for(j = 0; j < 20; ++j)
			matrica[i][j] = ' ';
	while(15){
		printf("Unesite broj tacaka: ");
		scanf("%d", &broj_tacaka);
		if(broj_tacaka <= 10 && broj_tacaka > 0)
			break;
		printf("Pogresan unos\n");
	}
	
	i = 1;
	while(i <= broj_tacaka){
		printf("Unesite %d. tacku: ", i);
		scanf("%d", &x_koordinata);
		scanf("%d", &y_koordinata);
		if(x_koordinata < 0 || x_koordinata > 19 || 
		   y_koordinata < 0 || y_koordinata > 19){
		   		printf("Pogresan unos\n");
		   		continue;
		   }
		++i;
		matrica[y_koordinata][x_koordinata] = '*';
	}
	i = 0;
	for(; i < 20; ++i){
		for(j = 0; j < 20; ++j)
			printf("%c", matrica[i][j]);
		printf("\n");
	}
	return 0;
}
