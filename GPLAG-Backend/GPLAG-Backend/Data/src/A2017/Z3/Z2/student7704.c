#include <stdio.h>
#include <math.h>
int suma(float br)
{
	int broj=(int)round(fabs(br)*10);
	int s=0;

	do {
		s+=broj%10;

		broj=broj/10;
	} while(broj!=0);

	return s;
}
void zaokruzi1(float *p, int n)
{
	int i;
	for(i=0; i<n; i++) {
		*(p+i)=((int)round(*(p+i)*10))/10.;
	}
}
void preslozi(float *p, int n, int k)
{
	int i,s,j,poz=0;
	float temp;
	//poziv funckije zaokruzi
	zaokruzi1(p,n);
	for(i=0; i<n; i++) {
		// pozivanje funkcije koja vraca sumu elemenata broja
		s=suma(*(p+i));

		if(s>=k) {
			temp=*(p+i);
			//pomjeranje elemenata za jedno mjesto udesno
			for(j=i; j>poz; j--) {
				*(p+j)=*(p+j-1);
			}
			*(p+poz)=temp;
			//pozicija posljednjeg elementa cija je suma veca od zadatog broja k
			poz++;
		}
	}
}
int main()
{
	int k=9,i;
	float niz[5]= {6.24, 6.23, 7.77, 2.222, 3.55 };
	//poziv funkcije preslaganja niza u odnosu na broj k
	preslozi(niz,5,k);
	printf("Niz glasi: ");
	for(i=0; i<5; i++) {
		printf("%g ",niz[i]);
	}
	return 0;
}
