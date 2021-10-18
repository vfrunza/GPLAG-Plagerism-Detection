#include <stdio.h>

struct Student {
    char ime[20], prezime[20];
    int ocjene[50];
    int br_ocjena;
};

void unesi(char niz[], int velicina) {
    char znak = getchar();
    int i = 0;
    if (znak == '\n') znak=getchar();
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

double pr (int niz[], int velicina) {
    
    int i;
    double prosjek = 0;
    
    for(i = 0; i < velicina; i++) prosjek += niz[i];
    if(velicina != 0) prosjek /= velicina;
    
    return prosjek;
}


void ispisi_genijalce (struct Student studenti[], int br_studenata) {
    
    int i;
    struct Student *prvi = NULL, *drugi = NULL, *treci = NULL, *genijalac = NULL;
    
    if(br_studenata != 0) {
        genijalac = &studenti[0];
        for(i = 0; i < br_studenata; i++) {
            if(pr((*genijalac).ocjene, (*genijalac).br_ocjena) < pr(studenti[i].ocjene, studenti[i].br_ocjena)) genijalac = &studenti[i];
            else if((pr((*genijalac).ocjene, (*genijalac).br_ocjena)) == pr(studenti[i].ocjene, studenti[i].br_ocjena)) {
            
            }
        }
        if(genijalac != NULL) prvi = genijalac;
    }
    
    if(br_studenata > 1) {
        genijalac = &studenti[0];
        if(genijalac == prvi) genijalac++;
        
        for(i = 0; i < br_studenata; i++) {
            if(prvi == &studenti[i]) continue; 
            else if(pr((*genijalac).ocjene, (*genijalac).br_ocjena) < pr(studenti[i].ocjene, studenti[i].br_ocjena)) genijalac = &studenti[i];
            else if((pr((*genijalac).ocjene, (*genijalac).br_ocjena)) == pr(studenti[i].ocjene, studenti[i].br_ocjena)) {
              
            }
        }
        if(genijalac != NULL) drugi = genijalac;
    }
    
    if(br_studenata > 2) {
        genijalac = &studenti[0];
        while(genijalac == prvi || genijalac == drugi) genijalac++;
        
        for(i = 0; i < br_studenata; i++) {
            if((prvi == &studenti[i]) || (drugi == &studenti[i])) continue; 
            else if(pr((*genijalac).ocjene, (*genijalac).br_ocjena) < pr(studenti[i].ocjene, studenti[i].br_ocjena)) genijalac = &studenti[i];
            else if((pr((*genijalac).ocjene, (*genijalac).br_ocjena)) == pr(studenti[i].ocjene, studenti[i].br_ocjena)) {
                
            }
        }
        if(genijalac != NULL) treci = genijalac;
    }
    
    
    if(prvi != NULL) printf("%s %s\n", (*prvi).prezime, (*prvi).ime);
    if(drugi != NULL) printf("%s %s\n", (*drugi).prezime, (*drugi).ime);
    if(treci != NULL) printf("%s %s\n", (*treci).prezime, (*treci).ime);
}

int genijalci (struct Student studenti[], int br_studenata, double prosjek) {
    
    double prosjek_ocjena = 0;
    int i, j;
    
    
    for(i = 0; i < br_studenata; i++) {
        for(j = 0; j < studenti[i].br_ocjena; j++) {
            if(studenti[i].ocjene[j] != 5) {
                prosjek_ocjena += studenti[i].ocjene[j];
            }
            else {
                prosjek_ocjena = 5;
                break;
            }
        }
        if(prosjek_ocjena == 0 || prosjek_ocjena == 5) prosjek_ocjena = 5;
        else prosjek_ocjena /= studenti[i].br_ocjena;
        
        if(prosjek_ocjena < prosjek) {
            if(br_studenata == 1) br_studenata = 0;
            else {
                for(j = i; j < (br_studenata - 1); j++) {
                    studenti[j] = studenti[j + 1];
                }
                br_studenata--;
                i--;
            }
        }
        
        prosjek_ocjena = 0;
    }
    
    ispisi_genijalce(studenti, br_studenata);
    
    return br_studenata;
}

int main() {
    
    struct Student studenti[100];
    int i, j, n;
    
    printf("Unesite broj studenata: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Unesite ime %d. studenta: ", i + 1);
        unesi(studenti[i].ime, 20);
        printf("Unesite prezime %d. studenta: ", i + 1);
        unesi(studenti[i].prezime, 20);
        printf("Unesite broj ocjena %d. studenta: ", i + 1);
        scanf("%d", &studenti[i].br_ocjena);
        if(studenti[i].br_ocjena != 0) {
            printf("Unesite te ocjene: ");
            for(j = 0; j < studenti[i].br_ocjena; j++) scanf("%d", &studenti[i].ocjene[j]);
        }
    }
    
    printf("\n%d", genijalci(studenti, n, 7));
    
    return 0;
}