#include <stdio.h>
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci);
int jednake(char* rijec1, char* rijec2);
void unesi(char niz[], int velicina);
void brisiRijec(char* string);
void unesiRijec(char* string, char* rijec);
int duzinaZnaka(char* string);
void ispisiZnak(char* string);
int main() {
	
	char* rijeci[1] = {"dobro"};
	char* zamjene[1] = {"dobro"};
	char tekst[] = "dobro dobro";
	printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 1));


	return 0;
}
char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char* pocetak= tekst;
	int i;
	for(i=0;i<broj_rijeci; i++){
		if(jednake(rijeci[i], zamjene[i]))			
			continue;										
		while (*tekst!='\0') {
			if(tekst==pocetak || *(tekst-1)==' '){				
				if(jednake(tekst, rijeci[i])){
					brisiRijec(tekst);
					unesiRijec(tekst, zamjene[i]);
				}
			}
			tekst++;
		}
		tekst= pocetak;
	}
	return pocetak;
}
int jednake(char* rijec1, char* rijec2){
	while(*rijec1!='\0' && *rijec1!=' '){						
		if(*rijec1== ' ' && *rijec2!= ' ' && *rijec2!= '\0')	
			return 0;
		if(*rijec1!= *rijec2)	
			return 0;
		rijec1++;
		rijec2++;
	}
	if((*rijec1=='\0' || *rijec1==' ') && *rijec2!= ' ' && *rijec2!= '\0')	
		return 0;
 

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
void brisiRijec(char* string){
	int brojac= 0;
	char* pocetak= string;
	
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
void unesiRijec(char* string, char* rijec){
	int duzinaRijeci= duzinaZnaka(rijec);
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
int duzinaZnaka(char* string){
	int brojac=0;
	while(*string++!='\0')
		brojac++;
	return brojac;
}
void ispisiZnak(char* string){
	while(*string!='\0')
		printf("%c",*string++);
	printf("\n");
}