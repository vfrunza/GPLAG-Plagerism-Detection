#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void ubaci(int *niz1,int velicina) {
	int *a,*b;
	int i,c,d,suma_cifara;
	a=b=niz1;
	/*Na posljednje mjesto niza postavljamo pokazivac*/ 
	for(i=(velicina-1);i>0;i--)
	{
		*(b+(2*i))=*(a+i);
		
	}
	a=niz1;
	for(i=0;i<velicina*2;i++) {
		suma_cifara=0;
		/* Uzimamo pozitivne vrijednosti zbog sume */
		c=*(a+i);
		c=abs(c);
		do {
			d=c%10;
			c=c/10;
			suma_cifara=suma_cifara+d;
			
		} while (c!=0);
		/* Upisujemo sumu u sljedeci clan */
		*(a+i+1)=suma_cifara;
		i++;
		
	}
	
}
int Fibon_niz(int f) {
	int e,g,h;
	if(f==1) 
	{ 
		return 1;
		
	}
	if(f<0) 
	{
		return 0;
		
	}
	e=1;
	g=1;
	while(1) {
		h=(e+g);
		if(h>f) 
		{
			return 0;
			
		}
		else if(f==h) 
		{
			return 1;
			
		}
		e=g;
		g=h;
		
	}

}
int izbaci( int *niz1, int velicina) {
	int i,c,j;
	int *a;
	a=niz1;
	for(i=0;i<velicina;i++) 
	{
		c=Fibon_niz(*(a+i));
		if(c==1)
		/*Ako pripada Fibonaccijevom nizu izbacujemo ga */
		{
			for(j=i;j<(velicina-1);j++) 
			{
				*(a+j)=*(a+j+1);
				
			}
			velicina--;
			i--;
		}
	}
	return velicina;
	
}
int main() {
	int niz1[20],i,c;
	int velicina=10;
	printf("Unesite niz od 10 brojeva:");
	for(i=0;i<velicina;i++) 
	{
		scanf("%d", &niz1[i]);
		
	}
	/*Velicina niza nakon funkcije je duplo veca od prvobitnog niza*/
	ubaci(niz1,velicina);
	c=izbaci(niz1,velicina*2);
	printf(" Modificirani niz glasi: ");
	for(i=0;i<(c-1);i++)
	{
		printf("%d, ", niz1[i]);
			
		}  
		printf("%d. ", niz1[i]);
	
	return 0;
}




















