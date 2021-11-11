#include <stdio.h>

int provjera(char* p,char* q){
    int jesu=1;
    while(*q!='\0'){
        if(*q++!=*p++){
            jesu=0;
            break;
        }
        if(*q=='\0' && (*p!=' ' && *p!='\0')){
            jesu=0;
            break;
        }
    }
    return jesu;
}

void zamjena(char* rec,char* rijec){
    while(*rijec!='\0'){
        *rec++=*rijec++;
    }
    rec++;
}

int dict(char** rijeci,char** zamjene,int broj_rijeci){
    int i=0,jesu=1;
    char* s,* s1;
    for(i=0;i<broj_rijeci;i++){
        s=rijeci[i];
        s1=zamjene[i];
        while(*s!='\0' || *s1!='\0'){
            if(*s++!=*s1)
            jesu=0;
        }
        if(jesu==0) break;
    }
    return jesu;
}
char* zamjena_rijeci(char* tekst,char** rijeci,char** zamjene,int broj_rijeci){
    char*p=tekst;
    char*s,*t,*k,*h;
    int i,brojac;
    if (dict(rijeci,zamjene,broj_rijeci))
    return tekst;
    while(*p!='\0'){
        if(p==tekst || *(p-1)==' '){
            while(*p==' ') p++;
            t=p;
            for(i=0;i<broj_rijeci;i++){
                brojac=0;
                p=t;
                s=rijeci[i];
                
                if (provjera(p,s)){
                    k=t;
                    while(*p!='\0' && *p!=' ')
                    p++;
                    
                    while(*p!='\0'){
                        *k++=*p++;
                    }
                    *k='\0';
                    p=t;
                    s=zamjene[i];
                    while(*s!='\0'){
                        brojac++;
                        s++;
                    }
                    h=k+brojac;
                    p--;
                    while(k!=p){
                        *h--=*k--;
                    }
                    s=zamjene[i];
                    zamjena(t,s);
                }
            }
        }
        p++;
    }
    return tekst;
}

int main() {
    char tekst[100]="beli sneg je pokrio beli breg";
    char* rijeci[2]={"beli","sneg"};
    char* zamjene[2]={"bijeli","snijeg"};
    printf("%s",zamjena_rijeci(tekst,rijeci,zamjene,2));
    return 0;
}
