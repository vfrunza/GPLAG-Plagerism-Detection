#include <stdio.h>
#define SIZE 20
int main() {
	
	char niz[SIZE][SIZE] = {' '};
	int i,j,tmp;
	int unos = -1, tackaA,tackaB;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&unos);
	if(unos > 0 && unos <= 10 ) break;
	printf("Pogresan unos\n");
	}while(1);
	for (i = 1; i <= unos;) {
		printf("Unesite %d. tacku: ",i);
		scanf("%d %d", &tackaB, &tackaA);
		if(tackaA > 19||tackaA < 0){ 
			printf("Pogresan unos\n");
			continue;
		}
		if(tackaB > 19 || tackaB < 0){ 
			printf("Pogresan unos\n");
			continue;
		}
		niz[tackaA][tackaB] = '*';
		i++;
	}
	
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if(niz[i][j] == '*')
			printf("%c",niz[i][j]);
			else
			printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
