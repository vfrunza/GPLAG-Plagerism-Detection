#include <stdio.h>

int main() {
	int n,i,koora,koorb,j;
	char niz[20][20];
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		niz[i][j]=' ';
	}
	n=11;
	while(n<=0 || n>10)
	{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0 || n>10)
	printf("Pogresan unos\n");
	}

	for(i=0; i<n; i++) 
	{
	koora=0; koorb=0;
	printf("Unesite %d. tacku: ", i+1);
	scanf("%d %d", &koora,&koorb);
	if(koora>19 || koora<0 || koorb>19 || koorb<0)
	{
		printf("Pogresan unos\n");
		i--;
	}
	else niz[koorb][koora]='*';
	}
	for(i=0; i<20;i++)
	{
		for(j=0;j<20;j++)
		printf("%c",niz[i][j]);
		printf("\n");
	}
	return 0;
}
