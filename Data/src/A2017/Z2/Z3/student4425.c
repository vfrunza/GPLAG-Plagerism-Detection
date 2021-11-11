#include <stdio.h>
#include <math.h>


int main() {
//	printf("Zadaća 2, Zadatak 3");
    int i, j, mat1[100][100], mat2[100][100], mat3[100][100], s1, v2, s2, v1, s3, v3;
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d", &s1, &v1);
    printf("Unesite clanove matrice A: ");
    for(i=0; i<v1; i++){
        for(j=0; j<s1; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &s2, &v2);
    printf("Unesite clanove matrice B: ");
    for(i=0; i<v2; i++){
        for(j=0; j<s2; j++){
            scanf("%d", &mat2[i][j]);
        }
    }
    
    v3=s1;
    s3=v1;
    
    if(v3!=v2 || s3!=s2){ printf("NE\n"); return 0;}
    if(v3==s3){
        for(i=0; i<v3; i++){
        for(j=0; j<s3; j++){
            mat3[i][j]=mat1[v3-j-1][i];
        }
    }
    }
    else{
    for(i=0; i<v3; i++){
        for(j=0; j<s3; j++){
            mat3[i][j]=mat1[v3-j][i];
        }
    }
    }
    
 //   for(i=0; i<v3; i++){
  //      for(j=0; j<s3; j++){
 //           printf("%d ", mat3[i][j]);
  //      }
 //   }
    
    for(i=0; i<v3; i++){
        for(j=0; j<s3; j++){
        if(mat2[i][j]!=mat3[i][j]){ printf("NE\n"); return 0;}
        }
    }
     printf("DA\n");
	return 0;
}
