#include <stdio.h>
#include <stdlib.h>

struct Datum {int dan, mjesec, godina;};
struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int prestupna (int god) {
	if (god%4==0 && (god%100!=0 || god%400==0)) return 1;
	return 0;
}

int porodica (char* s1, char* s2) {
	while ((*s1!=' ' && *s1!='-') || (*s2!=' ' && *s2!='-')) {
		if (*s1--!=*s2--) return 0;
	}
	if ((*s1==' ' || *s1=='-') && (*s2!=' ' && *s2!='-')) return 0;
	if ((*s2==' ' || *s2=='-') && (*s1!=' ' && *s1!='-')) return 0;
	return 1;
}



int dani (int god, int mjesec, int dan) {
	int mjeseci[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i, n=0;
	for (i=1; i<god; i++) {
		n+=365+prestupna(i);
	}
	for (i=1; i<mjesec; i++) {
		n+=mjeseci[i];
		if (i==2 && prestupna(god)==1) n++;
	}
	n+=dan;
	return n;
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	int dani_d=0, dani_k=0, i, j, komb1, komb2, komb3, komb4;
	char* prezime_k, *prezime_d, *temp1, *temp2, *t1, *t2, *t11, *t22;
	
	/* Broj dana do rođenja direktora: */
	dani_d=dani(direktor.datum_rodjenja.godina, direktor.datum_rodjenja.mjesec, direktor.datum_rodjenja.dan);
	
	for (i=0; i<vel; i++) {
		
		/* Broj dana do rođenja kandidata: */
		dani_k=dani(kandidati[i].datum_rodjenja.godina, kandidati[i].datum_rodjenja.mjesec, kandidati[i].datum_rodjenja.dan);
		
		if (broj_dana>0 && dani_d-dani_k<=broj_dana) continue;
		if (broj_dana<0 && dani_k-dani_d>=abs(broj_dana)) continue;
		if (broj_dana==0 && dani_d-dani_k!=0) continue;
		
		
		prezime_k=kandidati[i].ime_prezime;
		prezime_d=direktor.ime_prezime;
		
		/* Stavljamo promjenjive na kraj prezimena: */
		
		while (*prezime_k!='\0' && *prezime_k!='-') prezime_k++;
		while (*prezime_d!='\0' && *prezime_d!='-') prezime_d++;
		temp1=prezime_k;
		temp2=prezime_d;
		
		t1=prezime_k;
		t2=prezime_d;
		
		if (*t1=='-') {
			while (*t1!='\0') t1++;
		}
		if (*t2=='-') {
			while (*t2!='\0') t2++;
		}
		t11=t1;
		t22=t2;
		
		/* Poredimo sve kombinacije prezimena: */
		prezime_d--; prezime_k--; temp1--; temp2--; t1--; t2--; t11--; t22--;
		
		komb1=porodica(prezime_d, prezime_k);
		komb2=porodica(temp1, t2);
		komb3=porodica(t1, temp2);
		komb4=porodica(t11, t22);
		
		if (komb1==1 || komb2==1 || komb3==1 || komb4==1) continue;
		
		for (j=i; j<vel-1; j++) {
			kandidati[j]=kandidati[j+1];
		}
		vel--;
		i--;
	}
	return vel;
}

int main() {
	printf("Zadaća 5, Zadatak 1");
	return 0;
}
