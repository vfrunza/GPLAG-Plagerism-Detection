#include <stdio.h>

int DajBrojPonavljanja (char* tekst, char znak)
{
    int brojac = 0;
    while (*tekst != '\0')
    {
        if (*tekst++ == znak)
        {
            brojac++;
        }
    }
    return brojac;
}

int DajSljedeciBroj (char* tekst, int minPonavljanja, int maxPonavljanja)
{
    char* pocetakTeksta = tekst++;
    while (*tekst != '\0')
    {
        int trenutni = DajBrojPonavljanja (pocetakTeksta, *tekst);
        if (trenutni > minPonavljanja && trenutni < maxPonavljanja)
            minPonavljanja = trenutni;
        tekst++;
    }
    return minPonavljanja;
}

void PoredajUTablicu (char* tekst, char* tablica)
{
    char* pq = tablica;
    int maxBrPonavljanja = 0, minBrPonavljanja, brPonavljanja, i, DaLiJeUtablici;
    char* pocetakTeksta = tekst, *pocetakTablice, *pokNaTablicu, *h;
    char temp;
    
    while (*pq != '\0') *pq++ = '\0';
    /*Pronadje koliko puta se pojavljuje znak koji je najcesci */
    while (*tekst != '\0')
    {
        brPonavljanja = DajBrojPonavljanja(pocetakTeksta, *tekst);
        if (brPonavljanja > maxBrPonavljanja)
            maxBrPonavljanja = brPonavljanja;
        tekst++;
    }
    tekst = pocetakTeksta;
    /*Pronadje koliko puta se pojavljuje znak kojeg ima najmanje */
    minBrPonavljanja = maxBrPonavljanja;
    while (*tekst != '\0')
    {
        brPonavljanja = DajBrojPonavljanja(pocetakTeksta, *tekst);
        if (brPonavljanja < minBrPonavljanja)
            minBrPonavljanja = brPonavljanja;
        tekst++;
    }

    tekst = pocetakTeksta;
    pokNaTablicu = tablica;
    while (maxBrPonavljanja > DajSljedeciBroj(tekst, minBrPonavljanja, maxBrPonavljanja))
    {
	    /*tekst = pocetakTeksta;*/
        while (*tekst != '\0')
        {
            int JeLiSeDesioBreak = 0;
            if (DajBrojPonavljanja(pocetakTeksta, *tekst) == maxBrPonavljanja)
            {
                pocetakTablice = tablica;
                /* Ako je najvece ponavljanje 3 i ako se neko slovo ponavlja 3 puta onda treba proci kroz tablicu i vidjeti da li se ono vec nalazi u tablici*/
                while (*pocetakTablice != '\0')
                {
                    if (*pocetakTablice == *tekst)
                    {
                        JeLiSeDesioBreak = 1;
                        break;
                    }
                    pocetakTablice++;
                }
                if (!JeLiSeDesioBreak)
                {
                    *pocetakTablice = *tekst;
                    pocetakTablice++;
                    pocetakTablice = '\0';
                }
            }
            tekst++;
        }
        /* EH SAD TREBA SORTIRATI SVE OVE STO SE POJAVE MAX BROJ PUTA PO ASCII */

        h = pokNaTablicu;
        while (*pokNaTablicu != '\0')
        {
            pocetakTablice = h;
            while (*pocetakTablice != '\0')
            {
                if (*pocetakTablice > *pokNaTablicu)
                {
                    temp = *pocetakTablice;
                    *pocetakTablice = *pokNaTablicu;
                    *pokNaTablicu = temp;
                    pokNaTablicu--;
                    break;
                }
                pocetakTablice++;
            }
            pokNaTablicu++;
        }
        tekst = pocetakTeksta;
        maxBrPonavljanja = DajSljedeciBroj(tekst, minBrPonavljanja, maxBrPonavljanja);
    }
    /* OVDJE SAD IDE PASTE DIJELA KADA OSTANE JOS 1 ZNAK, CARE */
   while (*tekst != '\0')
    {
        int JeLiSeDesioBreak = 0;
        if (DajBrojPonavljanja(pocetakTeksta, *tekst) == maxBrPonavljanja)
        {
            pocetakTablice = tablica;
            /* Ako je najvece ponavljanje 3 i ako se neko slovo ponavlja 3 puta onda treba proci kroz tablicu i vidjeti da li se ono vec nalazi u tablici*/
            while (*pocetakTablice != '\0')
            {
                if (*pocetakTablice == *tekst)
                {
                    JeLiSeDesioBreak = 1;
                    break;
                }
                pocetakTablice++;
            }
            if (!JeLiSeDesioBreak)
            {
                *pocetakTablice = *tekst;
                pocetakTablice++;
                pocetakTablice = '\0';
            }
        }
        tekst++;
    }
    /* SADA JOS POSLOZI OVAJ DIO STO STO JE OSTAO ODNOSNO KAD SE DESI SLJEDECI == MAX */
    h = pokNaTablicu;
    while (*pokNaTablicu != '\0')
    {
        pocetakTablice = h;
        while (*pocetakTablice != '\0')
        {
            if (*pocetakTablice > *pokNaTablicu)
            {
                temp = *pocetakTablice;
                *pocetakTablice = *pokNaTablicu;
                *pokNaTablicu = temp;
                pokNaTablicu--;
                break;
            }
            pocetakTablice++;
        }
        pokNaTablicu++;
    }
    /* Sada su u tablici svi znakovi iz stringa poredani kako treba, ali sta je sa onim ostalim ?
        Strpite se, molim vas, evo sad ce doktor da pogeda..*/
    for (i = 32; i < 127; i++)
    {
        char t = i;
        DaLiJeUtablici = 0;
        pocetakTablice = tablica;
        while (*pocetakTablice != '\0')
        {
            if (*pocetakTablice == t)
                DaLiJeUtablici = 1;
            pocetakTablice++;
        }
        if (!DaLiJeUtablici)
        {
            while (*pocetakTablice != '\0')
                pocetakTablice++;
            *pocetakTablice++ = t;
            *pocetakTablice = '\0';
        }
    }
}

int DajPozicijuUtablici (char* tablica, char l)
{
    int pozicija = 0;
    while (*tablica != '\0')
    {
        if (*tablica == l)
            return pozicija;
        pozicija++;
        tablica++;
    }
    return pozicija;
}

char* kodiraj (char* tekst, char* tablica)
{
    char* p = tekst;
    PoredajUTablicu(tekst,tablica);
    while (*tekst != '\0')
    {
        *tekst = (char)(126 - DajPozicijuUtablici(tablica,*tekst));
        tekst++;
    }
    return p;
}

char* dekodiraj (char* tekst, char* tablica)
{
    char* p = tekst;
    int a;
    while (*tekst != '\0')
    {
        a = 126 - *tekst;
        *tekst = tablica[a];
        tekst++;
    }
    return p;
}

int main()
{
    char s[] = "ZAJKO jede malu djecu";
    char tablica[250] = "";
    char* d;
    char* p = kodiraj(s,tablica);
    while (*p != '\0')
        printf ("%c", *p++);
    printf ("\n");
    d = dekodiraj(s,tablica);
    while (*d != '\0')
        printf ("%c", *d++);
    
    
    return 0;
    
}
