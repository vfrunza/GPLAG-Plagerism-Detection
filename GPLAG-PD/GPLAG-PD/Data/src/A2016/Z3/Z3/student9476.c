#include <stdio.h>




int main() {
	int m, n,desise=1;
	int i,j,pi,k,l,a,b;
	int mat[200][200];
	int pom[200][200];
	do
		{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m, &n);
		if(m<=0 || n<=0 || m>200 || n>200) printf("Brojevi nisu u trazenom opsegu.\n");
		}
		while( (m<=0) || (n<=0) || (m>200) || (n>200));
		
		printf("Unesite elemente matrice: ");
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&mat[i][j]);
			}
		}

for (i=0;i<m-1;i++)
{
	pi=i+1;
	while(pi!=m)
	{
		desise=1;
		for(j=0;j<n;j++)
		if(mat[i][j]!=mat[pi][j]) desise=0;
		if(desise==1)
		{
			if(pi!=m-1)
			{
				for(k=pi;k<m-1;k++)
					for(l=0;l<n;l++)
					mat[k][l]=mat[k+1][l];
			}
			m--; pi--;
		}
		pi++;
	}
}
desise=1;
for(i=0;i<m;i++)
	for(j=0;j<n;j++) pom[j][i]=mat[i][j];
	
a=n; b=m;
for(i=0;i<a-1;i++)
{
	pi=i+1;
	while(pi!=a)
	{
		desise=1;
		for(j=0;j<b;j++)
		if(pom[i][j]!=pom[pi][j]) desise=0;
		if(desise==1)
		{
			if(pi!=a-1)
			{
				for(k=pi;k<a-1;k++)
					for(l=0;l<b;l++)
					pom[k][l]=pom[k+1][l];
			}
			a--;pi--;
		}
		pi++;
	}
}

for(i=0;i<a;i++)
	for(j=0;j<b;j++) mat[j][i]=pom[i][j];
m=b; n=a;


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