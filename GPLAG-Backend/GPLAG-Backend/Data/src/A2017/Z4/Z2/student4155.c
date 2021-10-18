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

int provjeri_duzine(char* tekst, int* niz,int vel){
    
     char *p,*q;
     int broj_rijeci=0,razmak=1,br_slova=0,brojac=0,br1=0,max_broj_rijeci=0,visak=0;
    
     q=p=tekst;
   
    
     while(*q!='\0'){
        
/*Brojimo ukupan broj rijeci*/        
        if(*q==' ' || *q=='.' || *q=='?' || *q=='`'|| *q=='_' || *q=='~' || *q=='@' || *q=='{' || *q=='!' || ((int)(*q))==39 && max_broj_rijeci>0)razmak++;
	 
	       if(*q!=' ' && *q!='.' && *q!='?' && *q!='`'&& *q!='_' && *q!='~' && *q!='@' && *q!='{' && *q!='!' && ((int)(*q))!=39 && razmak>0){
	       max_broj_rijeci++;
	       razmak=0;
	       }
	    
	    q++;
    }
   
    if(max_broj_rijeci>vel)return 0;
    razmak=1;
    
    while(*p!='\0'){
/*Brojimo rijeci*/         
         if(broj_rijeci-1>vel)return 0;
         if(*p==' ' || *p=='.' || *p=='?' || *p=='`'|| *p=='_' || *p=='~' || *p=='@' || *p=='{' || *p=='!' || (int)(*p)==39 && broj_rijeci>0)razmak++;
	        if(*p!=' ' && *p!='.' && *p!='?' && *p!='`'&& *p!='_' && *p!='~' && *p!='@' && *p!='{' && *p!='!' && (int)(*p)!=39 && razmak>0){
	           broj_rijeci++;
	           razmak=0;
         }
/*Brojimo slova rijeci pojedinacno*/        
        if(broj_rijeci>0 && *p!=' ' && vel<7)brojac++;
        else if(broj_rijeci>0 && *p!=' ' && *p!='.' && *p!='?' && *p!='`'&& *p!='_' && *p!='~' && *p!='@' && *p!='{' && *p!='!' && (int)(*p)!=39)brojac++;
        if(*p==' ' || *p=='.' || *p=='?' || *p=='`'|| *p=='_' || *p=='~' || *p=='@' || *p=='{' || *p=='!' || (int)(*p)==39){br_slova=brojac;brojac=0;}
       
        if(broj_rijeci==vel)br_slova=brojac;
/*Ako je element niza jednak broju slova novi brojac raste za jedan, znaci raste za jedan za svaki element jedna broju slova rijeci*/        
        if(niz[broj_rijeci-1]==br_slova){
            br1++;
            br_slova=0;
        }
         
        if(max_broj_rijeci<vel && broj_rijeci==max_broj_rijeci && brojac==niz[broj_rijeci-1])br1++;
       
        p++;
    }
/*Ako je velicina novog brojaca jednaka velicini niza onda je poslani niz odgovarajuci*/    
    if(br1==vel)return 1;
    
    return 0;
    
}

int main() {

char tekst[1000];
int i,vel,niz[100];

unesi(tekst,1000);
scanf("%d",&vel);
for(i=0;i<vel;i++)scanf("%d",&niz[i]);
printf("%d", provjeri_duzine(tekst,niz,vel));

	return 0;
}
