#include <stdio.h> 

/*Funkcija za vracanje pozicije*/
int vrati_poziciju(char c, char *tablica){
    int i=0;
    while(c!=*(tablica+i) && *(tablica+i)!='\0')
    i++;
    return i;
}

/*Funkcija kodira tekst koristeci se tablicom sifrovanja*/ 
char *kodiraj(char *tekst, char *tablica){
    int brojevi[95];
    int j=0;
    for(j=0; j<95; j++)
    brojevi[j]=0;
    j=0;
    while(*(tekst+j)!='\0'){
        brojevi[*(tekst+j)-32]++;
        j++;
    }
    
    for(j=0; j<96; j++){ /*popunjavanje tablice kodiranja*/
        int indeks=0;
        int max=-1;
        int k=0;
        
        while(k<95){
            if(brojevi[k]>max){
                max=brojevi[k]; /*pronalazak max broja*/
                indeks=k;
            }
            k++;
        }
        brojevi[indeks]=-1; /*zbog -1 vise nece dolaziti u obzir*/
        *(tablica+j)=indeks+32;
    }
    *(tablica+j-1)='\0';
    
    /*Kodiranje*/
    int i=0;
    while(*(tekst+i)!='\0'){
        *(tekst+i)=126-vrati_poziciju(*(tekst+i),tablica);
        i++;
    }
    return tekst;
}

/*Funckija dekodira tekst koristeci se tablicom desifrovanja*/
char *dekodiraj(char *tekst, char*tablica){
    int brojevi[95];
    char tablica2[96];
    int j=0;
    for(j=0; j<95; j++)
    brojevi[j]=0;
    j=0;
    while(*(tekst+j)!='\0'){
        brojevi[*(tekst+j)-32]++;
        j++;
    }
    for(j=0; j<96; j++){ /*popunjavanje tablice dekodiranja*/
        int indeks=0;
        int max=-1;
        int k=0;
        while(k<95){
            if(brojevi[k]>=max){
                max=brojevi[k];
                indeks=k;
            }
            k++;
        }
        brojevi[indeks]=-1; /*ne dolazi u obzir vise jer je -1*/
        *(tablica2+j)=indeks+32;
    }
    *(tablica2+j-1)='\0';
    
    /*Dekodiranje*/
    int i=0;
    while(*(tekst+i)!='\0'){
        int n=0;
        while(n<96){
            if(*(tekst+i)==*(tablica2+n)){
                *(tekst+i)=*(tablica+n);
                break;
            }
            n++;
        }
        i++;
    }
    return tekst;
}

int main(){
    char tablica[96]; 
    char tekst[]="";
    
    char *c=kodiraj(tekst,tablica); /*Poziv f-je kodiraj*/
    printf("%s", tekst); /*Ispis kodiranog teksta*/
    
    c=dekodiraj(tekst,tablica); /*Poziv f-je dekodiraj*/
    printf("%s", tekst); /*Ispis dekodiranog teksta*/
    
    return 0;  
}