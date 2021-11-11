#include <stdio.h>
#include <math.h>

int main() {
	 int niz[100],rez[100],PONAVLJANJA[100],i,velicina_niza,brojac_cifara=0,temp,cifra,n,brojac,j,stepen,x,br=0,broj_ponavljanja,br_cif;
	 printf("Unesite velicinu niza: ");
	 scanf("%d",&velicina_niza);
	 printf("Unesite clanove niza: ");
	 for(i = 0; i < velicina_niza; i++)
	 {
	     scanf("%d",&niz[i]);
	     if(niz[i] < 0)
	     {
	         i--;
	         printf("Unesite clanove niza: ");
	     }
	 }
	 for(i = 0; i < velicina_niza; i++)
	 {
	     brojac_cifara = 0;
	     temp = niz[i];
	     while(temp > 0)
	     {
	        cifra = temp % 10;
	        brojac_cifara++;
	        temp /= 10;
	     }
	 }
	 for(j = 0; j < velicina_niza; j++)
	 {
	     n = niz[j];
	     temp = n;
	     brojac = 0;
	     do{
	         brojac++;
	         temp /= 10;
	     }while (temp > 0);
	     temp = n;
	     brojac--;
	     for(i = brojac; i >= 0; i--)
	     {
	         stepen = pow(10,i);
	         x = temp / stepen;
	         temp = n - x*stepen;
	         n = temp;
	         rez[br] = x;
	         br++;
	         
	     }
	 }
	 br_cif= 0;
	 rez[br] = 10;
	 broj_ponavljanja =1;
	 for(i = 0; i < br; i++)
	 { 
	    if(rez[i] == rez[i+1])
	    {
	        broj_ponavljanja++;
	    }
	    else
	    {
	    	PONAVLJANJA[br_cif]= rez[i];
	    	br_cif++;
	        PONAVLJANJA[br_cif]=broj_ponavljanja;
	        br_cif++;
	        broj_ponavljanja= 1;
	    }
	    
	 }
	 printf("Finalni niz glasi:\n");
	 for(i = 0; i < br_cif; i++)
	 {
	     printf("%d ",PONAVLJANJA[i]);
	 }
	 
	return 0;
}
