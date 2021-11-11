#include <stdio.h>
#include <math.h>

int main() {
	int nizA[100],nizB[1000],nizC[1000];
	int n;
	int i,j;
	int broj=0,cifra=0,broj_clanova=0;
	int broj_cifara,brojac=1;
	int indeks=0;
	do{
	    printf ("Unesite velicinu niza: ");
	    scanf ("%d",&n);
	}
	while (n<=0 || n>100);
	printf ("Unesite clanove niza: ");
	for (i=0;i<n;i++)
	scanf ("%d", &nizA[i]);
	/*Nakon unosa niza,od polaznog niza formiran je novi koji se sastoji od cifara svih brojeva u prvom nizu. */
	for (i=0;i<n;i++)
	{
		broj=nizA[i];
		if (broj==0)
		{
			nizB[broj_clanova]=broj;
			broj_clanova+=1;
		}
		else
		{
			while (broj!=0)
			{
				broj_cifara=floor(log10(broj))+1;
				cifra=broj%10;
				broj/=10;
				nizB[broj_clanova+broj_cifara-1]=cifra;
			}
			broj_cifara=floor(log10(nizA[i]))+1;
			broj_clanova+=broj_cifara;
		}
	}
	/*Nakon formiranja drugog niza koji se sastoji samo od cifara, porede se susjedni elementi u nizu.*/
	/*Ako su isti brojac se povecava, a jedan od uzastopnih elemenata koji su isti se izbacuje.*/
	/*Na kraju u nizu imamo niz kod kojeg nijedna dva susjedna elementa nisu ista.Te elemente ostavljamo na parna mjesta u zavrsnom nizu,a brojace na neparna,*/
    for (i=0;i<broj_clanova;i++)
    {
    	if (i!=broj_clanova-1){
    	if (nizB[i]==nizB[i+1] )
    	{
    		for (j=i;j<broj_clanova-1 && j!=broj_clanova-2;j++)
    		nizB[j]=nizB[j+1];
    		nizB[broj_clanova-2]=nizB[broj_clanova-1];
    		broj_clanova--;
    		i--;
    		brojac++;
    	}
    	else
    	{
    		nizC[indeks]=nizB[i];
    		nizC[indeks+1]=brojac;
    		brojac=1;
    		indeks+=2;
    	}}
    	else
    	{   
    		    if (broj_clanova>1 && nizB[i]==nizB[i-1])
      			{brojac++;
    			nizC[indeks+1]=brojac;
      				brojac=1;
      			}
    			else
    			{
    				nizC[indeks]=nizB[i];
    				nizC[indeks+1]=brojac;
    			}
    	}
    }
    printf ("Finalni niz glasi: \n");
    for (i=0;i<2*broj_clanova;i++)
    printf ("%d ",nizC[i]);

	
    return 0;
}
