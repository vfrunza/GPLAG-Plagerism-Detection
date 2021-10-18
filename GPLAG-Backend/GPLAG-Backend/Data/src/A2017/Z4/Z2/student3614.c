#include <stdio.h>

void unesi (char niz[], int velicina)
{
    char znak=getchar();
    if (znak=='\n') znak=getchar();
    int i=0;
    while (i<velicina-1 && znak!='\n') {
        niz[i]=znak;
        i++;
        znak=getchar();
    }
    niz[i]='\0';
}

int provjeri_duzine (char* recenica, int* niz, int velicina)
{
    /*int* b=niz;*/
    int duzina=0;
    int pom;
    char* s=recenica;
    int* b=velicina;
    while(b<velicina) {
        while (*s!='\0') {
            if ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
                while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
                    duzina++;
                    s++;
                }
                int* b=niz;
                if (*b==duzina) {
                    pom=1;
                    b++;
                } else pom=0;
            }
            s++;
        }
    }
    if (pom==1) return 1;
    else return 0;
}

int main()
{
    char recenica [100];
    int niz[100];
    int velicina, i;
    printf ("Unesite recenicu: ");
    unesi(recenica, 100);
    printf ("Unesite velicinnu niza: ");
    scanf ("%d", &velicina);
    for (i=0; i<velicina; i++) {
        scanf ("%d", &niz[i]);
    }
    if (provjeri_duzine(recenica,niz,velicina)==1) {
        printf ("Tacno!");
    } else {
        printf("nije tacno!");
    }
    return 0;
}