#include <stdio.h>
#include <stdlib.h>

void ubaci (int* p1, int vel) 	/*Vrsenje izmjena nad vrijednostima clanova niza time sto ce im pristupati pomocu njihovih adresa*/
{
    int i, a, suma;
    int niz2[20]={0};       	/*Incijalizacija privremenog niza 2*/
    int* p2=niz2;
    for (i=0; i<vel; i++)
    {
        suma=0;
        *(p2+2*i)=*(p1+i); 		/*Smjestanje prvobitnih unesenih vrijednosti clanova niza na mjesta sa parnim indeksom*/
        a=abs(*(p1+i));		
        do{
            suma+=a%10;
            a/=10;
        }while(a!=0);
        *(p2+2*i+1)=suma;		/*Smjestanje dobivene sume na mjesta oznacena sa neparnim indeksom niza 2 */
    }
    for(i=0; i<2*vel; i++)
    {
    	*(p1+i)=*(p2+i);  		/*"Prepisivanje" vrijednosti clanova niza2 u niz1*/
    }
    
}

int fibonaci (int n) {  		/*Generisanje Fibonacijevih brojava, provjera poslane vrijednosti, te vracanje logicke vrijednosti*/
	int i=1, j=1, k;
	do {
		if (i==n)
		return 1;
		k=i;
		i=i+j;
		j=k;
		
	} while (n>=i); 			/*Izbjegnut ulazak u beskonacnu petlju*/
	return 0;
}

int izbaci (int* p1, int vel) 	/*Po nailasku na Fibonacijev broj, clanove poslije njega se pomjeraju za jedan, te se vraca nova duzina niza*/
{
	int i, j;
	for (i=0; i<vel; i++)
	{
		if (fibonaci(*(p1+i)))
		{
			for (j=i; j<vel-1; j++)
			{
				*(p1+j)=*(p1+j+1);
			}
			vel--;
			i--;
		}
	}
	return vel;
	
}

int main() {
	int niz1[20]={0}, i, n;
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++)
	{
	    scanf("%d", &niz1[i]);
	}
	ubaci(niz1, 10);		/*Pozivanje funkcije za ubacivanje sume cifara pocetnog niza*/
	n=izbaci(niz1, 20);		/*Pozivanje funckije za izbacivanje Fibonacijevih brojeva*/
	printf("Modificirani niz glasi: ");
	for (i=0; i<n; i++)
	{
		if (i==n-1)
		printf("%d.", niz1[i]);
		else
	    printf("%d, ", niz1[i]);
	}
	return 0;
}
