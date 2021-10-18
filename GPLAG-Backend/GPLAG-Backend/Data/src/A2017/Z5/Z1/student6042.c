#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ref_god 1800
#define ref_mj 1
#define ref_dan 1

struct Datum{
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};
	
	int DajRazliku(struct Datum a, struct Datum b){
		int proteklo_a=0, proteklo_b=0, a_prestupna=0, razlika=0;
		if(a.godina%4==0 && a.godina%100!=0 || a.godina%400==0) a_prestupna=1;
		if(!a_prestupna){
			if(a.mjesec==4 || a.mjesec==6 || a.mjesec==9 || a.mjesec==11){
				proteklo_a=(a.dan-ref_dan)+(a.mjesec-ref_mj)*30+(a.godina-ref_god)*365;
			}else if(a.mjesec==2){
				proteklo_a=(a.dan-ref_dan)+(a.mjesec-ref_mj)*28+(a.godina-ref_god)*365;
			}else{
				proteklo_a=(a.dan-ref_dan)+(a.mjesec-ref_mj)*31+(a.godina-ref_god)*365;
			}
			
			if(b.mjesec==4 || b.mjesec==6 || b.mjesec==9 || b.mjesec==11){
				proteklo_b=(b.dan-ref_dan)+(b.mjesec-ref_mj)*30+(b.godina-ref_god)*365;
			}else if(b.mjesec==2){
				proteklo_b=(b.dan-ref_dan)+(b.mjesec-ref_mj)*28+(b.godina-ref_god)*365;
			}else{
				proteklo_b=(b.dan-ref_dan)+(b.mjesec-ref_mj)*31+(b.godina-ref_god)*365;
			}
			razlika=proteklo_a-proteklo_b;
			if(a.godina>b.godina) razlika=abs(razlika);
			return razlika;
		}else{
			if(a.mjesec==4 || a.mjesec==6 || a.mjesec==9 || a.mjesec==11){
				proteklo_a=(a.dan-ref_dan)+(a.mjesec-ref_mj)*30+(a.godina-ref_god)*366;
			}else if(a.mjesec==2){
				proteklo_a=(a.dan-ref_dan)+(a.mjesec-ref_mj)*29+(a.godina-ref_god)*366;
			}else{
				proteklo_a=(a.dan-ref_dan)+(a.mjesec-ref_mj)*31+(a.godina-ref_god)*366;
			}
			
			if(b.mjesec==4 || b.mjesec==6 || b.mjesec==9 || b.mjesec==11){
				proteklo_b=(b.dan-ref_dan)+(b.mjesec-ref_mj)*30+(b.godina-ref_god)*366;
			}else if(b.mjesec==2){
				proteklo_b=(b.dan-ref_dan)+(b.mjesec-ref_mj)*29+(b.godina-ref_god)*366;
			}else{
				proteklo_b=(b.dan-ref_dan)+(b.mjesec-ref_mj)*31+(b.godina-ref_god)*366;
			}
			razlika=proteklo_a-proteklo_b;
			if(a.godina>b.godina) razlika=abs(razlika);
			return razlika;
		}
	} //Netacna funkcija
	
	int isto_prezime(char *a, char *b){
		int i=0;
		char prezime_a[50], prezime_b[50];
		while(*a!='\0') a++;
		while(*b!='\0') b++;
		a--;
		b--;
		while((*a>='A' && *a<='Z') || (*a>='a' && *a<='z') || *a=='-') a--;
		while((*b>='A' && *b<='Z') || (*b>='a' && *b<='z') || *b=='-') b--;
		a++;
		b++;
		while(prezime_a[i++]=*a++);
		prezime_a[i]='\0';
		i=0;
		while(prezime_b[i++]=*b++);
		prezime_b[i]='\0';
		if(strcmp(prezime_a, prezime_b)==0) return 1;
		else return 0;
	}
	
	int suzi_listu(struct Uposlenik *kandidati, int vel, struct Uposlenik direktor, int broj_dana){
		int i, razlika, j, k, p=0;
		struct Uposlenik tmp;
		
		for(i=0; i<vel; i++){
			if(isto_prezime(direktor.ime_prezime, kandidati[i].ime_prezime)) p=1;
			razlika=DajRazliku(direktor.datum_rodjenja, kandidati[i].datum_rodjenja);
			if(razlika>broj_dana){
				if(p==0){
					if(vel==1){
						vel=0;
						break;
					}
				for(j=i; j<vel-1; j++){
					for(k=j+1; k<vel; k++){
						tmp=kandidati[j];
						kandidati[j]=kandidati[k];
						kandidati[k]=tmp;
						j++;
					}
				}
				i--;
				vel--;
				p=0;
			}
			}
		}
		return vel;
	}


int main() {
	/* AT1: Neki clanovi ce biti izbaceni */
struct Uposlenik direktor = {"Mujo Mujic", {1, 3, 1980} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1980 } },
    { "Pero Peric", { 1, 2, 1980 } },
    { "Sara Sarac", { 2, 2, 1980 } },
    { "Fata Mujic", { 1, 2, 1976 } },
    { "Jozo Jozic", { 1, 10, 1980 } },
    { "Mijo Mijic", { 4, 3, 1979 } },
    { "Suljo Suljic", { 15, 1, 1982 } },
};

/* 1980 godina je bila prestupna, februar je imao 29 dana,
   sto znaci da je Pero Peric za 29 dana stariji od direktora,
   pa kako je 29>28 Pero treba biti izbacen a Sara ne. */

int novi_br = suzi_listu(kandidati, 7, direktor, 28);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}
