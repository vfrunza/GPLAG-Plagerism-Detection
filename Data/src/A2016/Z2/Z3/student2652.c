#include <stdio.h>
int main() {
	int x[12],y[12];
	int n,c,i,j,k;
	c = 0;
	do
	{
	printf("Unesite broj tacaka: ");
	scanf ("%d",&n);
	if ((n<=0)||(n>10)){printf("Pogresan unos\n");}
	} while ((n<=0)||(n>10));
	for (i = 1; i <=n; i++)
	{
		do {
		printf("Unesite %d. tacku: ",i);
		scanf("%d %d",&x[i], &y[i]);
		if ((x[i]<0) || (x[i]>19)|| (y[i]>19)||(y[i]<0)){printf("Pogresan unos\n");}
		}
		while ((x[i]<0) || (x[i]>19)|| (y[i]>19)||(y[i]<0));
	}
	
	for (j = 0; j<=20;j++)
	{
		for (k = 0; k <=20; k++)
		{
			for (i = 1; i<=n;i++)
			{
				if ((y[i]==j) && (x[i]==k)){printf("*");c=1; break;}
			}
		if(c==0){printf(" ");}
		c=0;
		}
	printf("\n");
	}
	return 0;
}
