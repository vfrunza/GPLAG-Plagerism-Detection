#include <stdio.h>

void zaokruzi1(float *niz,int vel){
		int i,cs;
		for(i = 0; i < vel; i++){
			cs=0;
			if(niz[i]<0){	cs=1; niz[i]=-niz[i];	}
			
			niz[i]= (int)(niz[i]*10 + 0.5) /10.;
			
			if(cs)	niz[i]=-niz[i];
			
			}
		}

void preslozi(float *niz,int vel,int k){
	int suma,pom,i,t=0,j;
	float cs;
	zaokruzi1(niz,vel);    
	for(i = 0; i < vel; i++){
		pom = niz[i]*10;
		suma = 0;
		if(pom <0)pom=-pom;
		while (pom != 0) {
			suma = suma + pom%10;
			pom/=10;
		}
		if(suma >= k){
			cs = niz[i];
			for(j = i; j > t; j--){
				niz[j] = niz[j - 1];
			}
			niz[t] = cs;
			t++;
		}
	}
}

int main() {
	int i;
float niz[] = {  -1.0, -0.1, -0.19999, -4.449999, -4.45001 };
zaokruzi1(niz, 5);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
printf("\n");
preslozi(niz,5,4);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
	return 0;
}
