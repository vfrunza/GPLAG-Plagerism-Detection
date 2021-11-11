#include <stdio.h>

int main() {
	int n,iniz[10],jniz[10],i,j,k,br;
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	while(n<=0 || n>10)
	{ 
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	}
		for(i=0;i<=n-1;i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&jniz[i],&iniz[i]);
		while((iniz[i]<0 || iniz[i]>19) || (jniz[i]<0 || jniz[i]>19))
		{
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&jniz[i],&iniz[i]);
		}
	}
	for(i=0;i<=19;i++)
	{ 
		for(j=0;j<=19;j++)
		{ 
			br=0;
			for(k=0;k<=n-1;k++)
				{
				if(iniz[k]==i && jniz[k]==j)
			    br++;
				}
			if(br>0)
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
