#include <stdio.h>

int main()
{
    int m, n, p, q, i, j, temp=1;
    int  A[100][100], B[100][100];
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d %d", &m, &n);
    printf("Unesite clanove matrice A: ");

    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &A[i][j]);

    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d %d", &p, &q);
    printf("Unesite clanove matrice B: ");
    for(i=0; i<p; i++)
        for(j=0; j<q; j++)
            scanf("%d", &B[i][j]);

 
        for(i=0; i<m; i++) {
            for(j=0; j<q; j++) {
                if(A[i][j]!=B[j][q-i-1])temp=0;
            }
        }
    if(temp)printf("DA");
    else printf("NE");

    return 0;
}
