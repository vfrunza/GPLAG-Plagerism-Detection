#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int izbaci_cifre(int niz1[], int n1, int niz2[], int n2);
int brojCifri(int broj);
int ponavljanje(int niz[], int n);

int main()
{
	int niz1[100], niz2[100], n1, n2, i;
	
	do
	{
		printf("Unesite duzinu niza: ");
		scanf("%d", &n1);
		
	}while(n1 <= 0 || n1 > 100);
	
	printf("Unesite niz: ");
	for(i = 0; i < n1; i++)
		scanf("%d", &niz1[i]);
		
	do
	{
		printf("Unesite duzinu niza: ");
		scanf("%d", &n2);
		
	}while(n2 < 0 || n2 > 100);
		

	printf("Unesite cifre: ");
	for(i = 0; i < n2; i++)
		scanf("%d", &niz2[i]);

	
		
	printf("%d", izbaci_cifre(niz1, n1, niz2, n2));
	
	return 0;
}

int izbaci_cifre(int niz1[], int n1, int niz2[], int n2)
{
	int i, j, clan, temp, suma = 0, duzina;
	int flag, x, negativan;
	int p = ponavljanje(niz2, n2);

	if(n2 > 10) return 0;
	else if(p == 0) return 0;
	else
	{
	
		for(i = 0; i < n1; i++)
		{
			
			negativan = 0;
			x = 0;
			duzina = brojCifri(niz1[i]);
			temp = niz1[i];
			suma = 0;
			
			if(temp < 0)
			{
				temp = abs(temp);
				negativan = 1;
			}
			
			do
			{
				
				flag = 0;
				clan = temp % 10;
				for(j = 0; j < n2; j++)
				{
					if(niz2[j] < 0 || niz2[j] > 9) return 0;
					else if(clan == niz2[j])
					{
						flag = 1;
						break;
					}
				}
				
				if(flag == 0)
				{
					suma = suma + clan * pow(10, x++);
				}
				
				temp = temp / 10;
				duzina--;
				
				
			}while(duzina > 0);
			
			if(negativan == 1) niz1[i] = suma * (-1);
			else niz1[i] = suma;
		}
		
		/*
		for(i = 0; i < n1; i++)
		{
			printf("%d ", niz1[i]);
		}*/
	}
	
	return 1;
}

int brojCifri(int broj)
{
    int duzina = 0;
    broj = abs(broj);
    
    do
    {
        broj /= 10;
        duzina++;
        
    }while(broj > 0);
    
    return duzina;
}

int ponavljanje(int niz[], int n)
{
	int i, j;
  
  	for(i = 0; i < n; i++)
    	for(j = i+1; j < n; j++)
      		if(niz[i] == niz[j])
        		return 0;
    
    return 1;
}
