#include <stdio.h>

void unesi (char niz[], int velicina)
{
    char znak = getchar();
    if (znak == '\n') znak = getchar ();
    int i = 0;
    while ( i<velicina - 1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar ();
    }

    niz[i] = '\0';
}

int duzina_rijeci (const char* s, char* znak)
{
    int brojac = 0, tmp;
    if (*znak >= 'A' && *znak <= 'Z')
        *znak += 'a' - 'A';
    while (*s != '\0') {
        tmp = *s;
        if (tmp >= 'A' && tmp <= 'Z')
            tmp += 'a' - 'A';
        if (tmp == *znak)
            brojac++;
        s++;
    }
    return brojac;
}

int provjeri_duzine (int duzine[], int velicina, char* string)
{   
    const char* q = string;
    char* p = string;
    int i,j;
    int duzine_rijeci; 
    
    while (*p != '\0'){
        if (*p == ' ' || (*p >= 36 && *p <= 47))
        p++;
        else
        duzine_rijeci = duzina_rijeci (q, p);
        p++;
    }
    for (i = 0 ; i < velicina ; i++){
    if (duzine_rijeci == duzine[velicina])
    j = 1;
    else 
    j = 0;
    }
    return j;
}

int main()
{
    char neki_tekst [100];
    int duz [100];
    printf ("Unesite tekst: ");
    unesi (neki_tekst, 100);
    printf ("Unesite duzine rijeci: ");
    
    do {
       
       scanf ("%d ", &duz[100]);  
       
    } while (duz[100] != -1);

    provjeri_duzine (duz, 100, neki_tekst);
    return 0;
}
