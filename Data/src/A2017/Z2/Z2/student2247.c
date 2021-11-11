#include <stdio.h>
#include <math.h>

int main() {
	int niz[100]={0}, izvrnutiniz[100]={0}, praviniz[100]={0}, finalniniz[1000]={0};
	int velicina, i, brojac=0, brojistih=1, brojackrajnjegniza=0;
	
	do {
		printf("Unesite velicinu niza: ");;
		scanf ("%d", &velicina);
	}while(velicina>100 || velicina<=0);
	
	printf ("Unesite clanove niza: ");
	
	/*unosim clanove niza u niz koji je velicine koju je korisnik unio */
	for (i=0; i<velicina; i++){
		scanf ("%d", &niz[i]);
		
	}
	
	for (i=velicina-1; i>=0; i--){
		/*ako naidje na broj koji je 0, spasi ga u niz i poveca njegov brojac*/
		if (niz[i]==0){ izvrnutiniz[brojac]=niz[i];
		brojac++;
			
		}
		
	     /*a u slucaju ako je broj na koji je naisao razlicit od nule i veci od nule logicno*/
		 else {
	  		while (niz[i]!=0) /*dijeljenje ovo dole koje radimo u while petlji ce se prekinuti onda kad taj broj 
	  		postane nula, tj prestat ce se dijeliti kad dodje do zadnje cifre (zadnja cifra/10=0)*/
	  		{
	  			izvrnutiniz[brojac]=niz[i]%10;
	  			niz[i]=niz[i]/10;
	  			brojac++;
	  	}
	  }
	} 
		
	/*sada elemente izvrnutog niza stavljamo u pravi redoslijed,
	tacnije zadnji element izvrnutog niza stavljam u prvi element pravog niza*/
	for(i=0;i<brojac;i++){
		praviniz[brojac-1-i]=izvrnutiniz[i];
	}
	/*brojim koliko se isti broj puta ponavlja zaredom*/
	for (i=0; i<brojac; i++){
		if (praviniz[i]==praviniz[i+1] && (i+1)!=(brojac-1))
			brojistih++;
			
			else if (praviniz[i]==praviniz[i+1] && (i+1)==(brojac-1)){
				brojistih++;
			/*u finalni niz upisujem elemente krajnjeg niza, pa onda broj istih cifara*/
			finalniniz[brojackrajnjegniza]=praviniz[i];
			finalniniz[brojackrajnjegniza+1]=brojistih;
			brojackrajnjegniza=brojackrajnjegniza+2;
			break; /*samo jednom ce doci do zadnjeg elementa, logicno*/
	}
	else {
		/*u finalni niz upisujem elemente krajnjeg niza, pa onda broj istih cifara*/
		finalniniz[brojackrajnjegniza]=praviniz[i];
		finalniniz[brojackrajnjegniza+1]=brojistih;
		brojackrajnjegniza=brojackrajnjegniza+2;
		brojistih=1;
	}	
		}
	
	printf ("Finalni niz glasi:\n");
	
	for(i=0;i<brojackrajnjegniza; i++){
	printf("%d ",finalniniz[i]);
	}

	return 0;
}
