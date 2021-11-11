#include <stdio.h>
#include <math.h>
void zaokruzi(double* niz, int vel) {
int i;
// zaokruzujemo na 1 decimalu
for (i=0; i<vel; i++) {
niz[i] *= 10;
niz[i] = round(niz[i]);
niz[i] /= 10;

}
}

double preslozi(double *niz,int broj_elemenata, int y){
    int i;
    double *h=niz;
    
    for (i=0;i<broj_elemenata;i++){
       zaokruzi(*niz);
       niz++;
    }
    // pravimo broj da izgleda kao int
    niz=h;
    for(i=0;i<broj_elemenata;i++){
        *niz=10*(*niz);
        niz++;
    }
    int a;
    niz=h;
    a=*niz;
    
    // !!!!???
    
    for(i=0;i<broj_elemenata-1;i++){
        
        niz++;
    
            while(*niz>0){
                a=(*niz)%10;
                a++;
            }
            
        
    }
        
}
int main() {
	return 0;
}












			