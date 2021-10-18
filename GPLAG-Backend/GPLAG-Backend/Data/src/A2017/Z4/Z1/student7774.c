#include <stdio.h>

/*Pomocna f-ja za pretvaranje broja u string*/
int pretvori(char *p, int broj){
	int pom, duzina=0,i;
	char *s=p;
	/*predznak*/
	if(broj<0){
		*s='-';
		broj=-broj;
		duzina++;
	}
	pom=broj;
	while(pom!=0){
		duzina++;
		pom/=10;
	}
	for(i=0; i<duzina; i++)
	s++;
	*s='\0';
	s--;
	pom=broj;
	while(pom!=0){
		*s=pom%10+'0';
		pom/=10;
		s--;
	}
	s=p;
	return duzina;
}

char *ubaci_broj(char *niz, int n){
	char sbroj[100];
	char *kraj, *s=niz, *p, *prov;
	int duzina=0;
	duzina=pretvori(sbroj,n);
	if(*s==' '){
		while(*s==' ') s++;
	}
	while(*s!='\0'){
		prov=s;
		while(*prov==' ') prov++;
		if(*prov=='\0') break;
		p=sbroj;
		if(*s==' '){
			if(*(s+1)==' '){
				kraj=s;
				while(*kraj!='\0') kraj++;
				while(kraj!=s){
					*(kraj+duzina)=*kraj;
					kraj--;
				}
				s++;
				while(*p!='\0') *s++=*p++;
				while(*s==' ') s++;
			}
			else{
				kraj=s;
				while(*kraj!='\0') kraj++;
				while(kraj!=s){
					*(kraj+duzina+1)=*kraj;
					kraj--;
				}
				s++;
				while(*p!='\0') *s++=*p++;
				*s=' ';
			}
		}
		s++;
	}
	return niz;
}
int main() {
	char niz1[]="Merima Fehric ETF";
	int broj=123;
	char *novi=ubaci_broj(niz1,broj);
	printf("%s",novi);
	return 0;
}
