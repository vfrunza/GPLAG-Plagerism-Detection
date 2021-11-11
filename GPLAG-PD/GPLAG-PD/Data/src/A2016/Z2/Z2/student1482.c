#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1415926
int main() {
	int broj_cl,n,i;
	double niz[500];
	float stepeni,sekunde,minute;
	printf("Unesite broj uglova: ");
	scanf("%d",&broj_cl);
	
	if (broj_cl<=500) {
		for(n=0;n<broj_cl;n++)
			scanf("%lf",&niz[n]);
		printf("Uglovi su:\n");
		
		for(n=0;n<broj_cl;n++) {
			stepeni=niz[n]*180/PI;
			minute=fabs((stepeni-(int)stepeni)*60);
			sekunde=fabs((minute-(int)minute)*60);

			sekunde=(int)(sekunde+0.5);
			stepeni=(int)stepeni;
			minute=(int)minute;
		
			if(sekunde==60)	{
				sekunde=0;
				minute++;
			}
			
			if(minute==60) {
				minute=0;
				if(stepeni<0)
					stepeni--;
				else
					stepeni++;
			}
		
			if (sekunde>30) {
				for(i=n;i<broj_cl-1; i++) 
					niz[n]=niz[i+1];
				broj_cl--;
					n--;
			}
			else 
				printf("%.f stepeni %.f minuta %.f sekundi\n",stepeni,minute,sekunde);
		}
 	}
	
	return 0;
}