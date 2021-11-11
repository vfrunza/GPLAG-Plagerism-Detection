#include <stdio.h>
#include <math.h>

/* VRACA BROJ CIFRI CJELOG BROJA */

int dajDecimale(int r){
    int brojac=0;
    if(r==0)return 1;
    while(r){
        brojac++;
        r/=10;
    }
    return brojac;
}

/* IZBACUJE DUZINA KARAKTERA POCEVSI OD NEKOG KARAKTERA */

void izbaci(char *s, int duzina){
    while(*(s+duzina)){
        *s=*(s+duzina);
        s++;
    }
    *s=*(s+duzina);
}

/* PROVJERAVA TACKE I VRACA POINTER NA PRVI KARAKTER STRINGA */

char* obuhvat(char *s, float x1, float y1, float x2, float y2){
    
    char *pocetak=s;
    int duzina=0;
    int negativ;
    int razlika;
    float x, y;
    int xdec, ydec;
    /* PROVJERAVA VALIDNOST UNOSA */
    if(*s==0)return s;
    while(*s){
        if(*s=='('){
            s++;
            if(*s=='-'){
                s++;
                if(*s==0)return NULL;
                if(*s>='0' && *s<='9'){
                    while(*s>='0' && *s<='9')s++;
                    if(*s==0)return NULL;
                    if(*s=='.'){
                        s++;
                        if(*s==0)return NULL;
                        while(*s>='0' && *s<='9')s++;
                    }
                } else return NULL;
            } else if(*s>='0' && *s<='9'){
                while(*s>='0' && *s<='9')s++;
                if(*s==0)return NULL;
                if(*s=='.'){
                    s++;
                    if(*s==0)return NULL;
                    while(*s>='0' && *s<='9')s++;
                }
            } else return NULL;
            if(*s!=',')return NULL;
            s++;
            if(*s=='-'){
                s++;
                if(*s==0)return NULL;
                if(*s>='0' && *s<='9'){
                    while(*s>='0' && *s<='9')s++;
                    if(*s==0)return NULL;
                    if(*s=='.'){
                        s++;
                        if(*s==0)return NULL;
                        while(*s>='0' && *s<='9')s++;
                    }
                } else return NULL;
            } else if(*s>='0' && *s<='9'){
                while(*s>='0' && *s<='9')s++;
                if(*s==0)return NULL;
                if(*s=='.'){
                    s++;
                    if(*s==0)return NULL;
                    while(*s>='0' && *s<='9')s++;
                }
            } else return NULL;
            if(*s!=')')return NULL;
            s++;
            if(*s==0)break;
            if(*s!=',')return NULL;
            s++;
            if(*s!='(')return NULL;
        } else return NULL;
    }
    /* PRETVARA STRING U FLOAT I PROVJERAVA USLOV PRIPADNOSTI */
    s=pocetak;
    while(*s){
        if(*s=='('){
            negativ=0;
            duzina=1;
            x=0;
            y=0;
            xdec=0;
            ydec=0;
            s++;
            if(*s=='-'){
                negativ=1;
                duzina++;
                s++;
                if(*s>='0' && *s<='9'){
                    while(*s>='0' && *s<='9'){
                        duzina++;
                        x=x*10+*s-48;
                        s++;
                    }
                    if(*s=='.'){
                        s++;
                        duzina++;
                        while(*s>='0' && *s<='9'){
                            duzina++;
                            xdec=xdec*10+*s-48;
                            s++;
                        }
                    }
                } 
            } else if(*s>='0' && *s<='9'){
                while(*s>='0' && *s<='9'){
                    duzina++;
                    x=x*10+*s-48;
                    s++;
                }
                if(*s=='.'){
                    duzina++;
                    s++;
                    while(*s>='0' && *s<='9'){
                        duzina++;
                        xdec=xdec*10+*s-48;
                        s++;
                    }
                }
            } 
            duzina++;
            s++;
            x=pow(-1, negativ)*x;
            xdec=pow(-1, negativ)*xdec;
            x=x+(float)xdec/pow(10, dajDecimale(xdec));
            negativ=0;
            if(*s=='-'){
                negativ=1;
                duzina++;
                s++;
                if(*s>='0' && *s<='9'){
                    while(*s>='0' && *s<='9'){
                        duzina++;
                        y=y*10+*s-48;
                        s++;
                    }
                    if(*s=='.'){
                        s++;
                        duzina++;
                        while(*s>='0' && *s<='9'){
                            duzina++;
                            ydec=ydec*10+*s-48;
                            s++;
                        }
                    }
                } 
            } else if(*s>='0' && *s<='9'){
                while(*s>='0' && *s<='9'){
                    duzina++;
                    y=y*10+*s-48;
                    s++;
                }
                if(*s=='.'){
                    duzina++;
                    s++;
                    while(*s>='0' && *s<='9'){
                        duzina++;
                        ydec=ydec*10+*s-48;
                        s++;
                    }
                }
            } 
            s++;
            duzina++;
            y=pow(-1, negativ)*y;
            ydec=pow(-1, negativ)*ydec;
            y=y+(float)ydec/pow(10, dajDecimale(ydec));
            if(*s==0){
                if(x<x1 || x>x2 || y<y1 || y>y2){
                    if((s-duzina)!=pocetak)izbaci(s-duzina-1, duzina+1); else izbaci(s-duzina, duzina);
                    break;
                }
            } else {
                duzina++;
                if(x<x1 || x>x2 || y<y1 || y>y2){
                    razlika=1-duzina;
                    izbaci(s+razlika, duzina);
                    s=s+razlika;
                } else s++;
            }
        }
    }
    return pocetak;
}

int main() {
    char g2[] = "(0,-6),(2,3),(3.50000001,1)"; 
    char* rez;
    rez = obuhvat(g2, -3, -3, 3.5, 3.5);
    printf("'%s'", rez);
	return 0;
}
