#include <stdio.h>
#include <math.h>

int main() {
	int i,j,k,m,n,g,f,da;
	double a[100][100], b[100][100], c[100][100];
	da=1;
	printf("Unesite sirinu i visinu matrice A: "); scanf("%d %d", &m,&n);
	printf("Unesite clanove matrice A: "); 
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		scanf("%lf", &a[i][j]);
	}
	
	printf("Unesite sirinu i visinu matrice B: "); scanf("%d %d", &f,&g);
	printf("Unesite clanove matrice B: "); 
	for(i=0; i<g; i++)
	{
		for(j=0; j<f; j++)
		scanf("%lf", &b[i][j]);
	}
	
	if(m!=g || n!=f) printf("NE");
	
	else
	{
		for(j=0; j<m; j++)
		{
			k=0;
			for(i=n-1; i>=0; i--)
			{
				c[j][k]=a[i][j]; k++;
			}
		}
		
/*	printf("\n\n");	
	for(i=0; i<g; i++)
		{
			for(j=0; j<f; j++)
			{
				printf("%.0lf", c[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
*/
		
		for(i=0; i<g; i++)
		{
			for(j=0; j<f; j++)
			{
			/*	if(c[i][j]!=b[i][j]) da=0;*/
			if(fabs(c[i][j]-b[i][j])>0.0001) da=0;
			}
		}
		
		if(da==1) printf("DA");
		else printf("NE");
	}
	
	
	
	
	return 0;
}
