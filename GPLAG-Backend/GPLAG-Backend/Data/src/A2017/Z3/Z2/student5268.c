#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int vel){
	int i;
	float temp, novi[1000];
	for(i=0; i<vel; i++){
		temp=niz[i];
		if(temp>0){
			temp=(int)(temp*10 + 0.5);
			temp=(float)(temp/10);
			novi[i]=temp;
		}
		else {
			temp=(int)(temp*10 - 0.5);
			temp=(float)(temp/10);
			novi[i]=temp;
		}
	}
	for(i=0;i<vel;i++) niz[i]=novi[i];
	}
	
int DajSumuCifara (float x) {
	int broj = 0;
	x = fabs(x);
	x*=10;
	while(x!=0){
		broj+=((int)(x))%10;
		x/=10;
	}
	return broj;	
}
	
void preslozi(float niz[], int vel, int k){
	int i, brojac1 = 0, brojac2 = 0;
	float novi[1000];
	zaokruzi1(niz,vel);
	
	for(i=0; i<vel; i++) {
		if (DajSumuCifara(niz[i]) >= k)
		brojac2++;
	}
	
	for(i=0; i<vel; i++){
		if(DajSumuCifara(niz[i])>=k) novi[brojac1++] = niz[i];
		else novi[brojac2++] = niz[i];
	}
	for(i=0; i<vel; i++) *(niz+i)=novi[i];
}
int main() {
	return 0;
}
