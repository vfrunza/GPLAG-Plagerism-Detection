#include <stdio.h>
#include <string.h>

struct Datum{
	int dan, mjesec, godina;
};
struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int Prestupna(int godina){
	if(godina%400==0 || (godina%4==0 && godina%100 != 0)) return 1;
	return 0;
}

int Mjesec(struct Datum dat){
	int mj=dat.mjesec;
	if(mj==1 || mj==3 || mj==5 || mj==7 || mj==8 || mj==10 || mj==12) return 31;
	else if(mj==2) return 28+Prestupna(dat.godina);
	else return 30;
	return 0;
}

int BrojDanaUGodiniDoTogDatuma(struct Datum dat){
	int suma=0, i=0;
	struct Datum tmp=dat;
	
	suma+=dat.dan-1; /* -1 jer taj dan ne treba da uracunamo u sumu */
	while(++i<dat.mjesec){
		tmp.mjesec=i;
		suma+=Mjesec(tmp);
	}
	return suma; 
}

int BrojDanaOdReferentnogDatuma(struct Datum dat2){ 
	struct Datum dat1={1,1,1850}; /* referentni datum */
	int god1=dat1.godina, god2=dat2.godina, pomocna_god; 
	int suma=0;

	pomocna_god=god1;
	while(pomocna_god < god2){ 
		suma+=365+Prestupna(pomocna_god);
		pomocna_god++;
	}
	suma+=BrojDanaUGodiniDoTogDatuma(dat2);
	return suma;
}

int PrebrojRijeci(char* s){
	int br=0, neslovo=1;
	while(*s != '\0'){
		if(!(*s>='A' && *s<='Z') && !(*s>='a' && *s<='z')) neslovo=1;
		else if(neslovo==1){
			neslovo=0;
			br++;
		}
		s++;
	}
	return br;
}

int JeLiSlovo(char c){
	if(c>='a' && c<='z') return 1;
	else if(c>='A' && c<='Z') return 1;
	return 0;
}

int UporediPrezime(struct Uposlenik kand, struct Uposlenik direktor){
	if(PrebrojRijeci(direktor.ime_prezime)==2 && PrebrojRijeci(kand.ime_prezime)==2){
		char *s1=direktor.ime_prezime, *s2=kand.ime_prezime;
		
		char niz1[50], niz2[50];
		char *pok1=niz1, *pok2=niz2;
		
		while(*s1 != '\0' && *s1 != ' ') s1++;
		if(*s1 == ' ') s1++;
		
		while(*s2 != '\0' && *s2 != ' ') s2++;
		if(*s2 == ' ') s2++;
		
		while((*pok1++ = *s1++));
		while((*pok2++ = *s2++));
		
		return strcmp(niz1, niz2); /*  0 ako su isti */
	}
	else if(PrebrojRijeci(direktor.ime_prezime)>2 || PrebrojRijeci(kand.ime_prezime)>2){
		char *s1=direktor.ime_prezime, *s2=kand.ime_prezime;
		int d_ima_dva_p=0, k_ima_dva_p=0; /* kand odnosno dir ima 2 prezimena */
		
		char niz1[50], niz2[50], niz3[50], niz4[50]; /* moguća su 4 prezimena */
		char *pok1=niz1, *pok2=niz2, *pok3=niz3, *pok4=niz4;
		char *pom;

		while(*s1 != '\0' && *s1 != '-') s1++;
		pom=s1;
		if(*s1 == '-')	{
			pom++;
			d_ima_dva_p=1;
		}
		while((*pok2++ = *pom++));
		
		while(*s2 != '\0' && *s2 != '-') s2++;
		pom=s2;
		if(*s2 == '-')	{
			pom++;
			k_ima_dva_p=1;
		}
		while((*pok4++ = *pom++));
		
		
		pom = s1-1;/* da pokazuje na zadnje slovo */
		while(JeLiSlovo(*pom)) pom--;
		pom++; /* da bude na 1. slovu 1. prezimena */
			
		while(JeLiSlovo(*pom))	*pok1++ = *pom++;
		*pok1='\0';
		
		
		pom = s2-1;
		while(JeLiSlovo(*pom)) pom--;
		pom++;
		
		while(JeLiSlovo(*pom))	*pok3++ = *pom++;
		*pok3='\0';
		
		
		/* NIZ1 I NIZ3 ĆE SIGURNO BITI POPUNJENI PREZIMENOM */
		if(strcmp(niz1, niz3) == 0) return 0; /* ako su prezimena ista */
		
		if(d_ima_dva_p && k_ima_dva_p){
			if(strcmp(niz1, niz4)==0 || strcmp(niz2, niz3)==0  || strcmp(niz2, niz4) == 0) return 0;
		}
		else if(d_ima_dva_p){
			if(strcmp(niz2, niz3)==0) return 0;
		}
		else if(k_ima_dva_p){
			if(strcmp(niz1, niz4)==0) return 0;
		}
		
	}
	
	return 99; 
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int x){
	int i, j; 											/* x je broj_dana */
	
	for(i=0; i<vel; i++){
		struct Datum dat1=kandidati[i].datum_rodjenja, dat2=direktor.datum_rodjenja;
		
		int br1=BrojDanaOdReferentnogDatuma(dat1), br2=BrojDanaOdReferentnogDatuma(dat2);
		if(br1+x >= br2) continue; /* nema izbacivanja */
		else if(UporediPrezime(kandidati[i], direktor) == 0) continue;

		for(j=i+1; j<vel; j++){
			kandidati[j-1]=kandidati[j];
		}
		vel--;  /* ako smo već izbacili 1 član iz niza, treba smanjiti vel */
		i--; /* radi ponovne provjere i-tog člana niza */
	}
	
	return vel;
}

int main(){
	struct Uposlenik direktor = {"Sef Mujo Buza-Kruji", {1, 1, 1992} };
	struct Uposlenik kandidati[7] = {
		{"Mu Suljo Kruji-Suljic", {15, 1, 1992} },
		{"Meho Kruji-Buza", {31, 1, 1990 } },
		{"Pero Peric", {1, 2, 1990 } },
		{"Sara Buza", {2, 10, 1990} },
		{"Fata Mujicic", {1, 2, 1986} },
		{"Jozo Jozic", {1, 10, 1990} },
		{"Mijo Mijic", {4, 3, 1989} },
	};
	
	int novi_br=suzi_listu(kandidati, 7, direktor, 15);
	printf("Novi broj: %d\n", novi_br);
	printf("\n%s ", kandidati[1].ime_prezime);
	
	return 0;
}