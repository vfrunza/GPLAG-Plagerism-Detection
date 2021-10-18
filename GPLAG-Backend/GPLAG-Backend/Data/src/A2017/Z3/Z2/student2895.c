#include <stdio.h>
#include <math.h>
void zaokruzi1(float *niz,int duz)
{
	int i;
	for(i=0; i<duz; i++) {
		niz[i]=round(niz[i]*10)/10;
	}
}
void preslozi(float *niz,int duz,int k)
{
	int i,j,c,temp;
	int suma=0;
	int brojac=0;
	float a;
	zaokruzi1(niz,duz);
	for(i=0; i<duz; i++) {
		suma=0;
		temp=fabs(niz[i]*10);
		while(temp!=0) {
			c=temp%10;
			temp=temp/10;
			suma+=c;
			if(suma>=k) {
				for(j=i; j>brojac; j--) {//Brojevi koji ispunjavaju uslov da im je suma cifara > ili = od trazenog broja se salju na pocetak niza
					a=niz[j];
					niz[j]=niz[j-1];
					niz[j-1]=a;
				}
				brojac++; //Osigurali smo mjesto do kojeg cemo pomjerati broj
			}
		}
	}
}

int main()
{
	return 0;
}
