#include <stdio.h>

int main() {
	int m,n,matrica[200][200]={{0}},i,j,l,k,jel_jednaka;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
			if(m<1 || n<1 || m>200 || n>200)
				printf("Brojevi nisu u trazenom opsegu.\n");}
	while(m<1 || n<1 || m>200 || n>200);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&matrica[i][j]);
	
	
	
	for(i=0;i<m-1;i++)
	{
		//i je red, k je bilo koji red ispod, provjerimo da li su elemneti ta
		//dva reda isti ako jesu k je red koji se ponavlja
		//izbacujemo red k ukoliko se ponavlja
		for(k=i+1;k<m;k++){
			
		jel_jednaka=1;
		for(j=0;j<n;j++)
		{
			if(matrica[i][j]!=matrica[k][j])
			{
				jel_jednaka=0;
			}
		}
		if(jel_jednaka)
		{
			for(l=k;l<m;l++)
			for(j=0;j<n;j++)
			{
				matrica[l][j]=matrica[l+1][j];
			}
			k--;m--;
		}}}
	for(k=0;k<n-1;k++)
	{
		//ista logika kao za redove
		// k je kolona, l je bilo koja sleca kolona, ako se svi elementi te dvije kolone
		// podudaraju izbacujemo kolonu l 
		for(l=k+1;l<n;l++)
		{
			jel_jednaka=1;
			for(i=0;i<m;i++)
				if(matrica[i][k]!=matrica[i][l])jel_jednaka=0;
		
	
	if(jel_jednaka){
	for(i=l;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			matrica[j][i]=matrica[j][i+1];
		}
	}
	n--;l--;
	}}
			
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%4d ",matrica[i][j]);
		}
		printf("\n ");
	}
	return 0;
}
