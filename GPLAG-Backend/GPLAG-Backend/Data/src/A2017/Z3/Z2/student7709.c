#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[], int br)
{
	int i;
	for(i=0; i<br; i++) {
		niz[i]=niz[i]*10;
		niz[i]=round(niz[i]);
		niz[i]/=10;
	}
}
int saberi(float br)
{
	float ok,z,suma=0;
	ok=fabs(br)*10;
	suma=0;
	while(ok!=0) {
		z=((int)ok)%10;
		suma=suma+z;
		ok=ok/10;
	}
	return suma;
}

void preslozi(float niz[], int br, int k)
{
	int i=0,j,l,suma=0;
	double temp;
	zaokruzi1(niz,br);
	for(l=0; l<br; l++) {
		suma=saberi(niz[i]);

		if(suma<k) {
			for(j=i; j<br-1; j++) {
				temp=niz[j];
				niz[j]=niz[j+1];
				niz[j+1]=temp;
			}
			i--;
		}
		i++;

	}
}

int main()
{
	return 0;
}
