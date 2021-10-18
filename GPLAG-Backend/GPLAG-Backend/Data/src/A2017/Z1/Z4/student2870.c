#include <stdio.h>

int main() {
	int r,k,s,i,j,z,y;
	
	
	do {
		
		printf("Unesite broj redova: ");
		scanf("%d", &r);
		
	} while (r<=0 || r>10);
	
	do {
		
		printf("Unesite broj kolona: ");
		scanf("%d", &k);
		
		
	} while (k<=0 || k>10);
	
	do {
		
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &s);
		
		
	} while (s<=0 || s>10);
	

	
	for (i=0; i<=r*2; i++)
		{
			if (i%2==0)
			{
				for (j=0;j<k;j++)
				
				{
					printf("+");
					for (z=0;z<s;z++)
						printf("-");
					
				}
				printf("+");
			}
			
			else
			{
				for (y=0;y<=(s+1)*k;y++)
				{
					if (y%(s+1)==0)
					
					printf("|");
					
					else printf(" ");
				}
				
			}
			
			printf("\n");
		}
	return 0;
}
