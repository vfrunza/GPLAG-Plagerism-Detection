#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[],int vel)
{
	int i;
	for(i=0; i<vel; i++) {
		if(niz[i]>0)
			niz[i]=(float)(((int)(niz[i]*10+0.5))/10.);
		else niz[i]=(float)(((int)(niz[i]*10-0.5))/10.);
	}
}
void preslozi(float niz[],int vel,int k)
{
	zaokruzi1(niz,vel);
	int i,suma,j,l,cifre;
	float broj,temp1,temp2;
	suma=0;
	j=0;
	for(i=0; i<vel; i++) {
		broj=niz[i];
		broj*=10;
		cifre=(fabs)(broj);
		while(cifre!=0) {
			suma+=cifre%10;
			cifre/=10;
		}
		if(suma>=k) {
			temp1=niz[j];
			niz[j]=niz[i];
			niz[i]=temp1;
			j++;
			for(l=j; l<i; l++) {
				temp2=niz[l];
				niz[l]=niz[i];
				niz[i]=temp2;
			}
		}
		suma=0;
	}
}
int main()
{
	return 0;
}
