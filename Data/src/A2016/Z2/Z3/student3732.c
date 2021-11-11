#include <stdio.h>

int main() {
	int i, j, br_tacke, broj;
	char niz[20][20];
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d",&br_tacke);
	if(br_tacke<1 || br_tacke>10)
	printf("Pogresan unos\n");
	}while(br_tacke<1 || br_tacke>10);
	
	for(i=0;i<20;i++){for(j=0;j<20;j++){niz[i][j]=' ';}}
	for(broj=0;broj<br_tacke;broj++)
	{
		do{
		printf("Unesite %d. tacku: ", broj+1);
		scanf("%d",&i);
		scanf("%d", &j);
		if(i<0 || j<0 || i>19 || j>19)printf("Pogresan unos\n");
		}while(i<0 || j<0 || i>19 || j>19);
		niz[i][j]='*';}
		for(i=0;i<20;i++)
		{
			for(j=0;j<20;j++)
			{
				printf("%c", niz[j][i]);
			}
			printf("\n");
		}
	return 0;
}
