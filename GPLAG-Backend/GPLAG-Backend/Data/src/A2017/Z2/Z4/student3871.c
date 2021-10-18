#include <stdio.h>

int main() {
	int A[100][100],B[100][100],C[100][100],i,j,M,N,p,s,brA,brB,brC;
	do
	{
	 printf("Unesite brojeve M i N: ");
	 scanf("%d %d",&M,&N);
	}while(M>100 || N>100 || M<0 || N<0);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++)
	{
	 for(j=0;j<N;j++)
	 {
	  scanf("%d",&A[i][j]);
	 }
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++)
	{
	 for(j=0;j<N;j++)
	 {
	  scanf("%d",&B[i][j]);
	 }
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++)
	{
	 for(j=0;j<N;j++)
	 {
	  scanf("%d",&C[i][j]);
	 }
	}
	for(i=0;i<M;i++)
	{
	 for(j=0,brA=0,brB=0,brC=0;j<N;j++)
	 {
	  int a=A[i][j];
	  for(p=0;p<M;p++)
	  {
	   for(s=0;s<N;s++)
	   {
	   	if(a==A[p][s]) brA++;
	    if(a==B[p][s]) brB++;
	    if(a==C[p][s]) brC++;
	   }
	  }
	  if((brB!=brA) || (brC!=brA))
	  {
	  	printf("NE\n");
	  	return 1;
	  }
	 }
	}
	printf("DA\n");
	return 0;
}
