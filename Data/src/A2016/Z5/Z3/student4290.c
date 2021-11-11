#include <stdio.h>
#include <string.h>
#define KAPACITET 200
struct Vrijeme{
	int sati,minute,sekunde;
};
struct Cas{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak,kraj;
};
int ucitaj_datoteku(struct Cas raspored[]){
	return 7;
}
int zapisi_datoteku(struct Cas raspored[]){
	return 2;
}
int dodaj_cas(struct Cas raspored[],int broj_casova,const char* predmet,int trajanje){
	return 3;
}
int preklapanje(struct Cas raspored[],int broj_casova,struct Cas cas){
	int i;
	for(i=0;i<broj_casova;i++){
		if((raspored[i].dan_u_sedmici==cas.dan_u_sedmici)&&(((raspored[i].pocetak.sati==cas.pocetak.sati)&&(raspored[i].kraj.sati==cas.kraj.sati))||(raspored[i].kraj.sati>cas.pocetak.sati&&raspored[i].pocetak.sati<cas.kraj.sati)))return 1;
	}
return 0;	
}
void ispis_rasporeda(struct Cas raspored[],int broj_casova){
	
}
void ispis_dan(struct Cas raspored[],int broj_casova,int dan){
	
}
void promijeni_cas(struct Cas raspored[],int broj_casova,int dan,int redni_broj,struct Cas promjena){
	
}
void obrisi_cas(struct Cas raspored[],int broj_casova,int dan,int redni_broj){
	
}

int main() {

	
	return 0;
}
