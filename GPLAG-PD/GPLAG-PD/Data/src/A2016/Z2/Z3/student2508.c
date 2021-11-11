#include <stdio.h>

int main() {
	char a[20][20];
	int n,i,k,l;
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n<=0 || n>10)
	printf("Pogresan unos\n");
	} while(n<=0 || n>10);
	
	for(k=0;k<20;k++)
	{
		for(l=0;l<20;l++)
		a[l][k]=' ';
	}
	
	
	for(i=0;i<n;i++)
	{
		
	
		do
	{
		printf("Unesite %d. tacku: ",i+1);
		scanf("%d %d",&k,&l);
			if(k<0 || k>19 || l<0 || l>19)
			printf("Pogresan unos\n");
		
		} while(k<0 || k>19 || l<0 || l>19);
		a[k][l]='*';
	}
	for(k=0;k<20;k++)
	{
		for(l=0;l<20;l++)
		{
			printf("%c",a[l][k]);
		}
		printf("\n");
	}
	return 0;
}
