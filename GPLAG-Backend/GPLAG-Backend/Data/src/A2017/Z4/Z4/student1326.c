#include <stdio.h>
#include <string.h>


void zamijeni(char *s){
	char tekst[]="jedan";
	int duzina=strlen(tekst)-1;
	while(*s!='\0'){
		if(*s=='1'){
			char *kraj=s;
			while(*kraj!='\0') kraj++;
			while(kraj>s){
				*(kraj+duzina)=*kraj;
				kraj--;
			}
		char *p=tekst;
		while(*p!='\0') *s++=*p++;
		}
		s++;
	}
}
int main() {
	char string[]="Danas je 1";
	zamijeni(string);
	printf("%s", string);
	return 0;
}
