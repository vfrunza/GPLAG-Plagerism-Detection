#include <stdio.h>
#include <math.h>
#include <string.h>
struct Datum {
    int dan, mjesec, godina
};
struct Uposlenik {
    char ime_prezime[50];
    struct Datum datum_rodjenja;
};
int PregledajPrezime(struct Uposlenik D,struct Uposlenik direktor)
{
    int Prezime=0,i,j;
    char PrvoPrezime[50]= {"AAAAAAAAAAAA"};;
    char* r=PrvoPrezime;
    char DrugoPrezime[50]= {"AAAAAAAAAAAA"};
    char* k=DrugoPrezime;
    char* p=D.ime_prezime;
    char* q=direktor.ime_prezime;
    while(*q!='\0') {
        if(*q==' ') {
            break;
        }
        q++;
    }
    while(*q!='\0') {
        *r=*q;
        r++;
        q++;
        if(*q=='-') {
            q++;
            while(*q!='\0') {
                *k=*q;
                k++;
                q++;
            }
        }
    }
    *k='\0';
    *r='\0';
    k=DrugoPrezime;
    r=PrvoPrezime;
    int naslo;
    int rezultat;
    while(*p!='\0') {
        if(*p==' ') {
            break;
        }
        p++;
    }
    p++;
    int kraj=strlen(PrvoPrezime)-1;
    int kraj2=strlen(DrugoPrezime)-1;
    while(*p!='\0') {
        if(*p==*(r+1) || *p==*(k+1)) {
            break;
        }
        p++;
    }
    if(*p=='-') {
        p++;
    }
    while(kraj!=0 || kraj2!=0) {
        if((*p==*(k+1) && *(p+1)==*(k+2) && *(p+2)==*(k+3)) || (*p==*(r+1) && *(p+1)==*(r+2) && *(r+2)==*(r+3))) {
            naslo=1;
            break;
        } else {
            naslo=0;
            break;
        }
        p++;
        kraj--;
        kraj2--;
    }
    int Brojac=0;
    kraj=strlen(PrvoPrezime)-1;
    kraj2=strlen(DrugoPrezime)-1;
    if(naslo=1) {
        r++;
        k++;
        while(Brojac<kraj || Brojac<kraj2) {
            if(*p!=*r && *p!=*k) {
                rezultat=0;
                break;
            } else rezultat=1;
            p++;
            r++;
            k++;
            Brojac++;
        }
        if((Brojac==kraj || Brojac==kraj2) && (*(p+1)<'a' || *(p+1)>'z')) {
            rezultat=1;
        } else rezultat=0;
    } else rezultat=0;
    if(rezultat==0) {
        return 0;
    }
    if(rezultat==1) return 1;
}
int DaniuGodinama(struct Datum datum1, struct Datum datum2)
{
    int Razlika=0,Rmjesec,Rdan,Rgodina,prestupna=0,RmjesecPravo=0,prestupna2=0;
    int mjeseci[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if(datum1.godina%400==0 && datum1.godina%100==0 || (datum1.godina%4==0 && datum1.godina%100!=0 && datum1.godina%400!=0) && datum1.godina!=1900) {
        prestupna++;
    }
    if(datum2.godina%400==0 && datum2.godina%100==0 || (datum2.godina%4==0 && datum2.godina%100!=0 && datum2.godina%400!=0)  && datum2.godina!=1900) {
        prestupna2++;
    }
    Rmjesec=datum1.mjesec-datum2.mjesec;
    int i;
    for(i=0; i<fabs(Rmjesec); i++) {
        RmjesecPravo=mjeseci[i]+RmjesecPravo;
    }
    if(Rmjesec==1 && datum2.mjesec==2 && prestupna==0 && prestupna2==0) {
        RmjesecPravo=27;
    }
    if (Rmjesec<0) {
        RmjesecPravo=-RmjesecPravo-prestupna-prestupna2;
    }
    Rdan=datum1.dan-datum2.dan;
    Rgodina=datum1.godina-datum2.godina;
    Rgodina=Rgodina*365;
    Razlika=Rgodina+RmjesecPravo+Rdan;
    if(prestupna==prestupna2 && datum2.mjesec==2 && prestupna==1) {
        Razlika=Razlika-prestupna-prestupna2;
    } else Razlika++;
    if(prestupna==0 && prestupna2==0) {
        Razlika--;
    }
    return Razlika;
}
int suzi_listu(struct Uposlenik* kandidati,int vel,struct Uposlenik direktor,int broj_dana)
{
    int BrojKandidata=vel;
    int Rezultat=0;
    int j;
    int i;
    int k;
    for(i=0; i<BrojKandidata; i++) {
        Rezultat=0;
        Rezultat=PregledajPrezime(kandidati[i],direktor);
        if(Rezultat==1) {
            while(Rezultat!=0) {
                i++;
                Rezultat=PregledajPrezime(kandidati[i],direktor);
            }
        }
        if(DaniuGodinama(direktor.datum_rodjenja,kandidati[i].datum_rodjenja)>broj_dana) {
            vel--;
            for(j=i; j<BrojKandidata-1; j++) {
                kandidati[j]=kandidati[j+1];
            }
            BrojKandidata--;
            i--;
        }
    }
    return vel;
}

int main()
{
    struct Uposlenik direktor = {"Mujo Mujic", {3, 1, 1982} };
    struct Uposlenik kandidati[7] = {
        { "Meho Mehic", { 31, 12, 1981 } },
        { "Pero Peric", { 1, 2, 1980 } },
        { "Sara Sarac", { 2, 2, 1980 } },
        { "Fata Mujicic", { 1, 2, 1976 } },
        { "Jozo Jozic", { 1, 1, 1982 } },
        { "Mijo Mijic", { 4, 3, 1979 } },
        { "Suljo Suljic", { 30, 12, 1981 } },
    };

    int novi_br = suzi_listu(kandidati, 7, direktor, 3);
    int i;
    printf("\nNakon suzenja liste:\n");
    for (i=0; i<novi_br; i++)
        printf("%s\n", kandidati[i].ime_prezime);
    return 0;
}
