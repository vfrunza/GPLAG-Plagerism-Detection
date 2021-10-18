#include <stdio.h>
#include <string.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int br_dana(struct Datum B_day) {
	int mj[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int dani=0, i;
	for(i=B_day.godina; i<2017; i++) {
		if((i%4==0 && i%100!=0)  || i%400==0) dani+=366;
		else dani+=365;
	}
	for(i=1; i<B_day.mjesec; i++) {
		dani+=mj[i];
	}
	dani+=B_day.dan;
	return dani;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int br=0, br2, drugo_prezime=0, t;
	struct Uposlenik* pok=kandidati;
	char prezime1[20], prezime2[20], *pok2=direktor.ime_prezime, *p1=prezime1, *p2=prezime2, kopija[50], *pok3, *kopi;
	while(*pok2!='\0') {
		while((*pok2>='a' && *pok2<='z') || (*pok2>='A' && *pok2<='Z')) pok2++;
		while(*pok2==' ') pok2++;
		while((*pok2>='a' && *pok2<='z') || (*pok2>='A' && *pok2<='Z')) { 
			*p1=*pok2;
			p1++;
			pok2++;
		}
		if(*pok2=='-') {
			pok2++;
			drugo_prezime=1;
			while((*pok2>='a' && *pok2<='z') || (*pok2>='A' && *pok2<='Z')) { 
				*p2=*pok2;
				p2++;
				pok2++;
			}
			break;
		}
		if(*pok2==' ')  {
			pok2++;
			p1=prezime1;
			while((*pok2>='a' && *pok2<='z') || (*pok2>='A' && *pok2<='Z')) { 
				*p1=*pok2;
				p1++;
				pok2++;
			}
			if(*pok2=='-') {
				pok2++;
				drugo_prezime=1;
				while((*pok2>='a' && *pok2<='z') || (*pok2>='A' && *pok2<='Z')) { 
					*p2=*pok2;
					p2++;
					pok2++;
				}
			}
		}
	}
	while(br<vel) {
		t=0;
		pok3=(*(kandidati+br)).ime_prezime;
		kopi=kopija;
		while(*pok3!='\0') {
			if(*pok3=='-') *kopi=' ';
			else *kopi=*pok3;
			kopi++;
			pok3++;
		}
		*kopi='\0';
		if(drugo_prezime==0) {
			if(strstr(kopija, prezime1)!=NULL) {
				br++;
				continue;
			}
		}
		if(drugo_prezime==1) {
			if(strstr(kopija, prezime1)!=NULL) {
				br++;
				continue;
			}
			if(strstr(kopija, prezime2)!=NULL) {
				br++;
				continue;
			}
		}
		if(broj_dana<0) {
			if((br_dana(direktor.datum_rodjenja)-br_dana(kandidati->datum_rodjenja))>-broj_dana) t=1;
		}
		if(broj_dana>=0) {
			if((br_dana(kandidati->datum_rodjenja)-br_dana(direktor.datum_rodjenja))>broj_dana) t=1;
		}
		if(t==1) {	
			br2=br;
			while(br2<vel-1) {
				*(pok+br2)=*(pok+br2+1);
				br2++;
			}
			vel--;
			br--;
		}
		br++;
	}
	return vel;
}
    
int main() {
	/*printf("Zadaća 5, Zadatak 1");*/
	return 0;
}