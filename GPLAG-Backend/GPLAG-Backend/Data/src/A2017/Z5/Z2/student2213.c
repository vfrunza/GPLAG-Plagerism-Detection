#include <stdio.h>
 
// 1. UNOS STRINGA
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
 
// 2. BROJ ZNAKOVA U STRINGU
int prebroji(char* s, char znak) {
    int broj = 0;
    while (*s != '\0') {
        if (*s == znak)
            broj++;
        s++;
    }
    return broj;
}
 
// 3. IZBACIVANJE NAJDUZE RIJECI
 
char* izbaci_najduzu(char* s){
    int raz=1;
    int duzine_rijeci[100];
    int najduza=0;
    char*copy=s;
    int index=0;
    int i=0;
    int br=0;
 
    while(*s!='\0'){
        if(*s==' '){
            raz=1;
        }else if(raz==1){
            raz=0;
            duzine_rijeci[br]=duzina_rijeci(s);
            br++;
        }
        s++;
    }
 
    najduza=duzine_rijeci[0];
 
    for(i=0;i<br;i++){
        if(duzine_rijeci[i]>najduza){
            najduza=duzine_rijeci[i];
            index=i;
        }
    }
 
    s=copy;
    raz=1;
    i=0;
    while(*s!='\0'){
       if(*s==' '){
           raz=1;
       }else if(raz==1){
           raz=0;
           if(i++==index){
               while(*(s+duzine_rijeci[index])!='\0'){
                   *s=*(s+duzine_rijeci[index]);
                    s++;
               }
               *s='\0';
               continue;
           }
       }
       s++;
   }
 
    return copy;
}
 
// 4. IZBACIVANJE N-TE PO REDU RIJECI
void izbaci_rijec(char* s, int n) {
    int neslovo=1, broj_rijeci=0;
    char* pocetak;
    while (*s != '\0') {
        if (!(*s>='A' && *s<='Z' || *s>='a' && *s<='z' ))
            neslovo=1;
        else if (neslovo == 1) {
            neslovo=0;
            broj_rijeci++;
            if (broj_rijeci==n) pocetak=s;
            if (broj_rijeci==n+1) {
                while (*pocetak++ = *s++);
            }
        }
    s++;
    }
    if (broj_rijeci == n) *pocetak = '\0';
}
 
// 5. IZBACIVANJE RAZMAKA
char* whitespace(char *s){
    char *pocetak=s, *novi, *drugi;
 
    while(*s!='\0'){
        if(*s=='\t' || *s=='\n'){
            *s=' ';
        }
        s++;
    }
    s=pocetak;
    while(*s!='\0'){
        if(*s==' ' && *(s+1)==' '){
            novi=s;
            drugi=s;
            while(*novi==' ') novi++;
            novi--;
            while(*novi!='\0'){
                *drugi=*novi;
                novi++; drugi++;
            }
            *drugi='\0';
        }
 
 
        s++;
    }
    return pocetak;
}
 
// 6. IZBACIVANJE SLOVA KOJE SE NAJVISE PONAVLJA
char* izbaci_max_slovo(char*s) {
    int brojaci[26]={0} ; 
    char* p = s ;
    int max = brojaci[0] ;
    int maxi = 0 ; 
    int i=0 ; 
    while(*s!='\0')
    {
        if(*s>='a' && *s<='z')
        {
           brojaci[(*s)-97]++ ; 
        }
        if(*s>='A' && *s<='Z')
        {
            brojaci[(*s)-65]++ ; 
        }
        for(i=0 ; i<26 ; i++)
        {
            if(brojaci[i]>max)
            {
                max = brojaci[i] ; 
                maxi = i ;
            }
        }
        s++ ; 
    }
    s = p ;
    while(*s!='\0')
    {
        if(*s==maxi+'A' || *s==maxi+'a')
        { 
            char* q1=s ; 
            char* q2 = s+1 ; 
            while(*q1!='\0')
            {
                *q1=*q2 ;
                q1++ ; 
                q2++ ;
            } 
            s-- ;
        }
        s++ ;
    }
    *s='\0' ;
 
    return p ;
}
 
// 7. TRAZENJE POSLJEDNJE RIJECI
char* PosljednjaRijec(char*s){
     int raz=1;
     int br_rijeci=0;
     char* rijeci[100];
 
     while(*s!='\0'){
          if(*s==' '){
               raz=1;
          }else if(raz==1){
               raz=0;
               rijeci[br_rijeci++]=s;    
          }
     s++;
     }
     return rijeci[br_rijeci-1];
 
}
 
// 8. NAJVECA SUMA CIFARA
int maxsuma(int *niz, int vel){
    int i=0;
    int *p=niz;
    int sume_cifara[100];
    int spaseni_niz[100];
    int suma=0;
    int c;
    int maxsuma;
    int index=0;
    if(vel==0)return 0;
 
    for(i=0;i<vel;i++){
        spaseni_niz[i]=fabs(*(p+i));
    }
 
    for(i=0;i<vel;i++){
 
        while(spaseni_niz[i]>0){
            c=spaseni_niz[i]%10;
            suma=suma+c;
            spaseni_niz[i]=spaseni_niz[i]/10;
        }
        sume_cifara[i]=suma;
        suma=0;
    }
 
    maxsuma=sume_cifara[0];
 
    for(i=0;i<vel;i++){
        if(maxsuma<sume_cifara[i]){
            maxsuma=sume_cifara[i];
            index=i;
        }else if(maxsuma==sume_cifara[i]){
            continue;
        }
    }
 
    return *(p+index);
 
}
 
// 9. ZAMJENA 1 SA "jedan"
void zamijeni1(char* s) {
    char * kraj = s;
    char * novi = s;
    while(*s!='\0'){
        if(*s=='1'){
           while(*kraj!='\0'){
               kraj++;
           }
           novi = kraj+4;
           while(kraj>s){
               *novi = *kraj;
               novi--; kraj --;
           }
           *s='j'; *(s+1)='e'; *(s+2)='d'; *(s+3)='a'; *(s+4)='n';
        }
        s++;
    }    
}
int main() {
	printf("Zadaća 5, Zadatak 2");
	return 0;
}
