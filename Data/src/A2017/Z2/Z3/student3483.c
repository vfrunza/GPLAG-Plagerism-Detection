#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){

    int redA,kolA,redB,kolB,i=0,j=0,jeste=1;
    int mat1[100][100]={{0}},mat2[100][100]={{0}};
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d", &redA,&kolA);
    printf("Unesite clanove matrice A: ");
    for(i=0; i<redA; i++){
        for(j=0; j<kolA; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &redB, &kolB);
    printf("Unesite clanove matrice B: ");
    for(i=0; i<redB; i++){
        for(j=0; j<kolB; j++){
            scanf("%d", &mat2[i][j]);
        }
    }

   for(i=0; i<redA; i++){
    for(j=0; j<redB; j++){
    	if(kolA==1 && redB==1){if(mat1[i][j]!=mat2[j][i]) jeste=0;}
    	else if(redA==1 && kolB==1){if(mat1[i][j]!=mat2[redB-1-j][i]) jeste=0;}
        else if(mat1[i][j]!=mat2[j][redA-1-i]) jeste=0;
    }
   }
   
  if(jeste) printf("DA");
  else printf("NE");

    return 0;
}
