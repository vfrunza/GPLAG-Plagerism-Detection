#include <stdio.h>

/*Funkcija provjerava da li je unos slovo ukljucujuci i veliko i malo*/
int je_li_slovo(char a){
    
    return((a>='A' && a<='Z') || (a>='a' && a<='z')); 
}

/*Funkcija trazi rijec*/
char *nadji_rijec(char *string, char *rijec){ 
    char *pocetak_stringa=string;
    char *pocetak_rijeci=rijec;
    
    while(*string!='\0'){
        char *kretanje=string;
        int nadjena=1; 
        while(je_li_slovo(*rijec) && *kretanje!='\0'){ /*uslov*/
            if(!(*rijec==*kretanje || *rijec+32==*kretanje || *rijec-32==*kretanje)) /*(*rijec) niz velikih i malih slova */
            nadjena=0; 
            rijec++; /*rijec se pomjera*/
            kretanje++; /*pomjeranje po stringu*/
        }
        if(nadjena && !je_li_slovo(*rijec) && (string==pocetak_stringa || !je_li_slovo(*(string-1))) && !je_li_slovo(*kretanje)) 
        return string;
        
        rijec=pocetak_rijeci;
        string++;
    }
    return NULL;
}

/*Funkcija brise rijec*/
void obrisi_rijec(char *string, char *rijec){
    int duzina=0;
    
    while(je_li_slovo(*(rijec+duzina))) 
        duzina++; /*dok je uslov ispunjen, duzina se pomjera*/
    char *pocetak=nadji_rijec(string, rijec); /*Poziv f-je nadji_rijec*/
    char *kretanje=pocetak;
    while(*(kretanje+duzina)!='\0'){
        *kretanje=*(kretanje+duzina);
        kretanje++; /*pomjeranje po stringu*/
    }
    *kretanje='\0';
}

/*Funkcija trazi najcescu rijec*/
char *najcesca_rijec(char *string){
    int max=0; /*max se postavlja se na 0*/
    int broj=0;
    char *pocetak=string;
    char *najcesca=string;
    char *rijec=string;
    char *nadjena=string;
    
    while(*rijec!='\0'){
        broj=0;
        string=pocetak;
        while(!je_li_slovo(*rijec)){ /*provjera*/
            if(*rijec=='\0')
            return najcesca;
            rijec++;
        }
        
        while(nadji_rijec(string,rijec)){
            broj++; /*broj ponavljanja rijeci se povecava*/
            string=nadji_rijec(string,rijec); /*Poziv f-je za pronalazak rijeci*/
            nadjena=string;
            while(je_li_slovo(*string))
            string++; 
            while (!je_li_slovo(*string) && *string!='\0')
            string++; 
            }
            
            if(broj>max){
                max=broj; /*max postaje jednako broju ponavljanja ako je uslov ispunjen*/
                najcesca=nadjena; /*najcesca rijec postaje nadjena*/
            }
            
            rijec++;
            while(je_li_slovo(*rijec))
            rijec++; 
    }
    return najcesca; /*F-ja vraca najcescu rijec*/
}

/*Funkcija trazi najvece ponavljanje, ista struktura kao u prethodnoj f-ji samo sto sada f-ja vraca max, a ne najcescu rijec*/
int najvece_ponavljanje(char *string){
    int max=0;
    int broj=0;
    char *pocetak=string;
    char *najcesca=string;
    char *rijec=string;
    char *nadjena=string;
    
    while(*rijec!='\0'){
        broj=0;
        string=pocetak;
        while(!je_li_slovo(*rijec)){
            if(*rijec=='\0')
            return max; /*F-ja vraca najvece ponavljanje*/
            rijec++;
        }
        
        while(nadji_rijec(string,rijec)){
            broj++;
            string=nadji_rijec(string,rijec); /*Poziv f-je za pronalazak rijeci*/
            nadjena=string;
            while(je_li_slovo(*string)) /*provjera*/
            string++;
            while(!je_li_slovo(*string) && *string!='\0') /*provjera*/
            string++;
        }
        
        if(broj>max){
            max=broj; /*max postaje broj ako je uslov ispunjen*/
            najcesca=nadjena;
        }
        rijec++;
        while(je_li_slovo(*rijec)) /*provjera*/
        rijec++;
    }
    return max; /*F-ja vraca max*/
}

/*Funkcija izabacuje najcescu rijeci*/
char *izbaci_najcescu(char *s){
    
    char *najcesca=najcesca_rijec(s); /*Poziv f-je najcesca rijec*/
    int ponavljanje=najvece_ponavljanje(s); /*Poziv f-je najvece ponavljanje*/
    int duzina=0;
    while(je_li_slovo(*(najcesca+duzina)))
    duzina++; /*duzina se pomjera*/
    while(ponavljanje>0){
        ponavljanje--;
        obrisi_rijec(s,najcesca); /*Poziv f-je obrisi rijec, brise se najcesca rijec*/
        najcesca=najcesca-duzina;
    }
    
    return s; 
    
}

int main(){
    
    char recenica[]="";
    char *d=izbaci_najcescu(recenica); /*Poziv f-je za izbacivanje najcesce rijeci*/
    printf("%s.",d); /*Izlaz programa-Ispis*/
    
    return 0; 
}

    
    
