#include <stdio.h>
#include <math.h>
#define epsilon 0.0001

void zamjeni(float *a, float *b)
{
	float temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void zaokruzi1(float niz[], int velicina)
{
	int i;
	for(i=0; i<velicina; i++) {

		if(niz[i]>0)
			niz[i]=(int)(niz[i]*10+0.5)/10.0;

		else niz[i]=(int)(niz[i]*10-0.5)/10.0;

	}

}
int zbir_cifara(int cifra)
{
	int zbir=0;
	if(cifra<0) cifra=cifra*(-1);
	while(cifra) {
		zbir=zbir+cifra%10;
		cifra=cifra/10;
	}
	return zbir;
}

void preslozi(float niz[], int velicina, int k)
{
	float temp;
	int i, pomocna=0, pomocna2, n=0, j=0, l=0, m, n2=0;
//	float niz1[1000], niz2[1000];
	zaokruzi1(niz, velicina);
	for(i=0; i<velicina; i++) {
		pomocna=(int)(niz[i]*10);
		n=zbir_cifara(pomocna);
//		if(n>=k) {
//			niz1[j]=niz[i]; j++;
//		}
//		else {
//			niz2[l]=niz[i]; l++;
//		}

		if(n>=k) continue;
		for(m=i+1; m<velicina; m++) {
			pomocna2=(int)(niz[m]*10);
			n2=zbir_cifara(pomocna2);
			if(n2>=k) break;
		}
		if(m<velicina) {
			temp=niz[m];
			for(j=m; j>i; j--) { //VIDI ZA OVAJ DIO MOZDA IMA NEKI LOOPHOLE
				niz[j]=niz[j-1];
			}
			niz[i]=temp;

		}
	}
//	for(i=0; i<velicina; i++) {
//		if(i<j) niz[i]=niz1[i];
//		else niz[i]=niz2[i-j];
//	}
}

int main()
{

	printf("Zadaća 3, Zadatak 2");
	return 0;
}
