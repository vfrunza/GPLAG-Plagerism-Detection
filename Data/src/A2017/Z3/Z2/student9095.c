#include <stdio.h>
#include <math.h>

/* Problem kod zaokruzivanja cifri zaokruzi na n.0 */

void zaokruzi(float *niz, int duzina);
void preslozi(float niz[], int duzina, int k);

int main()
{
	
	float niz[100];
	int n, i, k;
	
	do
	{
		printf("Unesite duzinu niza: ");
		scanf("%d", &n);
		
	}while(n <= 0 || n > 100);
	
	printf("Unesite niz: ");
	for(i = 0; i < n; i++)
		scanf("%g", &niz[i]);
		
	zaokruzi(niz, n);
	
	do
	{
		printf("Unesite koeficijent k: ");
		scanf("%d", &k);
		
	}while(k <= 0);
	
	preslozi(niz, n, k);
	
	return 0;
}

void zaokruzi(float *niz, int duzina)
{
    int i;
    
    for(i = 0; i < duzina; i++)
    {   
      *(niz + i) = roundf(*(niz+i) * 10) / 10;  
        
    }
}

void preslozi(float niz[], int duzina, int k)
{
	int i, j, temp, tempS, x;
	int suma[100] = {0};
	
	for(i = 0; i < duzina; i++)
	{
		x = niz[i] * 10;
		do
		{
			suma[i] = suma[i] + x % 10;
			x = x / 10;
			
		}while(x > 0);
	}
	
	for(i = 0; i < duzina; i++)
	{
		if(suma[i] >= k)
		{
			for(j = 0; j < i; j++)
			{
				if(suma[j] < k)
				{
					tempS = suma[i];
					suma[i] = suma[j];
					suma[j] = tempS;
					
					temp = niz[i];
					niz[i] = niz[j];
					niz[j] = temp;
				}
			}
		}
	}
	
	printf("Niz glasi: ");
	for(i = 0; i < duzina; i++)
		printf("%g ", niz[i]);
		
	
}
