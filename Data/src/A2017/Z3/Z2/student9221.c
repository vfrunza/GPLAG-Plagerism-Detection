#include <stdio.h>
#include <math.h>

void zaokruzi1(float* niz, int vel)
{
	int i;
	int pom;
	for(i=0; i<vel; i++) {
		pom=round(niz[i]*10);
		niz[i] = pom/10.;
	}
}

void preslozi(float* niz, int vel, int zbir)
{
	int pomocni[100];
	int i,j;
	int suma;
	float temp1;
	int temp2;
	int brojac=vel-1;
	zaokruzi1(niz,vel);
	for(i=0; i<vel; i++) {
		pomocni[i]=fabs(niz[i]*10);
		suma=0;
		while(pomocni[i]!=0) {
			suma+=pomocni[i]%10;
			pomocni[i]/=10;
		}
		pomocni[i]=suma;
		//printf("broj %f i suma %d\n", niz[i], pomocni[i]);
	}

	
	for(i=0; i<brojac; i++) {
		if(pomocni[i]<zbir) {
			temp1=niz[i];
			temp2=pomocni[i];
			for(j=i; j<vel-1; j++) {
				niz[j]=niz[j+1];
				pomocni[j]=pomocni[j+1];
			}
			niz[vel-1]=temp1;
			pomocni[vel-1]=temp2;
			brojac--;
			i--;
		}
	}
}

int main()
{
	int i;
float niz[] = { 3.2, -4.301, -123.1999, 6.1, 0.9 };
preslozi(niz, 5, 4);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
	return 0;
}
