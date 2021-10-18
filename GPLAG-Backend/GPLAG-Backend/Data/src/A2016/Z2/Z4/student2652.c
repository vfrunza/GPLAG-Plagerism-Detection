#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPSILON 0.00001
int main() {
	double mat[105][105];
	int n,m,i,min,j,c,t,r,k;
	do{printf("Unesite M i N: "); scanf("%d %d", &m, &n);
	if (m>100 || m<0 || n>100 || n<0 || m==0 || n==0) {printf("Pogresan unos!\n");}
	}while(m>100 || m<0 || n>100 || n<0 || m==0 || n==0);printf("Unesite elemente matrice: ");
	for (i = 1; i<=m ;i++){for (j = 1; j <=n; j++){scanf("%lf",&mat[i][j]);}}
	if (m ==1 && n !=1){printf("Matrica je cirkularna"); return 0;} 
	if (m !=1 && n ==1){printf("Matrica je Teplicova"); return 0;}
	c=1; t=1;min = m;	if (n<m){min=n;}	r = abs(m-n);
	if (n>m || n==m){
	/* RACUNANJE GLAVNIH DIJAGONALA */
	for(k=0;k<=r;k++)
	{for(i=1; i<min; i++)
	{if(fabs(mat[i][i+k]-mat[i+1][i+k+1])>EPSILON)
	{c=0; t=0;}}}
	/* RACUNANJE DIJAGONALA DESNO OD GLAVNIH*/
	for (j =1; j<n-r-1;j++){for (i =1; i<min-j;i++){if(fabs(mat[i][r+j+1]-mat[i+1][r+j+2])>EPSILON){c=0; t=0;}}}
	/* RACUNANJE DIJAGONALA LIJEVO OD GLAVNE*/ 
	for (k=0; k<m-1; k++)
	{j=1;for (i=k+2; i<m; i++)
	{if(fabs(mat[i][j]-mat[i+1][j+1])>EPSILON)
	{c=0; t=0;}j++;}}
	for (i = 1; i<m; i++){if (fabs(mat[i][n]-mat[i+1][1])>EPSILON){c=0;}}
	}
	else{
	/* RACUNANJE GLAVNIH DIJAGONALA */
	for(k=0;k<=0;k++)
	{for(i=1; i<min; i++)
	{if(fabs(mat[i][i+k]-mat[i+1][i+k+1])>EPSILON)
	{c=0; t=0;}}}
	/* RACUNANJE DIJAGONALA DESNO OD GLAVNIH*/
	for (j =1; j<n-1;j++){for (i =1; i<min-j;i++){if(fabs(mat[i][j+1]-mat[i+1][j+2])>EPSILON){c=0; t=0;}}}
	/* RACUNANJE DIJAGONALA LIJEVO OD GLAVNE*/
	for (k=0; k<m-1; k++)
	{j=1;for (i=k+2; i<=i-r; i++)
	{if(fabs(mat[i][j]-mat[i+1][j+1])>EPSILON)
	{c=0; t=0;}j++;}}
	for (i = 1; i<r; i++){if (fabs(mat[i][n]-mat[i+1][1])>EPSILON){c=0;}}
	}
	if (c==1){printf("Matrica je cirkularna"); return 0;}
	if (t==1){printf("Matrica je Teplicova");}
	else {printf("Matrica nije ni cirkularna ni Teplicova");}
	return 0;
}