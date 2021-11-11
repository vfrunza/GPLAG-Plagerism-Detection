/*#include <iostream>
#include <cmath>*/

/* Problem ako je prvi clan niza1 jednocifren */

/*using namespace std;*/
#include <stdio.h>
#include <math.h>

int brojCifri(int broj)
{
    int duzina = 0;
    
    do
    {
        broj /= 10;
        duzina++;
        
    }while(broj > 0);
    
    return duzina;
}

int main()
{
	int niz1[100], 
	    niz2[1000], 
	    duzina, 
	    cifra,
	    brojac = 1,
	    temp,
	    clan,
	    n, 
	    i, 
	    j = 0;
	    
	
	do
	{
	    /*cout << "Unesite duzinu niza: ";
	    cin >> n;*/
	    printf("Unesite velicinu niza: ");
	    scanf("%d", &n);
	    
	}while(n <= 0 || n > 100);
	
	/*cout << "Umesite broj: " << endl;*/
	printf("Unesite clanove niza: ");
	for(i = 0; i < n; i++)
	{
	    /*cin >> niz1[i];*/
	    scanf("%d", &niz1[i]);
	}
	
	
	
	for(i = 0; i < n; i++)
	{
		duzina = brojCifri(niz1[i]);
		
		/* Prva cifra za provjeru*/
		if(i == 0 && j == 0)
		{
			clan = pow(10, duzina - 1);
			temp = niz1[i] / clan;
			niz1[i] = niz1[i] % clan;
			if(duzina > 1) duzina--;
		}
		
		do
		{
			
			clan = pow(10, duzina - 1);
			cifra = niz1[i] / clan;
			
			if(cifra == temp) brojac++;
			else
			{
				niz2[j] = temp;
	        	niz2[j + 1] = brojac;
	        	temp = cifra;
	        	brojac = 1;
	        	j = j + 2;	
			}
			
			niz1[i] = niz1[i] % clan;
			duzina--;
			
			if(i == n - 1 && duzina == 0 && n > 1)
			{
				niz2[j] = cifra;
				niz2[j + 1] = brojac;
				j = j + 2;
			}
			
			
		}while(duzina > 0);
	}
	
	
	
	printf("Finalni niz glasi:\n");
	for(i = 0; i < j; i++) printf("%d ", niz2[i]);
	
	return 0;
}