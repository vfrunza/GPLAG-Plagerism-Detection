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

int strcmp(char *a1, char *a2){
    
    while(*a1>'A' && *a1<'Z' || *a1>'a' && *a1<'z' ||  *a2>'A' && *a2<'Z' || *a2>'a' && *a2<'z'){
        if(*a1<='Z' && *a2<='Z' && *a1<*a2 || *a1>='a' && *a2>='a' && *a1<*a2 ||
            *a1<='Z' && *a2>='a' && *a1+'a'-'A'<*a2 || *a1>='a' && *a2<='Z' && *a1<*a2+'a'-'A'){
            return 0;
        }
        if(*a1<='Z' && *a2<='Z' && *a1>*a2 || *a1>='a' && *a2>='a' && *a1>*a2 ||
            *a1<='Z' && *a2>='a' && *a1+'a'-'A'>*a2 || *a1>='a' && *a2<='Z' && *a1>*a2+'a'-'A'){
            return 0;
        }
        if(  (*a1<'A' || *a1>'Z' && *a1<'a' || *a1>'z')   && (*a2>='A' && *a2<='Z' || *a2>='a' && *a2<='z')  ){
            return 0;
        }
        if(  (*a2<'A' || *a2>'Z' && *a2<'a' || *a2>'z')   &&  (*a1>='A' && *a1<='Z' || *a1>='a' && *a1<='z')  ){
            return 0;
        }
        a1++;
        a2++;
    }
    return 1;
}

char* izbaci_najcescu(char* s){
    
    char *prvi_pokazivac;
    prvi_pokazivac=s;
    char *prva_rijec;
    char *druga_rijec;
    prva_rijec=s;
    druga_rijec=s;
    int i=0;
    int niz[300]={{0}};
    
    // poredjenje rijeci 
    
    while(*prva_rijec!='\0'){
        druga_rijec=prva_rijec+1;
        while(*druga_rijec!='\0'){
            while(  ( (*druga_rijec>='A' && *druga_rijec<='Z') || (*druga_rijec>='a' && *druga_rijec<='z')) && (*(druga_rijec-1)>='A' || (*(druga_rijec-1)<='Z' && *(druga_rijec-1)>='a') || *(druga_rijec-1)<='z') ){
                druga_rijec++;
            }
            if(*druga_rijec=='\0') break;
            druga_rijec++;
            if(strcmp(prva_rijec,druga_rijec)){
                niz[i]++;
            }
            
            
        }
        i++;
        prva_rijec++;
        while(  (*prva_rijec>='A' && *prva_rijec<='Z' || *prva_rijec>='a' && *prva_rijec<='z') && (*(prva_rijec-1)>='A' || *(prva_rijec-1)<='Z' && *(prva_rijec-1)>='a' || *(prva_rijec-1)<='z') ){
                prva_rijec++;
            }
            if(*prva_rijec=='\0') break;
            prva_rijec++;
            if(*prva_rijec=='\0') break;
    }
    int broj_rijeci=i;
    int max=niz[0];
    
    // trazenje one koja se najvise puta ponavlja
    
    for(i=1;i<broj_rijeci;i++){
        if(niz[i]>max) max=niz[i];
    }
    for(i=0;i<broj_rijeci;i++){
        if(niz[i]==max) break;
    }
    int indeks_rijeci=i;
    
    // postavljanje pokazivaca na prvo slovo te rijeci
    
    prva_rijec=prvi_pokazivac+1;
    for(i=0;i<indeks_rijeci;i++){
        while(  (*prva_rijec>='A' && *prva_rijec<='Z' || *prva_rijec>='a' && *prva_rijec<='z') && (*(prva_rijec-1)>='A' || *(prva_rijec-1)<='Z' && *(prva_rijec-1)>='a' || *(prva_rijec-1)<='z') ){
                    prva_rijec++;
        }
    }
    if(indeks_rijeci==0) prva_rijec=prvi_pokazivac;
    
    // trazenje duzine te rijeci
    
    int duzina_rijeci=0;
    char *pomocna_prva_rijec;
    pomocna_prva_rijec=prva_rijec;
    while(*pomocna_prva_rijec>='A' && *pomocna_prva_rijec<='Z' || *pomocna_prva_rijec>='a' && *pomocna_prva_rijec<='z'){
        duzina_rijeci++;
        pomocna_prva_rijec++;
    }
    
    // stavljanje rijeci u drugi string
    
    char rijec[50];
    char *nova_rijec;
    char *pomocna_nova_rijec;
    nova_rijec=&rijec[0];
    pomocna_nova_rijec=&rijec[0];
    while(*prva_rijec>='A' && *prva_rijec<='Z' || *prva_rijec>='a' && *prva_rijec<='z'){
        *(pomocna_nova_rijec) = *(prva_rijec);
        pomocna_nova_rijec++;
        prva_rijec++;
    }
    *pomocna_nova_rijec='\0';
    
    
    // izbacivanje te rijeci 
    
    prva_rijec=prvi_pokazivac;
    pomocna_prva_rijec=prva_rijec;
    while(*prva_rijec!='\0'){
        pomocna_prva_rijec=prva_rijec;
        if(strcmp(prva_rijec,nova_rijec)){
            while(*(pomocna_prva_rijec+duzina_rijeci)!='\0'){
                *pomocna_prva_rijec=*(pomocna_prva_rijec+duzina_rijeci);
                pomocna_prva_rijec++;
            }
            *pomocna_prva_rijec='\0';
        }
        
        while((*prva_rijec>='A' && *prva_rijec<='Z' || *prva_rijec>='a' && *prva_rijec<='z') && (*(prva_rijec-1)>='A' || *(prva_rijec-1)<='Z' && *(prva_rijec-1)>='a' || *(prva_rijec-1)<='z') ){
            prva_rijec++;
        }
        if(*prva_rijec=='\0') break;
        prva_rijec++;
        
    }
  
    // vracanje pokazivaca
    
    return prvi_pokazivac;
    
}

int main() {
	char recenica[100];
	printf("Unesi: ");
	unesi(&recenica[0], 100);
	char *p;
	p=izbaci_najcescu(&recenica[0]);
	printf("%s",recenica);
	return 0;
}
