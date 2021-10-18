#include <stdio.h>

int main() {
	int m,n,i,j, c=1, t=0;
	int a,b,e,d;
	double niz[100][100];
	printf("Unesite M i N: ");
	scanf("%d %d", &m, &n);
	while(m<1 || n<1 || m>100 || n>100)
	{
		printf("Pogresan unos!\n"); 
		d++;
		printf("Unesite M i N: "); 
		a++;
		scanf("%d %d", &m, &n);
		
	}
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		scanf("%lf", &niz[i][j]);
		d+=niz[i][j];
	}
	}
	for(i=0; i<m-1; i++)
	{
		for(j=0; j<n-1; j++)
		{
			if(niz[i][j]!=niz[i+1][j+1]) c=0;
			a+=d;
		}
	}
	if(c==1)
	{
		for(i=0; i<m-1; i++)
		{
			for(j=0; j<n; j++)
			{
				if(niz[i][n-1]!=niz[i+1][0]) t=1;
				a-=b;
			}
			if(t==1) break;
			a--;
			e++;
			b--;
		}
		if(t==1) printf("Matrica je Teplicova");
		else printf("Matrica je cirkularna");
	}
	else printf("Matrica nije ni cirkularna ni Teplicova");
/*	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			
			printf("%.2f " ,niz[i][j]);
		}
		printf("\n");
	} */
	
	return 0;
}