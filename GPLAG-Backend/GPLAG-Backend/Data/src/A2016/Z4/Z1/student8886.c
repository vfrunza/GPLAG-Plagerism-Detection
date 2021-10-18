#include <stdio.h>
#include <ctype.h>

char prazan_string[10000];

/*Funkcija za unos stringa*/
void unesi(char *niz, int vel) {
    int i=0;
    char znak=getchar();
    if (znak=='\n') znak=getchar();
    while (i<vel-1 && znak!='\n') {
            niz[i]=znak;
            i++;
            znak=getchar();
        }    
        niz[i]='\0';
}

/*Trazenje rijeci koja se ponavlja najveci broj puta*/
char* pronadji_najcescu (char *s) {
    char *p=s, *poc1, *poc2, *pocmax, *kraj, *krajmax, *pom1, *k, *z, *w;
    int brojac=0, max=0, i=0, ista;
   
    while (*p!='\0') {
    
        if (toupper (*p)>='A' && toupper (*p)<='Z') {
            poc1=p;
            while (toupper (*p)>='A' && toupper (*p)<='Z')
            p++;
            
            /*Oznacavanje trenutne rijeci koja se poredi s ostalima u stringu*/
            if (*p==' ' || *p=='\0') {
                kraj=p;
                pom1=p;
                brojac=1;
                while (*pom1!='\0') {
                    if (toupper(*pom1)>='A' && toupper(*pom1)<='Z') {
                        poc2=pom1;
                        while (toupper(*pom1)>='A' && toupper(*pom1)<='Z') 
                            pom1++;
                            if (*pom1==' ' || *pom1=='\0') {
                                /*Pretpostavka da smo pronasli istu rijec*/
                                ista=1;
                                k=poc1;
                                z=poc2;
                                while (k!=kraj) {
                                    if (toupper(*k++)!=toupper(*z++)) {
                                        ista=0;
                                        break;
                                    }
                                }
                                /*Uvecavanje brojaca nakon prvog ponavljanja jedne rijeci*/
                                if (ista==1) brojac++;
                            }
                        } 
                        else pom1++;
                    }
                    /*Pronalazak najveceg broja ponavljanja neke rijeci*/
                    if (brojac>max) {
                        pocmax=poc1;
                        krajmax=kraj;
                        max=brojac;
                    }
                }
            }
            else p++;
        }
        /*Upisivanje rijeci koja se ponovi najveci broj puta u prazan string*/
        while (pocmax!=krajmax) {
            prazan_string[i]=*pocmax;
            i++;
            *pocmax++;
        }
        prazan_string[i]='\0';
        w=&prazan_string[0]; 
    return w;
}

/*Izbacivanje rijeci koja se ponovi najveci broj puta*/
char* izbaci_najcescu(char *s) {
    char *p=s, *poc1, *kraj, *pom1, *k, *q;
    int jeste;
    
    if (*s=='\0') return 0;
    q=pronadji_najcescu(p);
    
    while (*p!='\0') {
        if ((toupper(*p)>='A' && toupper(*p)<='Z') && (*(p+1)!=' ' || *(p+1)=='\0')) {
            poc1=p;
            pom1=p;
            while (toupper(*p)>='A' && toupper(*p)<='Z')
            p++;
            /*Poredjenje rijeci u stringu 'string' s rijeci iz stringa 'prazan_string'*/
            k=q;
            jeste=1;
            kraj=p;
            
            while (poc1!=kraj) {
                if (toupper(*k++)!=toupper(*poc1++)) {
                    jeste=0;
                    break;
                }   
            }
            /*Izbacivanje rijeci iz stringa 'string' ukoliko je pretpostavka tacna*/
            if (jeste==1) {
                while(*kraj!='\0') 
                    *pom1++=*kraj++;
                *pom1='\0';
                p=p-(kraj-pom1);
            }
        }
        else p++;
    }
    return s;
}

int main() {
char string[10000];
unesi(string, 10000);
    printf ("'%s'", izbaci_najcescu(string));
  return 0;
}
