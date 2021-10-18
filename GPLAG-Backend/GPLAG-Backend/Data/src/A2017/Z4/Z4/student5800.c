#include <stdio.h>

int jelSlovoIliBroj(char znak){
	if(znak >= 65 && znak <= 90) || (znak>=97 && znak<= 122) || (znak>= 48 && znak<= 57))
		return 1;
	else return 0;
}

void provjeri(char tekst[]){
	
}

int main() {
	char tekst1[] = "<div id=\"tekst\"><h2>Naslov</h2><p>Ovo je <b>cetvrti</b> i <i>posljednji</i> zadatak iz <a href=\"zadaca4\">zadace 4</a></p></div>";
	char tekst2[] = "<b><a>proba</b></a>";
	
	return 0;
}
