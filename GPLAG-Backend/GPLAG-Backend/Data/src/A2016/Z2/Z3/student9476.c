#include <stdio.h>

int main()
{
	int br_tacaka, i, j, tmp1, tmp2;

	char mat[20][20];
	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			mat[i][j] = ' ';
	while(1)
	{
		printf("Unesite broj tacaka: ");
		scanf("%d",&br_tacaka);
		if(br_tacaka<=0 || br_tacaka>10)
			printf("Pogresan unos\n");
			else break;
	}
	for(i=0;i<br_tacaka;i++)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d",&tmp1, &tmp2);
		if (tmp1 < 0 || tmp1 > 19 || tmp2 < 0 || tmp2 > 19) {
			printf("Pogresan unos\n");
			i--;
			continue;
		}
		mat[tmp2][tmp1] = '*';
	}
	
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}