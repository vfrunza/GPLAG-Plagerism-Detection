#include<stdio.h>
#include<math.h>
struct Datum {
	int dan, mjesec, godina;
};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
int JesuLiIstaPrezimena (char *d, char *k) {
	while(*k!='\0') {
		char *p1=k;
		char *p2=d;
		while(*p1==*p2) {
			p1++;
			p2++;
			if(*p2=='\0' && (*p1=='-' || *p1=='\0')) return 1;
		}
		while(*k!='-' && *k!='\0') k++;
		if(*k=='-') k++;
	}
	return 0;
}
int suzi_listu (struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int i,j=0,br_prezim_direk,isto1=0,isto2=0,mladji,god,brojd;
	int prestupna[12]= {31,29,31,30,31,30,31,31,30,31,30,31};
	int neprestupna[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	char *s,*k;
	char prezime1[20];
	char prezime2[20];
	char prezime_k[20];
	s=direktor.ime_prezime;
	while(*s!='\0') s++;
	while(*s!=' ') s--;
	s++;
	while((*s>='A' && *s<='Z')||(*s>='a' && *s<='z')) {
		prezime1[j]=*s;
		j++;
		s++;
	}
	prezime1[j]='\0';
	if(*s=='-') {
		s++;
		br_prezim_direk=2;
		j=0;
		while(*s!='\0') {
			prezime2[j]=*s;
			s++;
			j++;
		}
		prezime2[j]='\0';
	} 
	else br_prezim_direk=1;
	
	for(i=0; i<vel; i++) {
		k=kandidati[i].ime_prezime;
		while(*k!='\0') k++;
		while(*k!=' ') k--;
		k++;
		j=0;
		while(*k!='\0') {
			prezime_k[j]=*k;
			j++;
			k++;
		}
		prezime_k[j]='\0';
		
		if(br_prezim_direk==1) {
			isto1=JesuLiIstaPrezimena(prezime1,prezime_k);
		} 
		else {
			isto1=JesuLiIstaPrezimena(prezime1,prezime_k);
			isto2=JesuLiIstaPrezimena(prezime2,prezime_k);
		}
		if(isto1==1 || isto2==1)  continue;
		brojd=0;
		if(fabs(kandidati[i].datum_rodjenja.godina-direktor.datum_rodjenja.godina)==1 && kandidati[i].datum_rodjenja.mjesec==12 && direktor.datum_rodjenja.mjesec==1) {
			for(j=kandidati[i].datum_rodjenja.dan; j<31; j++) brojd++;
			brojd+=direktor.datum_rodjenja.dan;
		} 
		else if(kandidati[i].datum_rodjenja.godina<direktor.datum_rodjenja.godina) {
			for(j=i; j<vel-1; j++) kandidati[j]=kandidati[j+1];
			i--;
			vel--;
		} 
		else if(kandidati[i].datum_rodjenja.godina==direktor.datum_rodjenja.godina) {
			if(kandidati[i].datum_rodjenja.mjesec<direktor.datum_rodjenja.mjesec) {
				god=kandidati[i].datum_rodjenja.godina;
				if((god%4==0 || god%400==0) && god%100!=0 ) {
					for(j=kandidati[i].datum_rodjenja.mjesec-1; j<direktor.datum_rodjenja.mjesec-1; j++) {
						if(j==kandidati[i].datum_rodjenja.mjesec-1) brojd+=(prestupna[j]-kandidati[i].datum_rodjenja.dan);
						else brojd+=prestupna[j];
					}
				} 
				else {
					for(j=kandidati[i].datum_rodjenja.mjesec-1; j<direktor.datum_rodjenja.mjesec-1; j++) {
						if(j==kandidati[i].datum_rodjenja.mjesec-1) brojd+=(neprestupna[j]-kandidati[i].datum_rodjenja.dan);
						else brojd+=neprestupna[j];
					}
				}
				brojd+=direktor.datum_rodjenja.dan;
			} 
			else if(kandidati[i].datum_rodjenja.mjesec==direktor.datum_rodjenja.mjesec) brojd+=(kandidati[i].datum_rodjenja.dan-direktor.datum_rodjenja.dan);
			else if (kandidati[i].datum_rodjenja.mjesec>direktor.datum_rodjenja.mjesec) continue;
		}
		
		if(brojd>fabs(broj_dana) && brojd!=0 ) {
			for(j=i; j<vel-1; j++) kandidati[j]=kandidati[j+1];
			vel--;
			i--;
		}
		if(broj_dana<0 && brojd<fabs(broj_dana) && brojd!=0) {
			for(j=i; j<vel-1; j++) kandidati[j]=kandidati[j+1];
			vel--;
			i--;
		}
	}
	return vel;
}
int main() {
	struct Uposlenik direktor={"Ferhat Aslan", {14,2,1982}};
	struct Uposlenik prijavljeni_k[6]={
		{"Asli Cinar-Aslan",{19,6,1984}},
		{"Sarp Yilmaz", {13,5,1980}},
		{"Gulsum Aslan",{21,3,1980}},
		{"Yaman Koper", {6,10,1982}},
		{"Mira Aslan-Koper", {30,12,1981}},
		{"Siyah Beyaz-Ask", {12,5,1979}}
	};
	int i,nakon_izbacivanja,broj_dana=27;
	nakon_izbacivanja=suzi_listu(prijavljeni_k,6,direktor,broj_dana);
	for(i=0; i<nakon_izbacivanja; i++) {
		printf("%s, %d.%d.%d.\n",prijavljeni_k[i].ime_prezime,prijavljeni_k[i].datum_rodjenja.dan,prijavljeni_k[i].datum_rodjenja.mjesec,prijavljeni_k[i].datum_rodjenja.godina);
	}
	return 0;
}
