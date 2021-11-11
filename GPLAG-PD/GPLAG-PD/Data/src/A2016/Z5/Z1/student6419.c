#include <stdio.h>
#include <math.h>
#define E 0.0001
void unesi(char niz[], int velicina) {
    char znak = getchar();
    if(znak=='\n')znak=getchar();
    int i = 0;
    while(i<velicina-1 && znak!='\n') {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}
struct Student {
    char ime[20];
    char prezime[20];
    int ocjene[50];
    int br_ocjena;
};
int genijalci(struct Student s[], int velicina, float prosjek) {
    int i, j, k, max=0, temp=0, prvi, drugi, treci, cetvrti, tmp, ispis=1;
    char *p;
    char *q;
    float pros, suma=0, niz[20];
    for(i=0; i<velicina; i++) {
        if(s[i].br_ocjena==0) temp=1;
        else
            for(j=0; j<s[i].br_ocjena; j++) {
                suma+=s[i].ocjene[j];
                if(s[i].ocjene[j]==5) {
                    temp=1;
                    break;
                }
            }
        if(temp==1) {
            pros=5.0;
            temp=0;
        }
        else
            pros=suma/s[i].br_ocjena;

        suma=0;
        if(pros<prosjek) {
            for(k=i; k<velicina-1; k++) {
                s[k]=s[k+1];
            }
            i--;
            velicina--;
        }
        else {
            niz[i]= pros;
        }
    }
    if(velicina) {
        if(velicina>=3) {
            for(i=0; i<velicina; i++) {
                if(niz[i]>max) {
                    max=niz[i];
                    prvi=i;
                }
            }
            max=0;
            for(i=0; i<velicina; i++) {
                if(i!=prvi && fabs(niz[i]-max)>E) {
                    max=niz[i];
                    drugi=i;
                }
            }
            max=0;
            for(i=0; i<velicina; i++) {
                if(i!=drugi && i!=prvi && fabs(niz[i]-max)>E) {
                    max=niz[i];
                    treci=i;
                }
            }
            max=0;
            for(i=0; i<velicina; i++) {
                if(i!=treci && i!=drugi && i!=prvi && fabs(niz[i]-max)>E) {
                    max=niz[i];
                    cetvrti=i;
                }
            }
            if(velicina>3) {
                if(fabs(niz[treci]-niz[cetvrti])<E) {
                    p=s[cetvrti].prezime;
                    q=s[treci].prezime;
                    while(*p!='\0') {
                        if(*p==*q) {
                            p++;
                            q++;
                            if(*p=='\0' && *q=='\0') temp=1;
                        }
                        else {
                            if(*p>*q) break;
                            else {
                                treci=cetvrti;
                                break;
                            }
                        }
                    }
                    if(temp==1) {
                        temp=0;
                        p=s[cetvrti].ime;
                        q=s[treci].ime;
                        while(*p!='\0') {
                            if(*p==*q) {
                                p++;
                                q++;
                            }
                            else{
                                if(*p>*q) break;
                                else {
                                    treci=cetvrti;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if(niz[prvi]>niz[drugi] && niz[drugi]>niz[treci]) {
                printf("%s %s\n%s %s\n%s %s\n", s[prvi].prezime, s[prvi].ime, s[drugi].prezime, s[drugi].ime, s[treci].prezime, s[treci].ime);
                ispis=0;
            }
            if(ispis) {
                if(fabs(niz[drugi]-niz[prvi])<E) {
                    p=s[drugi].prezime;
                    q=s[prvi].prezime;
                    while(*p!='\0') {
                        if(*p==*q) {
                            p++;
                            q++;
                            if(*p=='\0' && *q=='\0') temp=1;
                        }
                        else {
                            if(*p>*q) 
                                break;
                            else {
                                tmp=prvi;
                                prvi=drugi;
                                drugi=tmp;
                                break;
                            }
                        }
                    }
                    if(temp==1) {
                        temp=0;
                        p=s[drugi].ime;
                        q=s[prvi].ime;
                        while(*p!='\0') {
                            if(*p==*q) {
                                p++;
                                q++;
                            }
                            else{
                                if(*p>*q) 
                                    break;
                                else {
                                    tmp=prvi;
                                    prvi=drugi;
                                    drugi=tmp;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(fabs(niz[treci]-niz[drugi])<E) {
                    p=s[treci].prezime;
                    q=s[drugi].prezime;
                    while(*p!='\0') {
                        if(*p==*q) {
                            p++;
                            q++;
                            if(*p=='\0' && *q=='\0') temp=1;
                        }
                        else {
                            if(*p>*q) {
                                printf("%s %s\n%s %s\n%s %s\n", s[prvi].prezime, s[prvi].ime, s[drugi].prezime, s[drugi].ime, s[treci].prezime, s[treci].ime);
                                break;
                            }
                            else {
                                printf("%s %s\n%s %s\n%s %s\n", s[prvi].prezime, s[prvi].ime, s[treci].prezime, s[treci].ime, s[drugi].prezime, s[drugi].ime);
                                break;
                            }
                        }
                    }
                    if(temp==1) {
                        temp=0;
                        p=s[treci].ime;
                        q=s[drugi].ime;
                        while(*p!='\0') {
                            if(*p==*q) {
                                p++;
                                q++;
                                if(*p=='\0'  && *q=='\0')
                                    printf("%s %s\n%s %s\n%s %s\n", s[prvi].prezime, s[prvi].ime, s[drugi].prezime, s[drugi].ime, s[treci].prezime, s[treci].ime);
                            }
                            else{
                                if(*p>*q) {
                                    printf("%s %s\n%s %s\n%s %s\n", s[prvi].prezime, s[prvi].ime, s[drugi].prezime, s[drugi].ime, s[treci].prezime, s[treci].ime);
                                    break;
                                }
                                else {
                                    printf("%s %s\n%s %s\n%s %s\n", s[prvi].prezime, s[prvi].ime, s[treci].prezime, s[treci].ime, s[drugi].prezime, s[drugi].ime);
                                    break;
                                }
                            }
                        }
                    }
                }
                else
                    printf("%s %s\n%s %s\n%s %s\n", s[treci].prezime, s[treci].ime, s[prvi].prezime, s[prvi].ime, s[drugi].prezime, s[drugi].ime);
            }
        }
        else if(velicina==2) {
            for(i=0; i<velicina; i++) {
                if(niz[i]>max) {
                    max=niz[i];
                    prvi=i;
                }
            }
            max=0;
            for(i=0; i<velicina; i++) {
                if(i!=prvi && niz[i]>max) {
                    max=niz[i];
                    drugi=i;
                }
            }
            if(fabs(niz[drugi]-niz[prvi])<E) {
                p=s[drugi].prezime;
                q=s[prvi].prezime;
                while(*p!='\0') {
                    if(*p==*q) {
                        p++;
                        q++;
                        if(*q=='\0' && *p=='\0') temp=1;
                    }
                    else {
                        if(*p>*q) {
                            printf("%s %s\n%s %s\n", s[prvi].prezime, s[prvi].ime, s[drugi].prezime, s[drugi].ime);
                            break;
                        }
                        else {
                            printf("%s %s\n%s %s\n", s[drugi].prezime, s[drugi].ime, s[prvi].prezime, s[prvi].ime);
                            break;
                        }
                    }
                }
                if(temp==1) {
                    temp=0;
                    p=s[drugi].ime;
                    q=s[prvi].ime;
                    while(*p!='\0') {
                        if(*p==*q) {
                            p++;
                            q++;
                        }
                        else{
                            if(*p>*q) {
                                printf("%s %s\n%s %s\n", s[prvi].prezime, s[prvi].ime, s[drugi].prezime, s[drugi].ime);
                                break;
                            }
                            else {
                                printf("%s %s\n%s %s\n", s[drugi].prezime, s[drugi].ime, s[prvi].prezime, s[prvi].ime);
                                break;
                            }
                        }
                    }
                }
            }
            else {
                printf("%s %s\n%s %s\n", s[drugi].prezime, s[drugi].ime, s[prvi].prezime, s[prvi].ime);
            }
        }
        else if(velicina==1) {
            printf("%s %s\n", s[0].prezime, s[0].ime);
        }
    }
    return velicina;
}
struct Student unos_studenta() {
    struct Student s;
    int i;
    printf("Unesite ime: ");
    unesi(s.ime, 20);
    printf("Unesite prezime: ");
    unesi(s.prezime, 20);
    printf("Unesite broj ocjena: ");
    scanf("%d", &s.br_ocjena);
    printf("Unesite ocjene: ");
    for(i=0; i<s.br_ocjena; i++) {
        scanf("%d", &s.ocjene[i]);
    }
    return s;
}
void ispis_studenta(struct Student s) {
    printf("%s %s\n", s.prezime, s.ime);
}
int main() {
    struct Student studenti[100];
    int broj=1, i=0, j, temp;
    do {
        printf("Za unos studenta pritisnite 1, za ispis 2, za izlaz 0!\n");
        scanf("%d", &broj);
        if(broj==0) return 0;
        else if(broj==1) {
            studenti[i]=unos_studenta();
            i++;
        }
        else if(broj==2) {
            temp=genijalci(studenti, i, 7);
        }
        else {
            printf("Unijeli ste pogresan broj!");
            return 0;
        }
    }while(broj!=0);
    return 0;
}
