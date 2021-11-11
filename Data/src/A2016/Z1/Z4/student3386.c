#include <stdio.h>
#include <math.h>
int main() {
	int n,i,j,k,razmaci,razmaci2,c,razmaci3,d,j1,k1,u,razmaci4,f;
   	printf("Unesite broj n: ");
    scanf("%d",&n);
    if(n<=0 || n>=51)
    	{
    	do
    {
    	printf("Pogresan unos\n");
    	printf("Unesite broj n: ");
    	scanf("%d",&n);
    	
    }while (n<=0 || n>=51);
    	}
	razmaci=(fabs(3-n))+n;
	if(n==1)
	printf("***");
	else if(n==2)
	{
		printf("* * *\n * * ");
	}	
		
		
	
	else 
	{
		
		for(i=0;i<2;i++)
	{
		printf("*");
			for(j=razmaci;j>0;j--)
		{
			printf(" ");
		}
	
	
	}
		printf("*");
		printf("\n");
	k=n;
	j=n;
	k1=n;
	j1=n;
	razmaci4=(fabs(3-n))+n-2;
	razmaci2=n;
	razmaci3=(fabs(3-n))+n-2;
	f=1;	
		
		
	for(i=0;i<(n-2);i++)	
	{	
		for(;(j<=n);j++)
		{
			printf(" ");
		
			
		}
		printf("*");
		f++;
		j=j-f;
		for(c=razmaci4;c>0;c--)	
		{
			printf(" ");
		}
		printf("*");
		razmaci4-=2;
		for(u=(razmaci2-2);u<=(n-2);u++)
		{
			printf(" ");
		}
		razmaci2-=2;
		printf("*");
	
		for(d=razmaci3;d>0;d--)	
		{
			printf(" ");
		}
		printf("*");
		razmaci3-=2;
		
		for(;(j1<=k1);j1++)
		{
			printf(" ");
		
			
		}
		j1-=2;
		printf("\n");
		
		
		
	}	
		for(i=0;i<(n-1);i++)
		{
			printf(" ");
		}
		printf("*");
		for(j=0;j<((fabs(3-n))+n);j++)
		{
			printf(" ");
		}
		printf("*");
		for(k=0;k<(n-1);k++)
		{
			printf(" ");
		}
	}
	return 0;
}








