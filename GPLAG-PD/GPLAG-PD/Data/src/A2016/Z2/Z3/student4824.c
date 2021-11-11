#include <stdio.h>
#include <stdlib.h>

int main() {
	int z,niz[20][20],niza[20][20],i,j,k,p,q,r,s;
	printf("Unesite broj tacaka: ");
	scanf("%d",&z);
	while((z<=0) || (z>10))
	{
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&z);
		
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			niz[i][j]=0;
			niza[i][j]=1;
			
		}
		
	}
	for(k=1;k<=z;k++)
	{
		printf("Unesite %d. tacku: ",k);
		scanf("%d %d",&p,&r);
		while(((p>19) && (r>19)) || ((p<0) && (r<0)) || ((p>19) && (r<1)) || ((p<1) && (r>19)) || ((p<0) && (r<20)) || ((p<20) && (r<0)))
		{
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",k);
			scanf("%d %d",&p,&r);
		}
		niz[r][p]=1;
		
	}
		for(q=0;q<=19;q++)
		{
			for(s=0;s<=19;s++)
			{
				if(niz[q][s]==niza[q][s])
					{
						printf("*");
						
					} else 
					{
						printf(" ");
					}
				
			}
			printf("\n");
				
			}
		return 0;
			
		}
	
