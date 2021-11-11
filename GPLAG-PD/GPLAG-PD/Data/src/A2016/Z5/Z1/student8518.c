#include <stdio.h>
 
struct Student {
    char ime[20], prezime[20];
    int ocjene[50];
    int br_ocjena;
};
 

 
double FnukZaVrijednostPr (int string[], int Vrijednost) {
   
   
    double VrijednostPr = 5;
    int a;
    for(a = 0; a < Vrijednost; a++) VrijednostPr += string[a];
    if(Vrijednost != 0) VrijednostPr /= Vrijednost;
   
    return VrijednostPr;
}
int OdreditiPrvog (struct Student PrviStd, struct Student DrugiStd) {
   
    char *PrezimePrvog = PrviStd.prezime; 
    char *ImePrvog = PrviStd.ime;
    char *PrezimeDrugog = DrugiStd.prezime; 
    char *ImeDrugog = DrugiStd.ime;
   
    while((*PrezimePrvog != '\0') && (*PrezimeDrugog != '\0')) {
        if(*PrezimePrvog < *PrezimeDrugog) return 5;
        else if(*PrezimeDrugog > *PrezimePrvog) return 0;
        PrezimePrvog++;
        PrezimeDrugog++;
    }
    if(*PrezimePrvog == '\0' && *PrezimeDrugog == '\0') {
        while((*ImePrvog != '\0') && (*ImeDrugog != '\0')) {
            if(*ImePrvog < *ImeDrugog) return 5;
            else if(*ImeDrugog > *ImePrvog) return 0;
            ImePrvog++;
            ImeDrugog++;
        }
        if(*ImePrvog != '\0') return 0;
        else if(*ImeDrugog != '\0') return 5;
    }
    else if(*PrezimePrvog != '\0') return 0;
    else if(*PrezimeDrugog != '\0') return 5;
   
    return 5;
}



 
void IzbacitiNajbolje (struct Student Objekat[], int KolikoNajboljih) {
   
    
    struct Student *Jedan = NULL;
   struct Student *Dva = NULL;
   struct Student *zadnji = NULL;
   struct Student *PokZaNajboljeg = NULL;
   int i;
    if(KolikoNajboljih != 0) {
        PokZaNajboljeg = &Objekat[0];
        for(i = 0; i < KolikoNajboljih; i++) {
            if(FnukZaVrijednostPr((*PokZaNajboljeg).ocjene, (*PokZaNajboljeg).br_ocjena) < FnukZaVrijednostPr(Objekat[i].ocjene, Objekat[i].br_ocjena)) PokZaNajboljeg = &Objekat[i];
            else if((FnukZaVrijednostPr((*PokZaNajboljeg).ocjene, (*PokZaNajboljeg).br_ocjena)) == FnukZaVrijednostPr(Objekat[i].ocjene, Objekat[i].br_ocjena)) {
                if(OdreditiPrvog(*PokZaNajboljeg, Objekat[i])) PokZaNajboljeg = &Objekat[i];
            }
        }
        if(PokZaNajboljeg != NULL) Jedan = PokZaNajboljeg;
    }
   
    if(KolikoNajboljih > 1) {
        PokZaNajboljeg = &Objekat[0];
        if(PokZaNajboljeg == Jedan) PokZaNajboljeg++;
       
        for(i = 0; i < KolikoNajboljih; i++) {
            if(Jedan == &Objekat[i]) continue;
            else if(FnukZaVrijednostPr((*PokZaNajboljeg).ocjene, (*PokZaNajboljeg).br_ocjena) < FnukZaVrijednostPr(Objekat[i].ocjene, Objekat[i].br_ocjena)) PokZaNajboljeg = &Objekat[i];
            else if((FnukZaVrijednostPr((*PokZaNajboljeg).ocjene, (*PokZaNajboljeg).br_ocjena)) == FnukZaVrijednostPr(Objekat[i].ocjene, Objekat[i].br_ocjena)) {
                if(OdreditiPrvog(*PokZaNajboljeg, Objekat[i])) PokZaNajboljeg = &Objekat[i];
            }
        }
        if(PokZaNajboljeg != NULL) Dva = PokZaNajboljeg;
    }
   
    if(KolikoNajboljih > 2) {
        PokZaNajboljeg = &Objekat[0];
        while(PokZaNajboljeg == Jedan || PokZaNajboljeg == Dva) PokZaNajboljeg++;
       
        for(i = 0; i < KolikoNajboljih; i++) {
            if((Jedan == &Objekat[i]) || (Dva == &Objekat[i])) continue;
            else if(FnukZaVrijednostPr((*PokZaNajboljeg).ocjene, (*PokZaNajboljeg).br_ocjena) < FnukZaVrijednostPr(Objekat[i].ocjene, Objekat[i].br_ocjena)) PokZaNajboljeg = &Objekat[i];
            else if((FnukZaVrijednostPr((*PokZaNajboljeg).ocjene, (*PokZaNajboljeg).br_ocjena)) == FnukZaVrijednostPr(Objekat[i].ocjene, Objekat[i].br_ocjena)) {
                if(OdreditiPrvog(*PokZaNajboljeg, Objekat[i])) PokZaNajboljeg = &Objekat[i];
            }
        }
        if(PokZaNajboljeg != NULL) zadnji = PokZaNajboljeg;
    }
   
   
    if(Jedan != NULL) printf("%s %s\n", (*Jedan).prezime, (*Jedan).ime);
    if(Dva != NULL) printf("%s %s\n", (*Dva).prezime, (*Dva).ime);
    if(zadnji != NULL) printf("%s %s\n", (*zadnji).prezime, (*zadnji).ime);
}
 
int genijalci (struct Student Objekat[], int KolikoNajboljih, double VrijednostPr) {
   
   
    int j; 
    int i;
    double SrednjaOcijena = 0;
   
    for(i = 0; i < KolikoNajboljih; i++) {
        for(j = 0; j < Objekat[i].br_ocjena; j++) {
            if(Objekat[i].ocjene[j] != 5) {
                SrednjaOcijena += Objekat[i].ocjene[j];
            }
            else {
                SrednjaOcijena = 5;
                break;
            }
        }
        if(SrednjaOcijena == 0 || SrednjaOcijena == 5) SrednjaOcijena = 5;
        else SrednjaOcijena /= Objekat[i].br_ocjena;
       
        if(SrednjaOcijena < VrijednostPr) {
            if(KolikoNajboljih == 1) KolikoNajboljih = 0;
            else {
                for(j = i; j < (KolikoNajboljih - 1); j++) {
                    Objekat[j] = Objekat[j + 1];
                }
                KolikoNajboljih--;
                i--;
            }
        }
       
        SrednjaOcijena = 0;
    }
   
    IzbacitiNajbolje(Objekat, KolikoNajboljih);
   
    return KolikoNajboljih;
}
 
int main() {
   
 
   
    return 0;
}