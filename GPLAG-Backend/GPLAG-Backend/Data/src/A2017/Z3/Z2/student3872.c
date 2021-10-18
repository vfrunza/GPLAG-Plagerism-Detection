#include <stdio.h>
#include <math.h>
void zaokruzi1(float* niz, int vel_niza) {
    float*i = niz;
    
    while (i<niz+vel_niza){
        int t=0;
        if(*i<0){
            t=1;
            *i=-*i;
        }
        float r;
        r=(int)(*i*10 + 0.50001);
        *i=(int)(r + 0.5)/10.;
        if(t) *i=-*i;
        i++;
    }
}

/* Prije nego sto preslozimo niz, moramo da prebrojimo elemente u nizu. */

int prebroji(float n) {
    int suma = 0;
    int x;
    
    n = fabs(n);    
    x=round(n*10);      /* Zaokruzimo vrijednost sa round, jer nam je x tipa int. */      
    
    while(x){           
        suma+=x%10;
        x/=10;
    }
    
    return suma;
}

void preslozi(float* p, int vel_niza, int k) {
    zaokruzi1(p, vel_niza);
    float temp;
    int i, j;
    
    for(i=0; i<vel_niza; i++) {
        for(j=0; j<vel_niza-1; j++){
            if(prebroji(p[j+1])>=k && prebroji(p[j])<k) {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
            
        }
    }
    
}


int main() {
    float niz[] = {13.1, 15.749999, 15.75, 9.222, 78.1};
    int i;
    preslozi(niz, 5, 14);
    
    printf("Niz glasi: ");
    for(i=0; i<5;i++)
        printf("%g", niz[i]);
        
	return 0;
}
