#include <stdio.h>
#include <math.h>

int  zaokruzi1(float niz[], int vel) {
	int i=0;
	for(i=0; i<vel; i++) {
		niz[i] = round(niz[i]*10)/10;
	}
	return vel;
}

unsigned suma_cifara(float broj) {
	unsigned novi=0,suma=0;
	broj*=10;
	if(broj < 0) broj*= -1;
	novi = (int)(broj);
	while(novi !=0) {
		suma += novi%10;
		novi /= 10;
	}
	return suma;
}

int preslozi(float *niz,int vel,unsigned k){
	float krit1[1000]={0},krit2[1000]={0};
	unsigned i,j,kk=0,l=0,x=0;
	vel=zaokruzi1(niz,vel);
	for(i=0;i<vel;i++){
		if(suma_cifara(niz[i])>=k){
			krit1[kk++]=niz[i];
		}
		if(suma_cifara(niz[i])<k){
			krit2[l++]=niz[i];
		}
	}
		for(i=0;i<kk;i++){
			niz[i]=krit1[i];
		}
		for(j=kk;j<l+kk;j++){
			niz[j]=krit2[x++];
		}
	
	return vel;
}

int main() {
	int i;
	float niz[] = { -1.0, -0.1, -0.19999, -4.449999, -4.45001 };
	zaokruzi1(niz, 5);
	printf("Niz glasi: ");
	for (i=0; i<5; i++)
	    printf("%g ", niz[i]);
	return 0;
}
