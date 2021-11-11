/*Napisati funkciju sa prototipom:

char* izbaci_najcescu(char* s)

Funkcija treba iz primljenog stringa koji predstavlja neki tekst izbaciti riječ koja se u tekstu ponavlja najviše puta. Treba izbaciti 
sva ponavljanja te riječi u stringu. Riječ se definiše kao niz velikih i malih slova. Tako npr. tekst "auto-stop" posmatramo kao dvije 
riječi jer se u sredini nalazi znak minus koji nije slovo. Funkcija ne treba praviti razliku između velikih i malih slova (riječi 
"primjer", "PRIMJER" i "Primjer" se trebaju brojati kao tri ponavljanja iste riječi).

Funkcija treba vratiti pokazivač na početak primljenog stringa radi lakšeg lančanog pozivanja. Ukoliko se u tekstu nalazi više riječi 
koje se ponavljaju isti broj puta, funkcija treba izbaciti onu od najčešćih riječi koja je najbliža početku stringa. Prilikom izbacivanja 
riječi ne treba izbacivati okolne razmake i ostale znakove. Ukoliko primljeni string ne sadrži niti jednu riječ funkcija ne treba uraditi 
ništa.

Pri rješavanju zadatka nije dozvoljeno koristiti funkcije iz biblioteka string.h, stdlib.h kao ni funkcije sprintf i sscanf iz biblioteke 
stdio.h.

*/

#include <stdio.h>

void unesi(char niz[], int velicina) {
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

int duzina(char* s){
    char* temp;
    int duz=0;
    
    while (*s++)
        duz++;
    s=temp;
    return duz;
}


int iste(char *s1,char *s2){

while (*s1 != '\0' && *s2!='\0'){
        char c1=*s1;
        char c2=*s2;
        if(c1>= 'a')
            c1-= 'a'-'A';
        if(c2>='a')
            c2-='a'-'A';
        if(c1<c2)
            return 0;
        if (c1>c2)
            return 0;
        s1++;
        s2++;
    }
    if(*s1!='\0') 
        return 0;
    if(*s2!='\0')
        return 0;
        
    return 1;
}

int broj_rijeci(char *s){
    int broj = 0;
    char* pocetak=s;
    int razmak=1,broj_rijeci;
    
        while ( *s != '\0')	{
            if(*s==' ')
                razmak=1;
            else if(razmak==1){
                razmak=0;
                broj++;
            }
        
            s++;
        }
            
    return broj;
}

void i_ta_rijec (char *s, int num,char* rijec){
    int razmak=0,broj_rijeci=0;
    char *pocetak;
    char *temp=s;
    
    while (*s != '\0'){
        if (*s == ' ' || *s=='-')
            razmak=1;
        else if (razmak==1){
            razmak=0;
            broj_rijeci++;
            if(broj_rijeci==num) pocetak=s;
            if(broj_rijeci==num+1){
                while(*pocetak!=' ' && pocetak!='-'){
                    *rijec=*pocetak;
                    rijec++;
                    pocetak++;
                }
            }
        }
        s++;
    }
    s=temp;
}
    
int broj_ponavljanja(char *s,char *rijec){
    int i=0;
    int broj_ponavljanja=0;
    int br_rijeci = broj_rijeci(s);
    
    
   for(i=1; i<=br_rijeci;i++){
       char i_ta[20]={0};
      i_ta_rijec(s,i,i_ta);
       
         if(iste(i_ta,rijec))
            broj_ponavljanja++;
    }
    return broj_ponavljanja;
}
    
void napravi_histogram(char *recenica, int *histogram){
    int i=0;
    int br_rijeci=broj_rijeci(recenica);
    for (i=1; i<=br_rijeci;i++){
        char i_ta[20]={0};
        i_ta_rijec(recenica,i,i_ta);
        histogram[i-1]=broj_ponavljanja(recenica,i_ta);
    }
}

int vrati_najveci(int *histogram,int broj){
    int max=0,i=0;
    for (i=0; i<broj ; i++) {
        if ( histogram [i] > max )
        max = histogram [i];
        }
    
    return max;
}



void izbaci_rijec (char *s, int n)	{
    char* pocetak;
    char *temp=s ;
    int razmak = 1,broj_rijeci= 0;
        while ( *s != '\0')	{
            if(*s==' ')
            razmak = 1;

    else if ( razmak == 1)	{
        razmak = 0;
        broj_rijeci++;
    if ( broj_rijeci == n)	pocetak=s;
    if (broj_rijeci==n+1) {
            while (*pocetak++= *s++);
            return;
        }
}
        s++;

        }
s=temp;
if(broj_rijeci==n) *pocetak='\0';
}


char* izbaci_najcescu(char *s){
    char* temp=s;
    char prva_rijec[20]={0};
    char temp_rijec[20]={0};
    int histogram[50]={0},i=0,najveci=0,br_rijeci=0,izbaceno=0,prva=0;
    
    
    if (duzina(s) == 0) return s;
    br_rijeci=broj_rijeci(s);
        if(br_rijeci!=0){
            napravi_histogram(s,histogram);
            najveci=vrati_najveci(histogram,br_rijeci);
            if(najveci==0) return temp;
        }
        if(br_rijeci!=0 && duzina(s)!=0){
            napravi_histogram(s,histogram);
            najveci=vrati_najveci(histogram,br_rijeci);
            for (i=0; i<br_rijeci;i++){
                if(histogram[i]== najveci){
                    prva=i;
                    break;
                }
            }
            i_ta_rijec(s,prva+1,prva_rijec);
            for (i=0;i<br_rijeci;i++){
                i_ta_rijec(s,i+1,temp_rijec);
                    if(histogram[i]==najveci && iste(prva_rijec,temp_rijec)!= 1){
                        histogram [i]--;
                    }
                
            }
            for(i=0;i<br_rijeci;i++){
                if(histogram[i]==najveci){
                    izbaci_rijec(s,i+1-izbaceno);
                    izbaceno;
                    
                }
                
                
            }
        }
    
    s=temp;
    return s;
    
    
}
	
int main() {
	char tekst [200];
	char rijec[20]={0};
	char test[]="sto Je danas JE lijep i dANas jE auto-stop Danas suncan dan";
	int histogram[50]={0},i=0;
	
	printf("Unesite tekst: \n");
	unesi(tekst,200);

	
	
    printf("'%s'", izbaci_najcescu(tekst));
	
	return 0;
}
