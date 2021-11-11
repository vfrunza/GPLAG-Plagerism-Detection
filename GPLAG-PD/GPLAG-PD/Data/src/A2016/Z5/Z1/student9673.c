#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define eps 0.000001

struct Student{
	char ime[20], prezime[20];
	int ocjene[50];
	int br_ocjena;
};

/* funkcija za unos stringa */
void unesi(char niz[], int velicina){
    int i=0;
    char znak;
    do{
        znak=getchar();
    }while(znak=='\n');
    
    while(znak!='\n' && i<velicina-1){
        niz[i++]=znak;
        znak=getchar();
    }
    niz[i]='\0';
}

/* funkcija koja unosi podatke za svakog studenta iz niza studenata */
struct Student unesi_podatke(){
    struct Student s;
    int i=0;
    printf("Ime: ");
    unesi(s.ime, 20);
    printf("Prezime: ");
    unesi(s.prezime, 20);
    printf("Broj ocjena: ");
    scanf("%d",&s.br_ocjena);
    printf("Ocjene: ");
    for(i=0; i<s.br_ocjena; i++){
        scanf("%d",&s.ocjene[i]);
    }
    return s;
}

int genijalci(struct Student studenti[], int velicina, float prosjek){
    int i=0, j=0, k=0, vel=velicina, pret=0, index=0;
    float trenutni_prosjek=0, granica=prosjek, suma=0, niz[100], temp;
    struct Student pomoc[100];
    char pomocno_ime[20];
    char pomocno_prezime[20];
    for(i=0; i<vel; i++){
    suma=0;
    trenutni_prosjek=0;
    pret=0;
    
        if(studenti[i].br_ocjena==0){   /* ako student nema nijednu registrovanu ocjenu - prosjek 5.0 */
             trenutni_prosjek=5.0;
             pret=1;
        }
         if(pret==0){
         for(j=0; j<studenti[i].br_ocjena; j++){
         if(studenti[i].ocjene[j]==5){
             trenutni_prosjek=5.0;       /* ako petljom naiđe na ocjenu 5, prosjek postaje 5.0 */
             break;
         }
         suma+=studenti[i].ocjene[j];
            }
         }    
         
         if(fabs(trenutni_prosjek-trenutni_prosjek)<eps){
             trenutni_prosjek=suma/studenti[i].br_ocjena;
             if(fabs(trenutni_prosjek-5.0)>eps)niz[i]=trenutni_prosjek; /* prosjek svakog studenta se dodjeljuje nizu prosjeka */
        }
        
        /* izbaci studenta sa prosjekom manjeg od prosjeka poslanog iz main-a */
        if(pret==1 || trenutni_prosjek<granica){
            for(j=i; j<vel-1; j++){
                strcpy(studenti[j].ime, studenti[j+1].ime);
                strcpy(studenti[j].prezime, studenti[j+1].prezime);
                studenti[j].br_ocjena=studenti[j+1].br_ocjena;
                niz[j]=niz[j+1];
                for(k=0; k<49; k++){
                    studenti[j].ocjene[k]=studenti[j+1].ocjene[k];
                             }
                        }
                vel--;
                i--;
            }
        }
        
        /* kreira pomocni niz studenata koji ce se sortirati */
        for(i=0; i<vel; i++){
            strcpy(pomoc[i].ime, studenti[i].ime);
            strcpy(pomoc[i].prezime, studenti[i].prezime);
            pomoc[i].br_ocjena=studenti[i].br_ocjena;
            for(j=0; j<49; j++){
                pomoc[i].ocjene[j]=studenti[i].ocjene[j];
                }
        }    
    
        for(i=0; i<vel; i++){
                index=i;
                for(j=i; j<vel; j++){
                if(niz[j]>niz[index])index=j;
                }
                temp=niz[i];
                niz[i]=niz[index];
                niz[index]=temp;
                strcpy(pomocno_ime, pomoc[i].ime);
                strcpy(pomoc[i].ime, pomoc[index].ime);
                strcpy(pomoc[index].ime, pomocno_ime);
                strcpy(pomocno_prezime, pomoc[i].prezime);
                strcpy(pomoc[i].prezime, pomoc[index].prezime);
                strcpy(pomoc[index].prezime, pomocno_prezime);
                pomoc[i].br_ocjena=pomoc[index].br_ocjena;
                for(j=0; j<49; j++){
                    pomoc[i].ocjene[j]=pomoc[index].ocjene[j];
                }
            }
    /* ispisivanje studenata redom po prosjecima od najveceg ka najmanjem */
    for(i=0; i<vel; i++){
            if(i>=1 && strcmp(pomoc[i].prezime, pomoc[i-1].prezime)==0 && strcmp(pomoc[i].ime, pomoc[i-1].ime)==0)continue;
            else printf("%s %s\n",pomoc[i].prezime, pomoc[i].ime);
    }
    return vel;
}

int main(){
    int vel=0,i=0;
    float prosjek=0;
    struct Student studenti[100];
    printf("Unesi broj studenata: ");
    scanf("%d",&vel);
    printf("Unesi studente: \n");
    for(i=0; i<vel; i++){
        studenti[i]=unesi_podatke();
    }
    printf("Unesite prosjek: \n");
    scanf("%f",&prosjek);
    printf("Velicina nakon izbacivanja: %d",genijalci(studenti, vel, prosjek));
    return 0;
}
