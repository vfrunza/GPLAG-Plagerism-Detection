#include <stdio.h>
#include <math.h>
int duzina(int broj){
    int duz=0;
    while (broj!=0) {
        duz++;
        broj/=10;
     }
     return duz;
}

char* ubaci_broj(char* tekst,int broj){
    char *pozicija;
    char pomocni_char;
    char prethodni;
    int pozitivni;
    int temp;
    int duzina_temp;
    int pomak=duzina(broj);
    int duzina_broja = pomak;
    int ostatak;
    int razmaci_na_kraju=0;
    int privremeni_pomak;
    int i;
    
    char *kraj1 = tekst;
    while(*kraj1!='\0') kraj1++;
    kraj1--;
    while(*kraj1==' '){
        kraj1--;
        razmaci_na_kraju++;
    }
    kraj1++;
    *kraj1='\0';
    
    
    if (broj<0) {
        pomak++;
        pozitivni = broj*(-1);
    }
    else pozitivni = broj;
    //pomak++;
    
    pozicija=tekst;
    prethodni=*pozicija;
    pozicija++;
    
    if(*pozicija == '\0'){
        pozicija = NULL ;
    }
    
    while (pozicija) {
        temp = pozitivni;
        duzina_temp=duzina_broja;
        int privremeni;
        if(*pozicija==' ' && ((prethodni>='A' && prethodni<='Z')||(prethodni>='a' && prethodni<='z'))) {
            
            if(*(pozicija+1)==' ')privremeni_pomak=pomak;
            else privremeni_pomak = pomak+1;
            
            char *kraj = pozicija;
            while(*kraj!='\0') kraj++;
            while(kraj>pozicija){
                *(kraj+privremeni_pomak)=*kraj;
                kraj--;
            }
            pozicija++; 
            if(broj<0){
                *pozicija = '-';
                pozicija++;
            }
            
            while(duzina_temp>0){
                if(temp>9){
                    ostatak = pow(10, (duzina_temp-1));
                    privremeni = temp/ostatak;
                    pomocni_char = privremeni + '0';
                }
                else {
                    pomocni_char= temp +'0';
                }
                temp= temp % ostatak;
                duzina_temp--;
                *pozicija=pomocni_char;
                pozicija++;
            }
            if(privremeni_pomak!=pomak){
                *pozicija = ' ';
            
                pozicija++;
            }
                
        }
        prethodni=*pozicija;
        pozicija++;
        kraj1= pozicija;
        if(*pozicija=='\0') pozicija=NULL;
    }
    
    for(i = 0; i < razmaci_na_kraju; i++){
        *kraj1 = ' ';
        kraj1++;
    }
    *kraj1 = '\0';
    return tekst;
}
int main() {
	int broj=320;
	char niz[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
    printf("%s",ubaci_broj(niz, broj));
	return 0;
}
