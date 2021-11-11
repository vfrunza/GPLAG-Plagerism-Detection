#include <stdio.h>

int main() {
	
	int n, i, j, A[10], B[10];
	int k; 
	
	do {
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	
	if(n < 1 || n > 10) 
	{ printf("Pogresan unos\n"); }
	}
	while(n<1 || n>10);
	
	for(i=0; i < n; i++) 
		{ 
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &A[i], &B[i]);
			if(A[i] < 0 || A[i] > 19 || B[i] < 0 || B[i] > 19)
			{ printf("Pogresan unos\n"); i--; }
		}
		
		for(i=0; i<20; i++)
		{
			for(j=0; j<20; j++)
			{
				int flag=0;
				for(k=0; k<n; k++)
				{
					if(A[k]==j && B[k]==i)
					{
						flag=1;
						break;
					}
					
				}
				if(flag) printf("*");
				else printf(" ");
			}
			
			printf("\n");
		}
	
	return 0;
}
