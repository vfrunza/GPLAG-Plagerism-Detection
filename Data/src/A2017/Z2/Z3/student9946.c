#include <stdio.h>

int main()
{
	int visinaMatriceA,sirinaMatriceA,Amatrica[100][100];
	int sirinaMatriceB,visinaMatriceB,Bmatrica[100][100];
	int K[100][100],NN[100][100];
	int i,j,zarotirano=0,brojac=0;

	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirinaMatriceA,&visinaMatriceA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visinaMatriceA; i++) {
		for(j=0; j<sirinaMatriceA; j++) {
			scanf("%d",&Amatrica[i][j]);
		}
	}


	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirinaMatriceB,&visinaMatriceB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visinaMatriceB; i++) {
		for(j=0; j<sirinaMatriceB; j++) {
			scanf("%d",&Bmatrica[i][j]);
		}
	}
/*da li je matrica b jednaka matrici a kad je zarotiram za 90 stepeni*/
	if(sirinaMatriceA==visinaMatriceB && visinaMatriceA==sirinaMatriceB) {

		for(i=0; i<visinaMatriceB; i++) {
			for(j=0; j<sirinaMatriceB; j++) {
				zarotirano=Amatrica[j][i];
				NN[sirinaMatriceA-1-i][visinaMatriceA-1-j]=zarotirano;
			}
		}



		for(i=0; i<sirinaMatriceB; i++) {
			for(j=0; j<visinaMatriceB; j++) {
				zarotirano=NN[j][i];
				K[visinaMatriceB-1-j][i]=zarotirano;
			}
		}



		for(i=0; i<sirinaMatriceB; i++) {
			for(j=0; j<visinaMatriceB; j++) {
				if(Bmatrica[j][i]==K[j][i]) {
					brojac++;
				}
			}
		}

		if(brojac==sirinaMatriceA*visinaMatriceA || brojac==sirinaMatriceB*visinaMatriceB) {
			printf("DA\n");
		} else {
			printf("NE\n");

		}
	} else {
		printf("NE\n");
	}
	return 0;
}