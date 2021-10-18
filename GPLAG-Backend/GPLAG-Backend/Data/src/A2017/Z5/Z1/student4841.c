#include <stdio.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik{
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

int broj_imena(struct Uposlenik kandidat){
    int brojac=0;
    while(*kandidat.ime_prezime!='\0'){
        if(*kandidat.ime_prezime==' ') brojac++;
    }
    return brojac;
}

int broj_prezimena(struct Uposlenik kandidat){
    int brojac=1;
    while(*kandidat.ime_prezime!='\0'){
        if(*kandidat.ime_prezime=='-') brojac++;
    }
    return brojac;
}

int broj_dana(struct Datum rodjenje){
    int dani;
    dani=rodjenje.dan;
    switch(rodjenje.mjesec){
        case 12: dani+=31;
        case 11: dani+=30;
        case 10: dani+=31;
        case 9: dani+=30;
        case 8: dani+=31;
        case 7: dani+=31;
        case 6: dani+=30;
        case 5: dani+=31;
        case 4: dani+=30;
        case 3: dani+=31;
        case 2: dani+=28;
        case 1: dani+=31;
    }
    if(rodjenje.godina%400==0 || (rodjenje.godina%4==0 && rodjenje.godina%100!=0)) dani++;
    return dani;
}

struct Datum Novi_datum(struct Datum rodjenje_direktora, int dani){
    struct Datum novi;
    int br_dana, prestupna=0, ;
    br_dana=broj_dana(rodjenje_direktora);
    novi.godina=rodjenje_direktora.godina;
    if(rodjenje_direktora.godina%400==0 || (rodjenje_direktora.godina%4==0 && rodjenje_direktora.godina%100!=0)) prestupna=1;
    if(rodjenje_direktora.mjesec==1 || rodjenje_direktora.mjesec==3 || rodjenje_direktora.mjesec==5 || rodjenje_direktora.mjesec==7 || rodjenje_direktora.mjesec==8 || rodjenje_direktora.mjesec==10 || rodjenje_direktora.mjesec==12){
        if(rodjenje_direktora.dan-dani>31){
            novi.mjesec=rodjenje_direktora.mjesec+1;
        }
        else if(rodjenje_direktora.dan-dani<0){
            novi.mjesec=rodjenje_direktora.mjesec-1;
            if(rodjenje_direktora.mjesec==8) novi.dan=fabs(31-(rodjenje_direktora.dan-dani));
            else if(rodjenje_direktora.mjesec==3) novi.dan=fabs(28+prestupna-(rodjenje_direktora.dan-dani));
        } 
        else novi.mjesec=rodjenje_direktora.mjesec;
    }
    else if(rodjenje_direktora.mjesec==4 || rodjenje_direktora.mjesec==6 || rodjenje_direktora.mjesec==9 || rodjenje_direktora.mjesec==11)
        
    return novi;
}

int suzi_listu (struct Uposlenik* kandidat, int velicina, struct Uposlenik direktor, int broj_dana){
	int i;
	
	return velicina;
}

int main() {
struct Uposlenik direktor = {"Mujo Mujic", {1, 3, 1980} };
struct Uposlenik kandidati[7] = {
    { "Meho Mehic", { 31, 1, 1980 } },
    { "Pero Peric", { 1, 2, 1980 } },
    { "Sara Sarac", { 2, 2, 1980 } },
    { "Fata Mujic", { 1, 2, 1976 } },
    { "Jozo Jozic", { 1, 10, 1980 } },
    { "Mijo Mijic", { 4, 3, 1979 } },
    { "Suljo Suljic", { 15, 1, 1982 } },
};

/* 1980 godina je bila prestupna, februar je imao 29 dana,
   sto znaci da je Pero Peric za 29 dana stariji od direktora,
   pa kako je 29>28 Pero treba biti izbacen a Sara ne. */

int novi_br = suzi_listu(kandidati, 7, direktor, 28);
int i;
printf("Nakon suzenja liste:\n");
for (i=0; i<novi_br; i++)
    printf("%s\n", kandidati[i].ime_prezime);
	return 0;
}
