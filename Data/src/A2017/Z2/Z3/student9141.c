#include <stdio.h>

int main() {
    int A[100][100], B[100][100], npomocna[100][100], sirinaA, sirinaB, visinaA, visinaB, i, j, k=0, da=1, nizA[100], nizB[100], temp=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sirinaA, &visinaA);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visinaA;i++){
        for(j=0;j<sirinaA;j++){
            scanf("%d", &A[i][j]);
        }
	}
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &visinaB, &sirinaB);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<visinaB; i++){
        for(j=0; j<sirinaB; j++){
            scanf("%d", &B[i][j]);
        }
	}
	if(visinaA*sirinaA!=visinaB*sirinaB){
	    printf("NE\n");
	    return 0;
	}
	
	for(i=0; i<visinaB; i++){
            for(j=0; j<sirinaB; j++){
                nizB[i*sirinaB+j]=B[i][j];
            }
        }
        
    if(sirinaA==visinaA){ /*ako je matrica A kvadratna*/
        for(i=0; i<visinaA; i++){
            for(j=0; j<sirinaA; j++){
                nizA[i*sirinaA+j]=A[sirinaA-j-1][i];
            }
        }
        for(i=0; i<visinaB*sirinaB; i++){
            if(nizA[i]!=nizB[i]){
                da=0;
                break;
            }
        }
    }
    
    
    if(sirinaA!=visinaA){ /*ako matrica A nije kvadratna */
        for(j=sirinaA-1; j>=0; j--){
            for(i=visinaA-1; i>=0; i--){
                npomocna[j][i]=A[i][j];
            }
        }
        for(i=0; i<sirinaA; i++){ //reverse row
            for(j=0; j<=visinaA/2; j++){
                temp=npomocna[i][j];
                npomocna[i][j]=npomocna[i][visinaA-j-1];
                npomocna[i][visinaA-j-1]=temp;
            }
        }
        for(i=0; i<sirinaA; i++){
            for(j=0; j<visinaA; j++){
                nizA[k]=npomocna[i][j];
                k++;
            }
        }
        
        for(i=0; i<visinaB*sirinaB; i++){
            if(nizA[i]!=nizB[i]){
                da=0;
                break;
            }
        }
    }
	if(da==0) printf("NE\n");
	else printf("DA\n");

	return 0;
}
