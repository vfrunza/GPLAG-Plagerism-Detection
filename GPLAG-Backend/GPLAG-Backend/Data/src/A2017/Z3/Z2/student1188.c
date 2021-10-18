#include <stdio.h>
#include <math.h>	/* zbog fja round i fabs*/


void zaokruzi1(float* niz, int vel){
	int i;
	for(i=0; i<vel; i++){
		niz[i]=round(niz[i]*10)/10;
	}
}

int suma_cifara(float broj){
	int suma=0;
	broj=fabs(broj*10); /* broj*10 jer su u nizu svi brojevi zaokruženi na jednu decimalu*/
	while((int)(broj)!=0){
		suma+=(int)(broj)%10;
		broj/=10;
	}
	return suma;
}

void zamijeni(float* p, float* q){
	float temp=*p;
	*p=*q;
	*q=temp;
}

void preslozi(float* niz, int vel, int k){
	int i, j, l;
	zaokruzi1(niz, vel);
	
	for(i=0; i<vel; i++){
		if( suma_cifara(niz[i]) < k) { 					/* treba ga mijenjati */
			for(j=i+1; j<vel; j++){ 					/* tražim prvi čija je sumac >= k */
				if( suma_cifara(niz[j]) >= k){ 			/* sve od jtog pa do itog postepeno zamjenjuj */
					for(l=j-1; l>=i; l--){
						zamijeni(&niz[l+1], &niz[l]);
					}
					break;
				}
			}
		}
		
	}
	
	
}


int main() {
	int i;
	float vector[]={13.1, 15.749999, 15.75, 9.222, 78.1};
	/*zaokruzi1(vector, 5);*/
	
	preslozi(vector, 5, 14); 
	for(i=0; i<5; i++){
		printf("%g ", vector[i]);
	}
	return 0;
}
