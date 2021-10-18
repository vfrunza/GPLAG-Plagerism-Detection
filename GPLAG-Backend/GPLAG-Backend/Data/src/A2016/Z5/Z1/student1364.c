#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001 

/*1. (0,5 bodova) Data je struktura koja opisuje uspjeh studenta na fakultetu:
struct Student {
char ime[20], prezime[20];
int ocjene[50];
int br_ocjena;
};

Niz ocjene sadrži sve ocjene koje je student stekao tokom studija, a br_ocjena je broj članova tog niza. 
Ocjene su cijeli brojevi na intervalu [5,10] (nije potrebno provjeravati).

Napisati funkciju genijalci koja prima niz studenata, veličinu niza i realan broj prosjek, te iz niza izbacuje sve 
studente čiji je prosjek ocjena manji od unesenog prosjeka. Redoslijed studenata u nizu nakon izbacivanja treba ostati 
nepromijenjen! Ako student ima evidentiranu barem jednu ocjenu 5 smatra se da mu je prosjek 5.0 bez obzira na ostale ocjene. 
Također ako student nema nijednu registriranu ocjenu uzima se prosjek 5.0. Funkcija treba vratiti broj studenata koji su 
preostali u nizu nakon izbacivanja.

Osim toga funkcija treba na ekranu ispisati prezime i ime studenta sa najvećim prosjekom, zatim drugog i trećeg po prosjeku, 
svakog u zasebnom redu kao u sljedećem primjeru:
    Saric Sara
    Mujic Mujo
    Hanic Hana
Pri tome ne smiju se ispisivati studenti čiji je prosjek manji od primljenog parametra. Ako ne postoje tri studenta koji 
ispunjavaju ove uslove treba ispisati samo najbolja dva ili samo najboljeg ili ne ispisati ništa. U slučaju da više studenata
ima istu prosječnu ocjenu, najprije treba biti ispisan onaj čije je prezime ispred po leksikografskom redoslijedu, 
a ako imaju isto prezime onda onaj čije je ime ispred po leksikografskom redoslijedu. Ako studenti imaju isto prezime i ime 
i isti prosjek ocjena, svejedno je kojim redoslijedom ćete ih ispisati :)

Nije dozvoljeno sortirati niz studenata! Redoslijed mora ostati nepromijenjen. */

struct Student {
	char ime[20], prezime[20];
	int ocjene[50];
    int br_ocjena;
};

/* Funkcija koja racuna prosjek*/
float prosjek_ocjena (struct Student studenti) {
    float prosjek_st=0;
    int i, suma_ocjena=0;
    /* Ako student nema ocjena vraca 5*/
    if (studenti.br_ocjena==0)
    return 5;
    for (i=0; i<studenti.br_ocjena; i++) {
        /*Ako je jedna od ocjena pet, funkcija vraca prosjek pet*/
        if (studenti.ocjene[i]==5) 
        return 5;
        suma_ocjena+=studenti.ocjene[i];
    }
    prosjek_st=suma_ocjena/(float)studenti.br_ocjena;
    return prosjek_st;
}

/* Funkcija koja poredi dva stringa (leksikografski), vraca -1 ako je prvi string abecedno ispred drugog,
0 ako su stringovi jednaki, 1 ako je prvi string abecedno iza drugog.*/
int strcmp(const char* s1, const char *s2) {
	while (*s1 != '\0' && *s2 != '\0' ) {
		if (*s1 < *s2) return -1;
		if (*s1 > *s2) return 1;
		s1++;
		s2++;
	}
	if (*s1 != '\0') return 1;
	if (*s2 != '\0') return -1;
	
	return 0;
}

int genijalci (struct Student *studenti, int vel, float prosjek) {
    struct Student *p=studenti, *q=studenti, *r=studenti, *prvi=studenti, *drugi=studenti, *treci=studenti, *temp=studenti;
    int i, br_studenata=vel, j=0, k=0;
    float prosjek_studenta=0;
    /* Petlja koja prolazi kroz niz studenata*/
    for (i=0; i<vel; i++) {
        prosjek_studenta=prosjek_ocjena(*p);
        if (prosjek_studenta<prosjek) { 
            /* Pronasli smo studenta kojeg trebamo izbaciti*/
            q=p;
            prvi=p; drugi=p; treci=p; /*Inicijalizacija pokazivaca na studente koji sto posto nisu medju najboljim*/
            /* Do vel-1 da ne bi izasli iz opsega niza! */
            for (j=i; j<vel-1; j++) {
                *q=*(q+1);
                q++;
            }
            p--;
            br_studenata--;
        }
        p++;
    }
    
    /* Ako ni jedan student ne ispunjava uslov*/
    if (br_studenata==0) 
    return br_studenata;
    
    
     /*Petlja koja prolazi kroz studente koji imaju najveci prosjek, trazimo prvog, drugog i treceg studenta*/
      r=studenti;
        for (k=0; k<br_studenata; k++) {
            if (prosjek_ocjena(*r)>=prosjek_ocjena(*prvi) && r!=prvi) {
                /* Ako imamo dva studenta sa istim prosjekom poredimo im prezimena, a zatim i imena ako moramo*/
                if (fabs(prosjek_ocjena(*r)-prosjek_ocjena(*prvi))<EPSILON) {
                    /*poredjenje prezimena alfabetski*/
                    if (strcmp((*r).prezime, (*prvi).prezime)==-1) {
                        temp=prvi;
                        prvi=r;
                        drugi=temp;
                    }
                    else if (strcmp((*r).prezime, (*prvi).prezime)==0) {
                        /* Prezimena su ista, poredimo imena*/
                        if (strcmp((*r).ime, (*prvi).ime)==0)
                        drugi=r;
                        else if (strcmp((*r).ime, (*prvi).ime)==-1) {
                            temp=prvi;
                            prvi=r;
                            drugi=temp;
                        }
                        else drugi=r;
                    }
                    else drugi=r;
                }
                else
                prvi=r;
            }
        r++;
    }
    
     r=studenti;
        for (k=0; k<br_studenata; k++) {
            if (prosjek_ocjena(*r)>=prosjek_ocjena(*drugi) && r!=prvi && br_studenata>1) {
                /* Ako imamo dva studenta sa istim prosjekom poredimo im prezimena, a zatim i imena ako moramo*/
                if (fabs(prosjek_ocjena(*r)-prosjek_ocjena(*drugi))<EPSILON) {
                    /*poredjenje prezimena alfabetski*/
                    if (strcmp((*r).prezime, (*drugi).prezime)==-1) {
                        temp=drugi;
                        drugi=r;
                        treci=temp;
                    }
                    else if (strcmp((*r).prezime, (*drugi).prezime)==0) {
                        /* Prezimena su ista, poredimo imena*/
                        if (strcmp((*r).ime, (*drugi).ime)==0)
                        treci=r;
                        else if (strcmp((*r).ime, (*drugi).ime)==-1) {
                            temp=drugi;
                            drugi=r;
                            treci=temp;
                        }
                        else treci=r;
                    }
                    else treci=r;
                }
                else
                drugi=r;
            }
            else if (br_studenata==2 && r!= prvi)
            drugi=r;
        r++;
    }
    
     r=studenti;
        for (k=0; k<br_studenata; k++) {
            if (prosjek_ocjena(*r)>prosjek_ocjena(*treci) && r!=prvi && r!=drugi && br_studenata>2) {
                if (fabs (prosjek_ocjena(*r)-prosjek_ocjena(*treci))<EPSILON) {
                    /*poredjenje prezimena alfabetski*/
                    if (strcmp((*r).prezime, (*treci).prezime)==-1) {
                        treci=r;
                    }
                    else if (strcmp((*r).prezime, (*treci).prezime)==0) {
                        /* Prezimena su ista, poredimo imena*/
                        if (strcmp((*r).ime, (*drugi).ime)==-1) {
                            treci=r;
                        }
                    }
                    else treci=r;
                }
                else treci=r;
            }
        r++;
    }
    
    printf ("%s %s \n", (*prvi).prezime, (*prvi).ime);
    if (br_studenata>1) {
        printf ("%s %s \n", (*drugi).prezime, (*drugi).ime);
        if (br_studenata>2)
        printf ("%s %s \n", (*treci).prezime, (*treci).ime);
    }
        
    return br_studenata;
}

int main() {
	
	struct Student studenti[3] = {
	{ "Beba", "Bebic", { 6,6,6,6,6}, 5},
	{ "Mujo", "Mujic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8}, 29}, 
	{ "Fata", "Fatic", { 7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8}, 29}, 
	    
	};
    
    genijalci(studenti, 3, 7.0);

	return 0;
}
