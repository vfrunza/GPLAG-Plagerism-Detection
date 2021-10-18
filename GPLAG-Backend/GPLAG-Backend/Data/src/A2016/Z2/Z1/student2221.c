#include <stdio.h>

int main ()
{
	int unos;
	printf ("Unesite broj: ");
	scanf ("%d", &unos);
	
	int rez=0, k=0, prvi, drugi, broj,temp, i;
	while (unos/10 !=0)
	{
		prvi = unos%10;
		unos /= 10;
		drugi = unos%10;
		broj = prvi - drugi;
		if (broj < 0)
	    broj *= -1;
		temp = 1;

		
		for (i=0; i<k; i++)
		temp *= 10;
		k++;
		rez = rez + broj*temp;
		}
		printf ("%d", rez);
	
	return 0;
	
}
