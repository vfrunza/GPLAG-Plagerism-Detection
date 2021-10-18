#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[],int vel) {
	int i=0;
	for(i=0;i<vel;i++) {
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
	}
}

void preslozi(float niz[],int vel1,int k) {
	zaokruzi1(niz,vel1);
	int i,z,index=0;
	for(i=0;i<vel1;i++) {
		int cifra=niz[i]*10;
		int suma=0;
		while(cifra!=0){
			suma+=fabs(cifra%10);
			cifra/=10;
		}
		if(suma>=k) {
			float temp=niz[i];
			for(z=i;z>index;z--) {
				niz[z]=niz[z-1];
			}
			niz[index]=temp;
			index++;
		   }
			
		}
	}
	
int main() {
	/*printf("Zadaća 3, Zadatak 2");*/
	return 0;
}
