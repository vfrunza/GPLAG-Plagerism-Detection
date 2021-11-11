#include <stdio.h>
#include <math.h>

int velicina(int brojj){
	int velicina=0;
	while(brojj!=0){
		brojj=brojj/10;
		velicina++;
	}
	return velicina;
}

int funkcija_koja_vraca_broj (int niz, int velicina){
    int i;
    int broj=0;
    for(i=0; i<velicina; i++){
        broj+=pow(10,i)*niz[i];
    }
    return broj;
}


int novi(int broj, int niz, int velicinaa){
    int novibrojj=broj;
    int vel=velicina(broj);
    int noviniz[9];
    int i, j;
    for(i=0, i<vel; i++){
        noviniz[vel-1]=novibrojj%10;
        novibroj=novibrojj/10;
    }
    
    for(i=0; i<vel; i++){
        for(j=0; j<velicinaa; j++){
            if(noviniz[i]==niz[j]){
                
                
            }
        }
        v--;
    }
    if(v==0){
        novibrojj=0; 
        return novibrojj;
    }
    
    novibrojj=funkcija_koja_vraca_broj(noviniz, vel);
    return novibrojj;
    
}

int izbaci_cifre(int prvi, int vel1, int drugi, int vel2){
    int i, j;
    for(i=0; i<vel2; i++){
        if(i<0 || i>9) 
        return 0;
    }
    
    for(i=0; i<vel2; i++){
        for(j=i; j<vel2; j++){
            if(drugi[i]==drugi[j])
            return 0;
        }
    }
    
    
    int novibroj;
    for(i=0; i<vel1; i++){
        novibroj=novi(prvi[i], drugi, vel2);
        prvi[i]=novibroj;
    }
    return 1;
    
}


int main() {
    
    return 0;
}
