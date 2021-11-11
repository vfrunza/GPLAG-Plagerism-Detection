#include <stdio.h>


int main() {
	int i, j,  l, m, broj_tacaka;
	char  mat[20][20];
	/*j-visina, k-sirina, l-unesena koordinata na j-osi, m-unesena koordinata na l osi*/
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++){
			mat[i][j]=' ';
		}
	}
	do {
		printf("Unesite broj tacaka: ");
		scanf("%d", &broj_tacaka);
		if(broj_tacaka<=0 || broj_tacaka>10) {
			printf("Pogresan unos\n");
		}
	}
	while(broj_tacaka<=0 || broj_tacaka>10);
	for(i=0;i<broj_tacaka;i++) {
		do{
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &l, &m);
			if(l<0 || l>19 || m<0 || m>19) {
				printf("Pogresan unos\n");
			}
		}
		while(l<0 || l>19 || m<0 || m>19);
		mat[l][m]='*';
	}
	for(i=0;i<20; i++) {
		for(j=0;j<20; j++){
				printf("%c", mat[j][i]);
				
			}
		printf("\n");
	}
	return 0;
}
