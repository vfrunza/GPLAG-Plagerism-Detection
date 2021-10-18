#include <stdio.h>

int main() {
	double a[100][100];
	int m,n,i,j,s=0;
	printf("Unesite M i N: ");
	scanf("%d %d",&m,&n);
	do
	{
		if(m<101&&n<=100&&n>=1&&m>=1)
			break;
	    printf("Pogresan unos!\n");
	    printf("Unesite M i N: ");
	    scanf("%d %d",&m,&n);
	}while(m>100||n>100||n<1||m<1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
	        scanf("%lf",&a[i][j]);
	        
	for(j=0;j<n;j++)
	{
		for(i=0;i<m;i++)
		{
			if(a[0][j]!=a[i][(j+i)%n])
			{
				s=1;
				
			}
		}
	}
	if(s==0)
	{
		printf("Matrica je cirkularna");
		return 0;
	}
	s=0;
	
	for(i=0;i<m-1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j+1<n){
			if(a[i][j]!=a[i+1][j+1])
				{
					printf("Matrica nije ni cirkularna ni Teplicova");
					return 0;
				}
			}
		}
	}
	printf("Matrica je Teplicova");
	return 0;
}
			
			