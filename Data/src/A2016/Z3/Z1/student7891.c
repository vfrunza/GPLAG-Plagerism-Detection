#include <stdio.h>

int daj_prost()
{
	static int prosti_brojevi=1, povrvr; 
	int tacnop,i,br=0;
	tacnop=0;

	while(tacnop==0)
	{
		
		prosti_brojevi++;
		
		if(prosti_brojevi==2) {povrvr=2; return povrvr;}
		if(prosti_brojevi==3) {povrvr=3; return povrvr;}
		/*ispitivanje da li je broj prost, ako broj ima samo 2 djelioca (odnosno ako je broj djeljic sa 1 i sa samim sobom) onda je prost broj */
		for(i=1; i<=prosti_brojevi; i++)
		{
			if(prosti_brojevi%i==0) br++;
		}
		if(br==2) {tacnop=1; povrvr=prosti_brojevi; }
		br=0;
	}
	
	return povrvr;
	
	
}

int main() {
	int a,b,i,suma=0,prosti_brojevi;
	printf("Unesite brojeve A i B: ");
	scanf("%d%d", &a,&b);
	/*ispitivanje uslova iz zadatka (A i B moraju biti prirodni brojevi i a mora biti manje od B) */
do
	{
		if(a<=0 ) {printf("A nije prirodan broj. \n"); printf("Unesite brojeve A i B: ");	scanf("%d%d", &a,&b); }
		if(a>=b) { printf("A nije manje od B. \n"); printf("Unesite brojeve A i B: "); scanf("%d%d", &a,&b);}
		
		
	} while(a<=0 || b<=0|| a>=b);
	/*racunanje zbira svih prostih brojeva u intervalu od A do B (ukljucujuci A i B)*/
	for(i=0; i<=b; i++)
	{
		/*zbog napoemene da moramo koristiti funkciju daj_prost koja nema parametara, posmatramo proste brojeve od 0 do B, jer vrijednost A ne mozemo poslati u funkciju*/
		prosti_brojevi=daj_prost();
		if(prosti_brojevi>=b) break;
		
		if(prosti_brojevi>a) suma+=prosti_brojevi;
	}
	/*ispis zbira prostih brojeva*/
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
}
