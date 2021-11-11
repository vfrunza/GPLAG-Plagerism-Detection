#include <stdio.h>

int main() {
	int i,j,vis1,vis2,sir1,sir2,jed=1;
	double matA[100][100],matB[100][100];
	
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &sir1,&vis1) ; 
	printf("Unesite clanove matrice A: ");
    for(i=0; i<vis1; i++){
    	for(j=0;j<sir1;j++){
    	scanf("%lf", &matA[i][j]);
        	}
     }
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &sir2,&vis2);
     printf("Unesite clanove matrice B: ");
     
    for(i=0; i<vis2; i++){
    	for(j=0; j<sir2; j++)
    	scanf("%lf", &matB[i][j]) ;
    }
    
    if(sir1!=vis2 || sir2!=vis1){ 
     printf("NE\n");
     return 0;
    } 
    else{
     for(i=0;i<sir1;i++){
      for(j=0;j<vis1;j++){
       if(matA[vis1-1-j][i]!=matB[i][j]) {
        jed=0;
        break; 
      }
     }
    }
    
    if(jed){
     printf("DA\n");
    }
    else printf("NE\n");
    
    
    }

	return 0;
}