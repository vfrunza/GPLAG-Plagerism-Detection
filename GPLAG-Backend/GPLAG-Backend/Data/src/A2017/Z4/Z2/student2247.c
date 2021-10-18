#include <stdio.h>

void unesi (char niz[], int velicina){
	int i=0;
	char znak=getchar ();
	if (znak=='\n') znak=getchar ();
	while (i<velicina-1 && znak != '\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int jelSlovo(char znak){
	if(znak >= 65 && znak <= 90) return 1;
	else if(znak >= 97 && znak <= 122) return 1;
	else return 0;
}

int brojrijeci (char* s){
	int neslovo=1, brRijeci=0;
	char poc;
	while(*s != '\0'){
		if (!(*s >= 'A' && *s <= 'Z' || *s >= 'a' && *s <= 'z')) neslovo =1;
		else if (neslovo == 1){
			neslovo = 0;
			brRijeci++;
		}
		s++;
	}
	return brRijeci;
}

int duzinaRijeci (char* s){
	int duz=0;
	while (*s != ' '){
		duz++;
		s++;
	}
	return duz;
}


int provjeri_duzine (char* s, int niz[], int velicina){
	int brRijeci = brojrijeci(s);
	int brojac = 0;
	int brojac2 = 0;
	if (brRijeci!=velicina) return 0;
	
	
	while (1){
		while(jelSlovo(*s) == 0) s++;
		if(*s == '\0')break;
		while(jelSlovo(*s) == 1){
			s++;
			brojac++;
		}
		
		if(brojac != niz[brojac2]) return 0;
		
		else{
			    
				brojac=0;
				brojac2++;
				if(*s == '\0') break;
				s++;
		}
		if(*s == '\0')break;
/*while(jelSlovo(*s) == 0){
			if(*s == '\0')break;
			s++;
		}*/

	}
	
	return 1;
}

int main() {
	int s[100], velicina, i;
	
	printf("Unesite tekst: ");
	unesi (s, 100);
	printf ("Unesite niz brojeva: ");
	
	velicina=brojrijeci(*s);
	
	for (i=0; i<velicina; i++){
		scanf ("%d", &s[i]);
	}
	/*provjeri_duzine(s, niz, velicina);
	//printf("%d %d %d",jelSlovo('2'),jelSlovo('?'),jelSlovo('g'));
	//printf("%d",brojrijeci(tekst)); */
	return 0;
}
