#include <stdio.h>

int main() {
	int i, j, matricaA[100][100], visinaA, sirinaA, matricaB[100][100], visinaB, sirinaB, temp, transponovana[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d", &visinaA, &sirinaA);
	printf ("Unesite clanove matrice A: ");
	for (i=0; i<visinaA; i++){
		for (j=0; j<sirinaA; j++){
		scanf ("%d", &matricaA[i][j]);	
		}
	}
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &visinaB, &sirinaB);
	printf ("Unesite clanove matrice B: ");
	for (i=0; i<visinaB; i++){
		for(j=0;j<sirinaB; j++){
			scanf ("%d", &matricaB[i][j]);
		}
	}
	
	/*Transponovanje*/
	for (i=0; i<visinaA; i++){
		for (j=0; j<sirinaA; j++){
		  transponovana[j][i]=matricaA[i][j];
		}
	}
	/*NAPOMENA: Visina i Sirina se mijenjaju*/
	/*Zamjena kolona*/
	for (i=0; i<sirinaA; i++){
		for (j=0; j<visinaA/2; j++){
			temp=transponovana[i][j];
			transponovana[i][j]=transponovana[i][visinaA-1-j];
			transponovana[i][visinaA-1-j]=temp;
		}
	}
    if (sirinaA!=visinaB || visinaA!=sirinaB){
		printf ("NE\n");
		return 0;
	}
	for (i=0; i<sirinaA; i++){
		for (j=0; j<visinaA; j++){
			if (transponovana[i][j]!=matricaB[i][j]){
				printf ("NE\n");
				return 0;
			}
		}
	}
	printf ("DA\n");
	return 0;
}



