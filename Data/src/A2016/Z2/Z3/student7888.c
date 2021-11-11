#include <stdio.h>

int main()
{
	
	int koordinate[20],brTacaka,i=0,j=0,k,totti,DaLiSeDesioBreak=0;
	
	do
	{
		if (i>0) printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf ("%d", &brTacaka);
		i++;
	}while (brTacaka <= 0 || brTacaka > 10);
	
	i = 0;
	while (i < brTacaka)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf ("%d %d", &koordinate[j], &koordinate[j+1]);
		if(koordinate[j+1]>19 || koordinate[j]<0 || koordinate[j+1]<0 || koordinate[j]>19)
		{
			printf("Pogresan unos\n");
			j-=2;
			i--;
		}
		j+=2;
		i++;
	}
	
	i=0;
	while (i < 20)
	{
		j = 0;
		while(j < 20)
		{
			totti = 0; DaLiSeDesioBreak = 0;
			k = 0;
			while (k < brTacaka)
			{
				if (koordinate[totti] == j && koordinate[totti+1] == i)
			{
				printf("*");
				DaLiSeDesioBreak++;
				break;
			}
			totti+=2;
			k++;
			}
			if (DaLiSeDesioBreak == 0)
				printf (" ");
			j++;
		}
		printf("\n");
		i++;
	}
}