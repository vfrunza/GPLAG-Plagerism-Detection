#include <stdio.h>
struct Datum{
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

void unesi(char niz[], int velicina){
	char znak = getchar();
	if(znak=='\n') znak = getchar();
	int i=0;
	while (i<velicina-1 && znak != '\n'){
		niz[i]=znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana){
	int i;
	/*Provjera starosti kandidata.*/
	if(x>=0){
		for(i=0; i<vel; i++){
			if(direktor.datum_rodjenja.godina<kandidati[i].datum_rodjenja.godina) continue;
			else{
				if()
			}
		}
	}
}
int main() {
	struct  Uposlenik kandidati[1000], direktor;
	int x,vel,i;
	
	printf("Unesite velicinu niza");
	scanf("%d", &vel);
	
	printf("Unesite broj x");
	scanf("%d",&x);
	
	printf("Unesi ime direktora")
	void unesi(direktor.ime_prezime, 50);
	printf("Unesi datum direktora");
	scanf("%d %d %d", &direktor.datum_rodjenja.dan, &direktor.datum_rodjenja.mjesec, &direktor.datum_rodjenja.godina);
	
	for(i=0; i<vel; i++){
		printf("Unesi  ime %d. kandidata", i+1);
	void unesi(kandidati[i].ime_prezime, 50);
	printf("Unesi datum %d. kandidata");
	scanf("%d %d %d", &kandidati[i].datum_rodjenja.dan, &kandidati[i].datum_rodjenja.mjesec, &kandidati[i].datum_rodjenja.godina);
	
		
	}
	
	return 0;
}
