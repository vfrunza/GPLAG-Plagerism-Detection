#include <stdio.h>

char *zamjena_rijeci(char *tekst, char* rijeci[], char* zamjene[], int broj_rijeci) {
	char *pocetna=tekst, *pocetna_adresa_rijeci=0,*pocetna_adresa_zamjene=0,*kraj=0,*pocetna_trenutne=0;
	int razmak=1,i,isti=0,slova_rijeci=0,slova_zamjene=0,razlika=0;
	while(*tekst){
		while(*tekst) {
			if(*tekst==' ')
				razmak=1;
			else if(razmak) {
				razmak=0;
				break;
			}
			tekst++;
		}
		if(!(*tekst))
			break;
		pocetna_trenutne=tekst;
		for(i=0; i<broj_rijeci; i++){
			razlika=0; slova_rijeci=0; slova_zamjene=0; isti=0;	
			while(*rijeci[i]==' ')
				rijeci[i]++;
			while(*zamjene[i]==' ')
				zamjene[i]++;
			pocetna_adresa_rijeci=rijeci[i]; 
			pocetna_adresa_zamjene=zamjene[i];
			while(1) {
				if((*tekst==' ' || *tekst==0 ) && (*rijeci[i]==0||*rijeci[i]==' ')){
					isti=1;
					break;
				}
				if (*tekst!=*rijeci[i])
					break;
				tekst++;
				rijeci[i]++;
				slova_rijeci++;
			}
			if (isti) {
				while (*zamjene[i]) {
					if(*zamjene[i]==' ')
						break;
					slova_zamjene++;
					zamjene[i]++;
				}
				zamjene[i]=pocetna_adresa_zamjene;
				razlika=slova_zamjene-slova_rijeci;
				kraj=tekst;
				tekst=pocetna_trenutne;
				if(razlika>0){
					while(*kraj)
						kraj++;
					while(kraj>=tekst){
						*(kraj+razlika)=*kraj;
						kraj--;
					}
				}
				else if (razlika<0){
					while(*kraj!=0){
						*(kraj+razlika)=*kraj;
						kraj++;
					}
					*(kraj+razlika)=0;
				}
				while(*zamjene[i] && *zamjene[i]!=' ')
					*pocetna_trenutne++=*zamjene[i]++;
				rijeci[i]=pocetna_adresa_rijeci;
				zamjene[i]=pocetna_adresa_zamjene;
				break;
			}
			rijeci[i]=pocetna_adresa_rijeci;
			tekst=pocetna_trenutne;
		}
	}
	return pocetna;
}

int main() {

char* rijeci[2] = {"abc"};
char* zamjene[2] = {"sss"};
char tekst[100] = "abc";
printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 0));
return 0;

}
