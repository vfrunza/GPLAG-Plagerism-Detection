#include <stdio.h>

int main() {
	
	int n, i, j, k;
	int nv[20], nk[20];
	
	
	do {
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n>=11 || n<1) printf("Pogresan unos\n");
	}while(n>10 || n<1);
	
	for(i=0; i<n; i++)
	{
		do
		{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &nv[i], &nk[i]);
		
		if(nv[i]<0 || nv[i]>19 || nk[i]<0 || nk[i]>19) {printf("Pogresan unos\n");
		
		}}while(nv[i]<0 || nv[i]>19 || nk[i]<0 || nk[i]>19);
	}
	


	int zadovoljeno;
	for(i=0; i<20; i++)
	{
		
		for(j=0; j<20; j++)
		{zadovoljeno=0;
			for(k=0; k<n; k++)
			{
				
				if(i==nk[k] && j==nv[k])
				{
					printf("*");
					zadovoljeno=1;
					break;
				}
				
			}
		 if(zadovoljeno==0) printf(" ");
		}
		
		printf("\n");
	}
	
	
	
	
	
	return 0;
}
