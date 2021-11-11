/*Napravite program koji omogućuje unos dvije matrice realnih brojeva A i B. Najprije se unose dimenzije matrice A, pa 
matrica A, pa dimenzije matrice B i konačno članovi matrice B. Program treba ispisati DA ako je matrica B jednaka matrici 
A zarotiranoj za 90° u smjeru kazaljke na satu, a NE ako nije. Primjeri matrica koje su zarotirane:

Primjer ulaza i izlaza:
	Unesite sirinu i visinu matrice A: 2 2
	Unesite clanove matrice A: 1 2 3 4
	Unesite sirinu i visinu matrice B: 2 2
	Unesite clanove matrice B: 3 1 4 2
	DA

Napomena: Rješenje koje uvijek ispisuje DA ili NE ili hardcodira rješenja (npr. ako je matrica jednaka nekoj iz autotesta
uvijek ispisuje DA ili NE) biće bodovana sa 0 bodova bez obzira na potencijalno ispravne dijelove koda!
*/

#include <stdio.h>
#include<math.h>

int main(){
	double matA[100][100],matB[100][100];
	int vA,sA,vB,sB,i,j,t;

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d", &sA, &vA);
	printf("Unesite clanove matrice A: ");
	
	for(i=0; i<vA ;i++){
		for(j=0; j<sA; j++){
			scanf("%lf", &matA[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d", &sB, &vB);
	printf("Unesite clanove matrice B: ");
	
	for(i=0;i<vB;i++){
		for(j=0;j<sB;j++){
			scanf("%lf", &matB[i][j]);
		}
	}

	t=1;

	if((vA==sB && sA==vB) || (vA==vB && sA==sB && vA==sA)){
		for(i=0; i<vA; i++){
			for(j=0; j<sA; j++){
				if(!(fabs(matA[i][j]-matB[j][vA-i-1])<0.0001)){
				printf("NE");
				t=0;
					break;
				}
				
			}
		if(!t)
		break;
		}
		
		if(t)
		printf("DA");
		
	}
	else{
		printf("NE");
	}
	
	return 0;
}
