#include <stdio.h>

int main() {
	
	int broj, cifra1, cifra2, suma=1, br=0, k=0, rez=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	if(broj<0) broj=-broj;
	while(broj>10)
	{
	    cifra1=broj%10;
	    broj/=10;
	    cifra2=broj%10;
	    rez=cifra1-cifra2; if(rez<0) rez=-rez;
	    suma= suma*10 + rez;
	} 
	
	while(suma!=1)
	{
	  br=suma%10;
	  k= k*10 + br;
	  suma/=10;
	}
	printf("%d", k);


	return 0;
}
