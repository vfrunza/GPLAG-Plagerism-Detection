#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct Rijec {
    char rijec[10];
    int br_ponavljanja;
};

/* uporedi rijec (koristi se za rotiranje rijecu u redu) - prvo na osnovu br ponavljanja pa onda po alfabetu */
int cp_rijec(const void *v1, const void * v2) {
    const struct Rijec * p1 = (struct Rijec * ) v1;
    const struct Rijec * p2 = (struct Rijec * ) v2;
    if (p1 -> br_ponavljanja < p2 -> br_ponavljanja) {
        return -1;
    }
    if (p1 -> br_ponavljanja > p2 -> br_ponavljanja) {
        return +1;
    }
    return strcmp(p1 -> rijec, p2 -> rijec);
}

/* azurira red rijeci, ako je rijec vec prisutna u redu onda mu povecava br ponavljanja, ako ne onda ubacuje rijec u red rijeci */
int dodaj_pojavu_rijeci(struct Rijec rijeci[], int br_rijeci, int maximalni_broj_rijeci, char rijec[]) {
    if (strlen(rijec) > 1) {
        int rijec_poznata = 0, i;
        for( i = 0; i < br_rijeci; i++) {
            if(strcmp(rijeci[i].rijec, rijec) == 0) {
                /* rijec vec postoji u redu */
                rijeci[i].br_ponavljanja++;
                rijec_poznata = 1;
            }
        }
        /* rijec ne postoji u redu, i ako ima mjesta u redu dodajemo rijec */
        if( !rijec_poznata && (br_rijeci < maximalni_broj_rijeci) ) {
            strcpy(rijeci[br_rijeci].rijec, rijec);
            rijeci[br_rijeci].br_ponavljanja = 1;
            br_rijeci++;
        }
    }
    return br_rijeci;
}

/* ako je rijec u redu rijeci medju prvih deset, onda ce rijec dobiti asci codu 20 + pozicija rijecu u redu */
int pronadji_codu(struct Rijec rijeci[], int br_rijeci, char rijec[]) {
    int code = 0, i;
    for( i = 0; i < 10 && i < br_rijeci; i++) {
        if( strcmp(rijeci[i].rijec, rijec) == 0) {
            code = 20 + i;
        }
    }
    return code;
}

void kompresuj_izlaz(struct Rijec rijeci[], int br_rijeci, FILE * ulazna_datoteka, FILE * izlazna_datateka) {
    /* printaj tabelu u datoteku */
    int i;
    for(i = 0; i < 10 && i< br_rijeci; i++) {
        fprintf(izlazna_datateka, "%s\n", rijeci[i].rijec);
    }
    fprintf(izlazna_datateka, "\n");
    
    char ch;
    char temp[100];
    while ((ch = getc(ulazna_datoteka)) != EOF) {
        /* ako char nije 'space char' (tab, razmak ili nova linija) */
        if(!isspace(ch)) {
            /* vratimo pointer jedan karakter unazad */
            fseek(ulazna_datoteka, -1L, SEEK_CUR);
            /* citamo citavu rijec */
            fscanf(ulazna_datoteka, "%s", temp);
            
            int asci_coda = pronadji_codu(rijeci, br_rijeci, temp);
            if (asci_coda != 0) {
                fprintf(izlazna_datateka, "%c", asci_coda);
            } else {
                fprintf(izlazna_datateka, "%s", temp);
            }
        } else {
            fprintf(izlazna_datateka, "%c", ch);
        }
    }
}

void kompresuj(FILE * ulazna_datoteka, FILE * izlazna_datateka) {
    int maximalni_broj_rijeci = 1000;
    int br_rijeci = 0;
    struct Rijec rijeci[0];
    
    /* prvo pronadjimo rijeci i njihova ponavljanja */
    int i;
    /* recimo da rijeci nikad nisu duze od 100 slova */
    char temp[100];
    int index=0;
    /* citaj rijec*/
    char c;
    do {
        c=fgetc(ulazna_datoteka);
        if(isalpha(c))
        {
            temp[index]=c;
            temp[index+1]=0;
            index++;
        }
    }
        while (c != EOF && isalpha(c)); 
        br_rijeci = dodaj_pojavu_rijeci(rijeci, br_rijeci, maximalni_broj_rijeci, temp);
    
    qsort(rijeci, br_rijeci, sizeof(struct Rijec), cp_rijec);
    
    
    /* vrati pokazivac datoteke na pocetak */
    rewind(ulazna_datoteka);
    
    kompresuj_izlaz(rijeci, br_rijeci, ulazna_datoteka, izlazna_datateka);

}
 
void dekompresuj(FILE * ulazna_datoteka, FILE * izlazna_datoteka) {
    char ch, temp[100];
    ch = getc(ulazna_datoteka);
    /* ako datoteka ne pocinje s novom linijom onda imamo rijecu u tabeli */
    char rijeci[10][10];
    int index_rijeci = 0;
    while (ch != '\n' && index_rijeci < 10) {
        /* vratimo pointer na jedan kraj nazad */
        fseek(ulazna_datoteka, -1L, SEEK_CUR);
        
        fscanf(ulazna_datoteka, "%s", temp);
        strcpy(rijeci[index_rijeci], temp);
        index_rijeci++;
        /* citaj jednu novu liniju (poslije svake rijecu u tabeli slijedi jedna nova linija ) */
        ch = getc(ulazna_datoteka);
        /* citaj slijedi karakter (ako je i sljedeci kakter nova linija) */
        ch = getc(ulazna_datoteka);
    }
    
    /* dekompresuj */
    while ((ch = getc(ulazna_datoteka)) != EOF) {
        /*ako je char vrijed izmedju 20 i 29 onda je to kompresirana rijec */
            if (isspace(ch)) {
      fprintf(izlazna_datoteka, "%c", ch);
    } else if (ch >= 20 && ch <= 29) {
      // prinaj pravu rijec koja pripad asci codi
      fprintf(izlazna_datoteka, "%s", rijeci[ch - 20]);
    } else {
      /* rijec nije kompresirana - moramo je u orginalnom stanju ucitati i izprintati*/
      /* vratimo pointer jedan karakter nazad */
      fseek(ulazna_datoteka, -1L, SEEK_CUR);
      /* citamo citavu rijec */
      fscanf(ulazna_datoteka, "%s", temp);
      
      fprintf(izlazna_datoteka, "%s", temp);
    }
  }
}


FILE * otvori_ulaznu_datoteku() {
    char ime_ulazne_datoteke[100];
    printf("Unesite ime ulazne datoteke: ");
    scanf("%s", ime_ulazne_datoteke);
    
    FILE * ulazna_datoteka;
    ulazna_datoteka = fopen(ime_ulazne_datoteke, "r");
    if(ulazna_datoteka == NULL) {
        printf("Izlazna datoteka ne postoji\n");
        return NULL;
    }
    return ulazna_datoteka;
    
}

FILE * otvori_izlaznu_datoteku() {
  char ime_izlazne_datoteke[100];
  printf("Unesite ime izlazne datoteke: ");
  scanf("%s", ime_izlazne_datoteke);

  FILE * izlazna_datoteka;
  izlazna_datoteka = fopen(ime_izlazne_datoteke, "w");
  if (izlazna_datoteka == NULL) {
    printf("Izlazna datoteka ne postoji ");
    return NULL;
  }
  return izlazna_datoteka;
}

void obavi_kompresiju() {
    FILE * ulazna_datoteka = otvori_ulaznu_datoteku();
    if(ulazna_datoteka != NULL) {
        FILE * izlazna_datoteka = otvori_izlaznu_datoteku();
        kompresuj(ulazna_datoteka, izlazna_datoteka);
        fclose(ulazna_datoteka);
        fclose(izlazna_datoteka);
        
        printf("Datoteka kompresovana.\n");
    } else {
        printf("Probajte ponovo !\n");
    }
    
}

void obavi_dekompresiju() {
    FILE * ulazna_datoteka = otvori_ulaznu_datoteku();
    if(ulazna_datoteka != NULL) {
        FILE * izlazna_datoteka = otvori_izlaznu_datoteku();
        dekompresuj(ulazna_datoteka, izlazna_datoteka);
        fclose(ulazna_datoteka);
        fclose(izlazna_datoteka);
        printf("Datoteka dekompresovana.\n");
    } else {
        printf("Probajte ponovo !\n");
    }
}

int main() {
    /* ugasi buferovanje*/
    setbuf(stdout, NULL);
    int ponavljaj = 1;
    do {
        int komanda; 
        printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: 1");
        scanf("%d", & komanda);
        switch (komanda) {
            case 0: 
                ponavljaj = 0;
                break;
            case 1: 
                obavi_kompresiju();
                break;
            case 2: 
                obavi_dekompresiju();
                break;
            default: 
                printf("Pogresan unos, probajte ponovo!\n");
        }
        
    } while (ponavljaj);
    return 0;
    
}

