#include <stdio.h>
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci);
int daLiSuRijeciJednake(char* rijec1, char* rijec2);
void unesi(char niz[], int velicina);
void ukloniRijec(char* string);
void umetniRijec(char* string, char* rijec);
int duzinaStringa(char* string);
void printajString(char* string);
int main() {
	//printf("Zadaća 4, Zadatak 3");
	// char rijec1[100];
	// char rijec2[100];
	// rijec2[0]='\0';
	// char* rijeci[2] = { "beli", "sneg" };
	/* AT14: Slozeniji slucaj u kojem nema zamjene */
	char* rijeci[1] = {"dobro"};
	char* zamjene[1] = {"dobro"};
	char tekst[] = "dobro dobro";
	printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 1));
//	while(1){
//		printf("Rijec 1:");
//		unesi(rijec1, 100);
//		printf("%d",'^ ');
//		printf("Rijec 2:");
//		unesi(rijec2, 100);
//		ukloniRijec(rijec1);
//		printf("\nRijeci su: %d\n", daLiSuRijeciJednake(rijec2, rijec1));
//		printf("\nRijeci su: %s\n", rijec1);
//		umetniRijec(rijec1, rijec2);
//		printf("\nRijeci su: %s\n", rijec1);
//		izbaci_najcescu(rijec1);
//		printf("\n");
//		zamjena_rijeci(rijec1, rijeci, rijeci, 2);
//	}
	return 0;
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char* pocetak= tekst;
	int i;
	for(i=0; i<broj_rijeci; i++){
		if(daLiSuRijeciJednake(rijeci[i], zamjene[i]))			//ako su rijeci koje mijenjamo identicne netreba ih ni provjeravati
			continue;										
		while (*tekst!='\0') {
			if(tekst==pocetak || *(tekst-1)==' '){				//da li je pokazivac na pocetku rijeci
				if(daLiSuRijeciJednake(tekst, rijeci[i])){
					ukloniRijec(tekst);
					umetniRijec(tekst, zamjene[i]);
				}
			}
			tekst++;
		}
		tekst= pocetak;
	}
	return pocetak;
}
int daLiSuRijeciJednake(char* rijec1, char* rijec2){
	while(*rijec1!='\0' && *rijec1!=' '){						//dok jos uvijek ima rijec1 vrti petlju
		if(*rijec1== ' ' && *rijec2!= ' ' && *rijec2!= '\0')	//ako je rijec1 zavrsila, a rijec2 nije rijeci nisu iste
			return 0;
		if(*rijec1!= *rijec2)	
			return 0;
		rijec1++;
		rijec2++;
	}
	if((*rijec1=='\0' || *rijec1==' ') && *rijec2!= ' ' && *rijec2!= '\0')	//ako je rijec1 zavrsila, a rijec2 nije rijeci nisu iste
		return 0;
	
	//rijeci su identicne
	return 1;
}
void unesi(char niz[], int velicina){
    char znak = getchar();
    int i = 0;
    if (znak == '\n') znak=getchar();
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
void ukloniRijec(char* string){
	int brojac= 0;
	char* pocetak= string;
	//brojimo koliko ima karaktera u rijeci
	while(*string!='\0' && *string!=' '){
		brojac++;
		string++;
	}
	string= pocetak;
	while(*(string+brojac)!='\0'){
		*string= *(string+brojac);
		string++;
	}
	*string= *(string+brojac);
}
void umetniRijec(char* string, char* rijec){
	int duzinaRijeci= duzinaStringa(rijec);
	char* pocetak= string;
	while(*string++!='\0');
	while(string>pocetak){
		*(string+duzinaRijeci)= *string;
			string--;
	}
	*(string+duzinaRijeci)= *string;
	string= pocetak;
	while(*rijec!='\0'){
		*string= *rijec;
		string++;
		rijec++;
	}
}
int duzinaStringa(char* string){
	int brojac=0;
	while(*string++!='\0')
		brojac++;
	return brojac;
}
void printajString(char* string){
	while(*string!='\0')
		printf("%c",*string++);
	printf("\n");
}