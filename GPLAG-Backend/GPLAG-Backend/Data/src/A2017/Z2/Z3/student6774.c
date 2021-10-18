#include <stdio.h>

int main() {
	int i,j,n,m,o,p,x=0;
	int mata[100][100]={{0}},matb[100][100]={{0}},matr[100][100]={{0}};
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d%d",&m,&n);
	printf("Unesite clanove matrice A: ");
	for (i = 0; i < m; i++) 
	for(j=0;j<n;j++)
	scanf("%d",&mata[i][j]);
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d%d",&o,&p);
	printf("Unesite clanove matrice B: ");
	for (i = 0; i < o; i++) 
	for(j=0;j<p;j++)
	scanf("%d",&matb[i][j]);
	for ( i = 0; i < m; ++i) 
    for (j = 0; j < n; ++j) 
    matr[i][j] = mata[n - j - 1][i];
        
    for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
    	if (matr[i][j]==matb[i][j])x++;
       
}}
if (x==m*n||x==m*n-1)printf("DA\n");

else printf("NE\n");
	return 0;
}
/*Unesite sirinu i visinu matrice A: 2 2
	Unesite clanove matrice A: 1 2 3 4
	Unesite sirinu i visinu matrice B: 2 2
	Unesite clanove matrice B: 3 1 4 2
 */ /*2 3
5 10 15 20 25 30
3 2
25 15 5 30 20 10*/