#include <stdio.h>
#include <math.h>

void zaokruzi1(float *niz, int velicina){
	
	int i;
	for(i=0; i<velicina; i++) niz[i]=round(niz[i]*10) / 10;
}

void preslozi(float *niz, int velicina, int k){
	
	int i, a, suma, brv=0, brm=0, pomniz[1000], v=0, m=0, j=0;
	float nizv[1000], nizm[1000];
	
	zaokruzi1(niz,velicina);
	
	for(i=0; i<velicina; i++){
		pomniz[i]=niz[i]*10;
		if(pomniz[i]<0) pomniz[i]*=(-1);
	}
	
	for(i=0; i<velicina; i++){
		suma=0;
		a=pomniz[i];
		while(a!=0){
			suma+=a%10;
			a=a/10;
		}
		
		if(suma>=k) brv++;
		else if(suma<k) brm++;
	}
	

	for(i=0; i<velicina; i++){
		suma=0;
		a=pomniz[i];
		while(a!=0){
			suma+=a%10;
			a=a/10;
			
			
		}
		
		if(suma>=k){ nizv[v]=niz[i]; v++; }
		else if(suma<k){ nizm[m]=niz[i]; m++; }
	}
	
	
	for(i=0; i<brv; i++) niz[i]=nizv[i];
	for(i=brv; i<(brv+brm); i++){ niz[i]=nizm[j]; j++;}
	
}

int main() {
	float niz[1000];
	int velicina,k,i;
	
	printf("Unesi k: ");
	scanf("%d", &k);
	
	printf("Koja je velicina niza? ");
	scanf("%d", &velicina);
	
	printf("Unesi niz: ");
	for(i=0; i<velicina; i++) scanf("%f", &niz[i]);
	
	preslozi(niz,velicina,k); 
	
	printf("Niz glasi: ");
	for(i=0; i<velicina; i++) printf("%g ", niz[i]);
	
	return 0;
}
