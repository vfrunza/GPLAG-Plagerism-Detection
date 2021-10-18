#include <stdio.h>
#include <stdlib.h>

/*duzina stringa*/
int duzina_stringa (char *s) {
	
	int duzina=0;
	while (*s != '\0'){
		
		duzina++;
		s++;
	}
	
	return duzina;
}

/*funkcija koja pronalazi određenu riječ u stringu i vraća pokazivač na početak te riječi*/
char* trazi_rijec (char* s, char* rijec){
	
	while (*s != '\0'){
		while (*s == ' ') {
			s++;
		}
		char* p=s;
		char* a=s;
		char* q=rijec;
		
		while (*p++ == *q++) {
			if (*q == '\0' && (*p == ' ' || *p == '\0')) {
				return a;
			}
		}
		while (*s != '\0' && *s != ' '){
			s++;
		}
	}
	
	return NULL;
}

/*funkcija koja vraća broj riječi*/
int broj_rijeci1 (char* s)
{

	int neslovo=1, broj_rijeci1=0;

	while(*s != '\0') {

		if (!((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
			neslovo=1;
		} 
		else if (neslovo == 1) {

			neslovo=0;
			broj_rijeci1++;
		}
		s++;
	}

	return broj_rijeci1;
}

/*funkcija zamjena_rijeci*/
char* zamjena_rijeci (char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	
	int duzina;
	int i,j;
	
	if (duzina_stringa(tekst)==0 || broj_rijeci==0){
		return tekst;
	}
	
	
	for (j=0; j<broj_rijeci1(tekst); j++){
		for (i=0; i<broj_rijeci; i++){
			
			char* a;
			char* pok;
			a=trazi_rijec(tekst, rijeci[i]);
			
			if (a==NULL){
				continue;
			}
			
			duzina=duzina_stringa(zamjene[i])-duzina_stringa(rijeci[i]);
			
			/*slučaj kada je riječ koja se mijenja kraća od riječi sa kojom se mijenja*/
			if (duzina>=0) {
				
				char* kraj = a;
				while (*kraj != '\0') {
					kraj++;
				}
				
				/*ubacuje slobodna mjesta*/
				while (kraj>a) {
					*(kraj+duzina) = *kraj;
					kraj--;
				}
				/*prepisuje zamjenu preko riječi*/
				pok=zamjene[i];
				while (*pok != '\0') {
					*a=*pok;
					pok++;
					if (*pok != '\0') {
						a++;
					}
				}
			}
			
			/*slučaj kada je riječ koja se mijenja duža od riječi sa kojom se mijenja*/
			if(duzina<0){
				
				duzina=abs(duzina);
				
				/*izbacuje višak karaktera u riječi koja se mijenja*/
				char* pocetak=a;
				char* kraj=a+duzina;
				while (*pocetak++=*kraj++);
				
				/*prepisuje zamjenu preko riječi*/
				char* pocetak1=a;
				char* zamjena=zamjene[i];
				while (*zamjena != '\0'){
					*pocetak1=*zamjena;
					pocetak1++;
					zamjena++;
				}
			}
			
			a++;
		}
	}
	return tekst;
}
	
int main (){

char* rijeci[2] = { "auto", "stop" };
char* zamjene[2] = { "vozilo", "start" };
char tekst[100] = "auto-stop auto. stop auto kj stop";
printf ("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));

	return 0;
}
