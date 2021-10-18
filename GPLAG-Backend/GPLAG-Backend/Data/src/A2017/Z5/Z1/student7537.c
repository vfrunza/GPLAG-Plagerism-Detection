#include <stdio.h>

void unesi(char niz[], int velicina){
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}


struct Osoba {
		char ime[15];
		char prezime[20];
		int telefon;
	};

struct Osoba unos_osobe(){
	struct Osoba o;
	printf("\nUnesite ime: ");
	unesi(o.ime, 15);
	printf("\nUnesite prezime: ");
	unesi(o.prezime, 15);
	printf("\nUnesite broj telefona: ");
	scanf("%d", &o.telefon);
	
	return o;
}	

void ispis_osobe(struct Osoba *s){
	int i=0;
	for(; i<100; i++){
		printf("%d. ", i+1);
		printf("%s %s, ", s->ime, s->prezime);
		printf("Tel: %d", s->telefon);
	}
}

int main(){
	int b;
	struct Osoba imenik[100];
	printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: ");
	scanf("%d", &b);
	
	switch(b){
		case 0:
		break;
		
		case 1:
		unos_osobe;
		break;
		
		case 2:
		ispis_osobe(struct Osoba imenik);
	}
	
	return 0;
}