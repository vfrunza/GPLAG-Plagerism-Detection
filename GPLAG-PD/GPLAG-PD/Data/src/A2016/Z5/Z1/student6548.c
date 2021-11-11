#include <stdio.h>
#include <string.h>

struct Student{
    char ime[20],prezime[20];
    int ocjene[50];
    int br_ocjena;
};

double prosjecna_ocjena(int niz[],int vel){
    if(vel==0) return 0;
    int i;
    double prosjek=5, suma=0;
    for(i=0;i<vel;i++){
        if(niz[i]==5) return 5;
        suma+=niz[i];
    }
    prosjek=suma/vel;
    return prosjek;
}

int uporedi(char* s1, char* s2){
    while (*s1!='\0' && *s2!='\0'){
        if(*s1<*s2) return -1;
        if(*s1>*s2) return 1;
        s1++;
        s2++;
    }
    if(*s1!='\0') return 1;
    if(*s2!='\0') return -1;
    return 0;
}
int genijalci(struct Student studenti[], int velicina, double prosjek){
    int i,j;
    for(i=0;i<velicina;i++){
        if(prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena)<prosjek){
            for(j=i; j<velicina-1; j++)
                studenti[j]=studenti[j+1];
            velicina--;
            i--;
        }
    }
int prvi=-1, drugi=-1, treci=-1;
double najveci=0, prosj;
int ispred;

for(i=0; i<velicina; i++){
    if(prosjecna_ocjena(studenti[i].ocjene, studenti[i].br_ocjena) >= najveci){
        if(prosjecna_ocjena(studenti[i].ocjene, studenti[i].br_ocjena) > najveci){
            prvi=i;
            najveci=prosjecna_ocjena(studenti[i].ocjene, studenti[i].br_ocjena);
                continue;
        }
        najveci=prosjecna_ocjena(studenti[i].ocjene, studenti[i].br_ocjena);
        ispred=uporedi(studenti[prvi].prezime, studenti[i].prezime);
        if(ispred==0)
            ispred=uporedi(studenti[prvi].ime,studenti[i].ime);
        if(ispred==1){
            prvi=i;
            }
        }
    }
    najveci=0;
    for(i=0;i<velicina;i++){
        if(prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena)>=najveci && i!=prvi){
            if(prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena)>najveci){
                drugi=i;
        najveci=prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena);
            continue;
            }
            najveci=prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena);
            ispred=uporedi(studenti[drugi].prezime,studenti[i].prezime);
            if(ispred==0)
                ispred=uporedi(studenti[drugi].ime,studenti[i].ime);
                if(ispred==1){
                    drugi=i;
                }
        }
    }
    najveci=0;
    for(i=0;i<velicina;i++){
        if(prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena)>=najveci && i!=prvi && i!=drugi){
            if(prosjecna_ocjena (studenti[i].ocjene,studenti[i].br_ocjena)>najveci){
                
                treci=i;
                najveci=prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena);
                continue;
            }
            najveci=prosjecna_ocjena(studenti[i].ocjene,studenti[i].br_ocjena);
            ispred=uporedi(studenti[treci].prezime,studenti[i].prezime);
            if(ispred==0)
                ispred=uporedi(studenti[treci].ime,studenti[i].ime);
            if(ispred==1){
                treci=i;
            }
        }
    }
    for (i=0;i<velicina;i++)
        if(i==prvi)
            printf("\n%s %s\n", studenti[prvi].prezime, studenti[prvi].ime);
    for (i=0;i<velicina;i++)
        if(i==drugi)
            printf("%s %s\n", studenti[drugi].prezime, studenti[drugi].ime);
    for(i=0;i<velicina;i++)
        if(i==treci)
            printf("%s %s\n",studenti[treci].prezime, studenti[treci].ime);
    return velicina;
}
    
int main(){
    struct Student studenti[10]={
        {"Meho", "Mujic",{7,7,7,7,8},5},
        {"Pero", "Peric",{8,8,8,8,7},5},
        {"Beba", "Bebic",{7,8,9},3},
        {"Mujo", "Mujic",{10,10,10,10,9},5},
        {"Mujo", "Mujic",{7,7,7,7,7,7,7},7},
        {"Fata", "Fatic",{7,7,7,7,7,7,6,6,6,5},10},
        {"Osman", "Osmic",{8,6,9,10,9},5},
        {"Pero", "Mujic",{10,6,10,10,9},5},
        {"Beba", "Mujic",{10,8,7,6,9},5},
        
    };
    
    int vel=genijalci(studenti, 9, 7);
    return 0;
}