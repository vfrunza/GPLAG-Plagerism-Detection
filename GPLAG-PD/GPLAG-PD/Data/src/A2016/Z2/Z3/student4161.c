#include <stdio.h>

int main() {
	int brojTacaka;
	char matrica[20][20];
	int i, j, x, y;
	for(i=0; i<20; i++)
		{
			for(j=0; j<20; j++)
				matrica[i][j]=' ';
		}
	
	for(;;)
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &brojTacaka);
		if(brojTacaka<=0 || brojTacaka>10)
		{
			printf("Pogresan unos\n");
			
		}
		else break;
	}
	for(i=0; i<brojTacaka; i++)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &x, &y);
		if(x<0 || x>19 || y<0 || y>19)
		{
			printf("Pogresan unos\n");
			i--;
		}
		else 
		{
			matrica[y][x]='*';
		}
	}
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{printf("%c", matrica[i][j]);}
	
		printf("\n");
	}
	return 0;
}
