#include <stdio.h>

int provjeri_duzine(char* string, const int brojevi[], int duzina_niza) {
	int brojac_slova=0,i=0;
	if(duzina_niza<=1) return 0;
	while((*string<'a' || *string>'z') && (*string<'A' || *string>'Z')) string++;
	while(*string!='\0') {
		while((*string>='a' && *string<='z') || (*string>='A' && *string<='Z')) {
			brojac_slova++;
			if(*(string+1)=='\0') break;
			string++;
		}
		if(brojac_slova!=brojevi[i]) return 0;
		else i++;
		if(i>duzina_niza) return 0;
		if(*(string+1)=='\0') break;
		brojac_slova=0;
		while((*string<'a' || *string>'z') && (*string<'A' || *string>'Z')) {
			if(*(string+1)=='\0') break;
			string++;
		}
		if(*(string+1)=='\0') break;
	}
	if(i<duzina_niza) return 0;
	return 1;
}

int main() {
	return 0;
}