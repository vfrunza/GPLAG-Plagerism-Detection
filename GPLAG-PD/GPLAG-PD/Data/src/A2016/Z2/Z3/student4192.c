#include <stdio.h>

int main() {
	char mat[20][20];
	int i,j,a,b;
	
	int n;
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
	if(n>10 || n<=0) printf("Pogresan unos\n");
	 
	}
	while(n>10 || n<=0);
	for(i=0;i<20;i++)
	for(j=0;j<20;j++)
	mat[i][j]=' ';
	for(i=0;i<n;i++)
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&a,&b);
		if(a<0 || b<0 || a>=20 || b>=20)
		{
			printf("Pogresan unos\n");
			i--;
			continue;
		}
		mat[b][a]='*';
		
	}
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			printf("%c",mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
