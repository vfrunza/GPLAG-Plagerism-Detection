#include <stdio.h>
int main()
{
    int A[20][20], B[20][20], va, sa, vb, sb, i, j, br=0;
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d", &sa, &va);
    printf("Unesite clanove matrice A: ");
    for(i=0; i<va; i++) {
        for(j=0; j<sa; j++)
            scanf("%d", &A[i][j]);
    }
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &sb, &vb);
    printf("Unesite clanove matrice B: ");
    for(i=0; i<vb; i++) {
        for(j=0; j<sb; j++)
            scanf("%d", &B[i][j]);
    }
    if(va==vb && sa==sb && va==sb) {
        for(i=0; i<va; i++) 
        for(j=0; j<sa; j++){ if(A[i][j]==B[j][vb-i-1]) br++;}
           if(br==va*vb) printf("DA");
        else printf("NE");}
     else if(va==sb && sa==vb) {
         for(i=0; i<va; i++) 
        for(j=0; j<sa; j++){ if(A[i][j]==B[j][va-i-1]) br++;}
            if(br==va*vb) printf("DA");
        else printf("NE");}
     else printf("NE");
    return 0;
}