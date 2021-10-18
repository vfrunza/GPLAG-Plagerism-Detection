#include <stdio.h>
#include <stdlib.h>
#define br 10

void ubaci(int *niz, int br_clanova)
{
	int i, cifra;

	niz = niz + br_clanova-1;
	for(i=0; i<br_clanova; i++)
	{
		*(niz+br_clanova-1-2*i) = *(niz-i);
	}
	
	for(i=1; i<br_clanova*2; i++)
	{
		if(i%2 == 1)
		{
			*(niz-br_clanova+1+i) = 0;
			cifra = abs(*(niz-br_clanova+i));
			
			while(cifra != 0)
			{
				*(niz-br_clanova+1+i) += cifra%10;
				cifra /= 10;
			}
		}
	}
}

int izbaci(int *niz, int br_clanova)
{
	int max, i, j, fibo, fibo1, fibo2;
	int *pomocni_pokazivac = niz;
	
	max = *niz;
	while(pomocni_pokazivac < niz+br_clanova)
	{
		if(*pomocni_pokazivac > max)
		{
			max = *pomocni_pokazivac;
		}
		pomocni_pokazivac++;
	}
	
	for(i=0; i<br_clanova; i++)
	{
		fibo=0;
		fibo1=1;
		fibo2=0;
		
		while(fibo <= max)
		{
			fibo = fibo1 + fibo2;
			if(*(niz+i) == fibo)
			{
				for(j=i; j<br_clanova-1; j++)
				{
					*(niz+j) = *(niz+j+1);
				}
				br_clanova--;
				i--;
				break;
			}
			fibo2 = fibo1;
			fibo1 = fibo;
		}
	}
	
	return br_clanova;
}

int main()
{
	int niz[2*br], i, novi_br_clanova; 
	
	printf("Unesite niz od %d brojeva: ", br);
	for(i=0; i<br; i++) 							
	{
		scanf("%d", &niz[i]);
	}
	
	ubaci(niz, br);								
	novi_br_clanova = izbaci(niz, br*2); 			
								
	printf("Modificirani niz glasi: ");
	for(i=0; i<novi_br_clanova; i++)		
	{
		if(i == novi_br_clanova-1)
		{
			printf("%d.", niz[i]);
		}
		else
		{
			printf("%d, ", niz[i]); 
		}
	}	

	return 0;
}