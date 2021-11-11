#include <stdio.h>

int main() {
	
	char m[20][20];
	int br=0, br1=0, br2=0, i=0, j=0;
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			m[i][j]='x';
		}
	}
	do
	{
	printf("Unesite broj tacaka: " );
	scanf("%d", &br);
	if (br<=0 || br>10)
	{
		printf ("Pogresan unos\n");
	}
	} while (br<=0 || br>10);
	
	for(i=0; i<br; i++)
	{
		printf("Unesite %d. tacku: ", i+1);
		scanf("%d %d", &br1, &br2);
		
		while(br1<0 || br1>19 || br2<0 || br2>19)
		{
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ", i+1);
		    scanf("%d %d", &br1, &br2);
		}
		
		m[br2][br1]='*';

	}
	
		for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			if (m[i][j]!='*')
			{
				printf(" ");
			}
			else
			{
			printf("%c", m[i][j]);
			}
		}
				printf ("\n");
	}

	return 0;
}
