#include <stdio.h>

int provjera (char* text, char* zamjena)
{
	int je_li_isto=1;
	char* reset=text;
	char* prvoslovo=zamjena;
	while (*zamjena!='\0' && *text!='\0') {
		if(*text!=*zamjena)
			je_li_isto=0;
		zamjena++;
		text++;
	}
	if(*zamjena!='\0' || (*text!='\0' && *text!=' ')) je_li_isto=0;
	zamjena=prvoslovo;
	text=reset;
	return je_li_isto;
}

void promjena(char* text, char* zamjena, char* nova)
{
	int ostatak=0, cont=1,i;
	char* rst=text;
	char* reset_rij=zamjena;
	char* reset=nova;
	char* kraj=text;
	while(*text!='\0') {
		cont=0;
		while(*text!='\0' && *text!=*zamjena) text++;
		if(provjera(text, zamjena) && (text==rst || *(text-1)==' ') && *text!='\0') {
			while(*nova!='\0') {
				if(*text=='\0' || *text==' ') {
					kraj=text;
					while(*text!='\0') text++;
					text++;
					while(text>kraj) {
						*text=*(text-1);
						text=text-1;
					}
				}
				*text=*nova;
				nova++;
				text++;
			}
			cont=1;
		}
		if(cont==1 && *text!='\0' && *text!=' ') {
			kraj=text;
			while(*text!='\0' && *text!=' ') {
				text++;
				ostatak++;
			}
			text=kraj;
			for(i=0; i<ostatak; i++) {
				text=kraj;
				while(*text!='\0') {
					*text=*(text+1);
					text++;
				}
			}
			text=kraj;
		}
		if(*text!='\0' && *text!=' ') text++;
		nova=reset;
		zamjena=reset_rij;
	}
	nova=reset;
	zamjena=reset_rij;
	text=rst;
}

char* zamjena_rijeci(char*tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	char *reset=tekst;
	int i,br;
	br=broj_rijeci;
	for(i=0; i<br; i++) {
		tekst=reset;
		while(*tekst!='\0') {
			while(*tekst!='\0' && *tekst==' ')
				tekst++;
			if(provjera(tekst,rijeci[i])) {
				promjena(tekst, rijeci[i], zamjene[i]);
			}
			while(*tekst!='\0' && *tekst!=' ') tekst++;
		}
	}
	return reset;
}

int main()
{
	char* promjene[2]= {"",""};
	char* rij[2]= {"",""};
	char t[100]="";
	printf("%s", zamjena_rijeci(t, rij, promjene, 2));
	return 0;
}