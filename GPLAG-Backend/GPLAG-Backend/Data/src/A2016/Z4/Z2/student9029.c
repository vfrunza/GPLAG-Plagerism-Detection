#include <stdio.h>

int maximal(int ascii_niz[127]){
    int max, i=32, j, max_index;
    
    max=ascii_niz[i];
    max_index=i;
    
    for(i=32;i<127;i++){
        for(j=i+1;j<127;j++){
            if(ascii_niz[j]>max && ascii_niz[j]>=0){
            max=ascii_niz[j];
            max_index=j;
            }
        }
    }
    
    ascii_niz[max_index]=-1;
    
    return max_index;
}

char * kodiraj(char * niz, char * sifre){
    
    int ascii_niz[127]={0}, i=0, pozicija=0;
    char* pocetak=niz, *pocetak_sifre;
    
    pocetak_sifre=sifre;
    
    while(*niz!='\0'){
        ++ascii_niz[*niz];
        niz++;
    }
    niz=pocetak;
   
    for(i=0;i<100;i++){
            sifre[i]=maximal(ascii_niz);
            if(i==95){i++; sifre[i]='\0'; break;}
    }
    
    while(*niz!='\0'){
        sifre=pocetak_sifre;
        pozicija=0;
        while(*sifre!='\0'){
            if(*niz==*sifre){
                break;
            }
            sifre++; pozicija++;
        }
        *niz=(126-pozicija);
        niz++;
    }
    
    return pocetak;
}

char * dekodiraj(char * niz, char * sifre){
    int broj;
    char*  pocetak;
    pocetak=niz; 
    
    while(*niz!='\0'){
        broj=126-*niz;
        *niz=sifre[broj];
        niz++;
    }
    
    return pocetak;
}

int main() {
	char tekst[2000000], sifre[100];

	kodiraj(tekst, sifre);
	printf("%s", dekodiraj(tekst, sifre));
	
    return 0;
}
