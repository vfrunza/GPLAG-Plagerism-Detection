#include <stdio.h>
#include <math.h>

void zaokruzi1(float A[], int a)
{
	int i;
	float y;
	for (i=0; i<a; i++) {
		y=round(A[i]*10)/10;
		A[i]=y;
	}
}

void preslozi(float A[],int a,int k)
{
	zaokruzi1(A,a);
	int i;
	float niz1 [1000], niz2[1000];
	int v1=0,v2=0;

	for (i=0; i<a; i++) {
		int x=A[i]*10;
		if (x<0)
			x=x*(-1);
		int suma=0;
		while (x>0) {
			suma+=x%10;
			x=x/10;
		}

		if (suma>=k)
			niz1[v1++]=A[i];
		if (suma<k)
			niz2[v2++]=A[i];

	}
	for (i=0; i<v1; i++)
		A[i]=niz1[i];
	for (i=0; i<v2; i++)
		A[i+v1]=niz2[i];
}


int main ()
{
	return 0;
}