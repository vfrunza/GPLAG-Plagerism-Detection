#include <stdio.h>
struct Tag {
	char *pocetak;
	char *izakraja;
	int brojpostojecih;
};

int jesu_slovo_ili_broj(char);

int provjera(char *s) {
	
	int broji1=0; 
	int broji2=0;
	char *pocetak=s; 
	while(*pocetak!='\0') {
		if(*pocetak=='<') broji1++;
		else if(*pocetak=='>') broji2++;
		pocetak++;
	}
	if(broji1!=broji2) return 0;
	return 1;
}
int duzina_podstringa(char *pocetak, char *iza_kraja) 
{
	int duzina=0;
	char *poc=pocetak;
	char *kr=iza_kraja;
	while(poc<kr) {
		duzina++;
		poc++;
	}
	return duzina;

}

int jesu_slovo_ili_broj(char znak) 
{
	if(znak<='z' && znak>='a' || znak>='A' && znak<='Z' || znak>='0' && znak<='9') return 1;
	return 0;
}

int jesu_li_isti(char *poc1, char *izak1, char *poc2, char *izak2) //radi, ubaci verziju da ti ne razlikuje velika od malih slova
{
	char *pocetak1=poc1;
	char *pocetak2=poc2;
	char *iza_kraja1=izak1;
	char *iza_kraja2=izak2;
	int duzina1=duzina_podstringa(pocetak1, iza_kraja1);
	int duzina2=duzina_podstringa(pocetak2, iza_kraja2);
	if(duzina1!=duzina2) return 0;
	while(duzina1) {
		if(*pocetak1!=*pocetak2) return 0;
		pocetak2++;
		pocetak1++;
		duzina1--;
	}
	return 1;

}

struct Tag broj_otvorenih(char *pocetak, char *kraj) //hopefully radi i vraca zadnji otvoren tag
{
	struct Tag t1;
	char *t1start=pocetak;
	char *t1end=pocetak;
	char *prvi=pocetak;
	char *drugi=pocetak;
	if(*pocetak) drugi++;
	int brojac=0;
	int noviotvoren=0;
	while(*prvi!='\0') {
		if(*prvi=='<' && jesu_slovo_ili_broj(*drugi)) {
			prvi++;
			drugi++;
			if(*drugi=='>') {brojac++;  continue;}
			while((*drugi!='>' || noviotvoren>0) && *drugi!='\0') {

				if(*prvi=='<' && jesu_slovo_ili_broj(*drugi)) {
					noviotvoren++;
				}
				if(noviotvoren) {
					if(*drugi=='>') {
						noviotvoren--;
						brojac++;
						t1end=drugi;
						t1start=prvi;
					}

				}
				drugi++;
				prvi++;
			}

			if(*drugi=='>')	{brojac++; t1start=prvi; t1end=drugi;}
		}
		prvi++;
		drugi++;
	}
	t1.brojpostojecih=brojac;
	t1.pocetak=t1start;
	t1end++;
	t1.izakraja=t1end;
	return t1;
	
}

int broj_zatvorenih(char *pocetak, char *kraj)
{
	char *prvi=pocetak;
	char *drugi=pocetak;
	char *treci=pocetak;
	int duzina=0;
	int noviotvoren;
	if(*(prvi+1)!='\0' && *(prvi+2)!='\0' && *(prvi+3)!='\0') { //mislim da radi, ako ti je ovdje duzina nula znaci da nesto ili nije uredu sa tagovima ili ih nema zatvorenih u svakom slucaju ako je ovo nula vrati nulu
		drugi++;
		treci=treci+2;
		while(*treci!='\0') {
			
			if(*prvi=='<' && *drugi=='/' && jesu_slovo_ili_broj(*treci)) {
				char *iduci=treci+1;
				
				while(*iduci!='\0') {
					char *iza_iduceg=iduci+1;
					if(*iduci=='>') {duzina++; break;}
					if(jesu_slovo_ili_broj(*iduci)==0) break;
				
					
					iduci++;
					
				}
			}
			treci++;
			prvi++;
			drugi++;
			
		}
		
		}
	
	return duzina; }


int provjeri(char *s) {
	
	char *pocetak=s;
	char *kraj=s;
	if(provjera(s)==0) return 0;
	while(*kraj!='\0') kraj++;
	struct Tag t=broj_otvorenih(pocetak, kraj);
	int otvoreni=t.brojpostojecih;
	int zatvoreni=broj_zatvorenih(pocetak, kraj);
//	printf("%d	zatvoreni 	%d otvoreni", zatvoreni, otvoreni);
	if(zatvoreni!=otvoreni) return 0;
	
	
	return 1;
}
int main()
{
	
	return 0;
}
