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


void najduzi_bp (char* s1, char* s2) {
    char* p=s1;
    char* p2=s1;
    char* p3=s1;
    char* podniz=s1;
    char* zamjena=s2;
    int brojactrenutni=0;
    int brojacprethodni=0;
    int prviputsepojavljuje=0;
    while (*p != '\0') {
        if (((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) && (p == s1 || *(p-1)<'A' || (*(p-1)>'Z' && *(p-1)<'a') || (*(p-1)>'z'))) {
            p2=p;
            brojactrenutni=0;
            while ((*p2 >= 'A' && *p2 <= 'Z') || (*p2 >= 'a' && *p2 <= 'z')) {
                p3=p;
                brojactrenutni++;
                while (p3!=p2) {
                    if (*p2 == *p3 || *p2 == *p3 + 32 || *p2 == *p3 - 32) {
                        brojactrenutni--;
                        break; 
                    }
                    p3++;
                }
                p2++;
            }
        }
        
        if (brojactrenutni > brojacprethodni) {
            brojacprethodni=brojactrenutni;
            podniz=p;
        }
        p++;
    }
    
    p2 = podniz;
    while ((*p2 >= 'A' && *p2 <= 'Z') || (*p2 >= 'a' && *p2 >= 'Z')) {
        prviputsepojavljuje=1;
        p3=podniz;
        while (p3 != p2) {
            if (*p3 == *p2 || *p2 == *p3 + 32 || *p2 == *p3 - 32) {
                prviputsepojavljuje=0;
            }
            p3++;
        } 
        if (prviputsepojavljuje==1) {
            *zamjena=*p2;
            zamjena++; }
        
    p2++;
} 
*zamjena='\0';
}


int main () {
    char s1[100], s2[100];
    printf ("Unesi recenicu: ");
    unesi (s1,100);
    najduzi_bp(s1,s2);
    return 0;
} 