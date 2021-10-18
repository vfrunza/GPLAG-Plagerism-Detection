#include <stdio.h>

char *izbaci_najcescu(char *tekst){
	char *pocetna=tekst, *pok_najcesca=0,*uporedjivac=0,*adresa_trenutne_rijeci=0,*kraj_rijeci=0;
	int max=0,broj_ponavljanja=0,razmak=1,isti=1;
	while(*tekst) {
		/*Pomjerimo tekst na sljedecu rijec kojoj cemo mjerit broj ponavljanja*/
		while(*tekst) {
			if(*tekst<'A' || (*tekst>'Z' && *tekst<'a') || *tekst>'z')
				razmak=1;
			else if(razmak) {
				razmak=0;
				break;
			}
			tekst++;
		}
		uporedjivac=tekst;
		adresa_trenutne_rijeci=tekst;
		broj_ponavljanja=0;
		while(*uporedjivac) {
			isti=1;
			/*Uporedimo je sa tekstom*/
			while(1) {
				if( (*uporedjivac<'A' || (*uporedjivac>'Z' && *uporedjivac<'a') || *uporedjivac>'z') && (*tekst<'A' || (*tekst>'Z' && *tekst<'a') || *tekst>'z'))
					break;
				if(*tekst!=*uporedjivac && *tekst!=*uporedjivac+('a'-'A') && *tekst!=*uporedjivac-('a'-'A')) {
					isti=0;
					break;
				}
				tekst++;
				uporedjivac++;
			}
			tekst=adresa_trenutne_rijeci;
			if(isti)
				broj_ponavljanja++;

			/* Pomjerimo uporedjivac na sljedecu rijec */
			while(*uporedjivac) {
				if(*uporedjivac<'A' || (*uporedjivac>'Z' && *uporedjivac<'a') || *uporedjivac>'z')
					razmak=1;
				else if(razmak) {
					razmak=0;
					break;
				}
				uporedjivac++;
			}
		}
		razmak=0;
		/*Provjerimo je li trenutna rijec najponavljanija i postavimo pok na nju ako jeste*/
		if(broj_ponavljanja>max) {
			max=broj_ponavljanja;
			pok_najcesca=adresa_trenutne_rijeci;
		}

	}
	if(max==0) {
		return pocetna;
	}
	/*Izbacimo sada sva ponavljanja najcesce rijeci*/
	uporedjivac=pok_najcesca;
	while(*uporedjivac) {
		while(*uporedjivac) {
			if(*uporedjivac<'A' || (*uporedjivac>'Z' && *uporedjivac<'a') || *uporedjivac>'z')
				razmak=1;
			else if(razmak) {
				razmak=0;
				break;
			}
			uporedjivac++;
		}
		tekst=pok_najcesca;
		isti=1;
		adresa_trenutne_rijeci=uporedjivac;
		while(1) {
			if( (*uporedjivac<'A' || (*uporedjivac>'Z' && *uporedjivac<'a') || *uporedjivac>'z') && (*tekst<'A' || (*tekst>'Z' && *tekst<'a') || *tekst>'z'))
				break;
			if(*tekst!=*uporedjivac && *tekst!=*uporedjivac+('a'-'A') && *tekst!=*uporedjivac-('a'-'A')) {
				isti=0;
				break;
			}
			tekst++;
			uporedjivac++;
		}
		if(isti) {
			kraj_rijeci=uporedjivac;
			uporedjivac=adresa_trenutne_rijeci;
			while(*kraj_rijeci) {
				*uporedjivac++=*kraj_rijeci++;
			}
			*uporedjivac=0;
			uporedjivac=adresa_trenutne_rijeci;
		}
	}
	/*Moramo izbacit i prvo ponavljanje najcesce rijeci*/
	kraj_rijeci=pok_najcesca;
	while((*kraj_rijeci>='A' && *kraj_rijeci<='Z') || (*kraj_rijeci>='a' && *kraj_rijeci<='z')) {
		kraj_rijeci++;
	}
	while(*kraj_rijeci)
		*pok_najcesca++=*kraj_rijeci++;
	*pok_najcesca=0;

	return pocetna;
}



int main(){
	char tekst[50000];
	char tekst_2[100] = " ///***125 Ovo/ je ovo* jako ovo1 komplikovan i ovo? nerazumljiv tekst1   465..** ";
	int i;
	for(i=0; i<49997; i++) {
		tekst[i]='a';
	}
	tekst[i++]=' ';
	tekst[i++]='b';
	tekst[i]='\0';
	printf("'%s'",izbaci_najcescu(tekst));
	printf("\n'%s'", izbaci_najcescu(tekst_2));
	return 0;
}