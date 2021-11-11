#include <stdio.h>
#include <math.h>

/*Funkcija vraca x koordinate iz dobro formatiranog stringa*/ 
float vratiprvibroj(char *pocetak){
    pocetak++;
    int a=1;
    if(*pocetak=='-'){ /*provjera: da li je broj negativan*/
        a=-1; 
        pocetak++; 
    }
    
    float broj=0;
    int brojac=0;
    while(*pocetak!='.' && *pocetak!=','){ /*odredjivanje cijelog dijela broja iz stringa*/
        broj+=(*pocetak-48)/pow(10,brojac); /*formula: oduzima se 48 i svaka slj cifra se odredjuje dijeljenjem sa stepenom broja 10*/
        brojac++; 
        pocetak++; 
    }
    
    broj*=pow(10,brojac-1); /*formula: mnozi se sa step broja 10 da se dobije cijeli dio broja*/
    int i=1;
    float tmp=0;
    if(*pocetak=='.'){ /*odredjivanje decimalnog dijela ako uopce postoji*/
        pocetak++;
        while(*pocetak!=','){
            tmp+=(*pocetak-48)/pow(10,i); /*isti nacin kao i kod cijelog dijela broja*/
            i++; 
            pocetak++;
        }
    }
    broj+=tmp;
    return broj*a;
}

/*Funkcija vraca y koordinate iz dobro formatiranog stringa; ista struktura kao i za x koordinate*/
float vratidrugibroj(char *pocetak){
    while(*pocetak!=',') /*izuzetak je sto se preskace prvi broj*/
    pocetak++;
    pocetak++;
    int a=1; 
    if(*pocetak=='-'){ 
        a=-1; 
        pocetak++;
    }
    
    float broj=0;
    int brojac=0;
    while(*pocetak!='.' && *pocetak!=')'){ 
        broj+=(*pocetak-48)/pow(10,brojac); 
        brojac++;
        pocetak++;
    }
    broj*=pow(10,brojac-1);
    int i=1;
    float temp=0;
    if(*pocetak=='.'){
        pocetak++;
        while(*pocetak!=')'){ 
            temp+=(*pocetak-48)/pow(10,i); 
            i++;
            pocetak++;
        }
    }
    broj+=temp;
    return broj*a; 
}

/*Funkcija za izbacivanje dijela stringa, tj. izbacit ce sve izmedju *pocetak i *kraj*/
void izbaci(char *pocetak, char *kraj){
    while(*kraj!='\0') {
        *pocetak=*kraj;
        pocetak++; 
        kraj++; 
    }
    *pocetak='\0';
}

/*Funkcija za provjeru formata stringa*/
int format(char *s){
    int oz=0; /*otvorena zagrada*/
    int zz=0; /*zatvorena zagrada*/
    int zar=0; /*zarez*/
    char *p=s;
    int ok=1;
    if(*s!='(')
    return 0;
    /*provjera: koji se znak nalazi prije znaka do kojeg se dolazi*/
    while(*s!='\0'){
        if(*s=='('){ 
            ok=(s==p || *(s-1)==',');
            oz++; 
        }
        else if(*s==')'){ 
            ok=(*(s-1)=='.' || (*(s-1)>='0' && *(s-1)<='9'));
            zz++; 
        }
        else if(*s=='.'){ 
            ok=(*(s-1)>='0' && *(s-1)<='9');
        }
        else if(*s==','){ 
            ok=(*(s-1)==')' || *(s-1)=='.') || (*(s-1)>='0' && *(s-1)<='9');
            zar++; 
        }
        else if(*s=='-'){ 
            ok=(*(s-1)==',' || *(s-1)=='(');
        }
        else if(*s>='0' && *s<='9'){ 
            ok=((*(s-1)>='0' && *(s-1)<='9') || *(s-1)=='-' || *(s-1)=='.' || *(s-1)=='(' || *(s-1)==',');
        }
        else ok=0;
        if(!ok) {
            return ok;
        }
        s++;
    }
    if(*(s-1)!=')'){
        return 0;
    }
    /*broj oz mora biti jednak zz; broj zareza mora biti jednak oz+zz-1*/
    ok=((oz==zz && (oz+zz==zar+1)) || (oz==0 && zz==0 && zar==0)); 
    return ok;
} 

/*Funckija prima niz tacaka, te izbacuje sve tacke koje su unutar neke pravougaone povrsine*/
char *obuhvat(char *s, float x1, float y1, float x2, float y2){
    if(*s=='\0'){ /*prazan string ne treba vracati NULL*/
        return s;
    }
    if(!format(s)){ /*string pogresnog formata*/
        return NULL;
    }
    char *p=s;
    while(*p!='\0'){ /*kretanje po stringu*/
        while(*p!='(' && *p!='\0')
        p++; /*pomjeranje do prve otvorene zagrade*/
        if(*p=='\0')
        return s;
        /*odredjivanje koordinata*/
        float x=vratiprvibroj(p); /*poziv f-je vrati prvi broj*/
        float y=vratidrugibroj(p); /*poziv f-je vrati drugi broj*/
        if(x<x1 || x>x2 || y<y1 || y>y2){ /*provjera: da li tacka pripada pravougaoniku?*/
            char *k=p+1;
            while(*k!='(' && *k!='\0') 
            k++; /*pomjeranje do sljedece tacke*/
            izbaci(p,k); /*izbacivanje tacke*/
        }
        else p++; /*pokazivac se pomjera ukoliko tacka nije izbacena*/
    }
    if(*(p-1)==',')
        *(p-1)='\0'; /*ako se izbacuje zadnja tacka, zarez ostaje na kraju stringa pa se on uklanja*/
    
    return s; 
}

int main(){
    char s[]=" "; /*Unos*/
    printf("%s",obuhvat(s,-3,-3,3,3)); /*Ispis*/
    return 0;
}
 