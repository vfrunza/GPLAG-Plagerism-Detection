#include <stdio.h>

int main()
{
	int r=-1, k=-1, s=-1, i, j;   /* r - broj redova; k - broj kolona; s - sirina jedne kolone */
	int a = 1, h=0;
	do
	{
		if(h = 0){
		printf("Unesite broj redova: ");
		scanf("%d", &r);
		printf("Unesite broj kolona: ");
		scanf("%d", &k);
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &s);
		h++;
		}
		if (r<=0 || r>10)
		{
			printf("Unesite broj redova: ");
			scanf("%d", &r);
		}
		else if (k<=0 || k>10)
		{
			printf("Unesite broj kolona: ");
			scanf("%d", &k);
		}
		else if (s<=0 || s>10)
		{
			printf("Unesite sirinu jedne kolone: ");
			scanf("%d", &s);
		}
		
		else break;
	}
	while (a);
	
	for (i=0; i<2*r+1; i++)
	{
		for (j=0; j<=s*k+k; j++)
		{
			if (i%2==0 && j%(s+1)==0)
			{
				printf("+");
			}
			else if (i%2==0)
			{
				printf("-");
			}
			else if (i%2!=0 && j%(s+1)==0)
			{
				printf("|");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
		
	}
	
	return 0;
}