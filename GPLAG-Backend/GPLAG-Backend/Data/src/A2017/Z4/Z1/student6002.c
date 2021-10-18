#include <stdio.h>

void unesi(char niz[], int velicina)
{
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

char* ubaci_broj (char* tekst, int broj)
{
    char *p = tekst;
    int br = 0;
    while(broj != 0) {
        broj /= 10;
        br++;
    }
    while (*tekst != '\0') {
        if (*tekst == ' ') {
            while(*p != '\0')p++;
            while (p > tekst) {
                *(p + br) = *p;
                p--;
            }
        }
    }
    tekst = p;
    return tekst;
}

int main()
{
    int broj;
    char tekst[100];
    printf("Unesite tekst: ");
    unesi(tekst, 100);
    printf("Unesite broj: ");
    scanf("%d", &broj);
    printf("%s", ubaci_broj(tekst, broj));
    return 0;
}