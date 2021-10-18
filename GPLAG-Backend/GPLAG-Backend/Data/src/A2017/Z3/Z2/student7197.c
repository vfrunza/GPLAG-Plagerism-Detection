#include <stdio.h>
#include <math.h>
int SumaCifara(int n)
{
	if(n<0)n=-n;
	int sum=0;
	do{
		sum+=n%10;
		n/=10;
	}while(n);
	return sum;
}
void zaokruzi1(float *niz, int n)
{
	int i;
	for(i=0;i<n;i++)
		if(niz[i]>0)
		niz[i]=round((int)(niz[i]*10 + 0.5))/10;
		else
		niz[i]=round((int)(niz[i]*10 - 0.5))/10;
		
}
void preslozi(float *niz, int velicina, int k)
{
	zaokruzi1(niz,velicina);
	int nizSuma[100],i,brojac=0;
	float noviNiz[100];
	for(i=0;i<velicina;i++)
		nizSuma[i] = SumaCifara((int)(niz[i]*10));
		
	for(i=0;i<velicina;i++)
		if(nizSuma[i]>=k)
			noviNiz[brojac++]=niz[i];
			
	for(i=0;i<velicina;i++)
		if(nizSuma[i]<k)
			noviNiz[brojac++]=niz[i];
			
	for(i=0;i<velicina;i++)
		niz[i]=noviNiz[i];
}
int main() {
	int i;
	float niz[] = { 13.1, 15.749999, 15.75, 9.222, 78.1 };
	zaokruzi1(niz, 5);
	printf("Niz glasi: ");
	for (i=0; i<5; i++)
    	printf("%g ", niz[i]);
	return 0;
}
