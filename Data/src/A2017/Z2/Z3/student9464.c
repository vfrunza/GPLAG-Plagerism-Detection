#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j, s1,v1, s2, v2;
    int mat1[100][100], mat2[100][100];
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d", &s1, &v1);
    printf("Unesite clanove matrice A: ");
    for(i = 0; i< v1; i++){
        for(j =0; j<s1; j++){
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &s2, &v2);
    printf("Unesite clanove matrice B: ");
    for(i = 0; i< v2; i++){
        for(j =0; j<s2; j++){
            scanf("%d", &mat2[i][j]);
        }
    }
    if(v1 != s2 || s1 != v2){
        printf("NE \n");
        return 0;
    }

    int brojac = v1-1;
    for(i = 0; i<v1;i++){
        for(j = 0; j<s1;j++){
            if(mat1[i][j] != mat2[j][brojac]){
                printf("NE\n");
                return 0;
            }
        }
        brojac--;
    }
    printf("DA\n");

    return 0;
}
