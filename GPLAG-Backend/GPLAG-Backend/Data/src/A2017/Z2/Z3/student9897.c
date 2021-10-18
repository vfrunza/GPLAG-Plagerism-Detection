#include <stdio.h>

int main() {
	int visinaA, sirinaA, A[100][100],sirinaB, visinaB, B[100][100],NN[100][100],K[100][100];
	int i,j,random=0,brojac=0;
	  /*Unos matrice A */
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirinaA, &visinaA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visinaA; i++) {
		for(j=0; j<sirinaA; j++) {
			scanf("%d", &A[i][j]);
		}
	}
		
		/*Unos matrice B*/
		printf("Unesite sirinu i visinu matrice B: ");
		scanf("%d %d", &sirinaB,&visinaB);
		printf("Unesite clanove matrice B: ");
			for(i=0; i<visinaB; i++) {
				for(j=0; j<sirinaB; j++) {
					scanf("%d", &B[i][j]);
				}
			}
			/*matrica B = A+90 stepeni*/
			
			if(sirinaA==visinaB && visinaA==sirinaB) {
				/*Prodji petljom kroz matricu B*/
				for(i=0; i<visinaB; i++) {
					for(j=0; j<sirinaB; j++) {
						random=A[j][i];
						NN[sirinaA-1-i][visinaA-1-j]=random;}
						
					
				}
				/*Ponovno for petljom kroz matricu B ali sada obrnutim redoslijedom*/
			 
			for(i=0; i<sirinaB; i++) {
				for(j=0; j<visinaB; j++) {
					/*Eh sada, pravim novi niz od NN niza ...*/
					random=NN[j][i];
			/*konacan -K*/		K[visinaB-1-1*j][i]=random;
					
				}
			} 
			/*Nakon dobivenog konacnog treba uporediti matricu B koju okrecem sa prethodno dobivenom*/
			for(i=0; i<sirinaB; i++) {
				for(j=0; j<visinaB; j++) {
					if(B[j][i]==K[j][i]) {
						brojac++;
							
						}
					}
				}
				if(brojac==sirinaA*visinaA || brojac==sirinaB*visinaB){ 
					printf("DA\n");
					
				}
				else 
					printf("NE\n"); }
				else 
					printf("NE\n");
			
					
					
					
	return 0;
}
