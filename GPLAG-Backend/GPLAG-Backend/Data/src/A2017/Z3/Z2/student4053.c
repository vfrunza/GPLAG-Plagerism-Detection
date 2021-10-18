#include <stdio.h>
#include<math.h>
void zaokruzi1(float *niz,int vel)
{
	int j;
	float* p =niz;
	for(j=0; j<vel; j++) {
		while(p < niz+vel) {
			*p=round(*p*10)/10;
			p++;
		}
	}
}
void preslozi(float *niz,int vel,int k)
{
	int velp=0;
	float nizp[100000];
	int nizsuma[100000];
	int i,j,z;
	int suma,pom;

	zaokruzi1(niz,vel);
	for(i=0; i<vel; i++) {
		suma=0;
		pom=*(niz+i)*10;
		pom=fabs(pom);
		while(pom>0) {
			suma= suma + pom%10;
			pom=pom/10;
		}
		nizsuma[i]=suma;
		suma=0;
	}

	for(j=0; j<vel; j++) {
		if(nizsuma[j]>=k)

		{
			nizp[velp]=*(niz+j);
			velp++;
		}
	}
	for(z=0; z<vel; z++) {
		if(nizsuma[z]<k) {

			nizp[velp]=*(niz+z);
			velp++;
		}

	}
	zaokruzi1(nizp,velp);
	for(i=0; i<vel; i++) {
		*(niz+i)=nizp[i];
	}

}
int main()
{

	return 0;
}
