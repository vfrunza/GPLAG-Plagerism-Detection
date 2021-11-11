#include <stdio.h>


char tuper(char c){
    if( c >= 'a' && c <= 'z') 
    return c-('a' - 'A');
    return c;
}

int slovo(char c){
        
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) 
        return 1;
        
    return 0;
}

int ponavljanje(char *s, char *poc, char* kra){
    char *p=s;
    char *q;
    int br = 0;
    while(*p != '\0'){
        q=poc;
        if(tuper(*p) == tuper(*q) && (p == s || slovo (*(p-1)) == 0)){
            while(tuper(*p) == tuper(*q) && q != kra && *p != '\0'){
                p++;
                q++;
            }
            if(q == kra && slovo(*p) == 0) br++;
        } else
        p++;
    }
    return br;
}

void izbaci(char *s, char *poc, char *kra){
    char *p=s;
    char *q, *ci, *pi;
    int br=0;
    
    while(*p != '\0'){
        q=poc;
        
        if(tuper(*p) == tuper(*q) && (p == s || slovo(*(p-1)) == 0)){
            pi=p;
            while(tuper(*p) == tuper(*q) && q != kra){
                p++;
                q++;
            }
            if(q == kra && slovo(*p) == 0){
                ci=p;
                while(*ci != '\0'){
                    *pi++ = *ci++;
                }
                *pi = '\0';
                p = p - (ci - pi);
            }
        }else
        p++;
    }
}

char *izbaci_najcescu(char *s){
    char *pt, *kt, *pt1, *kt1, *t, *t1, *p, *r, *pm, *km, *pi, *ci;
    int br, max = 0, iste;
    int ima = 0;
    
    p=s;
    
    if(*p == '\0') return 0;
    
    while(*p != '\0'){
        if((slovo(*p) == 1)){
            ima = 1;
            pt = p;
            while(slovo(*p) == 1) p++;
            kt = p;
            br = ponavljanje(s,pt,kt);
            if(br > max){
                max = br;
                pm = pt;
                km = kt;
            }
        } else 
        p++;
    }
    if(ima == 1){
        izbaci(km, pm, km);
        pi = pm;
        ci = km;
        while(*ci != '\0') *pi++ = *ci++;
        *pi = '\0';
    }
    return s;
}

int main(){
    
    return 0;
}