#include <stdio.h>

/*funkcija za unos stringa*/
void unesi(char niz[], int velicina){
	
	char znak=getchar();
	if (znak == '\n'){
		znak = getchar();
	}
	
	int i=0;
	
	while (i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	
	niz[i]='\0';
}

/*funkcija koja vraća broj ponavljanja određenog znaka u stringu*/
int prebroji (char* s, char znak){
	
	int broj=0;
	while (*s != '\0') {
		if (*s == znak) {
			broj++;
		}
		s++;
	}
	
	return broj;
}

char* kodiraj (char* tekst, char* kod){
	
	int i,j;
	char tmp;
	
	/*upisivanje karaktera u niz, sortirano po ASCII vrijednosti*/
	for (i=0; i<96; i++){
		*(kod+i)=32+i;
	}
	
	*(kod+i-1)='\0';
	
	/*sortiranje niza prema broju ponavljanja*/
	for (i=0; i<95; i++){
		for (j=i; j<95; j++){
			
			if (prebroji(tekst,*(kod+j)) > prebroji(tekst,*(kod+i))){
				tmp=*(kod+i);
				*(kod+i)=*(kod+j);
				*(kod+j)=tmp;
			}
			else if (prebroji(tekst,*(kod+j)) == prebroji(tekst,*(kod+i))){
				if (*(kod+j)<*(kod+i)){
					tmp=*(kod+i);
					*(kod+i)=*(kod+j);
					*(kod+j)=tmp;
				}
			}
		}
	}
	
	char* s=tekst;
	
	/*kodiranje teksta*/
	while (*s != '\0'){
		int pozicija=0;
		char* a=kod;
		while (*a != *s) {
			a++;
			pozicija++;
		}
		
		*s=126-pozicija;
		s++;
	}
	
	return tekst;
}


char* dekodiraj(char* tekst, char* kod) {
	
	char *a=tekst;
	char *b;
	
	/*dekodiranje teksta*/
	while(*a != '\0'){
		
		int pozicija=0;
		b=kod;
		while (*b!='\0'){
			if(*a == 126-pozicija){
				*a=*b;
				break;
			}
			b++;
			pozicija++;
		}
		a++;
	}
	
	
	return tekst;
}


int main() {
	
	char tekst[200];
	char kod[100];
	
	unesi(tekst, 200);
	printf("%s\n", tekst);
	kodiraj(tekst, kod);
	printf("%s\n%s", kod, tekst);
	dekodiraj(tekst, kod);
	printf("\n%s", tekst);
	

	return 0;
}
