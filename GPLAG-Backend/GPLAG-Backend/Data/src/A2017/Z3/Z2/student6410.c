#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[], int vel){
	int i;
	for(i=0; i<vel; i++){
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
	}
}


void preslozi(float niz[], int vel, int k){ 
	int m,i, vela=0, velb=0,  n=0, cifra=0;
		float b[1000], a[1000];
			zaokruzi1(niz,vel);
	for(i=0; i<vel; i++){ 
	   m=niz[i]*10; 
	  	
	  
		while(m!=0){
			cifra=fabs(m%10);
				n+=cifra; 
			m/=10;
			
		} if(n>=k) {a[vela]=niz[i]; vela++;}
		else {b[velb]=niz[i]; velb++;}
		n=0;
		
	
	}
	
	for (i=0; i<vela; i++)
    { 
    	niz[i]=a[i];
    }

    for (i=0; i<velb; i++)
    { 
    	niz[i+vela]=b[i];
    }
}


int main() {
	float niz[1000];
	int vel;
	int i,k;
	scanf("%d", &vel);
	printf("Unesite clanove niza:");
	for(i=0; i<vel; i++){
		scanf("%f", &niz[i]);
	}
	printf("Unesite koeficijent k:");
	scanf("%d", &k);
      preslozi(niz, vel, k);
	
	return 0;
}