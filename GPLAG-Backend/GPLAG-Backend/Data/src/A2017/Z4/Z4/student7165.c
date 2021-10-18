#include <stdio.h>

int provjeri(char* kod) {
	char* pok1=kod,pok2=kod;
	
	if(*kod!='<') return 0;
	while(*pok1!='\0') {
		
		kod++;
	}
	return 0;
}

int main() {
	char tekst1[] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
	char tekst2[] = "<b><a>proba</b></a>";
	printf("%d ", provjeri(tekst1));
	printf("%d ", provjeri(tekst2));
	return 0;
}
