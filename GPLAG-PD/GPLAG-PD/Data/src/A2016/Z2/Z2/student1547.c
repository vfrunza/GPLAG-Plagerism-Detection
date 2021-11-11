#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	double niz[500], x, z, y;
	int stepeni, minute, sekunde, m, n, i, j;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);
	}
	m=n;
	printf("Uglovi su: \n");
	for(i=0; i<n; i++){
		y=niz[i]*(180/PI);
		stepeni=(int)y;
		x=(y-stepeni)*60;
		minute=(int)(x);
		z=(x-minute)*60;
		if(z<0)
		sekunde=(abs)(z-0.5);
		else if(z>0)
		sekunde=(int)(z+0.5);
		else sekunde=0;
		
		if(sekunde==60)
		{
			sekunde=0;
			minute=(abs)(minute);
			minute++;
			if (minute==60)
			{
			minute=0;
			if (stepeni<0)
			stepeni--;
			else if (stepeni>0)
			stepeni++;
			}
			
		}
		minute=(abs)(minute);
		if (sekunde<=30 && sekunde>=-30) {
			printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);}
		
		if (sekunde>30 || sekunde<-30)
			{for(j=i; j<m-1; i++)
		 	{niz[j]=niz[j+1];
		 	i--;
		 	m--;}}}
		
		
		
	return 0;
}
