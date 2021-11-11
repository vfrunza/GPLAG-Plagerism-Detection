#include <stdio.h>

/* FUNKCIJA koja provjerava da li je slovo */

int da_li_je_slovo(char c){
	if((c>64 && c<91)||(c>96 && c<123)){
		return 1;
	}
	return 0;
}

/* FUNKCIJA koja provjerava da li treba mijenjati */

int da_li_treba_mijenjati(char *tekst, char *rijec){
	char *pocetak=tekst;
	char *pocetak_rijeci=rijec;
	int br=0;
	while(*tekst!='\0' && *rijec!='\0'){
		if(*tekst!=*rijec){
			br=0;
		}
		tekst++;
		rijec++;
	}
	if((*tekst!='\0' && *tekst!=' ')|| *rijec!='\0'){
		br=0;
	}
	tekst=pocetak;
	rijec=pocetak_rijeci;
	return br;
}

/* FUNKCIJA koja minenja */

void zamijeni(char* tekst, char* rijec, char* nova_rijec){
	char *temp=tekst, *rijec_temp=rijec, *nova_temp=nova_rijec, *x=tekst;
	int i, v=0, n=1;
	while(*tekst!='\0'){
		n=0;
		while(*tekst!=*rijec && *tekst!='\0'){
			tekst++;
		}
		if(*tekst!='\0' && (tekst==temp || *(tekst-1)==' ') && da_li_treba_mijenjati(tekst, rijec)){
			while(*nova_rijec!='\0'){
				if(*tekst==' ' || *tekst=='\0'){
					x=tekst;
					while(*tekst!='\0'){
						tekst++;
					}
					tekst++;
					while(tekst>x){
						*tekst=*(tekst-1);
						tekst--;
					}
				}
				*tekst=*nova_rijec;
				tekst++;
				nova_rijec++;
			}
			n=1;
		}
		if(*tekst!=' ' && *tekst!='\0' && n==1){
			x=tekst;
			while(*tekst!='\0' && *tekst!=' '){
				v++;
				tekst++;
			}
			tekst=x;
			for(i=0;i<v;i++){
				tekst=x;
				while(*tekst!='\0'){
					*tekst=*(tekst+1);
					tekst++;
				}
			}
			tekst=x;
		}
		if(*tekst!='\0' && *tekst!=' '){
			tekst++;
		}
		rijec=rijec_temp;
		nova_rijec=nova_temp;
	}
	tekst=temp;
	rijec=rijec_temp;
	nova_rijec=nova_temp;
}

/* FUNKCIJA koja mijenja rijeci */

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char *temp_tekst=tekst;
	int i;
	for(i=0;i<broj_rijeci;i++){
		tekst=temp_tekst;
		while(*tekst!='\0'){
			while(*tekst==' ' && *tekst!='\0'){
				tekst++;
			}
			if(da_li_treba_mijenjati(tekst, rijeci[i])){
				zamijeni(tekst, rijeci[i], zamjene[i]);
			}
			while(*tekst!='\0' && *tekst!=' '){
				tekst++;
			}
		}
	}
	return temp_tekst;
}

/* FUNKCIJA main */

int main() {
	char* rijeci[2]={ "", "" };
	char* zamjene[2]={ "", "" };
	char tekst[100]="";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
