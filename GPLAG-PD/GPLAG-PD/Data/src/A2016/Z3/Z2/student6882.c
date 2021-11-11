#include <stdio.h>
#include<math.h>
#include <stdlib.h>


int suma_cifara (int n)
{ 
	int suma=0;
	if (n<0)
	{
	n=-n; }
	while (n)
	{
		suma+=n%10;
		n/=10;
	}
	return suma;
}

int dajFib(int n)
{ 
	int i, fib1,fib2,fibn;

	fib1=1;
    fib2=0;
    fibn=1;
    for(i=2;i<=n;i++)
    {
   fibn=fib1+fib2;
     fib2=fib1;
     fib1=fibn;
    }
    return fibn;
}
int je_li_fib (int n)
{ 
	int i=0;

    int ima=0;
	while (1)
	{
		if (n==dajFib(i)) return 1;
		else if (dajFib(i)>n) return 0;
	
	i++;
		
	} 


}
int izbaci (int *niz, int n)
{  
	int i,j;
    
    for(i=0;i<n;i++)
    {
    if (je_li_fib(niz[i]))
    {
    for (j=i; j<n-1;j++)
    {
    	niz[j]=niz[j+1];
    	
    }
    n--; i--;
    } }
    
  
    return n;
}

void ubaci_element(int *niz, int br, int poz, int el)
{
	int i;
	for (i=br; i>poz; i--)
    niz[i]=niz[i-1];
	niz[poz]=el;
}

void ubaci (int *niz, int br)
{ 
	int i;
	for (i=0; i<br;i+=2)
	
		
		ubaci_element(niz,br++,i+1,suma_cifara(niz[i]));
	
}



int main() {
	int niz[20];
	int i;
		printf ("Unesite niz od 10 brojeva: ");
	for (i=0; i<10;i++)
	{
	 scanf ("%d",&niz[i]);
	} 

  
  ubaci(niz,10);
   
   int velicina;
   velicina=izbaci(niz,20);
   
   printf ("Modificirani niz glasi: ");
    for (i=0; i<velicina-1;i++)
    {
    	printf ("%d, ",niz[i]);
    }
    if (i==velicina-1)
    printf ("%d.",niz[i]);
	return 0;
}
