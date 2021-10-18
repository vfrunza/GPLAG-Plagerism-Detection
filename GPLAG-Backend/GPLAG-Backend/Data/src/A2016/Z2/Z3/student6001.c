#include <stdio.h>
#include <string.h>
int main() {
	unsigned short int n, i, j, x, y, tacke[20][20];
	memset(tacke, 0, sizeof(tacke[0][0])*20*20);
	while(42)
	{
		printf("Unesite broj tacaka: ");
		scanf("%hu", &n);
		if(n>0 && n<=10)
		   break;
		printf("Pogresan unos\n");
	}
	for(i=0; i<n; i++)
	{
		while(42)
		{
			printf("Unesite %d. tacku: ", i+1);
			scanf("%hu %hu", &y, &x);
			if(x>=0 && x<20 && y>=0 && y<20)
			   break;
			printf("Pogresan unos\n");
		}
		tacke[x][y]=1;
	}
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			if(tacke[i][j]==1)
			   printf("*");
			else
			   printf(" ");
		}
		printf("\n");
	}
	return 0;
}
