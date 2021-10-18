#include <stdio.h>

/*Funkcija provjerava da li je unos znak*/
int je_li_znak(char a){
    return (a!=' ' && a!='\0'); /*rijec je omedjena razmakom, pocetkom ili krajem stringa*/
}

/*Funkcija u stringu trazi rijec; vraca pokazivac na mjesto gdje pocinje ta rijec u stringu*/
char *nadji_rijec(char *string, char*rijec){
    char *pocetak_stringa=string;
    char *pocetak_rijeci=rijec;
    
    while(*string!='\0'){
        char *kretanje=string;
        int nadjena=1; /*pretpostavka da je rijec nadjena*/
        while(je_li_znak(*rijec) && *kretanje!='\0'){
            if(!(*rijec==*kretanje))
            nadjena=0; /*ako je ono na sta pokazuje string i rijec razlicito, rijec nije nadjena*/
            rijec++; 
            kretanje++; /*pomjeranje po stringu i rijeci*/
        }
        /*ako je nadjena provjera da li su uslovi zadovoljeni*/
        if(nadjena && !je_li_znak(*rijec) && (string==pocetak_stringa || !je_li_znak(*(string-1))) && !je_li_znak(*kretanje))
        return string; /*poslije rijeci mora biti razmak ili kraj recenice*/
        
        rijec=pocetak_rijeci;
        string++; 
    }
    return NULL;
}

/*Funkcija vraca duzinu rijeci*/
int duzina(char *rijec){
    int duz=0; /*brojac se povecava sve dok karakter na kojeg pokazuje zadovoljava uslove*/
    while(je_li_znak(*(rijec+duz))) /*uslovi odredjeni u f-ji je_li_znak*/
    duz++; 
    return duz;
}

/*Funckija nisu iste rijeci*/
int nisu_iste(char *rijec1, char *rijec2){
    while (*rijec1!='\0' && *rijec2!='\0') { /*provjera: da li su 2 rijeci identicne*/
        if(*rijec1!=*rijec2)
        return 1;
        rijec1++;
        rijec2++;
    }
    return(*rijec1!=*rijec2);
}

/*Funkcija mijenja rijeci odgovarajucim rijecima iz niza zamjene*/
char *zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci){
    
    int i=0;
    while(i<broj_rijeci){
        
        if(nisu_iste(*(rijeci+i),*(zamjene+i))) /*zamjenu vrsimo samo ako rijeci nisu iste*/
        {
            int razlika= duzina(*(rijeci+i))-duzina(*(zamjene+i)); /*poziv f-je duzina*/
            while(nadji_rijec(tekst,*(rijeci+i))) /*poziv f-je nadji rijec*/
            {
                char *kraj=tekst;
                while(*kraj!='\0')
                kraj++;
                char *pocetak=nadji_rijec(tekst,*(rijeci+i)); /*poziv f-je nadji rijec*/
                int j=0;
                if(razlika<0) { /*pomjeranje u desno*/
                    while(kraj+j!=pocetak){
                        *(kraj+j-razlika)=*(kraj+j);
                        j--;
                    }
                }
                else if(razlika>0){ /*pomjeranje u lijevo*/
                    while(kraj!=pocetak+j){
                        *(pocetak+j)=*(pocetak+razlika+j);
                        if(*(pocetak+j)=='\0') 
                        break; /*u slucaju da se ne pristupi nedeklarisanoj lokaciji*/
                        j++;
                    }
                }
                else ;
                
                int k=0;
                while(k<duzina(*(zamjene+i))){ /*nakon pomjeranja vrsi se zamjena*/
                    *(pocetak+k)=*(*(zamjene+i)+k);
                    k++; 
                }
            }
        }
        i++;
    }
    return tekst; /*f-ja vraca tekst*/
}

int main(){
    /*rijeci, zamjene i tekst*/
    char *rijeci[2]={ " ", "" };
    char *zamjene[2]= {" ", " " };
    char tekst[100]= " ";
    printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2)); /*Ispis*/
    
    return 0;
}
