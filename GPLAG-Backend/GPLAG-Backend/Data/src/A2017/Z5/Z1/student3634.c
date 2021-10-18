#include <stdio.h>
#include <ctype.h>
#include <math.h>
	int alpha(int s){
		if((s >= 'a' && s <='z') || (s >= 'A' && s <= 'Z')) return 1;
		return 0;
	}
	struct Datum { 
		int dan, mjesec, godina; 
	};
	
	struct Uposlenik {
		char ime_prezime[50];
		struct Datum datum_rodjenja;
	};

	int istoPrezime(char* s1,char* s2){
		char* poc = s2;
		char* poce = s1;
		int test = 1, i = 0;
		while(alpha(*s2))s2++;
		if(*s2 == '-') test++;
		s2 = poc;
		for(i = 0; i < test; i++)
		{
			if(i == 1){
				while(alpha(*s2))s2++;
				s2++;
			}
			while(*s1 == *s2){
				s1++;
				s2++;
				if(*s1 == '\0' || *s2 == '\0') break;
			}
			if((*s2 == '\0' || *s2 == '-') && (*s1 == '\0' || *s1 == '-')) return 1;
			s2 = poc;
			while(alpha(*s1))s1++;
			s1++;
			while(*s1 == *s2){
				s1++;
				s2++;
				if(*s1 == '\0' || *s2 == '\0') break;
			}
			if((*s2 == '\0' || *s2 == '-') && (*s1 == '\0' || *s1 == '-')) return 1;
			s1 = poce;
		}
		return 0;
	}
	
	int da_li_je_isto_prezime(char* kandidat, char* direktor){

		
		while(*direktor != '\0'){
			
			direktor++;
		}
		while(*direktor != ' ') direktor--;
		while(*kandidat != '\0'){
			kandidat++;
		}
		while(*kandidat != ' ') kandidat--;
		kandidat++;
		direktor++;
		if(istoPrezime(direktor, kandidat)) return 1;
		return 0;
	}

	
	int izbaci_iz_niza(struct Uposlenik *kandidati, int n, int vel){
		int j;
				for(j = n + 1; j < vel; j++){
					kandidati[n] = kandidati[j];
					n++;
				}
				vel--;
		return vel;
	}
				
	
	int prestupna(int godina) {
	if ((godina%4 == 0 && godina%100 != 0) || godina%400 == 0)
	return 1;
	return 0;
	}
	
	int br_dn(struct Datum d1,struct Datum d2, int br){
		int dani_u_mjesecu[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		unsigned int ukupno1=0, ukupno2=0;
		int i, ukupno;
		for (i=1700; i<d1.godina; i++) ukupno1 += 365 + prestupna(i);
		if(prestupna(d1.godina)) dani_u_mjesecu[2]++;
		for (i=1; i<d1.mjesec; i++) ukupno1 += dani_u_mjesecu[i];
		
		ukupno1 += d1.dan;
		
		
		dani_u_mjesecu[2]=28;
		for (i=1700; i<d2.godina; i++) ukupno2 += 365 + prestupna(i);
		if(prestupna(d2.godina)) dani_u_mjesecu[2]++;
		for (i=1; i<d2.mjesec; i++)	ukupno2 += dani_u_mjesecu[i];
		ukupno2 += d2.dan;
		
		ukupno = ukupno2 - ukupno1;
		return ukupno>br;
	}
	
	int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik Direktor, int broj_dana){
		int i;
		for(i = 0; i < vel; i++){
			if(br_dn(kandidati[i].datum_rodjenja, Direktor.datum_rodjenja,broj_dana) && !da_li_je_isto_prezime(kandidati[i].ime_prezime, Direktor.ime_prezime))
			{
				vel = izbaci_iz_niza(kandidati, i, vel);
				i--;
			}
		}
		return vel;
	}

int main() {
	/* AT7: Negativna razlika dana, ne ostaje niko */
struct Uposlenik direktor = {"Mujo Mujic", {1, 1, 1892} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1990 } },
    { "Pero Peric", { 1, 2, 1990 } },
    { "Sara Sarac", { 2, 10, 1990 } },
    { "Fata Mujicic", { 1, 2, 1986 } },
    { "Jozo Jozic", { 1, 10, 1990 } },
    { "Mijo Mijic", { 4, 3, 1989 } },
    { "Suljo Suljc", { 15, 1, 1992 } },
};
int novi_br = suzi_listu(kandidati, 7, direktor, -15);
printf("Novi broj: %d\n", novi_br);
direktor.datum_rodjenja.godina = 1992;
novi_br = suzi_listu(kandidati, 7, direktor, 15);
printf("Novi broj: %d\n", novi_br);
printf("%s", kandidati[0].ime_prezime);
	return 0;
}
