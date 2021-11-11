#include <stdio.h>

char* uzmi_rijec(char* s, char* rijec){
	char *p=s;
	*rijec='\0';
	while(*p !=' ' && *p!='\0'){
		*rijec=*p;
		rijec++;
		p++;
	}
	if(rijec !='\0') *rijec='\0';
	return p;
}

int uporedi_rijeci(const char* prva, const char* druga){
	int iste=1;
	while(*prva !='\0'){
		if(*druga=='\0'){
			iste=0;
			break;
		}
		/*case sensitive*/
		if(*prva != *druga){
			iste=0;
			break;
		}
		prva++;
		druga++;
	}
	if(*druga != '\0') iste=0;
	return iste;
}

void kopiraj(const char* prvi_string, char* drugi_string){
	while (*prvi_string !='\0'){
		*drugi_string=*prvi_string;
		drugi_string++;
		prvi_string++;
	}
	*drugi_string='\0';
}

char* zamjena_rijeci(char* tekst, char**rijeci, char** zamjene, int broj_rijeci){
	char rijec[50]="", pomocni_string[500]="";
	char *pocetak, *temp;
	char *p=tekst, *pok_na_pomocni_string=pomocni_string;
	int i, zamijenjeno;
	while(*p !='\0'){
		pocetak=p;
		p=uzmi_rijec(p,rijec);
		zamijenjeno=0;
		
		for (i=0; i<broj_rijeci; i++){
			if(uporedi_rijeci(rijec, rijeci[i])){
				temp=zamjene[i];
				while(*temp !='\0'){
					*pok_na_pomocni_string=*temp;
					pok_na_pomocni_string++;
					temp++;
				}
				if (*p!='\0'){
					*pok_na_pomocni_string=' ';
					pok_na_pomocni_string++;
				}
				zamijenjeno=1;
			}
		}
		if(!zamijenjeno){
			p++;
			while (pocetak !=p) {
				*pok_na_pomocni_string=*pocetak;
				pocetak++;
				pok_na_pomocni_string++;
			}
			p--;
		}
		p++;
	}
	*pok_na_pomocni_string='\0';
	kopiraj(pomocni_string, tekst);
	return tekst;
}

int main() {

	return 0;
}
