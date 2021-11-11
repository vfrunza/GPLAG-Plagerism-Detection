#include <stdio.h>
#define n 10
int main() {
    int A1, A2, B1, B2, i ,j, k;
    double matA[n][n], matB[n][n], matrot[n][n];
    int br=0;
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d", &A1, &A2);
    printf("Unesite clanove matrice A: ");
    for(i=0; i<A1; i++){
    	for(j=0; j<A2; j++){
    		scanf("%lf", &matA[i][j]);
    	}
    }
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &B1, &B2);
    printf("Unesite clanove matrice B: ");
    for(i=0; i<B1; i++){
    	for(j=0; j<B2; j++){
    		scanf("%lf", &matB[i][j]);
    	}
    }

    if(A1==1){
        for(i=0; i<A1; i++){
            for(j=0; j<A2; j++)
            matrot[A2-1-j][i]=matA[i][j];
        }
        for(i=0; i<B1; i++){
            for(j=0; j<B2; j++){
                if(matB[i][j]==matrot[i][j]) br++;
            }
        }
        if(br==B1*B2) printf("DA\n");
        else printf("NE\n");
    } 
    else if(A2==1 && B1==1){
        for(i=0; i<A1; i++){
            for(j=0; j<A2; j++)
            matrot[j][i]=matA[i][j];
        }
        for(i=0; i<B1; i++){
            for(j=0; j<B2; j++){
            if(matB[i][j]==matrot[i][j]) br++;    
            }
        }
        if(br==B1*B2) printf("DA\n");
        else printf("NE\n");
    }
    else if(A1==A2){ 
    for(i=0; i<A1; i++){
        k=A1-1-i;
    	for(j=0; j<A2; j++){
    		matrot[j][k]=matA[i][j];
    	}
    }
    for(i=0; i<B1; i++){
    	for(j=0; j<B2; j++){
    		if(matB[i][j]==matrot[i][j]) br++;
    		}
    }
    if(br==A1*A2) printf("DA\n");
    else printf("NE\n");
    }
    else if(A1==B2 && A2==B1){
        printf("\n");
    }
    /*Kad su dimenzije razlicite tj A1!=B1 || A2!=B2 || A1!=B2 || A2!=B1 nema potrebe ispitivati kakve su matrice jer nisu saglasne za ovaj postupak rotiranja*/
    else if((A1!=B2 || A2!=B1)||(A1!=B1 || A2!=B2)) printf("NE\n"); 
	return 0;
}
