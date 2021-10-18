#include <stdio.h>
#include <string.h>

void unesi(char niz[], int velicina) {
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}


//funkcija za obrtanje stringa

char *obrni(char *s){
	char temp;
	char *pomocni = s;
	while(*pomocni != '\0'){
		pomocni++;
	}
	pomocni--;
	
	while(*s != '\0'){
		temp = *pomocni;
		*pomocni = *s;
		*s = temp;
		pomocni--;
		s++;
}

char *ubaci_broj (char *tekst, int broj){
	char *s = tekst;
	char *pocetak = tekst;
	char *kraj = tekst;
	
	char novi[100];
	char *nnovi = novi;
	char *vrati = novi;
	
	char brojevni[10];
	char *pok_na_br= brojevni;
	int cifra = 0;
	char *pomocni = pok_na_br;
	
	
	
	while(*pok_na_br != '\0'){
		while(n != 0){
			cifra = n%10;
			n/=10;
			*pok_na_br++ = cifra + '0';
		} *pok_na_br = '\0';
	}
	
	Obrni(pomocni);
	
	while(*s != '\0'){
		if((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')){
			while((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')){
				*nnovi++ = *s++;
			} else if( *s == ' '){
				while(*s == ' '){
				*nnovi++ = *pok_na_br++;
			} *nnovi = ' ';
			}
		} 
		s++;
	}
	
	*nnovi = '\0';
	
	return vrati;
}

int main(){
	printf("Zadaca 4,Zadatak 1");
	return 0;
}