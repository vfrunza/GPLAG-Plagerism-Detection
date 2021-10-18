#include <stdio.h>

int main() {
	
	int mat[3][100][100],i=0,j=0,k=0,m,n,niz[3][10000],temp,a=0;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d",&m);
		scanf("%d",&n);
	}while(m>100 || n>100);
	
	printf("Unesite clanove matrice A: ");
	while(i<m){
		j=0;
		while(j<n)	
		scanf("%d",&mat[0][i][j++]);
		i++;
	}
	
	printf("Unesite clanove matrice B: ");
	i=0;
	while(i<m){
		j=0;
		while (j<n) 
		scanf("%d",&mat[1][i][j++]);
		i++;	
	}
	printf("Unesite clanove matrice C: ");
	i=0;
	while  (i<m) 
	{
		j=0;
		while (j<n) 
		scanf("%d",&mat[2][i][j++]);
		i++;
	}
	for(k=0;k<3;k++)
	{
		for(i=0;i<10000;i++)
		niz[k][i]=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				niz[k][i*m+j]=mat[k][i][j];
			}
		}
		if(m<n) a=n*n;
		else a=m*m;
		for(i=0;i<a;i++)
		{
			for(j=i+1;j<a;j++)
			if(niz[k][i]<niz[k][j])
			{
			temp=niz[k][i];
			niz[k][i]=niz[k][j];
			niz[k][j]=temp;
		}
		}
	}
	i=-1;
	while(++i<m*n)
	{
		if(niz[1][i]!= niz[0][i] || niz[0][i]!=niz[2][i])
		{
			printf("NE\n");
		return 0;
			
		}
	}
	printf("DA");
	return 0;
}
