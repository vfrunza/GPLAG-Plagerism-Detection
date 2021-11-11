#include <stdio.h>
#define visA 100
#define sirA 100
#define visB 100
#define sirB 100

int main() {
	int sirinaA=0, visinaA=0,sirinaB=0,visinaB=0,i=0,j=0,matricaA[visA][sirA],matricaB[visB][sirB],brojac=0,pom;
	printf ("Unesite sirinu i visinu matrice A: ");
	scanf ("%d %d",&sirinaA, &visinaA);
	printf ("Unesite clanove matrice A: ");
	for (i=0;i<visinaA;i++) {
		for (j=0;j<sirinaA;j++) {
			scanf ("%d ",&matricaA[i][j]);
		}
	}
	printf ("Unesite sirinu i visinu matrice B: ");
	scanf ("%d %d", &sirinaB, &visinaB);
	printf ("Unesite clanove matrice B: ");
	for (i=0;i<visinaB;i++) {
		for(j=0;j<sirinaB;j++) {
			scanf ("%d ",&matricaB[i][j]);
		}
	}
	for (i=0;i<visinaA;i++) {
		for (j=0;j<sirinaA;j++) {
			for(i=0;i<visinaA;i++) {
				for(j=0;j<sirinaA;j++) {
			
			pom==matricaA[i][j];
			matricaA[i][j]==matricaB[j][i];
			matricaB[j][i]==pom;
				
			
			if(pom!=matricaA[i][j]) {
				brojac++;
					}
				}
			}
		}
	}
	if (brojac==0) {
		printf("DA\n");
		
	}
	else {
		printf ("NE\n");
		
	}
	
	return 0;
}
