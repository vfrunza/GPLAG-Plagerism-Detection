#include <stdio.h>

/* UBACI RADI 100% */
void ubaci(int *niz, int brclan) {
	int i, t;
	
	/* Uduplava clanove niza, tako da se isti broj ponavlja po 2 puta zaredom, popunjava sve clanove niza da mozemo stavljati zbir */
	for(i=brclan*2 - 1; i>=0; i--) {
		niz[i]=niz[i/2];
	}
	
	/* Inkrement za 2 tako da ima 20 clanova i tako da ima mjesta za nove (one koji su zbir cifara) */
	for(i=0; i<brclan*2; i++) {
		/* Pretvaranje negativnog u pozitivni broj */
		if(niz[i]>0) t=niz[i];
		else t=niz[i] * (-1);
		
		/* Samo overwrite duplikate, neparne clanove! */
		if(i%2!=0) {
			niz[i]=0;
			/* Sabiranje cifara clana u sljedeci clan */
			while(t!=0){
			niz[i]+=t%10;
			t/=10;
			}
		}
	}
}

int izbaci(int *niz, int brclan) {
	int i, j, fib[1000]={0}, k;
	/* Generisanje Fibonaccijevog niza */
	fib[0]=1;
	fib[1]=2;
	for(i=2; i<1000; i++) {
		fib[i]=fib[i-1]+fib[i-2];
	}

	/* Izbacivanje clanova koji se podudaraju sa Fibonaccijevim nizom */
	for(i=0; i<brclan; i++) {
		for(j=0; j<1000; j++) {
			if(niz[i]==fib[j]) {
				for(k=i; k<brclan-1; k++) {
					niz[k]=niz[k+1];
				}
				/* Brise se clan i smanjuje ukupni broj elemenata */
				brclan--;
				i--;
				break;
			}
		}
	}
	return brclan;
}

int main() {
	int niz[21]={0}, i, brclan=10;
	
	/* Unos niza */
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++) {
		scanf("%d", &niz[i]);
		if (niz[i]%1!=0) i--;
	}
	
	/* Funkcije */
	ubaci(niz, brclan);
	/* Nakon sto smo dodali zbirove treba nam mjesto za sami clan i zbir njegovih cifara tj. svakom clanu trebaju dva mjesta i duplo veci niz */
	brclan*=2;
	izbaci(niz, brclan);
	
	/* Ispis */
	printf("Modificirani niz glasi: %d", niz[0]);
	for(i=1; i<brclan; i++) {
		if(niz[i]!=1) printf(", %d", niz[i]);
		}
	
	printf(".");
	
	return 0;
}