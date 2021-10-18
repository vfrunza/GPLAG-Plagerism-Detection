#include <stdio.h>

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

int provjeri_duzine(char *s , int *niz, int vel){
	int brojac = 0;
	int provjera = 0;
	int i = 0;
	int broj_rijeci = 0;
	
	
	char *pocetak = s ;
	char *kraj = s;
	while(*s != '\0'){
		if((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')){
		broj_rijeci++;
		pocetak = s;
			while((*s >= 'a' && *s <= 'z') || (*s >= 'A' && *s <= 'Z')){
				s++;
			} 
		kraj = s;
		
		brojac = 0;
		while(pocetak < kraj){
			brojac++;
			pocetak++;
		}
		
		if(i < vel && niz[i] == brojac) provjera++;
		i++;
		} else s++;
	}
	
	if(provjera == vel && vel == broj_rijeci) return 1;
	return 0;
}

int main() {
	char string[100];
	int niz[5];
	int vel,i;
	int provjera;
	
	printf("UNesite string: \n");
	unesi(string,100);
	printf("Unesite dimenziju niza: \n");
	scanf("%d",&vel);
	printf("\nUNesite elemente niza: \n");
	for(i = 0 ; i < vel ; i++){
		scanf("%d",&niz[i]);
	}
	
	provjera = provjeri_duzine(string,niz,vel);
	if(provjera == 1 ) printf("DOBRO");
	else printf("NIJE DOBRO");
	return 0;
}
