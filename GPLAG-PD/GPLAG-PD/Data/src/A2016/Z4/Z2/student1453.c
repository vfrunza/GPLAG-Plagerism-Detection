#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *spoji(char *tekst, char *dodati){
    char *s=tekst, *p=dodati;
    while(*s!='\0') s++;
    
    while (*p!='\0') {
        *s=*p;
        s++;
        p++;
    }
    return tekst;
}
int prebroji(char *s, char ch){
    int brojac=0;
    if(ch>='A' && ch<='Z'){
        while(*s!='\0'){
            if(*s==ch||*s==ch+32)
                brojac++;
            s++;
        }
        return brojac;
    }
    while(*s!='\0'){
        if(*s==ch||*s+32==ch)
            brojac++;
        s++;
    }
    return brojac;
}
int postoji(char *s, char ch){
    while(*s!=0){
        if(*s==ch) 
            return 1;
        s++;
    }
    return 0;
}
int duzina(char *tekst){
    char *t=tekst;
    int brojac=0;
    while(*t!='\0'){
        brojac++;
        t++;
    }
    return brojac;
}

char *kodiraj(char *tekst, char *tabela){
    char *p_tekst, *p_tabela, *p_tabela2, *p_temp, dodavanje[100];
    int velicina, brojac, i,j, niz[96] ,rezultat, temp, ch=32;
    velicina=duzina(tekst);
    p_temp=&ch;
    strcpy(tabela,tekst);
    
    
    for(i=0;i<95;i++){
        *(dodavanje+i)=ch;
        ch++;
    }
    *(dodavanje+i)='\0';
    char *dod=dodavanje;
    int vel=95;
    int uslov=1;
    for(i=0;i<vel;i++){
        if(uslov==0)
            i--;
        p_tekst=tekst;
        uslov=1;
        while(*p_tekst!='\0'){
            if(*(dod+i)==*p_tekst){
                for(j=i;j<vel-1;j++){
                    *(dod+j)=*(dod+j+1);
                }
                
                vel--;
                uslov=0;
                break;
            }
            
            
            p_tekst++;
        }
        
    }
    *(dod+i)='\0';
    
    //printf("%s\n", dodavanje);
    //izbacuje sve clanove sto se ponavljaju i pravi niz sa vrijednostima broja puta koji se ponavljaju
    p_tabela=tabela;
    p_tekst=tekst;
    for(i=0;i<velicina;i++){
        niz[i]=prebroji(p_tabela,*p_tabela);
        p_tabela2=p_tabela;
        p_tabela2++;
        while(*p_tabela2!='\0'){
            if(*p_tabela==*p_tabela2){
                for(j=0;j<velicina-1;j++)
                    *(p_tabela2+j)=*(p_tabela2+j+1);
                velicina--;
                continue;
            }
            p_tabela2++;
        }
        p_tabela++;
    }
    //sortira slova po broju puta sto se ponavljaju
    p_tabela=tabela;
    for(i=0;i<velicina;i++){
        for(j=i+1;j<velicina;j++){
            if(niz[i]<niz[j]){
                *p_temp=*(p_tabela+i); 
                *(p_tabela+i)=*(p_tabela+j);
                *(p_tabela+j)=*p_temp;
                temp=niz[i];
                niz[i]=niz[j];
                niz[j]=temp;
            
            }
        }
        
    }
    
    //sortira slova po ascci vrijednosti ako se ponavljaju isti broj puta
    p_tabela=tabela;
    for(i=0;i<velicina;i++){
        for(j=i;j<velicina;j++){
            if(niz[i]==niz[j] && *(p_tabela+i)>*(p_tabela+j)){
                *p_temp=*(p_tabela+i);
                *(p_tabela+i)=*(p_tabela+j);
                *(p_tabela+j)=*p_temp;
                temp=niz[i];
                niz[i]=niz[j];
                niz[j]=temp;
            
            }
        }
        
    }
    
    
    
    //kodira tekst
    p_tekst=tekst;
    while(*p_tekst!='\0'){
        p_tabela2=tabela;
        brojac=0;
        while(*p_tabela2!='\0'){
            if(*p_tekst==*p_tabela2){
                *p_tekst=126-brojac;
            }
            brojac++;
            p_tabela2++;
        }
        p_tekst++;
    }
    

   spoji(tekst,dodavanje);
   
    return tekst;
}

char *dekodiraj(char *tekst, char *tabela){
    int velicina, i;
    char *p=tekst;
    velicina=duzina(tekst);
    for(i=0;i<velicina;i++){
        *p=*(tabela+126-*p);
        p++;
    }
    
    
    return tekst;
}

int main() {
    int i;
    char tekst[]={"LLMLNLNMONM"}, niz[100];
    printf("%s", kodiraj(tekst,niz));
    
    
    
	return 0;
}
