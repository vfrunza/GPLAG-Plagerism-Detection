#include <stdio.h>
#include <ctype.h>
void ZamijeniRijeci(char*recenica, char*rijec){
	while(*rijec!='\0'){
		*recenica++=*rijec++;
	}
	recenica++;
}
void da_li_su_isti(char *pomocni_string, char *temp, char* kraj_trenutne, char* pocetak_trenutne, int brojac, int i, char**zamjene){ // funkcija provjerava da li su isti stringovi
	int logicka_pretpostavka=1;
	char *kraj_izbacene;
	while(*temp!='\0'){
		 if(*temp++!=*pomocni_string++){
		 	logicka_pretpostavka=0;
		 	break;
		 }
		if(*temp=='\0'&& (*pomocni_string!=' ' && *pomocni_string!='\0')){
			logicka_pretpostavka=0; 
			break;
		}
		}
	if(logicka_pretpostavka==1){
		kraj_trenutne=pocetak_trenutne;
		while(*pomocni_string!='\0'&& *pomocni_string!=' ')pomocni_string++;
		while(*pomocni_string!='\0'){
			*kraj_trenutne++=*pomocni_string++;
		}
		*kraj_trenutne='\0';
		pomocni_string=pocetak_trenutne;
		temp=zamjene[i];
		while(*temp!='\0'){
			brojac++;
			temp++;
		}
		kraj_izbacene=kraj_trenutne+brojac; 
		pomocni_string--;
		while(kraj_trenutne!=pomocni_string){
			*kraj_izbacene--=*kraj_trenutne--;
		}
		temp=zamjene[i];
		ZamijeniRijeci(pocetak_trenutne, temp);
	}
	
}


int rijecnik(char **rijeci, char**zamjene, int broj_rijeci){
	int i, logicka_pretpostavka=1;
	char *pomocna, *pomocna1;
	for(i=0; i<broj_rijeci;i++){
		pomocna=rijeci[i];
		pomocna1=zamjene[i];
		while(*pomocna!='\0'|| *pomocna1!='\0'){
			if(*pomocna++!=*pomocna1++)
				logicka_pretpostavka=0;
		}
		if(logicka_pretpostavka==0) break;
	}
	return logicka_pretpostavka;
}
char* zamjena_rijeci(char*tekst, char**rijeci, char**zamjene, int broj_rijeci){ //funkcija zamjenjuje rijeci
	char*pomocni_string=tekst;
	char *temp, *pocetak_trenutne, *kraj_trenutne, *kraj_izbacene;
	int i, brojac;
	if(rijecnik(rijeci, zamjene, broj_rijeci)) return tekst;
	while(*pomocni_string!='\0'){
		if(pomocni_string==tekst || *(pomocni_string-1)==' '){
			while(*pomocni_string==' ') pomocni_string++;
			pocetak_trenutne=pomocni_string;
			for(i=0; i<broj_rijeci; i++){
				brojac=0;
				pomocni_string=pocetak_trenutne; 
				temp=rijeci[i];
				da_li_su_isti(pomocni_string, temp, kraj_trenutne, pocetak_trenutne, brojac, i, zamjene);
				
			}
		}
		pomocni_string++;
	}
	return tekst;
}
int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
