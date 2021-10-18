#include <stdio.h>

void najduzi_bp(char * s1, char * s2){
    char *cita = s1;
    char *kraj_rijeci = cita;
    char *pocetak_rijeci = cita;
    char *prvo_ponavljanje = cita;
    char *zapamti = cita;
    char *pocetak = cita;
    char *kraj = cita;
    int maks_brojac = 0;
    char slovo;
    while(*cita != '\0'){
        
        if((*cita >= 'A' && *cita <= 'Z') ||  (*cita >= 'a' && *cita <= 'z')){
            
            if(cita == s1 || *(cita -1) == ' ' || !((*(cita-1) >= 'A' && *(cita-1) <= 'Z') ||  (*(cita-1) >= 'a' && *(cita-1) <= 'z')) ){
                //printf("postavlja se pocetak rijeci i to %c\n", *cita);
                pocetak_rijeci = cita;
                prvo_ponavljanje = pocetak_rijeci;
                
            }
            if (cita == kraj_rijeci) {
                if(pocetak_rijeci == prvo_ponavljanje) prvo_ponavljanje = kraj_rijeci;
                //printf("Uslo gdje je sita==kraj_rijeci i to %c\n", *cita);
                if(prvo_ponavljanje - pocetak_rijeci > maks_brojac){
                    maks_brojac = prvo_ponavljanje - pocetak_rijeci;
                    pocetak = pocetak_rijeci;
                    kraj = prvo_ponavljanje;
                    //printf("Uslo gdje je ispunjen uslov i to %c je pocetak rijeci a %c je kraj rijeci\n", *pocetak_rijeci, *prvo_ponavljanje);
                }
            }
            
            zapamti = cita;
            
            slovo = *zapamti;
            //printf("postavlja se slovo za poredjenje i to  %c\n", *cita);
            if(slovo>='A' && slovo <= 'Z'){
                slovo = slovo + 'a' - 'A';
            }
            cita++;
            while(*cita != slovo && *cita != slovo -('a'-'A') &&  *cita != ' ' && ((*cita >= 'A' && *cita <= 'Z') ||  (*cita >= 'a' && *cita <= 'z')) && *cita !='\0'){
                //printf("pomjera se cita i to %c\n", *cita);
                cita++;
                
            }
            
            if(*cita == ' ' || *cita == '\0' || !((*cita >= 'A' && *cita <= 'Z') ||  (*cita >= 'a' && *cita <= 'z'))){
                kraj_rijeci = cita -1;
                //printf("postavlja se kraj rijeci rijeci i to %c\n", *kraj_rijeci);
                
            }
            else if(*cita == slovo || *cita == slovo -('a'-'A') ){
                //printf("uslo gdje je cita == slovo i to %c\n", *cita);
                if(prvo_ponavljanje - pocetak_rijeci < cita - zapamti){
                    prvo_ponavljanje = cita-1;
                    //printf("postavlja se prvo ponavljanje i to %c\n", *cita);
                }
            }
            
            cita = zapamti;
            //printf("vraca se cita i to %c\n", *cita);
            
        }
        cita ++;
    }
    
    while(pocetak != kraj){
        *s2++ = *pocetak++;
    }
    *s2++ = *kraj;
    *s2 = '\0';
}
int main(){
char niz[10];
        najduzi_bp ("_abCdeFgh@", niz);
        printf ("Niz: '%s'", niz);
        return 0;
}