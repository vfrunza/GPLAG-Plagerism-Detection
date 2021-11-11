#include <stdio.h>
#include <math.h>

void ubaci(int niz[], int vel){
	int cifra,suma=0,i,pom,novi[20000];
	
	for(i=0; i<vel; i++) {
		/*potrebno je sacuvati niz pomocu nekog pomocnog*/
		pom=niz[i];
		while(1) {
			if(niz[i]==0) break;
			/*Razdvajanje broja na cifre*/
			cifra=niz[i]%10;
			niz[i]=niz[i]/10;
			suma+=fabs(cifra);
	
		}
		niz[i]=pom;
		
		/*svaki sljedeci clan niza je suma cifara tog broja, pa je novi niz novi[velicina + 1]*/
		novi[i*2]=pom;
		novi[i*2+1]=suma;
		/*Posto sada suma ima neku vrijednost od nekog clana niza, ona opet mora biti
		nula zbog drugih clanova*/
		suma=0;
	}
	
	for(i=0; i<vel*2; i++)
		niz[i]=novi[i];
}

int izbaci(int niz[], int vel) {
	int i,j,fib[50],f,k;
	/*Prvi i drgi clan Fibonacijevog niza su jedinice */
	fib[0]=1;
	fib[1]=1;
	for(i=2; i<50; i++) { 
		fib[i]=fib[i-1]+fib[i-2];
		/*Deklarise se neka vrijednost clana jer kad bi bio niz "fib[i]" u drugoj petlji sa k (ispod) ne bi
		kompajler prepoznao i*/
		f=fib[i];
		for(k=0; k<vel; k++) {
			if(niz[k]==f || niz[k]==1) {
				/*Ako je uslov zadovoljen izbacuje se iz niza taj broj na ovaj nacin po algoritmu
				za izbacivanje iz niza sa ocuvanjem redosljeda */
				for(j=k; j<vel-1; j++) 
					niz[j]=niz[j+1];
				vel--;
				k--;
			}
		}
	}
	return vel;
}

int main() {
	int niz[20], i,iz;
	int vel=10;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
		scanf("%d", &niz[i]);
	
	printf("Modificirani niz glasi: " );
	
	ubaci(niz, vel);
	/*Niz je modificiran iz fje ubaci i sada ima 10 elemenata vise*/
	iz=izbaci(niz, vel*2);
	
	for(i=0; i<iz-1; i++)
		printf("%d, ", niz[i]);
	
	/*Na zadnjem clanu niza kojeg treba ispisati stoji tacka, pa se ispisuje niz sa zarezom
	sa predzadnjim clanom (velicina niza-1) i na kraju, iza zadnjeg clana je tacka*/
	printf("%d.", niz[iz-1]);
	
	return 0;
}
