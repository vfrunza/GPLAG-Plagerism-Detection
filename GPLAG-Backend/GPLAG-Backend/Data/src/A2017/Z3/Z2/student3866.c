#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int v)
{
	int i;
	for(i=0; i<v; i++)
		niz[i]=round((niz[i]*10))/10.;
}
int dajSumu(float br)
{
	int brNovi, suma=0;
	br*=10;
	if(br<0) br*=(-1);
	brNovi=br;

	while(brNovi) {
		suma+=brNovi%10;
		brNovi/=10;
	}
	return suma;
}

void preslozi (float niz[], int v, int k)
{
	float temp;
	int brojac=0, i,j;

	zaokruzi1 (niz,v);

	for(i=0; i<v; i++)
		if(dajSumu(niz[i])>=k) {
			temp=niz[i];
			for(j=i; j>brojac; j--)
				niz[j]=niz[j-1];
			niz[brojac]=temp;
			brojac++;
		}
}
int main()
{
	return 0;

}