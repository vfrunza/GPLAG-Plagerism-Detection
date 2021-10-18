#include <stdio.h>
void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

char* ubaci_broj (char* tekst, int broj){
    char*pom=tekst;
    if ((*tekst >= 'A' && *tekst <= 'Z' ||
*tekst >= 'a' && *tekst <= 'z')){
	tekst++;
	if(*tekst=' '){
while (*tekst != '\0') {

char* kraj = tekst;
while (*kraj != '\0') kraj++;
while (kraj > tekst) {
*(kraj+duzina) = *kraj;
kraj--;
}
char* p = tekst;
while (*p != '\0') *s++ = *tekst++;}
		}else {tekst--;}
	

tekst++;
}return pom;
} 


int main() {
    
    /* AT1: Primjer iz zadatka */
char s[44] = "Ovo je neki primjer teksta";
printf("\"%s\"", ubaci_broj(s, 123));
	return 0;
}
