#include <stdio.h>

int main() {
	int broj_redova,broj_kolona,sirinajednekolone;
	int i,j,z,n,k;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &broj_redova);
	}while(broj_redova<=0 || broj_redova>10);
	
	do {
		printf("Unesite broj kolona: ");
		scanf("%d", &broj_kolona);
		} while(broj_kolona<=0 || broj_kolona>10);
		 
	do {
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirinajednekolone);
		
	} while(sirinajednekolone<=0 || sirinajednekolone>10);
	
	
 for(i=0; i<broj_redova; i++) {
 	for(j=0; j<broj_kolona; j++) {
 		
 			printf("+");
 			for(z=0; z<sirinajednekolone; z++) {
 				printf("-");
 			}
 	} printf("+\n");
 	//Dalje mi treba ispisivati redove..
 	
 	for(j=0; j<broj_kolona; j++) {
 		printf("|"); 
 			for(n=0; n<sirinajednekolone; n++) {
 				printf(" ");
 			}
 		} printf("|\n");
 	}  /*fali jos plusića*/
 	/*mozda jos jedna petlja..*/
 	
  for(j=0; j<broj_kolona; j++) {
 	printf("+"); 
 	for(k=0; k<sirinajednekolone; k++) {
 		printf("-");
 	}
 } printf("+");

	
	return 0;
}
