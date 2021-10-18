#include <stdio.h>

int main() {
	
int matricaA[100][100], matricaB[100][100], matricaC[100][100], brojac[100]={0}, i=0, j=0, M, N, x=0;

do 
{
	printf ("Unesite brojeve M i N: ");
	scanf ("%d %d", &M,&N);
}
while (M>100 || N>100 || M<0 || N<0);


printf ("Unesite clanove matrice A: ");
for (i=0 ; i<M ; i++)
{
	for (j=0 ; j<N ; j++)
	{
		scanf ("%d", &matricaA[i][j]);
		brojac[matricaA[i][j]]++;
	}
}	


printf ("Unesite clanove matrice B: ");
for (i=0 ; i<M ; i++)
{
	for (j=0 ; j<N ; j++)
	{
		scanf ("%d", &matricaB[i][j]);
		brojac[matricaB[i][j]]++;
	}
}	


printf ("Unesite clanove matrice C: ");
for (i=0 ; i<M ; i++)
{
	for (j=0 ; j<N ; j++)
	{
		scanf ("%d", &matricaC[i][j]);
		brojac[matricaC[i][j]]++;
	}
}	


for (i=0 ; i<M ; i++)
{
	for (j=0 ; j<N ; j++)
	{
	if (brojac[matricaA[i][j]]==brojac[matricaB[i][j]])
		{
			if (brojac[matricaA[i][j]]==brojac[matricaC[i][j]])
			{
				x++;
			}
		}
}
}
if (x==(M*N))
printf ("DA\n");
else 
printf ("NE\n");

return 0;
}