#include <stdio.h>
#include <string.h>

int main() {
	int i, j, n, xtacke[20], ytacke[20], k;
	char koord[20][20];
	memset(koord, ' ', sizeof(koord));
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10) printf("Pogresan unos\n");
	}while(n<=0 || n>10);
	for(i=0; i<n; i++){
		do{
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &xtacke[i], &ytacke[i]);
			if(xtacke[i]<0 || xtacke[i]>19 || ytacke[i]<0 || ytacke[i]>19) printf("Pogresan unos\n");
		}while(xtacke[i]<0 || xtacke[i]>19 || ytacke[i]<0 || ytacke[i]>19);
	}
	for(k=0; k<n; k++){
		for(i=0; i<20; i++){
			for(j=0; j<20; j++){
				if(xtacke[k]==j && ytacke[k]==i) koord[i][j] = '*';
			}
		}
	}
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			printf("%c", koord[i][j]);
		}
		printf("\n");
	}
	return 0;
}
