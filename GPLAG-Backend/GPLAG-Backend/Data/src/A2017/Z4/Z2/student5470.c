#include <stdio.h>

int broj_rijeci(char* s)
{
	int brojac=0, nerijec=1;
	char* temp=s;
	while(*s!='\0') {
		if(!((*s>='A' && *s<='Z')||(*s>='a' || *s<='z'))) {
			nerijec=1;
		} else if(nerijec==1) {
			nerijec=0;
			brojac++;
		}
		s++;
	}
	s=temp;
	return brojac;
}

int provjeri_duzine(char* s, int brojevi[], int velicina)
{
	int duzina=0, rijec=0;
	char* kraj=s;
	while(*s!='\0') {
		if((*s>='A' && *s<='Z')||(*s>='a' && *s<='z')) {
			duzina++;
		} else {
			kraj=s;
			while(kraj!='\0') {
				if((*kraj>='a' && *kraj<='z') || (*kraj>='A' && *kraj<='Z'))  {
					s=kraj;
					break;
				}
				kraj++;
			}
			if(duzina!=brojevi[rijec]) {
				return 0;
			}
			rijec++;
			duzina=1;
		}
		s++;
	}
	if((rijec+1)!=velicina) {
		return 0;
	}
	return 1;
}

int main()
{
	char s[]="Primjer je ovo neki";
	int brijeci=broj_rijeci(s);
	printf("%d", brijeci);
	return 0;
}
