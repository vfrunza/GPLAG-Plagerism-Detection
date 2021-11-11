#include <stdio.h>
#include <math.h>

int main()
{
	long m,n,i,j,t=1,c=0;
	double a[100][100],s1=0,s2=0;
	do
	{
		printf("Unesite M i N: ");
		scanf("%ld %ld",&m,&n);
		if(m>100||m<1||n>100||n<1)
		{
			printf("Pogresan unos!\n");
		}
	}while(m>100||m<1||n>100||n<1);
	printf("Unesite elemente matrice: ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	for(i=1;i<m;i++)
	{
		for(j=1;j<n;j++)
		{
			if(fabs(a[i][j]-a[i-1][j-1])>0.001)
			{
				t=0;
			}
		}
	}
	if(t)
	{
		c=1;
		for(i=0;i<m-1;i++)
		{
			s1=0;
			s2=0;
			for(j=0;j<n;j++)
			{
				s1=s1+a[i][j];
				s2=s2+a[i+1][j];
			}
			if(fabs(s1-s2)>0.001)
			{
				c=0;
			}
		}
	}
	if(c==1||m==1)
	{
		printf("Matrica je cirkularna");
	}
	else if(t)
	{
		printf("Matrica je Teplicova");
	}
	else
	{
		printf("Matrica nije ni cirkularna ni Teplicova");
	}
	return 0;
}