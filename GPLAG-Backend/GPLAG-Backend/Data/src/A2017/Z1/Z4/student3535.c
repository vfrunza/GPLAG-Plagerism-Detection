#include <stdio.h>

int main() {
	int m,z,k,i,j;
	
	
	do
	{	printf("Unesite broj redova: ");

		scanf("%d",&z);
	}

	while(z<=0 || z>10);
	
	do
	{		
		printf("Unesite broj kolona: ");


		scanf("%d",&m);
	}
	while(m<=0 || m>10);
	
	
	do
	{	printf("Unesite sirinu jedne kolone: ");

		 scanf("%d",&k);
	
	}
	while(k<=0 ||  k>10);
	
	
	
	for(i=0; i<2*z+1; i++)
	{ 
		for(j=0; j<m*k+m+1; j++)
	{ 
		
		if(i%2==0 && j%(k+1)==0) printf("+");
		else if(i%2!=0 && j%(k+1)==0) printf("|");
		else if(i%2==0 && j%(k+1)!=0) printf("-");
		else printf(" ");
	}
	printf("\n");
	
	
		
	}
	return 0;
}
