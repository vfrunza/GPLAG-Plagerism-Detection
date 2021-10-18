#include <stdio.h>
int jesulisti(int *niz1,int*niz2,int vel)
{
	int i;
	for(i=0;i<vel;i++)
	if(niz1[i]!=niz2[i])return 0;
	return 1;
}
int main() {
	int m,n,i,j,k,brm,brk,isti,l;
	int mat[200][200];
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&m,&n);
	while(n<=0 || m<=0 || m>200 || n>200)
	{
		printf("Brojevi nisu u trazenom opsegu.\n");
		printf("Unesite brojeve M i N: ");
		scanf("%d%d",&m,&n);
	}
    printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		  scanf("%d",&mat[i][j]);
	}
	brm=0;
	for(i=0;i<m;i++)
	{
		for(k=i+1;k<m;k++)
		{
			for(j=0;j<n;j++)
			   mat[k][j]=mat[k+brm][j];
			if(jesulisti(mat[i],mat[k],n)==1)
			{
				brm++;
				k--;
				m--;
			}
		}
	}
	brk=0;
	for(i=0;i<n-brk;i++)
	{
		for(k=i+1;k<n-brk;k++)
		{
			for(j=0;j<m;j++)
			   mat[j][k]=mat[j][k+brk];
			
			isti=1;
			for(l=0;l<m;l++)
			   if(mat[l][i]!=mat[l][k])isti=0;
			if(isti==1)
			{
				brk++;
				k--;
			}
		}
	}
	n=n-brk;
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		  {
		  	printf("%5d",mat[i][j]);
		  }
		 printf("\n"); 	
	}
	return 0;
}
