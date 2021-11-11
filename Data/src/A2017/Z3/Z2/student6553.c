#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void zaokruzi1(float*pok,int vel)
{
	float*kraj=pok+vel;
	for(; pok<kraj; pok++) {
		*pok=round((*pok)*10)/10;
	}
}
int saberi_cifre(int a)
/*a je trazena suma */
{
	int suma=0;
	a=abs(a);
	while(a) {

		suma=suma+a%10;
		a/=10;
	}
	return suma;
}

void preslozi(float niz[],int vel, int a)
{
	int i=0,p=0,j;
	float temp;

	zaokruzi1(niz,vel);
	for(i=0; i<vel; i++) {
		if(saberi_cifre((int)(niz[i]*10))>=a) {

			temp=niz[i];
			for(j=i; j>p; j--) {
				niz[j]=niz[j-1];
			}
			niz[p]=temp;
			p++;
		}
    }
}

int main()
{

	return 0;
}
