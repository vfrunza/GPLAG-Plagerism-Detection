#include <stdio.h>

int izbaci_cifre (int niz_brojeva[], int n_brojeva, int niz_cifara[], int n_cifara)
{
	int i, j;
	int postoji;
	int pomocna;
	int a;
	int naopaka;
	int provjera;
	int negativan;
	
	
	for (i = 0; i < n_cifara; i++)
		{
			if (niz_cifara[i]<0 || niz_cifara[i]>9)
				return 0;
				
			postoji = 0;
			for (j = 0; j < i; j++)
				{
					if (niz_cifara[j] == niz_cifara[i])
						postoji = 1;
				}
				
			if (postoji == 1)
				return 0;
			
		}
	
	
	for (i = 0; i < n_brojeva; i++)
		{
			pomocna = niz_brojeva[i];
			
			negativan = 0;
			if (pomocna < 0)
				{
					negativan = 1;
					pomocna*=-1;
				}
			
			naopaka = 0;
			while(pomocna>0)
				{
					a = pomocna%10;
					
					provjera = 0;
					for (j = 0; j < n_cifara; j++)
						{
							if (niz_cifara[j] == a)
								provjera = 1;
						}
						
					if (provjera == 0)
						naopaka = naopaka*10+a;
					
					
					pomocna/=10;
				}
				
			pomocna = naopaka;
			naopaka = 0;
			while (pomocna>0)
				 {
				 	a = pomocna%10;
				 	naopaka = naopaka*10+a;
				 	pomocna/=10;
				 	
				 }
			
			if (negativan == 1)
				naopaka*=-1;
			
			niz_brojeva[i] = naopaka;
		}
	
	
	
	
	
	
	
	
	
	return 1;
}






int main() {
	
	int brojevi[1] = {12345};
	int cifre[3] = {1,3,5};
	
	izbaci_cifre(brojevi,1,cifre,3);
	printf("%d\n", brojevi[0]);

	return 0;
}
