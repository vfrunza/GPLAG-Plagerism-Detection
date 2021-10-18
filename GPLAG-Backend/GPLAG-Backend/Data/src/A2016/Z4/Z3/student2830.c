#include <stdio.h>
int izbroji(char *niz){
    int n=0;
    char *o;
    o=niz;
    while(*o!='\0'){
        n++;
        o++;
    }
    return n;
    
}
int trazi_rijec(char * tekst, char *rijec){
    char *p,*q,*z,*j;
    z=tekst;
    j=tekst;
    p=tekst;
    q=rijec;
    while(*j!='\0'){
        p=j;
        q=rijec;
        while(*p++ == *q++)
        if(*q=='\0' && (j==z || *(j-1)==' ') && (*p==' ' || *p=='\0')) return 1;
        j++;
    }
    return 0;
}

char *zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci){
    char *p,*s,*k,*r,*u,*rez,**q,*kraj,*poc,*pomocni;
    int duzina,i=0,h=0,hehe=0,j;
    u=tekst;
    q=rijeci;
    
    for(i=0;i<broj_rijeci;i++){
        s=tekst;
       h=trazi_rijec(tekst,*(q+i));
        duzina=izbroji(*(zamjene+i))-izbroji(*(q+i));
    if(h!=0){
    while( *s!='\0'){
        rez=s;
        r=*(q+i);
        while(*rez!=32 && *rez!='\0'){
        if(*rez==*r ){
            hehe++;
            r++;
        }
        if(hehe==1){
            poc=rez;
        }
        rez++;
         if(*r=='\0'){
            kraj=rez;
            goto ovdje;
        }
          
        }
        hehe=0;
        ovdje:
  if (*r=='\0' && (poc==u || *(poc-1)==' ') && (*kraj==' ' || *kraj=='\0') ){
      pomocni=s;
      if(duzina<0){
          for(j=0;j<duzina*(-1);j++){
              s=pomocni;
              while(*s!='\0'){
                  *s=*(s+1);
                  s++;
              }
              s=pomocni;
          }
          duzina=0;
      }
            k=s;
            while(*k!='\0'){
                k++;
            }
            while(k>=s){
                *(k+duzina)=*k;
                k--;
            }
            p=zamjene[i];
            while(*p!='\0'){
                *s++=*p++;
            }
            s--;
        } 
        
        s++;
    }
    
    }
    }
    
    return u;
}

int main() {
	return 0;
}
