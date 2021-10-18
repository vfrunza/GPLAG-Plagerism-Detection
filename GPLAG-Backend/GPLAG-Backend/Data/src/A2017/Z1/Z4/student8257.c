#include <stdio.h>

int main() {
	int broj_red,broj_kol,sirina_kol;
	int i,j,k;
	do {
		printf("Unesite broj redova: ");
		scanf("%d",&broj_red);
	} while(broj_red<=0 || broj_red >10);
	do {
		printf("Unesite broj kolona: ");
		scanf("%d",&broj_kol);
	}  while(broj_kol <=0 || broj_kol>10);
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sirina_kol);
	} while( sirina_kol<=0 || sirina_kol>10);
	
		// Prvi red
		
		printf("+");
		for (j=0;j<broj_kol;j++) {
			for(k=0;k<sirina_kol;k++){
				printf("-");
			}
			printf("+");
		}
		printf("\n");
		
		// OSTATAK TABELE
		
		for(i=0;i<broj_red*2;i++) {
			
			// PARNI REDOVI ( PIPE redovi)
			
			if(i%2==0){
				printf("|");
				for(j=0;j<broj_kol;j++){
					for(k=0;k<sirina_kol;k++)
						printf(" ");
					printf("|");
				}
				
			}
			 // NEPARNI REDOVI (COPY-PASTE prvog reda)
			 
			else {
					printf("+");
					for (j=0;j<broj_kol;j++) {
						for(k=0;k<sirina_kol;k++){
							printf("-");
						}
					printf("+");
					}
				}
			printf("\n");
		}
		
	
	return 0;
}
