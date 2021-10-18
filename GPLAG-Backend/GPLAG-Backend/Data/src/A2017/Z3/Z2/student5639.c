#include <stdio.h>
#include <math.h>
void zaokruzi1 (float *niz, int vel){
	float *p=niz;
	int i;
	for(i=0;i<vel;i++){
		*p=round(*p*10)/10;
		p++;
	}

}

void preslozi (float niz[], int vel, int k){
	zaokruzi1(niz,vel);
	int i;
	int prvi=0,drugi=0;
	int zbir_cifara=0,prelaz=0;
	float niz1[1000], niz2[1000];
	
	for(i=0; i<vel; i++) {
		prelaz=(fabs)(*(niz+i)*10);
		do {
			zbir_cifara+=prelaz%10;
			prelaz/=10;
		} while(prelaz>0);

		if(zbir_cifara<k) {
			niz1[prvi]=*(niz+i);
			prvi++;
		} else if(zbir_cifara>=k) {
			niz2[drugi]=*(niz+i);
			drugi++;
		}
	}

	for(i=0; i<vel; i++) {
		if(i<drugi) {
			*(niz+i)=*(niz2+i);
		} else {
			*(niz+i)=*(niz1+i-drugi);
			
		}

	}
}

int main() {
	
	return 0;
}
