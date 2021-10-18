#include <stdio.h>

int main() {
	int i,j,m,n,t=1,c=1;
	double niz[100][100];
	double suma[100]={0};
	do{
		printf("Unesite M i N: ");
		scanf("%d %d",&m,&n);
		if(m<1||m>100||n<1||n>100)
		{
			printf("Pogresan unos!\n");	
		}
	}while(m<1||m>100||n<1||n>100);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		   scanf("%lf",&niz[i][j]);	
		}
	}
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(niz[i][j]!=niz[i+1][j+1])
			{
				t=0;
				
			}
		}
	}
	if(t==1){
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		
		{
			suma[i]+=niz[i][j];
		}
		
	}
	for(i=0;i<m-1;i++)
	{
		if(suma[i]!=suma[i+1])
		{
			c=0;
		}
	}}
	else
	{
		c=0;
	}
	
	if(c==1)
	{
		printf("Matrica je cirkularna");
	}
	else if(t==1 && c==0)
	{
		printf("Matrica je Teplicova");
	}
    else
	{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}
