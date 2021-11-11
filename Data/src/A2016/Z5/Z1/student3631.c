#include <stdio.h>

struct Student {
char ime[20], prezime[20];
int ocjene[50];
int br_ocjena;
};

int uporedi(char* s1, char* s2){
    while(*s1!='\0' && *s2!='\0'){
        if (*s1<*s2) return -1;
        if (*s1>*s2) return 1;
        s1++;
        s2++;
    }
    if(*s1!='\0') return 1;
    if(*s2!='\0') return -1;
    return 0;
}

int genijalci(struct Student studenti[], int vel, double prosjek){
    int i,j,max[4];
    int broj_petica=0,suma_ocjena=0;
    double moj_prosjek[4]={};
    struct Student max[4];
    
    
    
    for (i=0;i<vel;i++)
    {
        for(j=0;j<studenti[i].br_ocjena;j++){
            
        if(studenti[i].ocjene[j]==5) { broj_petica++;}
        suma_ocjena=suma_ocjena+studenti[i].ocjene[j];
     }
        
        if(broj_petica>0) {moj_prosjek[j]=5.0;}
        
        else if (studenti[i].br_ocjena==0) {moj_prosjek[j]=5.0;}
        else {moj_prosjek[i]=suma_ocjena%studenti[i].br_ocjena;}
    
        if(moj_prosjek[i]<prosjek){
            for(j=i;j<vel-1;j++) { studenti[j]=studenti[j+1];}
            vel--;
            i--;
        }   
        
        max[i]
    } 
        

        
        printf("%10s %10s",studenti[i].prezime, studenti[i].ime);
   
        return vel;
    }
    
    
    
int main() {
struct Student studenti[4];
int velicina=4;
double prosjek;
scanf ("%f", &prosjek);
genijalci(studenti,&velicina,prosjek);
return 0;
}
