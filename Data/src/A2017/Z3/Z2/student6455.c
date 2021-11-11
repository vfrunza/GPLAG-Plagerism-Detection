#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz, int velicina)
{
	int i;
	for(i=0; i<velicina; i++) {
		niz[i]*=10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
	}

}//da ne komplikujemo funckciju preslozi napravimo posebnu funkciju za sumu
int suma(int p)
{
	int ostatak=0, suma=0;
	if(p!=0) {
		while(p!=0) {
			ostatak=p%10;
			suma+=ostatak;
			p/=10;
		}
		return suma;
	}
	return 0;

}
void preslozi(float niz[], int velicina, int k)
{

	int i=0,j=0,brojac=0;
	float temp=0;
	zaokruzi1(niz,velicina);

	for(i=0; i<velicina; i++) {
//kada pronadjemo najveci clan u nizu for petljom ga saljemo na pocetak niza
		if(suma(fabs(*(niz+i)*10))>k || suma(fabs(*(niz +i)*10))==k) {
			for(j=i; j>brojac; j--) {
				temp=niz[j];
				niz[j]=niz[j-1];
				niz[j-1]=temp;
			}
			brojac++;

		}
	}



}
int main()
{

	return 0;
}
