#include <stdio.h>
/*Provjeravamo da li se rijec na koju smo naisli nalazi u nizu rijeci*/
int provjera_rijeci(char* s, char *rijeci){
    int vrati=1;
    while(*s!='\0' && *s!=32 && *rijeci!='\0'){
        if(*s!=*rijeci)
            vrati= 0;
        rijeci++;
        s++;
        if(*rijeci=='\0' || *s=='\0')
			break;
    }
 	if(*s!=32 && *s!='\0' && *rijeci=='\0')
 		vrati=0;
 	if(*rijeci!='\0')
 		vrati=0;
    return vrati;
}
int duzina_rijeci(char* s){
    int brojac=0;
    while((*s!='\0') && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))){
        brojac++;
        s++;
    }
    return brojac;
}
/*Zamjenjujemo rijec*/
void zamjena(char *s, char *zamjene){
	char *p,*vrati,*kraj;
	int duzina;
	duzina=duzina_rijeci(zamjene);
	vrati=s;
	p=s;
	while((*p!='\0') && ((*p>='A' && *p<='Z') ||(*p>='a' && *p<='z')))
		p++;
	/*Izbacivanje rijeci*/
	while(*p!='\0'){
		*s=*p;
		s++;
		p++;
	}
	*s='\0';
	/*Prosirivanje niza*/
	s=vrati;
	kraj=s;
    while(*kraj!='\0') 
    	kraj++;
	while (kraj >= s){
    	*(kraj+duzina)=*kraj;
         kraj--;
	}
	/*Ubacivanje rijeci u niz*/
    while(*zamjene!='\0'){
    	*s=*zamjene;
		zamjene++;
		s++;
		if(*zamjene=='\0')
			break;
    }
}
char *zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
	char *vrati,*s;
	int ista,i;
	vrati=tekst;
	for(i=0; i<broj_rijeci; i++){
		s=tekst;
		while(*s!='\0'){
			while(*s!='\0' && (*s<'A' || (*s>'Z' && *s<'a') || *s>'z' ))
				s++;
			if(*s=='\0')
				break;
			ista=provjera_rijeci(s,rijeci[i]);
			if(ista){
				zamjena(s,zamjene[i]);
				ista=0;
			}
			while(*s!='\0' && *s!=32 )
				s++;
		}
	}
	return vrati;
}
void unesi(char niz[], int velicina) {
	int i = 0;
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int main() {
	int broj_rijeci=1;
	char tekst[100];
	char* rijeci[1]={"c"};
	char* zamjene[1]={"Prijestolonasljednikovica"};
	printf("Unesi tekst: ");
	unesi(tekst,100);
	printf("%s",zamjena_rijeci(tekst,rijeci,zamjene,broj_rijeci));
	return 0;
}
