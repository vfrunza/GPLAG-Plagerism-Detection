#include <stdio.h>
#define limit 1000

void unesi(char niz[], int velicina){
	int i=0;
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	while (i < velicina - 1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}

int test_jednakosti (char* s1, char* s2){
    int istinitost;
    
    while (*s1 != '\0' || *s2 != '\0') {
        istinitost=0;
        
        if (*s1 == *s2) {
            istinitost = 1;
        }
        else{
            istinitost = 0; break;
        }
        s1++;
        s2++;
    }
    
    return istinitost;
}



char* izbaci_najcescu(char *s){
    char* reset = s;
    char* drugeRijeciPok = s;
    char* pocetak;
    char* kraj;
    char kopija[limit], trenutnaRijec[limit], drugeRijeci[limit], maxRijec[limit];
    int istinitost, l, max=0, brojac=0, i=0;
    
    /*Ako nije rijec... kraj programa*/
    if (*s == '\0') {
        return 0;
    }
    while (*s != '\0'){
        if ((*s >= 'A' && *s <= 'Z')||(*s >= 'a' && *s <= 'z')){
            l = 1;
            break;
        }
        else{
            l = 0;
        }
        s++;
    }
    if (l == 0){
        return reset;
    }
    s= reset;
    
    /*Pronaci rijec koja se najvise ponavlja*/
    /*1° Stvaranje kopije  stringa */
    while (*s != '\0'){
        kopija[i]=*s;
        s++;
        i++;
    }
    kopija[i]='\0';
    i=0;
    s=reset;
    
    /*2° Case sensitive: *predpostavka sve mala slova* */
    while (kopija[i]!='\0') {
        if (kopija[i] >= 'A' && kopija[i] <= 'Z'){
            kopija[i]+=32;
        }
        i++;
    } /*Formiran niz gdje su sva slova mala, prilikom rada, slova idu u temp i sa ovim se kompariraju.*/
    i=0;
    
    /*3° Brojanje rijeci; Prvo uzeti jednu rijec iz stringa, pa prebrojiti koliko puta je u stringu*/
    while (*s != '\0'){
        while(!((*s >= 'A' && *s <= 'Z')||(*s >= 'a' && *s <= 'z'))){
            s++;
        }
        while ((*s >= 'A' && *s <= 'Z')||(*s >= 'a' && *s <= 'z')){
            if (*s >= 'A' && *s <= 'Z'){
                *s = *s +32;
            }
            trenutnaRijec[i] = *s;
            s++;
            i++;
        }
        trenutnaRijec[i]='\0';
        /*Imamo rijec za komparaciju*/
        
        i=0;
        drugeRijeciPok = reset;
        /*Pronalazak i brojanje ponavljanja drugih rijeci*/
        while (*drugeRijeciPok != '\0'){
            while(!((*drugeRijeciPok >= 'A' && *drugeRijeciPok <= 'Z')||(*drugeRijeciPok >= 'a' && *drugeRijeciPok <= 'z'))){
                drugeRijeciPok++;
            }
            while ((*drugeRijeciPok >= 'A' && *drugeRijeciPok <= 'Z')||(*drugeRijeciPok >= 'a' && *drugeRijeciPok <= 'z')){
                if (*drugeRijeciPok >= 'A' && *drugeRijeciPok <= 'Z'){
                    *drugeRijeciPok = *drugeRijeciPok +32;
                }
                drugeRijeci[i] = *drugeRijeciPok;
                drugeRijeciPok++;
                i++;
            }
            drugeRijeci[i]='\0';
            i=0;
            istinitost = test_jednakosti(trenutnaRijec, drugeRijeci);
            if (istinitost){
                brojac++;
            }
        }
        
        /*Postavljanje max vrijednosti i rijeci*/
        if (brojac > max){
            max = brojac;
            while (trenutnaRijec[i] != '\0'){
                maxRijec[i] = trenutnaRijec[i];
                i++;
            }
            maxRijec[i] = '\0';
        }
        i=0;
        brojac=0;
        
    }
    
    /*Izbaciti sva ponavljanja te rijeci u tekstu*/
    s = reset;
    i=0;
    
    while(*s != '\0'){
        /*ako nije slovo, idi dalje*/
        while(!((*s >= 'A' && *s <= 'Z')||(*s >= 'a' && *s <= 'z'))){
            s++;
        }
        pocetak = s;
        while ((*s >= 'A' && *s <= 'Z')||(*s >= 'a' && *s <= 'z')){
            if (*s >= 'A' && *s <= 'Z'){
                *s = *s +32;
            }
            trenutnaRijec[i] = *s;
            s++;
            i++;
        }
        kraj = s;
        trenutnaRijec[i]='\0';
        i=0;
        istinitost = test_jednakosti(maxRijec,trenutnaRijec);
        
        if (istinitost) {
            while (pocetak != kraj){
            *pocetak = '~';
            pocetak++;
            }
        }
    }
    s = reset;
    
    while (*s != '\0'){
       if (*s == '~'){
           pocetak = s;
           do {
               *pocetak = *(pocetak+1);
               pocetak++;
           } while (*(pocetak) != '\0');
           *pocetak = '\0';
           
       }
       else{
           s++;
       }
    }

    
    return reset;
}

int main(){
    /*Unos teksta za kodiranje*/
    char tekst[limit];
    printf("Unesite tekst: ");
    unesi(tekst,limit);
    
    izbaci_najcescu(tekst);
    
    return 0;
}
