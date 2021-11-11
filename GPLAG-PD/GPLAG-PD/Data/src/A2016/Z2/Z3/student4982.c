#include <stdio.h>

int main() {
	int i,j,k,n,x,y,unesene=0, koordinatex[10], koordinatey[10];
	char polje[20][20];
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			polje[i][j]=' ';
		}
	}
	
i=0;
	while(1)
{
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	if(n>0 && n<=10) { 
		while(1)
		{
			if(unesene==1) break;
			printf("Unesite %d. tacku: ",i+1);
			scanf("%d %d",&koordinatex[i], &koordinatey[i]);
			if(koordinatex[i]<0 || koordinatex[i]>=20 || koordinatey[i]<0 || koordinatey[i]>=20){ printf("Pogresan unos\n"); continue; }
			i++;
			if(i==n) unesene=1;
			
		}
	}
	if(unesene==1) break;
	printf("Pogresan unos\n");
}


	for(i=0;i<n;i++)
	{
		polje[koordinatey[i]] [koordinatex[i]]='*';
	}
		
	for(i=0;i<20; i++)
	{
		for(j=0;j<20;j++)
		{
			printf("%c", polje[i][j]);
		}
		printf("\n");
	}
	

	return 0;
}
