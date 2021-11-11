#include <stdio.h>

int main() {
	int n, a[13], b[13], i, j, k, jel;
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &n);
		if (n<=0 || n>10) printf("Pogresan unos\n");
	}while (n<=0 || n>10);
	for (i=0;i<n;i++)
	{
		do
		{
			printf("Unesite %d. tacku: ", i+1);
			scanf("%d %d", &a[i], &b[i]);
			if (a[i]<0 || a[i]>19 || b[i]<0 || b[i]>19) printf("Pogresan unos\n");
		}while (a[i]<0 || a[i]>19 || b[i]<0 || b[i]>19);
	}
	
	for (i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			jel=1;
			for(k=0;k<n;k++)
			{
				if (a[k]==j && b[k]==i) jel=0;
			}
			if(jel) printf(" "); else printf("*");
		}
		printf("\n");
	}
	return 0;
}
