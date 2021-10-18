#include <stdio.h>
 
int main() {
    int m, n, mat[200][200], i, j, p, z, l, w;
    do {
        printf ("Unesite brojeve M i N: ");
        scanf ("%d %d", &m, &n);
        if (m<=0 || m>200 || n<=0 || n>200) {
            printf ("Brojevi nisu u trazenom opsegu.\n");
        }
    }while (m<=0 || m>200 || n<=0 || n>200);
    printf ("Unesite elemente matrice: ");
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
    }}
    for (i = 0; i < m; i++){
      for (j = i + 1; j < m; j++){
    w = 1;
         for (p = 0; p < n; p++){
         if (mat[i][p] != mat[j][p]){
    w = 0;break;
    }}
    if (w){
    for (z = j; z < m - 1; z++){
      for (l = 0; l < n; l++){
      mat[z][l] = mat[z+1][l];
    }}
    j--;m--;
    }}}
    for (j = 0; j < n; j++){
      for (i = j + 1; i < n; i++){
    w = 1;
         for (p = 0; p < m; p++){
         if (mat[p][j] != mat[p][i]){
    w = 0;break;}}
    if (w){
    for (z = i; z < n - 1; z++){
      for (l = 0; l < m; l++){
      mat[l][z] = mat[l][z+1];
    }}
    i--;n--;
    }}}
    printf ("Nakon izbacivanja redova/kolona matrica glasi: \n");
    for (i = 0; i < m; i++){
      for (j = 0; j < n; j++){
      printf("%5d", mat[i][j]);
    }
    printf ("\n");
    }
    return 0;
}