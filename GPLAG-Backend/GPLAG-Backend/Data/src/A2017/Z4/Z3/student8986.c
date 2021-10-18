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

void najduzi_bp(char* s1, char* s2){
    
    int kont=0,i=1,broj_rijeci=1,broj_slova=0,duzina_rijeci=0,max=0,ponav=0;
    char *p,*q,*r,*t,*z,*poc,*kraj,*k;
    
    q=r=z=p=t=s1;
    k=s2;
    
    
    while(i>0){
/*Brojimo slova i stavljamo pokazivac na prvo slovo rijeci*/
        if(*p!=' ' && *p!='7' && *p!='8' && *p!='_' && *p!='@' && *p!='\0'){
            broj_slova++;
            if(broj_slova==1)r=p;
        }
/*Brojimo rijeci*/
        if(*p==' ' || *p=='7' || *p=='8' || *p=='_' || *p=='@' || *p=='\0' && broj_slova>0){
            duzina_rijeci=broj_slova;
            broj_slova=0;
            broj_rijeci++;
            
        }

   
/*Stavljamo jos jedan pokazivac na kraj rijeci*/ 
        if(broj_slova==0  && broj_rijeci>1){
            t=p;
            t--;
            
            q=r;
            z=t;
             
            
            while(q<z){
/*Duzina rijeci opada za jedan za svako slovo koje se ponavlja, poredeci ga sa zadnjim clanom stringa*/                 
                if(*q==*z || (*q)-32==*z || (*q)+32==*z){
                    
                    if(ponav==0)duzina_rijeci--;
                    ponav++;
                }
/*Kada se pokazivac pomjeri da je pored zadnjeg clana stringa vracamo ga na pocetak i vracamo pokazivac na zadnji clan za jedan*/                
                if(q+1==z){
                    q=r;
                    z--;
                    ponav=0;
                }
                 q++;
            }
/*Spasavamo adresu pokazivaca koji pokazuju na prvo i zadnje slovo najduze rijeci bez ponavljanja slova*/            
            if(duzina_rijeci>max){
                max=duzina_rijeci;
                poc=r;
                kraj=t;
                
                
            }
            
        }

       
    if(*p=='\0')break;
     
        
        p++;
    }
    
    
  
/*Kopiramo tu rijec u prazni string*/     
    while(poc<=kraj){
        *s2=*poc;
        poc++;s2++;
    }
    
    *s2='\0';
        
    kraj=s2-1;
    poc=s2=k;
    k=kraj-1;
        
        
/*Kontrola ima vrijednost nula; ako se zadnji clan stringa ponavlja smanjujemo string za jedan*/      
opet:   kont=0;    
      while(poc<=k){
          if(*kraj==*k || (*kraj)-32==*k || (*kraj)+32==*k){
              *kraj='\0';
              kraj--;
        }
            k--;
    }
   
    k=poc+1;
/*Ako se prvi clan stringa ponavlja stavljamo na njegovo mjesto razmnak i kontrol raste za jedan*/      
      while(k<=kraj){
          
          if(*k==*poc){
              *poc=' ';
              kont++;
              
          }
          
          k++;
      }
/*Ako je prvi clan razmak vracamo sve elemente za jedan*/   
   if(kont!=0){
    
    k=poc+1;
        while(*k!='\0'){
            *poc=*k;poc++;k++;
        }
 
    k--;
    *k='\0';
    }

    k--;
    poc=s2;
    kraj=k;
    k=kraj-1;

/*U slucaju da se prvi clan ponavljao ponavlja se dio koda koji provjerava da li se novi prvi clan ponavlja*/ 
    if(kont>0)goto opet;

}


int main() {

char niz[100],podniz[100];
unesi(niz,100);
podniz[0] = '\0';

 najduzi_bp(niz,podniz);
 
 printf("%s",podniz);
	
	return 0;
}
