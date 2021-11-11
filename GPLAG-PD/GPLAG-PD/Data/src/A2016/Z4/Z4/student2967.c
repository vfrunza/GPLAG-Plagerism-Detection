#include <stdio.h>
#include <math.h>
#define epsilon 0.0001
int provjera(char *p, float Tx, float Ty,float x1,float y1,float x2, float y2){
    int izbaci=0,vrati=0;
    char*s,*kraj;
    if(Tx<x1 || Tx>x2 || Ty>y2 || Ty<y1)
        izbaci=1;
    if(izbaci==1){
        /*Izbacivanje tacke*/
        vrati=1;
        kraj=p;
        s=p;
        while(*kraj!=')'){
            if(*kraj=='\0')
                break;
            kraj++;
        }
       
        while(*kraj!='('){
            if(*kraj=='\0')
                break;
            kraj++;
        }
        if(*kraj=='\0'){
            s--;
            *s='\0';
           return 2;
        }
        while(*kraj!='\0'){
            *s=*kraj;
            kraj++;
            s++;
        }
        s--;
        while(*s==','){
            s--;
        }
        s++;
        *s='\0';
    }
    return vrati;
}
/*Funkcija koja provjerava da li je unos stringa ispravan*/
int provjera_ispravnosti(char *s){
    int vrati=1,br,nema;
    char *p,*q;
    p=s;
    while(*s!='\0'){
        if(*s!=40 && *s!=41 && *s!=44 && *s!=45 && *s!=46 && (*s<48 || *s>57 ))
            return 0;
        s++;
    }
    s=p;
    while(*s!='\0'){
        if(*s==41)
            vrati=1;
        else vrati=0;
        s++;
    }
    s=p;
    while(*s!='\0'){
        if(*s=='('){
            q=s;
            br=0;
            while(*q!=')' && *q!='\0'){
                if(*q==',')
                    br++;
                q++;
            }
            if(br>=2)
                vrati=0;
        }
        s++;
    }
    s=p;
    if(*s!='(')
        vrati=0;
    s++;
    while(*s!='\0'){
        if(*s=='.'){
            s--;
            if(*s<'0' || *s>'9')
                vrati=0;
                s++;
        }
        s++;
    }
    s=p;
    while(*s!='\0'){
        if(*s==','){
            s++;
            if(*s!='('  && (*s<'0' || *s>'9') && *s!='-')
                vrati=0;
            s--;
        }
        s++;
    }
    s=p;
    while(*s!='\0'){
        if(*s=='('){
            s++;
            if(*s!='-'  && (*s<'0' || *s>'9'))
                vrati=0;
            s--;
        }
        s++;
    }
    s=p;
    nema=0;
    while(*s!='\0'){
        if(*s=='('){
            while(*s!=')'){
                if(*s==',')
                    nema=1;
                s++;
                if(*s=='\0')
                    break;
            }
            if(nema==0)
                vrati=0;
            nema=0;
            s--;
        }
        s++;
    }
    s=p;
    while (*s!='\0') {
        if(*s==')'){
            s++;
            if(*s!='\0')
                s++;
            if(*s!='\0' && *s!='(')
                vrati=0;
            s--;
        }
        s++;
    }
    return vrati;
}
char* obuhvat(char *s,float x1,float y1,float x2, float y2){
    char *p,*vrati,*n;
    int ispravnost,predznak,brojac,br,broj_tacke=0,PR=0;
    float broj,suma1,suma2,Tx,Ty;
    vrati=s;
	ispravnost=provjera_ispravnosti(s);
	if(ispravnost==0)
	    return 0;
	p=s;
	while(*s!='\0'){
	   p=s;
	   while(*s==')' || *s==',' || *s=='('){
	        s++;
	        if(*s=='\0')
	            break;
	   }
	   if(broj_tacke!=0){
	        while(*p!='('){
	            p++;
	            if(*p=='\0')
	                break;
	        }
	    }
	    suma1=0;
	    suma2=0;
	    broj=0;
	    brojac=0;
	    Tx=0;
	    Ty=0;
	    br=0;
	    if(*s<48 || *s>57){
	        predznak=1;
	        s++;
	    }
	    else predznak=0;
	    n=s;
	    while(*n>='0' && *n<='9' && *n!='\0'){
            br++;
            n++;
            if(*n=='\0')
	            break;
        }
        /*Racunanje x koordinate tacke*/
	    while(*s>='0' && *s<='9' && *s!='\0'){
            broj=*s-48;
            broj=broj*pow(10,br);
            suma1+=broj;
            s++;
            br--;
            if(*s=='\0')
	            break;
        }
        suma1=suma1/10;
        if(*s=='.'){
            s++;
            while(*s>='0' && *s<='9' && *s!='\0'){
                broj=*s-48;
                broj=broj*10;
                suma2+=broj;
                if(*s=='\0')
	                break;
                s++;
                brojac++;
               
            }
            suma2=suma2/(pow(10,brojac+1));
        }
        Tx=suma1+suma2;
	    if(predznak==1)
	        Tx=Tx*(-1);
	    s++;
	    suma1=0;
	    suma2=0;
	    brojac=0;
	    broj=0;
	    br=0;
	    if(*s<48 || *s>57){
	        predznak=1;
	        s++;
	    }
	    else predznak=0;
	    /*Racunanje y koordinate tacke*/
	    n=s;
	    while(*n>='0' && *n<='9' && *n!='\0'){
            br++;
            n++;
            if(*n=='\0')
	            break;
        }
	    while(*s>='0' && *s<='9' && *s!='\0'){
            broj=*s-48;
            broj=broj*pow(10,br);
            suma1+=broj;
            s++;
            if(*s=='\0')
	            break;
            br--;
        }
        suma1=suma1/10;
        if(*s=='.'){
            s++;
            while(*s>='0' && *s<='9' && *s!='\0'){
                broj=*s-48;
                broj=broj*10;
                suma2+=broj;
                if(*s=='\0')
	                break;
                s++;
                brojac++;
            }
            suma2=suma2/(pow(10,brojac+1));
        }
        Ty=suma1+suma2;
	    if(predznak==1)
	        Ty=Ty*(-1);
	    PR=provjera(p,Tx,Ty,x1,y1,x2,y2);
	    if(PR==1){
	        s=p;
	    }
	    else if(PR==2){
	        *p='\0';
	        while(*p!=',' && p!=vrati)
                p--;
            while(*p!=')' && p!=vrati)
            p--;
            p++;
	        *p='\0';
	        
	        break;
	    }
	    else{
	        p=s;
	        while(*s==')' || *s==',' || *s=='('){
    	        if(*s=='\0')
	                break;
	            s++;
	        }
	    }
	    broj_tacke++;
	}
	return vrati;
}

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
int main() {
    float x1=-50,x2=50,y1=-50,y2=50;
	char s[100];
	printf("Unesi: ");
	unesi(s,100);

    printf("%s",obuhvat(s,x1,y1,x2,y2));
	return 0;
}