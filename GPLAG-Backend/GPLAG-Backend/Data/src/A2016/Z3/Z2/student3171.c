#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void ubaci(int niz[], int velicina)
{
	int i, j, suma=0, temp, cifra;
	j=velicina*2-2;
	
	
	for(i=velicina-1; i>=0; i--)
	{
		niz[j]=niz[i];
		j=j-2;
	}
	
	
	/* racunanje sume cifri broja niza*/
	
	for(i=0; i<velicina*2; i+=2)
	{
		suma=0;
		temp=niz[i];
		
		do
		{
			cifra=temp%10;
			suma=suma+abs(cifra);
			temp=temp/10;
			
		}while(temp!=0);
		
		
		niz[i+1]=suma;
		
		
	}
	

	
	
}


int izbaci(int niz[], int velicina)
{
	
	int i, x[100], j, k;
	
	x[0]=1;
	x[1]=1;
	
	/* x-fibonaccijev niz*/
	for(i=2; i<100; i++)
	{
		x[i]=x[i-1]+x[i-2];
	}
	
	/* izmacivanje iz niza; posebno provjeriti za 1 jer je i ona fibonaccijev broj*/
	for(i=0; i<velicina; i++)
	{
		if(niz[i]==1)
		{
			for(k=i; k<velicina-1; k++)
				{
					niz[k]=niz[k+1];
				}
				
				velicina--;
				k--;
				i--;
			
		}
		
		
		else 
		{
			for(j=2; j<100; j++)
			{
				if(niz[i]==x[j])
				{
					/* izbacujemo iz niza */
				
					for(k=i; k<velicina-1; k++)
					{
						niz[k]=niz[k+1];
					}
				
					velicina--;
					k--;
					i--;
					break;
				
				}
				
			}
		}
		
		
	}
	
	
	
	
	
	return velicina;
}



int main() {
	
	int niz[20], i;
	int br;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
	{
		scanf("%d", &niz[i]);
	}
	
	/*pozivanje funkcije ubaci */
	ubaci(niz, 10);
	
	/* poziv funkcije izbaci */
	
	br=izbaci(niz, 20);

	/* poziv modificiranog niza */
	
	printf("Modificirani niz glasi: ");
	for(i=0; i<br; i++)
	{
		if(i<br-1)
		printf("%d, ", niz[i]);
		
		else printf("%d. ", niz[i]);
	}

	
	
	
	
	
	
	return 0;
}
