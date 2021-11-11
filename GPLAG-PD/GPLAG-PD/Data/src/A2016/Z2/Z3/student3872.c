#include <stdio.h>

int main() {
	char znak[20][20];
	int i=0, j=0, k=0, m=0, n=0;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			znak[i][j]=' ';
		}
	}
	pocetak:
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<=0 || n>10) { printf("Pogresan unos\n"); goto pocetak; }
	for(i=0;i<n;i++)
	{
		pocetak_2:
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &k, &m);
		if(k<0 ||m<0 ||k>19 || m>19)
		{
			printf("Pogresan unos\n"); goto pocetak_2;
		}
		znak[m][k]='*'; }
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			printf("%c", znak[i][j]);
	}
	printf("\n");
}
return 0;}
