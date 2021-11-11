#include <stdio.h>
#include <math.h>



void zaokruzi1(float* niz, int velicina)
{

	float* iza_kraja=niz+velicina;

	while(niz<iza_kraja) {
		*niz=*niz*10;
		*niz=round(*niz);
		*niz=*niz/10;
		niz++;
	}

//	for(i=0; i<velicina; i++) {
//		niz[i] = niz[i]*10;
//		niz[i] = round(niz[i]);
//		niz[i]=niz[i]/10;
//	}
}

void preslozi(float *p, int vel, int k)
{
	zaokruzi1(p, vel);
	int temp, brojc, suma, i, j, brojvecih=0;
	float temp1;

	for(i=0; i<vel; i++) {
		suma=0;
		brojc=0;
		temp=fabs(*(p+i)*10);
		do {
			brojc=brojc+1;
			temp=temp/10;
		} while (temp>=1);
		temp = fabs(*(p+i)*10);
		do {
			suma=suma+temp%10;
			temp=temp/10;
			brojc--;
		} while (brojc!=0);

		if(suma>=k) {
			for(j=i; j> 0+brojvecih; j--) {
				temp1=*(p+j-1);
				*(p+j-1)=*(p+j);
				*(p+j)=temp1;
			}
			brojvecih++;
		}

	}
}


int main()
{

	return 0;
}
