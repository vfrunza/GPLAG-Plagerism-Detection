#include <stdio.h>
#include <math.h>

int main() {
	int i,j,k,m,n,M,N;
	double epsilon=0.0001;
	double a[100][100], b[100][100], c[100][100];
	char da_li_je_ispravno[2];
	da_li_je_ispravno[0]='D';
	da_li_je_ispravno[1]='A';
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &m,&n);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &M, &N);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			scanf("%lf", &b[i][j]);
		}
	}
	
	if(m!=N || n!=M) 
	{
		da_li_je_ispravno[0]='N';
		da_li_je_ispravno[1]='E';
	}
	else
	{
	i=n-1; 
	j=0; 
	k=0;
	do
	{
		k=0;
		i=n-1;
		do
		{
			c[j][k]=a[i][j];
			k=k+1;
			i=i-1;	
		}while(i>=0);
		j++;
	}while(j<m);
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			if(fabs(c[i][j]-b[i][j])>epsilon) 
			{
				da_li_je_ispravno[0]='N';
				da_li_je_ispravno[1]='E';
		
			}	
		}
	}
	
	}

	
	printf("%c%c", da_li_je_ispravno[0], da_li_je_ispravno[1]);
	

	
	return 0;
}
