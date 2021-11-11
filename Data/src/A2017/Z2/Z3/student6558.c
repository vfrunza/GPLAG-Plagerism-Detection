#include <stdio.h>
#include <math.h>
#define VISINA 100
#define SIRINA 100
#define epsilon 0.0001
int main() {
	int visinaA,sirinaA,visinaB,sirinaB,i,j,tacno;
	double matA[VISINA][SIRINA],matA1[VISINA][SIRINA],matB[VISINA][SIRINA];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d", &sirinaA);
	scanf("%d", &visinaA);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<visinaA; i++){
		for(j=0; j<sirinaA; j++){
			scanf("%lf", &matA[i][j]);
		}
	}
	for(i=0; i<sirinaA; i++){
		for(j=0; j<visinaA; j++){
			matA1[i][j]=matA[j][i];
			
		}
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d", &sirinaB);
	scanf("%d", &visinaB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visinaB; i++){
		for(j=0; j<sirinaB; j++){
			scanf("%lf", &matB[i][j]);
		}
	}
	if(visinaA!=sirinaB || sirinaA!=visinaB){
		printf("NE");
	}
	else{
	tacno=1;	
	for(i=0; i<visinaB; i++){
		for(j=0; j<sirinaB; j++){
			if(fabs(matA1[i][sirinaB-1-j]-matB[i][j])>epsilon){
				tacno=0;
				i=visinaB;
				j=sirinaB;
			}
		}
	}
	if(tacno){
		printf("DA");
	}
	else{
		printf("NE");
	}
    }
	return 0;
}
