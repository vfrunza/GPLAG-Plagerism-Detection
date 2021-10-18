#include <stdio.h>

char* kodiraj ( char* tekst, char* sifrarnik ) {
    
    char* pokazivac_teksta = tekst;
    char temp, privremeni_pokazivac;
    int broj_ponavljanja[96] = {0}, ASCII_vrijednosti[96], i, j, trenutni_index, privremeni_index;

    /* Primarno nam je prebrojati ponavljanja karaktera u tekstu a to cemo najlakse napraviti tako sto
    prodjemo kroz kompletan tekst i postavimo brojace za svaki karakter 
    Vazno je da indekse karaktera spasimo pomocu njihovih ASCII vrijednosti
    Zbog toga imamo:
    broj_ponavljanja[privremeni_pokazivac - 32]++;
    */
    
    while ( *pokazivac_teksta) {
        
        privremeni_pokazivac = *pokazivac_teksta;
        
        broj_ponavljanja[ privremeni_pokazivac - 32 ]++;
        
        pokazivac_teksta++;
        
    }
    
    /* Petlja ispod sluzi samo da bi svakom clanu niza ASCII_vrijednosti dodijelili ASCII vrijednost po redu u ASCII tablici */
    
    for ( i = 0; i < 96; i++ ) {

        ASCII_vrijednosti[i] = i + 32;

    }
    
    /* Najbitniji dio ovo zadatka je sortiranje ova dva niza s kojima cemo u stvari kodirati sto radimo na slijedeci nacin */
    
    for ( i = 0; i < 95; i++ ) {
        
        for ( j = i + 1; j < 96; j++ ) {
            
            if ( broj_ponavljanja[i] < broj_ponavljanja[j] ) {
                
                privremeni_index = broj_ponavljanja[i];
                broj_ponavljanja[i] =  broj_ponavljanja[j];
                broj_ponavljanja[j] = privremeni_index;
             
                /* Da bi uskladili to da nam se clan koji se najvice puta ponavlja nalazi na istom indexu kao i nejgova ASCII vrijednost
                moramo ova dva niza uskladiti "simultano" */
                
                privremeni_index = ASCII_vrijednosti[i];
                ASCII_vrijednosti[i] = ASCII_vrijednosti[j];
                ASCII_vrijednosti[j] = privremeni_index; 

            }

        }

    }
    
    /* U narednom dijelu pravimo sifrarnik koji je u stvari string karaktera koji ovisi od ASCII_vrijednosti */ 
    
    for ( i = 0; i < 96; i++ ) {
        
        *sifrarnik = ASCII_vrijednosti[i];
        
        sifrarnik++;

    }
    
    *sifrarnik = '\0'; /* Zavrsen string */
    
    pokazivac_teksta = tekst; /* Vratimo pokazivac na pocetak stringa */ 
    
    /* Naredni dio ce u stvari uraditi kodiranje gdje ce izvrsiti promjene ASCII vrijednosti karaktera kako je naznaceno u zadatku */
    
    while ( *pokazivac_teksta ) {
        
        temp = *pokazivac_teksta;
        
        for ( i = 0; i < 96; i++ ) {
            
            if ( ASCII_vrijednosti[i] == temp ) {
                
                trenutni_index = i;
                
                break;

            }
            
        }
        
        *pokazivac_teksta = 126 - trenutni_index; 
        
         pokazivac_teksta++;

    }

	return tekst;

}

char* dekodiraj ( char* tekst, char* sifrarnik ) {
    
    /* U sustini ova funkcija ce raditi obratno od funkcije kodiraj pa ce se i kod otprilike tako ponasati */
    
    char* pokazivac_teksta = tekst;
    char temp;
    int ASCII_vrijednosti[96] = {0}, i = 0, trenutni_index;
    
    while ( *sifrarnik && i < 96 ) {
        
        ASCII_vrijednosti[i] = *sifrarnik;
        
        i++;
        sifrarnik++;
        
    }
    
    /* Dio ispod u stvari mijenja karaktere iz sifriranog koda na slican nacin kao i petlja u funckiji kodiraj
    pa je prekopirano i doradjeno */
    
    while ( *pokazivac_teksta ) {
        
         temp = *pokazivac_teksta;
        
        for ( i = 0; i < 96; i++ ) {
            
            if ( ASCII_vrijednosti[i] == temp ) {
                
                trenutni_index = i;
                
                break;

            }
            
        }
        
        /* Ovdje trenutni karakter mijenjamo obrnuto pa ga fakticni mijenjamo kao jednacinu
        Kako nam je i kretalo od 0 a trebalo nam je 32 dodali smo 32 u pelji u funkciji kodiraj pa cemo to ovjde oduzeti,
        a posto je najvisa vrijednost znaka koji mozemo koristiti 126(ne 128 kao sto je bilo napisano prvi put kada program nije radio)
        od toga cemo oduzeti 32 i vrijednost trenutnog indexa koju smo odredili u petlji iznad
        */
        
        *pokazivac_teksta = ASCII_vrijednosti[ 126 - 32 - trenutni_index ]; 
        
         pokazivac_teksta++;
        
    }
    
    return tekst;
    
}

int main() {
    
    char tekst[] = "LLMLNLNMONM";
    char sifrarnik[100] = "";
    
    int i = 0;
    
    kodiraj(tekst, sifrarnik);
    printf("%s\n", tekst);
    
    for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
	
	return 0;
    
}