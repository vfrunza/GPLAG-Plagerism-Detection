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

char* obuhvat(char* tekst, double x1, double x2, double y1, double y2){
    char* krajprosle;
    char *s=tekst;
    double x=0,y=0;
    double o=0.1;
     
    while (*s!='\0'){
        
        if (!((*s>=0 && s<=9) || *s=='-' || *s=='.' || *s==',')) return 0;
        int imadec=0, predznak=1;
        char* poc;
         if (*s='(') {poc=s; s++;}
        x=0;
       
        while (*s!=','){
        if (!((*s>=0 && s<=9) || *s=='-' || *s=='.' || *s==',')) return 0;
        
        if (*s=='-') {s++;predznak=-1;}
        if (*s=='.') {imadec=1;s++;}
        if (*s==',') {break;}
        
        if (imadec==0){
            x=x*10+(*s-48);
        }
        
        else {
            x=x+(*s-48)*o;
            o=o/10;
        }
        s++;
        }
        
        x=x*predznak;
        imadec=0;predznak=1;
        s++;
        y=0;
        
        o=0.1;
        
        while(s!=')') {
            
        if (*s=='-') {s++;predznak=-1;}
        if (*s=='.') {imadec=1;s++;}
        
        if (imadec==0){
            
            y=y*10+(*s-48);
        }
           else {
               y=y+(*s-48)*o;
               o=o/10;
           } 
            s++;
        }
        
        y=y*predznak;
        krajprosle=s;
        
        char *a=poc;
        int izb=0;
        if(y>y2 ||y<y1 || x<x1 || x>x2) {
            izb=1;
        if(*(s+1)=='\0') {*(poc-1)='\0'; return tekst;  }
        else {char*hod=s+2;
        while (*hod!='\0'){ *poc=*hod;
        poc++; hod++;
        }
        poc='\0';
        
    }
}

if (izb) {
    s=a; s-=2;}
    s++; s++;
} return tekst; }


int main() {
char s[]="(2.,2)";
char* rez= obuhvat(s,-3,-3,3,3);
printf ("%s %s", rez, s);



	return 0;
}
