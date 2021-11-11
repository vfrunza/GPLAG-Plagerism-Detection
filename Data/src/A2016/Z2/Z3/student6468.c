#include <stdio.h>

int main() {
	int matrica[20][20];
	int tmpX, tmpY, i, j, counter=-1, tmp=0;
	for(i=0; i<20; i++)
		for(j=0; j<20; j++)
			matrica[i][j] = 0;
	
	for(;;){
		printf("Unesite broj tacaka: ");
		scanf("%i", &counter);
		if(counter >=1 && counter <=10) break;
		else printf("Pogresan unos\n");
	}
	for(;;){
		printf("Unesite %i. tacku: ", tmp+1);
		scanf("%i %i", &tmpX, &tmpY);
		if(tmpX<0 || tmpX>19 || tmpY<0 || tmpY>19)
			printf("Pogresan unos\n");
		else{
			matrica[tmpY][tmpX]=1;
			tmp++;
		}
		if(tmp == counter) break;
	}
	
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			if(matrica[i][j] == 0) printf(" ");
			else printf("*");
		}
		printf("\n");
	}
	return 0;
}
