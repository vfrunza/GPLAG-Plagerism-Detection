#include <stdio.h>

int pozicija(char slovo,char niz[]){
    int i;
    
    for(i=0;i<=94;i++){
        if(niz[i] == slovo)return i;
    }
    
}

char *kodiraj(char *tekst,char *tablica){
    
    char *pocetak = tekst;
    char *poc = tablica;
    char slova[200];
    int niz[200] = {0};
    char *s = tekst;
    int i = 0;
    
    //napravit cemo prvo niz slova popunjen sa svim znakovima cije su asci vrijednosti izmedu 32 i 126
    for(i=32;i<=126;i++){
        slova[i-32] = i;
    }
    
   
    
    //sada cemo napravit niz intova u kojima se broje slova pa posto je prvo slovo u datom intervalu space to ce niz[0] biti onoliko koliko ima spacova
    while(*tekst != '\0'){
        
        int poz = (int)*tekst;
        niz[poz - 32]++;
        tekst++;
    }
    
   
   
   //sada cemo uz pomoc ova slova i niz poredati slova u tablicu prema ponavljanju
   
    int j,temp1;
    char temp2;
    
    //petlje za sortiranje
    
    for(i=0;i<=94;i++){
        for(j=i+1;j<=94;j++){
            
            //drugi uslov postavljamo ako je broj ponavljanja 2 slova ista ali onda ih poredimo po asci vrijednosima(od manjeg ka vecem npr MN)
            if(niz[j] > niz[i] || (niz[j] == niz[i] && slova[j] <  slova[i] )){
                
                //sortiramo intove
                temp1 = niz[i];
                niz[i] = niz[j];
                niz[j] = temp1;
                
                //sortiramo slova
                
                temp2 = slova[i];
                slova[i] = slova[j];
                slova[j] = temp2;
            }
        }
    }
    
    //for(i=0;i<=94;i++)printf("%c %d\n",slova[i],niz[i]);
    
    //sada tablica sadrzi sortiran niz slova prema broju ponavljanja
    for(i=0;i<=94;i++){
        *(tablica+i) = slova[i];
    }
    *(tablica+i) = '\0';
    
    
    //for(i=0;i<=94;i++)printf("%c \n",*(tablica+i));
    
    //sada zamijenjujemo znakove u primljenom stringu sa 126-pozicija u tablici
    
    //ako ne restartujemo tekst na pocetak necemo uraditi nikakve promjene na stringu(gore smo pomjerali tekst++)
    
    tekst = pocetak;
    
    while(*tekst != '\0'){
        *tekst = 126 - pozicija(*tekst,tablica);
        tekst++;
    }
    *tekst = '\0';
    
    return pocetak;
}


char *dekodiraj(char *tekst,char *tablica){
    char *pocetak = tekst;
    
    while(*tekst != '\0'){
       *tekst = tablica[126-*tekst];
        tekst++;
    }
    
    *tekst = '\0';
    return pocetak;
}


int main() {
	
	char niz[] = "LLMLNLNMONM";
	char tablica[200];
	kodiraj(niz,tablica);
    char *p=	dekodiraj(niz,tablica);
    
    printf("%s",p);
	
	return 0;
}
