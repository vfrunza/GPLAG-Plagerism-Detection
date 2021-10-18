#include <stdio.h>

void unesi(char niz[], int velicina) {
    int i = 0;
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

int duzina(char* s,int space) {
    int duz=0;
    if (space){
        while (*s != '\0') {
            if ((*s>= 'A' && *s<='Z') || (*s>= 'a' && *s<='z'))
                duz++;
            s++;
        }
    } 
    else {
        while (*s != '\0') {
            duz++;
        s++;
        }
    }
    return duz;
}

int uporedi(char* s1, char* s2) {
    char nesto[100], nesto2[100];
    char*temp=nesto,*t;
    t=s1;
    while(*t!='\0'){
        if(*t>='A' && *t<='Z')
            *temp=*t+'a'-'A';
        else
            *temp=*t;
        t++;temp++;
    }
    *temp='\0';
    t=s2; temp=nesto2;
    while(*t!='\0'){
        if(*t>='A' && *t<='Z')
            *temp=*t+'a'-'A';
        else
            *temp=*t;
        t++;temp++;
    }
    *temp='\0';
    s1=nesto,s2=nesto2;
    while (*s1 != '\0' ) {
        if (*s1 != *s2) {
            return 0;
        }
        s1++;
        s2++;
    }
    return 1;
}

int isti(char a,char b){
    if(!(((a>='A' && a<='Z')||(a>='a'&&a<='z'))&&((b>='A' && b<='Z')||(b>='a'&&b<='z'))))
        return 0;
    if(a>='A' && a<='Z')
        a+='a'-'A';
    if(b>='A' && b<='Z')
        b+='a'-'A';
    if(a==b)
        return 1;
    return 0;
}

char * izbrisi(char*s, char*t,int c){
    int brojac=0;
    char *poc=s,*kraj=s,*r=s,*v=t;
    
    while (*r != '\0'){
        t=v;
        if (isti(*r,*t)){
            poc = r;
            while (*t != '\0'){
                if (!(isti(*r,*t))) {
                    brojac =0;
                    break;
                } 
                else {
                    if(r-s>0 && brojac==0)
                        if((*(r-1)>='A' && *(r-1)<='Z')||(*(r-1)>='a' && *(r-1)<='z')){
                            brojac=0;
                            r++;
                            break;
                        }
                    r++;
                    t++;
                    brojac++;
                }
            }
            if (brojac==c && !((*r>='A' && *r<='Z')||(*r>='a' && *r<='z'))){
                kraj = r;
                r=poc;
                while (*kraj!='\0'){
                   *poc = *kraj;
                   poc++;
                   kraj++;
               }
               *poc='\0';
            }
        } 
        else {
            r++;
        brojac=0;
        }
    }
    return (s);
    
}










char* izbaci_najcescu(char* s) {
    char *pocetak=s,*pocetak1=s;
    char niz_rijeci[500][500]= {{0}};
    char test[500];
    int brojac=0,i=0,br_rijeci=0,brojac_char=0,j=0;
    int duzina_rec=duzina(s,0);
    int broj_ponavljanja[500]={0},br_ponavljanja=0;
    int max=0,k=0;
    
    while (*pocetak != '\0') { 
        brojac_char++;
        if (((*pocetak >='A' && *pocetak <= 'Z' )|| (*pocetak >= 'a' && *pocetak <= 'z')) && brojac_char<duzina_rec) 
            brojac++;
        else if (brojac != 0 ) {
            pocetak1 = pocetak - brojac;
            for (i=0; i<brojac; i++)
                niz_rijeci[br_rijeci][i] = *(pocetak1+i);
            brojac=0;
            br_rijeci++;
        }
        if(*(pocetak+1)=='\0' && ((*(pocetak-1)>='A' && *(pocetak-1)<='Z')||(*(pocetak-1)>='a' && *(pocetak-1)<='z'))){
        /* znamo da je slovo ispred i da je ovo zadnja stvar u rečenici*/
            if(!((*(pocetak-1)>='A' && *(pocetak-1)<='Z')||(*(pocetak-1)>='a' && *(pocetak-1)<='z')));
            else
                niz_rijeci[br_rijeci-1][i]=*(pocetak1+i);
        }
        
        else if(*(pocetak+1)=='\0' && !((*(pocetak-1)>='A' && *(pocetak-1)<='Z')||(*(pocetak-1)>='a' && *(pocetak-1)<='z'))){
            pocetak1 = pocetak - brojac;
                niz_rijeci[br_rijeci][0] = *(pocetak1);
            br_rijeci++;        
        }
            
        pocetak++;
    }

    for (i=0; i<br_rijeci; i++){
        for (j=i+1; j<br_rijeci; j++){
            if (duzina(niz_rijeci[i],1)== duzina(niz_rijeci[j],1)){
                if (uporedi(niz_rijeci[i],niz_rijeci[j])){
                    br_ponavljanja++;
                }
            }
        }
        broj_ponavljanja[i]=br_ponavljanja;
        br_ponavljanja=0;
    }

    for (i=0; i<br_rijeci; i++){
        if (broj_ponavljanja[i]>max){
            max = broj_ponavljanja[i];
            k=i;
        }
    }
    
    for (i=0; i<duzina(niz_rijeci[k],1); i++){
        test[i] = niz_rijeci[k][i];
    }
    test[i]='\0';

    k = duzina (test,1);
    s = izbrisi(s,test,k);
    
    return (s);   
}

int main() {
    char t[]=" Koristio sam auto-stop da dodjem do znaka stop ali prije stopa sam otvorio dekstop kompjutera stop";
    printf("'%s'", izbaci_najcescu(t));
    return 0;
}
