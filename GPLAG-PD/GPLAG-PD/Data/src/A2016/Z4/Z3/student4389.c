#include <stdio.h>

int compare (char *s1, char *s2){
	char *p1=s1, *p2=s2;
	if(*p1==*p2) return 1;
	while(*p1){
		if(*p1!=*p2) return 0;
		p1++;
		p2++;
	}
	if(*p2!=0) return 0;
	return 1;
}

int duzina(char *s){
	int duz=0;
	while(*s){
		duz++;
		s++;
	}
	return duz;
}

void zamijeni(char *s, char *p){
	char *kraj=s;
	int duzina_p=duzina(p);
	while(*s){
		while(*kraj) kraj++;
		while(kraj>s){
			*(kraj+duzina_p)=*kraj;
			kraj--;
		}
		while(*s++=*p++);
		s--;
	}
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char *pocetak=tekst, pok_rijec_tekst[100];
	int i, j, razmak=1, broj_rijeci_tekst=0;
	while(*tekst){
		if(*tekst==' ') razmak=1;
		else if(razmak==1){
			razmak=0;
			while((*tekst>='A' && *tekst<='Z') || (*tekst>='a' && *tekst<='z')){
				pok_rijec_tekst[broj_rijeci_tekst]=*tekst;
				tekst++;
			}
			broj_rijeci_tekst++;
		}
		tekst++;
	}
	for(i=0; i<broj_rijeci_tekst; i++){
		for(j=0; j<broj_rijeci; j++){
			if(compare(pok_rijec_tekst, rijeci[j])){
				
				zamijeni(pok_rijec_tekst, zamjene[j]);
			}
		}
	}
	return pocetak;
}

int main() {
	char* rijeci[2] = { "beli", "sneg" };
	char* zamjene[2] = { "bijeli", "snijeg" };
	char tekst[100] = "beli sneg je pokrio beli breg";
	printf("\n%s\n", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	/* Da li je promijenjen i polazni string? */
	printf("%s", tekst);
	return 0;
}
