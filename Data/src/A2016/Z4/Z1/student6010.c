#include <stdio.h>

void unesi(char* niz, int velicina) {
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	} niz[i]='\0';
} 
int brojSlova(char* zaizbacit) {
	int broj=0;
	char* temp=zaizbacit;
	while(*temp!='\0') {
		broj++;
		temp++;
	}
	return broj;
}

int uporedi(char* pokazivaci, char* s) {
	char* p=pokazivaci;
	char* zamjena=s;
	int brponavljanja=0;
	while(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && *zamjena!='\0'){
		if((*zamjena<'A' || (*zamjena>'Z' && *zamjena<'a') || *zamjena>'z') || ((*p!=*zamjena) && (*p!=*zamjena+32) && (*p!=*zamjena-32))) {
			p=pokazivaci;
		}

	p++;
		zamjena++	;
		if(*p<'A' || (*p>'Z' && *p<'a') || *p>'z' ) {brponavljanja++;
		p=pokazivaci;}
		
	
	}
	return brponavljanja;
}

 /* Funkcija "uporedi" mi sluzi da uporedjujem odredjenu rijec sa ostalim rijecima u stringu.Princip radafje je da dok god je slovo rijeci jednako 
	nekom slovu rijeci iz stringa i dalje se uporedjuju, u suprotnom pokazivac na slova odredjene rijeci se vraca na pocetak te rijeci i ceka se iduca rijec.
	Ako nakon while petlje je *p nul terminator onda to znaci da je cijela rijec ponovljena i broj ponavljanja se povecava.
	Funkcija vraca broj ponavljanja odredjene rijeci.*/
char* izbaci_najcescu(char* s){
	int rednibroj=0, i, a=0, max, prostor; 
	char* pokazivaci[25], *zaizbacit[10];
	char* p=s;
	char* r, *q, *poc;
	q=s;
	int brojpon[25]={0};
	if((*p>='A' && *p<='Z') ||(*p>='a' && *p<='z')) {pokazivaci[0]=s;
													rednibroj++;
	}
	while(*p!='\0') {
		p++;
		if(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && (*(p-1)<'A' || (*(p-1)>'Z' && *(p-1)<'a') || *(p-1)>'z')) {rednibroj++;
			pokazivaci[rednibroj-1]=p;
		} 
	}
		/*Pomocu ove while-petlje postavljam jedan od clanova iz niza pokazivaca na pocetak svake rijeci (pretpostavio sam da 
	nece biti vise od 25 rijeci, mozda bi bilo bolje da sam napravio funkciju koja broji rijeci i stavik da je broj elemnata niza
	pokazivaca broj rijeci.*/
	for(i=0; i<rednibroj; i++) {
		brojpon[i]=uporedi(pokazivaci[i], s);
	} /*U ovoj for-petlji pozivam funkciju "uporedi" za svaku rijec stringa tj. za svaki pokazivac iz niza pokazivaca i dobijam broj njenog ponavljanja*/
	max=brojpon[0]; 
	for(i=1; i<rednibroj; i++) {
		if(brojpon[i]>max) {max=brojpon[i];}
		
	} /*U ovoj for-petlji vidim koji je najveci broj ponavljanja*/
	while(a<10) {
		for(i=0; i<25; i++) {
			if(brojpon[i]==max) zaizbacit[a]=pokazivaci[i];
		} a++;
	} /*U ovoj while-petlji imam pretpostavku da ne treba izbaciti vise od 10 rijeci.Tu ukolikojebroj ponavljanja neke rijeci jednak broju
	ponavljanja rijeci koja se najvise ponavlja to znaci da je to ta rijec i da je treba izbaciti, pa sam preko for-petlje trazio
	koju trebam izbaciti.*/
	prostor=brojSlova(*zaizbacit); 
	while(*q!='\0') {
		for(i=0; i<10; i++) {
			if(q==zaizbacit[i]) {
			poc=q; 
			r=q+prostor;
			while((*poc>='A' && *poc<='Z') || (*poc>='a' && *poc<='z')) {
				*poc=*r;
				poc++;
				r++;
			}
			}
			} 
		 q++;
	}
	return s;
}
int main() {
	char s[250];
	unesi(s,250);
	char* rez;
	rez=izbaci_najcescu(s);
	printf("%s", rez);
	return 0;
}