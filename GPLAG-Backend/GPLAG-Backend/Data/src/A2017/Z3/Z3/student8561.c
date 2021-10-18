#include <stdio.h>
#include <math.h>

/*void rastavi_niz_na_cifre (int nizBrojeva[], int n)
{
	int nizCifri[100];
	int i, brojac, broj, temp;
	brojac = 0;
	for (i = n-1; i>=0; i--) 
	{
		broj = nizBrojeva[i];
		while (broj != 0) 
		{
			nizCifri[brojac] = broj%10;
			broj /= 10;
			brojac++;
		}
    }
  for (i=0; i<brojac/2; i++) 
  {
    temp = nizCifri[i];
    nizCifri[i] = nizCifri[brojac-1-i];
    nizCifri[brojac-1-i] = temp;
  }
  printf ("Cifre: ");
    for (i=0; i<brojac; i++)
    {
    	printf ("%d ", nizCifri[i]);
    }
}
void izbaci (int niz[], int vel, int niz2[], int vel2)
{
	int i, j, k, broj;
	for (k=0; k<vel2; k++) 
	{
		broj = niz2[k];
	for (i=0; i<vel; i++)
	{
		if (niz[i] == broj || niz[i] == -broj)
		{printf("niz[i]: %d ", niz[i]);
		printf("broj: %d ", broj);
			for (j=i; j<vel-1; j++)
			{
				niz[j] = niz[j+1];
			}
			vel--;
			j--;
		}
	}
	}
	printf ("\nNiz1: ");
	for (i=0; i<vel; i++) printf ("%d ", niz[i]);
	printf ("\n");
	printf ("Niz2: ");
	for (i=0; i<vel2; i++) printf ("%d ", niz2[i]);
	printf ("\n");
}
void sastavi (int niz[], int vel)
{
	int nizBrojeva[100];
	int i, n, br_cifara;
	for (i=0; i<vel; i++) printf ("%d ", niz[i]);
	printf ("vel: %d\n", vel);
	br_cifara = vel/2; printf("%d\n", br_cifara);
	for (i=0; i<vel; i++)
	{
		printf ("%d ", niz[i]);
		for (n=0; n<br_cifara; n++)
		{
			nizBrojeva[n] += pow(10,n) * niz[i];
		}
	}
	printf ("\nposlije sastavljanja: ");
	for (i=0; i<br_cifara-1; i++) printf ("%d ", nizBrojeva[i]);
	printf ("\n");
	for (i=0; i<vel; i++) printf ("%d ", niz[i]);
}*/
int izbaci_cifre (int nizBrojeva[], int vel_br, int cifre[], int vel)
{
	int nizCifri[100];
	int i, j, k, brojac, broj, temp;
	int test;
	brojac = 0;
	for (i = vel_br-1; i>=0; i--) 
	{
		broj = nizBrojeva[i];
		while (broj != 0) 
		{
			nizCifri[brojac] = broj%10;
			broj /= 10;
			brojac++;
		}
		
    }
  for (i=0; i<brojac/2; i++) 
  {
    temp = nizCifri[i];
    nizCifri[i] = nizCifri[brojac-1-i];
    nizCifri[brojac-1-i] = temp;
  }
  //for (i=0; i<brojac; i++)	printf ("nizCifri %d ", nizCifri[i]);
  //printf ("\n");
  for (k=0; k<vel; k++) 
	{
		test = 0;
		if (cifre[k] <= 0 || cifre[k] >= 9) test = 1;
		
	}
  for (k=0; k<vel; k++) 
	{
		broj = cifre[k];
	for (i=0; i<brojac; i++)
	{
		if (nizCifri[i] == broj || nizCifri[i] == -broj)
		{//printf("nizCifri[i]: %d ", nizCifri[i]);
		//printf("broj: %d ", broj);
			for (j=i; j<brojac-1; j++)
			{
				nizCifri[j] = nizCifri[j+1];
			}
			brojac--;
			j--;
		}
	}
	}
	//printf ("\nNiz1: ");
	//for (i=0; i<brojac; i++) printf ("%d ", nizCifri[i]);
	//printf ("\n");
	//printf ("Niz2: ");
	//for (i=0; i<vel; i++) printf ("%d ", cifre[i]);
	//printf ("\n");
	//printf ("Funkcija sastavi:\n");
  int nizBrojeva1[100];
  //for (i=0; i<brojac; i++) printf ("%d ", nizCifri[i]);
	//printf ("vel: %d\n", brojac);
	
	int brojic = 0;

	for (i=0; i<brojac/2; i++)
	{
		brojic = 10*brojic + nizCifri[i];
		nizBrojeva1[i] = brojic;
		//printf ("nizBrojeva1[i]: %d ",nizBrojeva1[i]);
	}
	
	//printf ("brojic: %d ", brojic);
	//for (i=0; i<brojac; i++) printf ("nizBrojeva1[i]: %d ",nizBrojeva1[i]);
	for (i=0; i<vel_br; i++)
	{
		nizBrojeva[i] = brojic;
		if (nizBrojeva[i] < 0) nizBrojeva[i] = -brojic;
		//printf("%d ", nizBrojeva[i]);
		
	}
	if (test==1) return 0;
	else return 1;
}

int main() 
{
	int niz_br[100], cifre[100];
	int velicina = 0, vel = 0;
	int i;
	printf ("Niz brojeva: ");
	for (i=0; i<100; i++)
	{
		scanf ("%d", &niz_br[i]);
		if (niz_br[i] == 0) break;
		velicina++;
	}
	printf ("Niz cifara: ");
	for (i=0; i<100; i++)
	{
		scanf ("%d", &cifre[i]);
		if (cifre[i] == 0) break;
		vel++;
	}
	
	//printf ("Novi niz: ");
	
	izbaci_cifre(niz_br,velicina,cifre,vel);
	return 0;
}
