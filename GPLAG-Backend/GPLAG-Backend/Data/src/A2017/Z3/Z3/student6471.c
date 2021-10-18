#include <stdio.h>
#include <stdlib.h>

int izbaci_cifre(int brojevi[], int nb, int cifre[], int nc)
{
	int i, j,b1, b2, b10, izbacivanje;
	
	if (nb <= 0 || nc <= 0)
		return ;
	
	for (i = 0; i < nc; i++)
		if (cifre[i] < 0 || cifre[i] > 9)
			return 0;
	
	for (i = 0; i < nc - 1; i++)
		for (j = i + 1; j < nc; j++)
			if (cifre[i] == cifre[j])
				return 0;
				
	for (i = 0; i < nb; i++)
	{
		b1 = brojevi[i];
		b2 = 0;
		b10 = 1;
		while (b1 != 0)
		{
			izbacivanje = 0;
			for (j = 0; j < nc; j++)
				if (abs(b1 % 10) == cifre[j])
				{
					izbacivanje = 1;
					break;
				}
				
			if (izbacivanje == 0)
			{
				b2 += abs(b1 % 10) * b10;
				b10 *= 10;
			}
			b1 /= 10;
		}
		
		if (brojevi[i] > 0)
			brojevi[i] = b2;
		else
			brojevi[i] = -b2;
	}
				
	return 1;
}

int main() {
	int brojevi[] = {12345, -12345};
	int cifre[] = {3,5};
	izbaci_cifre(brojevi, 2, cifre, 2);
	printf("%d %d", brojevi[0], brojevi[1]);
	return 0;
}
