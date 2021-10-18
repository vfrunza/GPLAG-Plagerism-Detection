#include <stdio.h>

char* zamjena_rijeci(char* tekst, char** rijeci, 
char** zamjene, int broj_rijeci){
	char* p;
	char* b;
	char* krajstringa=tekst;
	int i, j, razmak, jednaki, duzinarijeci, duzinazamjene;
	for(i=0;i<broj_rijeci;i++){
		/*Trazenje i-te rijeci pocinje od pocetka stringa*/
		p=tekst;
		razmak=1;
		while(*p!='\0'){
			if(*p==' ') razmak=1;
			/*Razmak koristim kao logicku varijablu kako bih znao da je neki znak 
			pocetak rijeci a ne znak unutar rijeci*/
			if((*p>='!' && *p<='~') && razmak==1){
				/*Provjera da li je pronadjena rijec jedna od rijeci
				koju treba zamijeniti*/
				jednaki=1;
				j=0;
				while(*(p+j)!=' ' && *(p+j)!='\0' && *(rijeci[i]+j)!='\0'){
					if(*(p+j)!=*(rijeci[i]+j)){
						jednaki=0;
						break;
					}
					j++;
				}
				if(*(p+j)!=' ' && *(p+j)!='\0') jednaki=0;
				if(*(rijeci[i]+j)!='\0') jednaki=0;
				/*Sljedeci blok koda vrsi zamjenu i-te rijeci sa i-tom
				zamjenom*/
				if (jednaki){
					/*Brojanje slova u rijeci koju treba zamijeniti kao i u 
					rijeci kojom je treba zamijeniti*/
					duzinarijeci=0;
					duzinazamjene=0;
					j=0;
					while(*(rijeci[i]+j)!='\0'){
						duzinarijeci++;
						j++;
					}
					j=0;
					while(*(zamjene[i]+j)!='\0'){
						duzinazamjene++;
						j++;
					}
					krajstringa=p;
					/*Ako je rijec duza od svoje zamjene primljeni string je 
					potrebno suziti odnosno prepisati preko viska mjesta.
					Ako je rijec kraca od svoje zamjene potrebno je u primljenom 
					stringu napraviti dodatna mjesta.*/
					if(duzinazamjene>duzinarijeci){
						while(duzinazamjene>duzinarijeci){
							while(*krajstringa!='\0') krajstringa++;
							b=krajstringa++;
							while(b>p){
								*(b+1)=*b;
								b--;
							}
							duzinazamjene--;
						}
					}else if(duzinarijeci>duzinazamjene){
						while(duzinarijeci>duzinazamjene){
							j=0;
							while(*(p+j)!='\0'){
								*(p+j)=*(p+j+1);
								j++;
							}
							duzinarijeci--;
						}
					}
					/*Pisanje zamjene u string.*/
					j=0;
					while(*(zamjene[i]+j)!='\0'){
						*(p+j)=*(zamjene[i]+j);
						j++;
					}
				}
			razmak=0;
			}
			p++;
		}
	}
	return tekst;
}

int main() {
	char* rijeci[2] = { "c" };
	char* zamjene[2] = { "Prijestolonasljednikovica" };
	char tekst[100]; /* = "c c"; */
	tekst[0] = 'c';
	tekst[1] = ' ';
	tekst[2] = 'c';
	tekst[3] = '\0';
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 1));
	return 0;
}
