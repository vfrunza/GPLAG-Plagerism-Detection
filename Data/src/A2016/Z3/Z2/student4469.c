#include <stdio.h>
#include <stdlib.h>

int saberi(int a) {           //funkcija koja sabire cifre broja
	int s=0;
	a=abs(a);
	while(a>0) {
		
		s=s+a%10;
		a=a/10;
	}
	return s;
}


int fibonacci(int a) {               //funkcija koja generise brojeve iz fibonaccijevog niza
	int prvi=0,drugi=1,sljedeci,i;
	for(i=0;i<a;i++) {
		
		sljedeci=prvi+drugi;
		prvi=drugi;
		drugi=sljedeci;
	if(sljedeci==a) {              //Ako je broj iz fibonaccijevog niza jednak broju koji je poslat funkciji, vraca istinitosnu vrijednost 1
		return 1;
	}	
	}
	return 0;                //Ako se petlja zavrsila znaci da broj nije iz fibonaccijevog niza, vraca istinitosnu vrijednost 0

}




void ubaci(int*p,int velicina) {       //funkcija koja ce na svako drugo mjesto u nizu ispisati zbir cifara prethodnog clana
int i;

int nizclanova[10],nizzbirova[10];
for(i=0;i<velicina;i++) {
	nizclanova[i]=*p;                 //formiramo lokalni niz clanova
	nizzbirova[i]=saberi(*p);         //lokalni niz zbirova cifara, koji su kalkulisani u funkciji saberi
	p++;
}

p=p-velicina;                 //vracamo pokazivac na pocetak
for(i=0;i<velicina;i++) {      
	
	*p=nizclanova[i];          // vrsi se upisivanje, u niz iz maina, clana iz lokalnog niza clanova
	*(p+1)=nizzbirova[i];      // upisivanje clana iz lokalnog niza zbirova u niz iz maina (zbir cifara prethodnog clana)
	p=p+2;
}

}


int izbaci (int *p,int velicina) {             //funkcija koja izbacuje fibonaccijeve brojeve iz niza
int i,j,a=0,b,niz[20],*q=p,velicina2;


for(i=0;i<velicina;i++) {              //ucitavamo brojeve iz niza iz maina u lokalni niz
	niz[i]=*p;
	p++;
}

 
	for(i=0;i<velicina;i++) {           //izbacivanje clanova iz lokalnog niza, za koje je vracena istinitosna vrijednost 1 iz funkcije fibonacci
	if(fibonacci(niz[i])==1) {
		a++;
		for(j=i;j<velicina-1;j++) {
			niz[j]=niz[j+1];
		}
		velicina--;
		i--;

		}
	}
	p=q;       //vracanje pokazivaca na pocetak niza iz maina

	for(i=0;i<velicina;i++) {       //ucitavanje clanova iz lokalnog niza u niz iz maina
		*p=niz[i];
		p++;
	}
	
	return velicina;
	
}


int main() {
	int niz[20],i=0,brojclanova=0, velicina=10;

printf("Unesite niz od 10 brojeva: "); 
	
for(i=0;i<velicina;i++) {
	scanf("%d", &niz[i]);
}
	
ubaci(niz,velicina);        
brojclanova=izbaci(niz,2*velicina); //prosljedjuje se dvostruka vrijednost velicine jer ce funkcija izbaci raditi sa kompletnim nizom(nizom gdje su clanovi i zbirovi njihovih cifara)

if(brojclanova==0) {
	printf("Prazan niz");
	return 0;
}
printf("Modificirani niz glasi: ");
for(i=0;i<brojclanova;i++) {
if(i==brojclanova-1) {
	printf("%d.",niz[i]);
}

else {
	printf("%d, ",niz[i]);
}
	
}
	return 0;
}
