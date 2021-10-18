#include <stdio.h>
char* izbaci_najcescu(char *s);
int slovo(char x);
void odrediNajcescu(char *rijec, char *tekst);
int prebroj(char *rijec, char *tekst);
int isti(char x, char y);

/*Prebroj koliko se puta rijec nalazi u tekstu*/
int prebroj(char *rijec, char *tekst)
{
	int razmak=1, broj=0;
	char *tmp;
	while(*tekst!='\0') {
		if(!slovo(*tekst)) {
			razmak=1;
		} else if(razmak) {
			razmak=0;
			tmp=rijec;
			while(isti(*rijec++,*tekst++)) {
				if(*rijec=='\0' || *tekst=='\0')
					break;
			}
			if(*rijec=='\0' && !slovo(*tekst)) {
				broj++;
			}
			if(!slovo(*tekst))
				razmak=1;
			rijec=tmp;
		}
		if(*tekst=='\0')
			break; /*U slucaju da smo zadnju prebrojali*/
		tekst++;
	}
	return broj;
}
/*Poredi da li su dva slova jednaka, uzma u obzir i velika i mala*/
int isti (char x, char y)
{
	if(x==y)
		return 1;
	else if(slovo(x) && slovo(y)) {
		if(x<='Z')
			x+='a'-'A';
		if(y<='Z')
			y+='a'-'A';
		if(x==y)
			return 1;
	}
	return 0;
}
/*Vraca 1 ako je x slovo, u suprotnom vraca 0*/
int slovo(char x)
{
	if((x>='A' && x<='Z') || (x>='a' && x<='z')) {
		return 1;
	} else return 0;
}
/*Prima niz u koji ce smjestiti najcescu rijec u tekstu*/
void odrediNajcescu(char *rijec, char *tekst)
{
	char poredi[1000];
	char *pocetak=tekst;
	char *pocRijeci=rijec;
	int razmak=1,i;
	int brojPon=0, maxPon=0;
	char *tmp;
	while(*tekst!='\0') {
		if(!slovo(*tekst)) {
			razmak=1;
		} else if(razmak) {
			/*Smjestam svaku novu rijec u niz poredi i onda poredim citav
			tekst sa tom rijeci i provjeravam broj ponavljanja*/

			tmp=tekst;
			i=0;
			while(slovo(*tekst)) {
				poredi[i++]=*tekst++;
			}
			poredi[i]='\0';
			tekst=tmp;
			/*Rijec smjestena u poredi, sad je poredimo sa citavim tekstom*/
			brojPon=prebroj(poredi, pocetak);
			if(brojPon>maxPon) {
				maxPon=brojPon;
				rijec=pocRijeci;
				i=0;
				while(poredi[i]!='\0') {
					*rijec=poredi[i++];
					rijec++;
				}
				*rijec='\0';
			}
			razmak=0;
		}
		tekst++;
	}
}

char *izbaci_najcescu(char*s)
{
	char najcesca[1000];
	char *pok=s;
	int razmak=1, brisi, duzina=0, i=0;
	char *tmp;
	najcesca[0]='\0';
	odrediNajcescu(najcesca,s);
	while(1) {
		if(najcesca[i++]=='\0')
			break;
	}
	duzina=i-1;
	while(*s!='\0') {
		if(!slovo(*s)) {
			razmak=1;
		} else if(razmak) {
			razmak=0;
			i=0;
			brisi=0;
			while(isti(*s++,najcesca[i++])) {
				if(*s=='\0' || najcesca[i]=='\0')
					break;
			}
			if(najcesca[i]=='\0' && !slovo(*s)) {
				brisi=1;
				s--;
			}
			if(brisi) {
				s++;
				tmp=s;
				while(*s!='\0') {
					*(s-duzina)=*s;
					s++;
				}
				*(s-duzina)='\0';
				s=tmp-duzina-1;
			}
		}
		s++;
	}
	return pok;

}

int main()
{

	return 0;
}