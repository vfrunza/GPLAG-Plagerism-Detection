#include <stdio.h>
int duzina(char*);
void funkcija1(char *s, const char *p) 
{
	while(*p!='\0') {
		*s=*p;
		s++;
		p++;
	}
	*s='\0';
}

char *funkcija2(char *s, char *p)
{
	int i, j;
	int pronadjen=0;
	if(s==NULL || p==NULL) return 0;
	for(i=0; s[i]!='\0'; i++) {
		if(s[i]==p[0] && (i==0 || s[i-1]==' ') && (s[i+duzina(p)]==' ' || s[i+duzina(p)]=='\0')) {
			for(j=i;;j++) {
				if(p[j-i]=='\0') {
					pronadjen=1;
					break;
				}
				if(s[j]==p[j-i]) continue;
				else break;
			}
		}
		else if(i==duzina(s)-1 || s[i+1]=='\0' || s[i+1]==' ') {
			for(j=i;;j++) {
				if(p[j-i]=='\0') {
					pronadjen=1;
					break;
				}
				if(s[j]==p[j-i]) continue;
				else break;
		}
		}
		if(pronadjen) break;
		}
	if(pronadjen) return(s+i);
	else return 0;
}

int duzina(char *str)
{
	char *p;
	p=str;
	while(*str!='\0') str++;
	return str-p;
}



char *funkcija4(char *s, const char *p)
{
	funkcija1(s+duzina(s),p);
	return s;
}

char *funkcija5(char *s, const char *p, int n)
{
	int i;
	char *t=s;
	for(i=0; i<n; i++) {
		*s=*p;
		s++;
		p++;
	}
	return t;
}

void funkcija6(char *s, char *orig, char *zamjena)
{
	char niz[10000];
	char *p=s;
	while(p=funkcija2(p, orig)) {
		funkcija5(niz,s,p-s);
		niz[p-s]='\0';
		funkcija4(niz, zamjena);
		funkcija4(niz, p+duzina(orig));
		funkcija1(s, niz);
		p++;
	}
}

char *zamjena_rijeci(char* tekst, char **rijeci, char** zamjene, int broj_rijeci)
{
	char *p=tekst;
	int i;
	for(i=0; i<broj_rijeci; i++) {
		funkcija6(tekst, rijeci[i], zamjene[i]);
	}
	return p;
}

int main() {

	return 0;
}
