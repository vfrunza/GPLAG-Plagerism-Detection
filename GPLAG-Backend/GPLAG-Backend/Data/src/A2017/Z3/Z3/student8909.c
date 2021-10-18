#include <stdio.h>
#include <math.h>

void zaokruzi1(float B[],int m)
{
	int j;
	for(j=0; j<m; j++)
	B[j]=round(B[j]*10)/10;
}
void preslozi(float niz[],int m, int k){
	int j,suma=0,i=0,f=0;
	float nizB[1000]={0},nizC[1000]={0},B[1000]={0};
	if(m==0) return;
	else {
		zaokruzi1(niz,m);
		for(j=0; j<m; j++)
		B[j]=niz[j];
		for(j=0; j<m; j++)
		niz[j]=fabs(niz[j]*10);
		for(j=0; j<m; j++)
		{
			while (niz[j]>0) {
				suma=suma+((int)niz[j]%10);
				niz[j]/10;
			}
		if(suma>j || suma==k){
			nizB[i]=B[j];
			i++;}
		else{
			nizC[f]=B[j];
			f++;
		}
	suma=0;
}
for(j=0; j<i; j++) niz[j]=nizB[j];
for(j=i; j<(i+f); j++){
	niz[j]=nizC[j-i];
}
	return 0;
}
}
int main(void)
{return 0;}







