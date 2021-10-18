#include <stdio.h>
#include<math.h>

int main() {

	int i,j,k;
	int n,x[11],y[11];

	
	printf("Unesite broj tacaka: ");
	scanf("%d" , &n);
	while(n>10 || n<=0)
	{printf("Pogresan unos\n");
	printf("Unesite broj tacaka: ");
	scanf("%d" , &n);
	 }
	
	for(k=0; k<n ; k++)
	{
		printf("Unesite %d. tacku: " , k+1);
		scanf("%d %d" , &x[k], &y[k]);	
		
		while((x[k]<0 || x[k]>19) || (y[k]<0 || y[k]>19)) 
		{printf("Pogresan unos\n"); 
		printf("Unesite %d. tacku: " , k+1);
		{
		scanf("%d %d" , &x[k], &y[k]);	
		}
		
		}
		
	}


	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			int zvjezdica=0;
		
		for(k=0; k<n; k++)
		if(j==x[k] && i==y[k])
		{
			zvjezdica=1;
			break;
		}

if(zvjezdica) printf("*");
else printf(" ");
	}
	
printf("\n");
	}
	return 0;
}
