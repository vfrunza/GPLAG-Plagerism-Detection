#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KAPACITET 200

struct Vrijeme {
		int sati, minute, sekunde;
};
struct Cas {
		char predmet[10];
		int dan_u_sedmici;
		struct Vrijeme pocetak, kraj;
};


int ucitaj_datoteku(struct Cas raspored[]);
int zapisi_datoteku(struct Cas raspored[], int broj_casova);
int dodaj_cas(struct Cas raspored[], int broj_casova, const char* predmet, int trajanje);
int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas);
void ispis_rasporeda(struct Cas raspored[], int broj_casova);
void ispisi_dan(struct Cas raspored[], int broj_casova, int dan);
void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena);
void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj);

int ucitaj(int num, FILE *ulaz, char *niz){
    //vraca 0 ako je samo whitespace ucito
int i;
char c;
int whitespace = 1;
    for(i = 0; i < num; i++){
        c = fgetc(ulaz);
        if(c != ' '){
            whitespace = 0;
        }
        niz[i] = c;
    }
    
    niz[i] = '\0';
    //ucitali smo i viska razmaka ako ih je bilo pa cemo ih eliminisati
    for( i = 0; i < num; i++){
        if(niz[i] == ' ' && (niz[i + 1] == ' '|| niz[i+1] == '\0'))
        niz[i] = '\0';
    }
    fgetc(ulaz);
    if(whitespace == 0)
        return 1;
    return 0;
}
int zapisi_datoteku(struct Cas raspored[], int broj_casova){
    FILE *ulaz;
    int i,j,k, brojKolona = 0, maxVrijeme =9;//najnize vrijeme 9 sati
    int trenutnoVrijeme = 9;
    int bioCas = 0;//da li je bio cas u tom mjestu u tabeli
    
    if(broj_casova > 200)
        broj_casova = 200;
    
    if ((ulaz = fopen("raspored.dat","w")) == NULL) {
        printf("Greska pri otvaranju datoteke");
        exit(1);
    }
    // odredujemo broj redova
    for(i = 0; i < broj_casova; i++){
        if(raspored[i].kraj.sati > maxVrijeme){
            maxVrijeme = raspored[i].kraj.sati;
        }
    }
    brojKolona = maxVrijeme - 8;
    fprintf(ulaz, "      PON       UTO       SRI       CET       PET       SUB       \n");

    for(i = 0; i < brojKolona; i++){
    if(trenutnoVrijeme == 9){
                fprintf(ulaz, "%d:00  ",trenutnoVrijeme);
    }
    else{
                fprintf(ulaz, "%d:00 ",trenutnoVrijeme);
    }
        for(j = 0; j < 6; j++){
            bioCas = 0;

            //za svako mjesto prolazimo kroz sve casove i provjeravamo da li da ih ispisujemo
            for(k = 0; k < broj_casova; k++){
                if(raspored[k].pocetak.sati <= trenutnoVrijeme &&raspored[k].kraj.sati >= trenutnoVrijeme && raspored[k].dan_u_sedmici == j){
                    fprintf(ulaz,"%-10s", raspored[k].predmet);

                    bioCas = 1;
                    break;
                }
            }
            if(!bioCas){
                //ako nismo ispisali neki cas, onda ispisujemo prazan prostor
                fprintf(ulaz,"          ");
            }
        }
        fprintf(ulaz,"\n");
        trenutnoVrijeme++;
    }
    fclose(ulaz);
    return 1;
}

void ispis_rasporeda(struct Cas raspored[], int broj_casova){
    int i,j,k, brojKolona = 0, maxVrijeme =9;//najnize vrijeme 9 sati
    int trenutnoVrijeme = 9;
    int bioCas = 0;//da li je bio cas u tom mjestu u tabeli


    // odredujemo broj redova
    for(i = 0; i < broj_casova; i++){
        if(raspored[i].kraj.sati > maxVrijeme){
            maxVrijeme = raspored[i].kraj.sati;
        }
    }
    brojKolona = maxVrijeme - 9;
    printf("      PON       UTO       SRI       CET       PET       SUB       \n");

    for(i = 0; i < brojKolona; i++){
    if(trenutnoVrijeme == 9){
                printf("%d:00  ",trenutnoVrijeme);
    }
    else{
                printf("%d:00 ",trenutnoVrijeme);
    }
    //slicno kao zapisu u datoteku
        for(j = 0; j < 7; j++){
            bioCas = 0;

            //za svako mjesto prolazimo kroz sve casove i provjeravamo da li da ih ispisujemo
            for(k = 0; k < broj_casova; k++){
                if(raspored[k].pocetak.sati == trenutnoVrijeme && raspored[k].dan_u_sedmici == j){
                    printf("%-10s", raspored[k].predmet);
                    bioCas = 1;
                    break;
                }
            }
            if(!bioCas){
                //ako nismo ispisali cas, onda prazno
                printf("          ");
            }
        }
        trenutnoVrijeme++;
    }
}

int ucitaj_datoteku(struct Cas raspored[]){

    int ret = 0, i, numSkip, tmpHr, tmpMin;
    char imePred[11];

    char tmp[200];
    FILE *ulaz;

    if ((ulaz = fopen("raspored.dat","r")) == NULL) {
        printf("Greska pri otvaranju datoteke");
        exit(1);
    }
    //fseek(ulaz, 11, SEEK_SET);
   fgets(tmp, 100, ulaz);

    while(!feof(ulaz)){

        if(fscanf(ulaz,"%d:%d", &tmpHr, &tmpMin) != 2)
            break;

        if(tmpHr < 10)
            fgetc(ulaz);
        fgetc(ulaz);
        for( i = 0; i < 6; i++){
            if(ucitaj(9, ulaz, imePred)){
                //ucitavamo podatke za svaki predmet redom
                strcpy(raspored[ret].predmet, imePred);
                raspored[ret].dan_u_sedmici = i;
                raspored[ret].pocetak.sati = tmpHr;
                raspored[ret].pocetak.minute = tmpMin;
                raspored[ret].pocetak.sekunde = 0;
                raspored[ret].kraj.sati = tmpHr + 1;
                raspored[ret].kraj.minute = tmpMin;
                raspored[ret].kraj.sekunde = 0;
                ret++;
            }
        }
    }
    fclose(ulaz);
    return ret;
}


int main() {
    struct Cas raspored[KAPACITET];
	FILE *ulaz;
	char ime[] = "raspored.dat";
	int val;
	int broj_casova;
	int x;
	//ucitavam podatke iz raspored.dat, ako ne postoji idem dalje sa praznom bla bla
	if ((ulaz = fopen(ime,"r")) != NULL) {
        int ucitaj_datoteku(raspored);
        fclose(ulaz);
        ulaz = fopen(ime, "a+");
    }
    else{
        ulaz = fopen(ime,"a+");
    }
    //ucitaj(raspored.dat);//bla bla
    broj_casova = ucitaj_datoteku(raspored);
    do{
    printf("1) Ispis rasporeda \n2) Dodavanje casa \n3) Promjena casa \n4) Brisanje casa \n0) Kraj rada \nIzaberite opciju: ");
    scanf("%d", &val);
    switch(val){
    	case 1: ispis_rasporeda(raspored, broj_casova);
    	break;
    	case 2: //dodajCas();
    	break;
    	case 3: //promijeniCas();
    	break;
    	case 4: //obrisiCas();
    	break;
    	case 0: //update();
    	break;
    	default:
    	break;
    }
    }while(val != 0);

	return 0;
}
