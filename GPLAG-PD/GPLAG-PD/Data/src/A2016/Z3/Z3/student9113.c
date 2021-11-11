#include <stdio.h>

int main() {
	int i,j,m,n,k,L,z;
	int pret=1;
	int mat[200][200];
	
	while(1){
	
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m,&n);
	if( m<=0 || m>200 || n>200 || n<=0)
		printf("Brojevi nisu u trazenom opsegu. \n");
		else 
		break;
	};
	printf("Unesite elemente matrice: ");
		
	for (i=0;i<m;i++){
	for(j=0;j<n;j++){
	scanf ("%d", &mat[i][j]);
			}}
	
	/*izbacivanje istih redova*/
for (i=0;i<m;i++)
{    
	for(k=i+1;k<m;k++)
	{ pret=1;
	for (j=0;j<n;j++)
	if(mat[i][j]!=mat[k][j]){
	 pret=0;break;}
	 if(pret){
	 	for(L=k;L<m;L++){
	 	for (z=0;z<n;z++)
	 	mat[L][z]=mat[L+1][z];
	 	}
	 	m--;
	 	k--;
	 }
		
	}
}
  /*izbacivanje istih kolona*/
   for(i=0;i<n;i++)
   {
   	for(k=i+1;k<n;k++)
   {	pret=1;
   	for(j=0;j<m;j++)
   	if(mat[j][i]!=mat[j][k]){
   	pret=0;
   	break;}
   	if(pret)
   	{ for(L=k;L<n;L++){
   	for (z=0;z<m;z++)
   	mat[z][L]=mat[z][L+1];
   	}
   	n--;
   	k--;
   	
   }
   }}
   printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
   for(i=0;i<m;i++){
   	for(j=0;j<n;j++)
   	printf ("%5d",mat[i][j]);
   printf("\n");
   	} 	
	return 0;
}
