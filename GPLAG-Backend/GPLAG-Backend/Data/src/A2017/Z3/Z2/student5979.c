#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[],int velicina ){
	int i;
	float *pok=&niz[0];
	for (i = 0; i < velicina; i++) {
		(*pok)*=10;
		if(*pok>=0)
		*pok=*pok+0.5;
		else
		*pok=*pok-0.5;
		*pok=(int)*pok;
		*pok/=10;
		pok++;
		
	}
}
	void preslozi(float niz[],int velicina,int k)
	{
		int i,j,suma,suma2,a;
		float temp;
		float *p=niz;
		float *q=niz;
		float *mjesto;
		zaokruzi1(niz,velicina);
		for(p=niz; p<niz+velicina; p++) {
			/*Racunanje sume cifara*/
			suma=0;
			a=(*p)*10;
			if(a<0)
				a=-a;
			do {
				suma+=a%10;
				a/=10;
			} while (a>0);
			/*Ako je suma broja manja od k, trazi prvi element desno cija je suma veca od k i desni broj stavalja na mjesto lijevog zamjenjujuci ga sa svakim susjednim  brojem*/
			if(suma<k) {
				mjesto=p;
				for(q=mjesto; q<niz+velicina; q++) {
					suma2=0;
					a=(*q)*10;
					if(a<0)
						a=-a;
					do {
						suma2+=a%10;
						a/=10;
					} while (a>0);
					if(suma2>=k) {
						for (i = 0; i <q-mjesto ; i++) {
							temp=*(q-i-1);
							*(q-i-1)=*(q-i);
							*(q-i)=temp;
						}
						break;
					}
				}
			}
		}
	}
	
	
	
	
	
	

int main() {
	printf("Zadaća 3, Zadatak 2");
	return 0;
}
