#include <stdio.h>
int broj_cifara(int n) {
	int broj=0;
	if(n<0) n=-n;
	for(;;) {
		broj++;
		n/=10;
		if(n==0) break;
	}
	return broj;
}
char *ubaci_broj (char *tekst, int broj) {
	char * poc = tekst,* kraj, *p,*pom;
	char niz_broj[20];
	int i=broj_cifara(broj), duzina_broja, broj_razmaka=0;
	niz_broj[0]=' '; i++;
	if(broj<0) {
		niz_broj[1]='-'; i+=1;
		broj=-broj;
	}
	niz_broj[i]=' ';
	niz_broj[i+1]='\0';
	duzina_broja=i;
	for(;;i--) {
		niz_broj[i-1]=broj%10+'0';
		broj/=10;
		if(broj==0) { break; 
	}
}
i=duzina_broja;
while(*tekst==' ') tekst++;
while(*tekst!='\0') {
	if(*tekst==' ') {
		pom=tekst;
		duzina_broja=i;
		pom++;
		broj_razmaka=0;
		while(*pom==' ') {
			broj_razmaka++;
			pom++;
		}
		if(*pom=='\0') break;
		if(broj_razmaka>0) {
			duzina_broja-=1;
		}
		kraj=tekst;
		while(*kraj != '\0') kraj++;
		while(kraj>tekst) {
			*(kraj+duzina_broja)=*kraj;
			kraj--;
		}
		p=niz_broj;
		while(*p!='\0') {
			*tekst=*p;
			tekst++;
			p++;
		}
		while(*tekst==' ')tekst++;
	}
	tekst++;
}
return poc;
}
int main() {
	return 0;
}
