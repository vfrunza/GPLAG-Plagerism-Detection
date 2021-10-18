#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

int broj_nula(int br){
    int b=0,br_nul=0;
    int c;
    
    if(br<0) b=1;
    
    while (br!=0){
        c=br%10;
        br=br/10;
        br_nul++;
    }
    
    if(b==1) br_nul++;
    
    return br_nul;
}

char* ubaci_broj(char *s,int br){

    char *pocetak=s;
    char *pom=s;
    int i,negativan=0,vel_broja,pom_br;
    
    /*if(br<0){
        negativan=1;
        br=abs(br);
        vel_broja=broj_nula(br);
    }
    else vel_broja=broj_nula(br);*/
    vel_broja=broj_nula(br);
    if (br<0) negativan=1;
    br=abs(br);
    
    while(*pom!='\0'){
        /*if(*pom!=' ' && *(pom-1)==' '){
            pom++;
            continue;
        }*/
        if(*pom==' '){
            char *kraj=pom;
            while(*kraj!='\0')kraj++;
            
            while(kraj>pom){
                *(kraj+vel_broja)=*kraj;
                kraj--;
            }
            i=0;
            pom++;
            pom_br=br;
            
            if(negativan==1){
                *pom='-';
                pom++;
                i++;
            
                while(i<vel_broja){
                    *pom++=pom_br/pow(10,vel_broja-1-i)+'0';
                    pom_br=pom_br%(int)pow(10,vel_broja-1-i);
                    i++;
                }
            }
            else{
                while(i<vel_broja){
                    *pom++=pom_br/pow(10,vel_broja-1-i)+'0';
                    pom_br=pom_br%(int)pow(10,vel_broja-1-i);
                    i++;
                }
            }
        }
        
        if(*pom!=' ' && *(pom-1)==br%10+'0'){
            char *kraj=pom;
            while(*kraj!='\0') kraj++;
            while(kraj>pom-1){
                *(kraj+1)=*kraj;
                kraj--;
            }
            *pom=' ';
        }
        if(*pom=='\0') break;
        pom++;
    }
    
    pom=s;
    
    return pocetak;
}

int main(){
    
char s[44] = "Ovo je neki primjer teksta";
printf("\"%s\"", ubaci_broj(s, -5));
    
    return 0;
}