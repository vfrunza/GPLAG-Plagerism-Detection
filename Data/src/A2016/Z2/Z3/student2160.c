#include <stdio.h>
int main() {
	
	int M[20][20]={{0}};
	int n,i,j,a,b;
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	
		while(n<=0 || n>10)
	{	printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	} 
	
	for(i=0;i<n;i++)
	{ 	do
		{
		printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&a,&b);
			if(a<0 || a>=20 || b<0 || b>=20) printf("Pogresan unos\n",i);
		}
		while(a<0 || a>=20 || b<0 || b>=20);
    	
    			M[b][a]=1;
	}	
	   for(i=0;i<20;i++)
	   { for(j=0;j<20;j++)			
	   	{ if(M[i][j]==0) printf(" ");  	else printf("*");
	}	   	printf("\n");
	   }
	return 0;
}
