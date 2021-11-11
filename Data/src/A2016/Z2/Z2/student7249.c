#include <stdio.h>
#define PI 3.1415926
int main() {
	double niz[500], x, x2, sekunde;
	int n, i=0, j=0, stepeni, minute, sekunde2;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++) {scanf("%lf", &niz[i]);}
	printf("Uglovi su: ");
	for(i=0;i<n;i++)
	{	
		stepeni=(int)(180*niz[i]/PI);
		minute=(int)(60*((float)(180*niz[i]/PI)-(int)(180*niz[i]/PI)));
		x=60*((float)(180*niz[i]/PI)-(int)(180*niz[i]/PI));
		x2=x-(int)x;
		sekunde=x2*60;
		sekunde=sekunde+0.5;
		sekunde2=sekunde;
		if(sekunde2>=60) {sekunde2=sekunde2-60; minute=minute+1;}
		if(minute>=60) {minute=minute-60; stepeni=stepeni+1;}
		if(sekunde2>30) 
		{for(j=i;j<n-1;j++)
			{ niz[j]=niz[j+1];
			}
			n--;
			i--;
			continue;
			}
		printf("\n%d stepeni %d minuta %d sekundi", stepeni, minute, sekunde2);
	}
	return 0;
}
