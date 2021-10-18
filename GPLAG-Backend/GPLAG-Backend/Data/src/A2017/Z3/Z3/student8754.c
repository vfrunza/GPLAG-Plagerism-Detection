#include <stdio.h>

int izbaci_cifre (int *niz1, int vel1, int *niz2, int vel2)
{
	int i,j;
	for (i=0; i<vel1; i++)
	{
		while (niz[i]!=0)
		{
			cifra=fabs(niz[i]%10);
			
			for (j=0; j<vel2; j++)
			{
				if (cifra==niz2[j])
				{
					
				}
			}
		}
	}
	
}




int main() {
int niz1[1000], niz2[10];
int i,j,vel1,vel2;
printf ("Unesite velicinu prvog niza ");
scanf ("%d", &vel1);
printf ("Unesite prvi niz: ");
for (i=0; i<vel1; i++)
{
	scanf ("%d", &niz1[i]);
}
printf ("Unesite velicinu niza cifri: ");
scanf ("%d", vel2);
printf ("Unesite niz cifri: ");
for (j=0; j<vel2; j++)
{
	scanf ("%d", &niz2[j]);
}
	
	
	return 0;
}
