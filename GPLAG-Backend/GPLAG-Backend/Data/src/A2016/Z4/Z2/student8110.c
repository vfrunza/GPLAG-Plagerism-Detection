#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char* kodiraj(char* s1, char* s2) {
    char *reset1=s1;
    char znak=' ',naj_pon_slovo[96],poredbeni[97];
    int tablica[96]={0},max,i=-1,j,index,br=-1;
    while(*s1!='\0') {
        i=0;
        while(znak!='~') {
            if(znak==*s1) {
                tablica[i]++;
            }
            i++;
            znak++;
        }
        znak=' ';
        s1++;
    }
        
    for(i=0;i<96;i++) {
        max=0;
        index=-1;
        for(j=0;j<96;j++) {
            if(tablica[j]>max) {
                max=tablica[j];
                index=j;
            }
        }
        if(index!=-1) {
            br++;
            naj_pon_slovo[br]=index+32;
            tablica[index]=-1;
        }
    }
    br++;
        
    for(i=0;i<96;i++) {
        if(tablica[i]==0) {
            naj_pon_slovo[br]=i+32;
            br++;
        }
    }
    naj_pon_slovo[--br]='\0';
        
    znak='~';
    for(i=0;i<br;i++) {
        poredbeni[i]=znak;
        znak--;
    }
    poredbeni[i]='\0';
    s1=reset1;
    while(*s1!='\0') {
        for(i=0;i<br;i++) {
            if(*s1==naj_pon_slovo[i]) {
                break;
            }
        }
        *s1=poredbeni[i];
        s1++;
    }
    *s1='\0';
    i=0;
    while(i<br) {
        *s2=naj_pon_slovo[i];
        i++;
        s2++;
    }
    *s2='\0';
    s1=reset1;
    return reset1;
}


char* dekodiraj (char* s1, char* s2) {
    char* reset1=s1;
    char znak,poredbeni[97];
    int i;
    znak='~';
    for(i=0;i<96;i++) {
        poredbeni[i]=znak;
        znak--;
    }
    while(*s1!='\0') {
        for(i=0;i<96;i++) {
            if(*s1==poredbeni[i]) {
                break;
            }
        }
        *s1=*(s2+i);
        s1++;
    }
    return reset1;
}

int main() {
    char tekst[]="LLMLNLNMONM";
    char sifrarnik[100]="";
    printf("Unesite tekst za kodiranje: ");
    unesi(tekst, 100);
    kodiraj(tekst, sifrarnik);
    printf("%s", tekst);
    printf("\n%s", sifrarnik);
    dekodiraj(tekst, sifrarnik);
    printf("\n%s", tekst);
    return 0;
}