#include <stdio.h>
#include <stdlib.h>
#define KAPACITET 333

float *AlocirajNiz(int broj_el) { //eventualno realociraj to ti je bolje valjda
	float *pok=(float* )malloc(sizeof(float)*broj_el);
	return pok; 
}

void OslobodiNiz(int *niz) {
	free(niz);
}
struct Oblik {
	char naziv[20];
	char br_stranica; 
	float stranica;
	
}; 
unsigned long saznaj_velicinu() { // bar nesto radi, sada decoderiaj format nekako
	FILE* ulaz=fopen("oblici.dat", "rb"); 
	if(ulaz==NULL) return 0; 
	long  duzina=0; 
	fseek(ulaz, 0, SEEK_END);
	duzina=ftell(ulaz);
	return duzina;
}


void dodaj(struct Oblik nekioblik) {
	struct Oblik oblici[1]; 
	oblici[0]=nekioblik;
	FILE* ulaz=fopen("oblici.dat", "ab");
	if(ulaz==NULL) exit(1);
	fseek(ulaz,0,SEEK_END); //iako je append vec postavljen na kraj ali eto
	int dodano=fwrite(oblici, 21+nekioblik.br_stranica*4, 1, ulaz);
if(ferror(ulaz)) printf("Nije uspjelo!");

}



int main() {
	struct Oblik o={"Tacka", 1, {1.7}};
	dodaj(o);
	printf("dodano");
	return 0; 
}