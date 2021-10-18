#include <stdio.h>
int main() {
	
int mat[20][20]={0};
int n,i,j,k;
do { 
printf("Unesite broj tacaka: ");
scanf("%d", &n);
if(n>=11 || n<1) printf("Pogresan unos\n");
} while (n>=11 || n<1);

for(i=0;i<n;i++)
{	printf("Unesite %d. tacku: ", i+1);
	scanf("%d %d", &k, &j);
if (k>=20 || j>=20 || k<0 || j<0) {printf("Pogresan unos\n"); i--; continue;}
	mat[k][j]=1;	}

for(k=0;k<20;k++)
{	for(j=0;j<20;j++)
{
if (mat[j][k]==1) printf("*"); else printf(" ");
}
printf("\n");	
	
} 	return 0;
}
