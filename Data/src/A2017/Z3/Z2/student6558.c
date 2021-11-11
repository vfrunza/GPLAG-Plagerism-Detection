#include <stdio.h>
#include <math.h>

void zaokruzi1 (float* niz, int velicina) {
	int i;
	for(i=0; i<velicina; i++){
		*(niz+i)=round(*(niz+i)*10)/10;
	}
	
}
void preslozi (float* niz, int velicina, int k){
	
	float  temporal,temporal_sume;
	int i,temp,c,j,veci;
	int suma_cifri[100]= {0};
	zaokruzi1(niz, velicina);
		for(i=0; i<velicina; i++) {
		temp=(*(niz+i)*100)/10;
/*Rastavljanje broja na cifre i upisivanje sume*/
		while(temp!=0) {
			c=temp%10;
			suma_cifri[i]+=c;
			temp/=10;
		}

	}
/*Algoritam sortiranja*/
	for(i=0; i<velicina; i++){
		if(suma_cifri[i]<k){
			veci=i;
			for(j=i+1; j<velicina; j++){
				if(suma_cifri[j]>k){
					veci=j; 
					break;
				}
			}
			temporal=*(niz+i);
			*(niz+i)=niz[veci];
			niz[veci]=temporal;
			temporal_sume=suma_cifri[i];
			suma_cifri[i]=suma_cifri[veci];
			suma_cifri[veci]=temporal_sume;
			
			
		}
	}
	
	
}
int main() {
	float niz[7]= {123.9,133.3,111.1,996.4,452.6, 999.3, 111.2};
	int i;
	zaokruzi1(niz, 7);
	for(i=0; i<7; i++){
		printf("%g ", niz[i]);
	}
	printf("\n");
	preslozi(niz,7,14);
	for(i=0; i<7; i++){
		printf("%g ", niz[i]);
	}
	return 0;
}
