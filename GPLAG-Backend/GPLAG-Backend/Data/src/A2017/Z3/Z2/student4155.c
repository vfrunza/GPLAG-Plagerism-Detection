#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz,int vel){
 
/* Zaokruzuje svaki element niza na jednu decimalu */
    float* p = niz;
       
    while (p < niz+vel) {
         *p *= 10;
         *p = round(*p);
         *p++ /= 10;
    }
	
}

void preslozi(float* niz,int vel,int broj){
    
    int i,j=0,k=0,l=0,bez_decimale,cif,suma=0;
    float *p,*q,veci[100],manji[100],krajnji[100];

    zaokruzi1(niz,vel);

   
    for(i=0;i<vel;i++){

/* Dijeli elemente niza na cifre ciju sumu sabira */ 
        bez_decimale=fabs((int)(niz[i]*10));
	    while(bez_decimale>0){
	        cif=bez_decimale%10;
	        bez_decimale=bez_decimale/10;
	        suma=suma+cif;
	    }

/* Ako je suma cifara elementa veca od broja pohranjuje element u niz vecih a ako je manja u niz manjih */
        if(suma>=broj)veci[j++]=niz[i];
        else if(suma<broj)manji[k++]=niz[i];
        suma=0;
    }   

/* Prvi dio krajnjeg niza je niz vecih */
    l=0;    
    for(i=0;i<j;i++)krajnji[i]=veci[l++];
    
/* Drugi dio krajnjeg niza je niz manjih */
    l=0;
    for(i=j;i<j+k;i++)krajnji[i]=manji[l++];
       
/* Vrijednosti krajnjeg niza prebacujemo u prvobitni niz */    
    p=niz;
    q=krajnji;
    while(p<niz+vel){  
        *p=*q;
        p++;
        q++;
    }

    
}

int main() {
    
int i,n,k;
float niz[100];

    scanf("%d",&n);
    scanf("%d",&k);
    
    for(i=0;i<n;i++)scanf("%f",&niz[i]);
    
    preslozi(niz,n,k);
    for(i=0;i<n;i++)printf("%g ",niz[i]);

	return 0;
}
