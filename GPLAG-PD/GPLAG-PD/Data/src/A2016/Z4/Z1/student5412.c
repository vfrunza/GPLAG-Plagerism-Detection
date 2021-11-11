#include <stdio.h>

void unesi (char niz[], int velicina) //funkcija za unos stringa
{
    char znak = getchar();
    if(znak == '\n') znak = getchar();
    int i=0;
    while(i < velicina - 1 && znak != '\n')
    {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i] = '\0';
}

char *izbaci_najcescu(char *s)  //funkciija za izbacivanje rijeci koja se najcesce ponalja
{
    int rijec; 
	char *pocetak = s, *kraj = s; //pocetak i kraj stringa
	int razmak = 1, broj_rijeci = 0; 
    while (*s != '\0')
    {
        if (*s == ' ') //ako je razmak u stringu nastavi dalje kroz string
            razmak = 1;
        else if (razmak == 1)
        {
            razmak = 0;
            broj_rijeci++;
            if(broj_rijeci == rijec) //pise u autotestu da nije incijalizovano, zasto?
            {
		        pocetak=s;
		        kraj=s;
		        while(*kraj!='\0' && ((*kraj>='A' && *kraj<='Z') || (*kraj>='a' && *kraj<='z'))) kraj++;
		        while (*pocetak++=*kraj++);
		    }
        }
        s++;
    }
    *kraj = '\0';
    return kraj;
}

int main() 
{
    char recenica[100];
    
    printf ("Unesite recenicu: ");
    unesi(recenica, 100);
    
    //printf ("Izbaci najcescu %s", izbaci_najcescu(recenica));
    izbaci_najcescu(recenica);
	return 0;
}

