#include <stdio.h>
void najduzi_bp(char* s1,char *s2) {
	int hist[200] = {0},i;
	char* pocetakMax = s1;  // pocetak najduzeg podniza
	char* pocetakRijeci = s1;
	int duzina_podniza = 0;
	int maxDuzina = 0;
	
	/* Prolazim kroz svaku rijec i trazim duzinu najduzeg podstringa */
	
	while(*s1!='\0') {
		if((*s1>='A' && *s1<='Z')||(*s1>='a' && *s1<='z')) {
			pocetakRijeci = s1;
			while((*pocetakRijeci>='A' && *pocetakRijeci<='Z')||(*pocetakRijeci>='a' && *pocetakRijeci<='z')) {
				if(*pocetakRijeci>='A' && *pocetakRijeci<='Z')
					hist[*pocetakRijeci+32]++;
				else 
					hist[*pocetakRijeci]++;
				
				if(hist[*pocetakRijeci]==1 || hist[*pocetakRijeci+32]==1) { // Kratkospojna evaluacija osigurava i mala i velika slova
					duzina_podniza++;
					pocetakRijeci++;
				}
				else 
					break;
			}
			if(duzina_podniza>maxDuzina) {
				maxDuzina=duzina_podniza;
				pocetakMax = s1;
			}
			duzina_podniza=0;
			s1++;
			i=0;
			while(i<130) {
				hist[i]=0;
				i++;
			}
		}
		else {
			i=0;
			while(i<130) {
				hist[i]=0;
				i++;
			}
			s1++;
		}
	}
	/* Kopiram najduzi podstring u s2 */
	i=0;
	while(i<maxDuzina) {
		*s2 = *pocetakMax;
		s2++;
		pocetakMax++;
		i++;
	}
	*s2='\0';
}
int main() {
	 char niz[10];
     najduzi_bp("abcde 7motikam cdefg", niz);
     printf ("Niz: '%s'", niz);
     printf("\n");
     char niz2[10];
     najduzi_bp ("Ovo je neki primjer teksta", niz2);
     printf ("Niz: '%s'", niz2);
	return 0;
}
