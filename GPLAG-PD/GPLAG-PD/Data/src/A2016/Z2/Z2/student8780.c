#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main()
{

	int i,j,a,p;
	double sekunde,stepeni,minute,niz[500];


	printf ("Unesite broj uglova: ");
	scanf ("%d",&a);


	for (i=0; i<a; i++) {
		scanf ("%lf",&niz[i]);
	}


	printf ("Uglovi su: \n");

	for (i=0; i<a; i++) {
		stepeni=(niz[i]*180)/PI;
		minute=(stepeni-(int)stepeni)*60;
		sekunde=(minute-(int)minute)*60;

		stepeni=(int)stepeni;
		minute=(int)minute;
		if (sekunde>0) {sekunde=(int)(sekunde+0.5);} else {sekunde=(int)(sekunde-0.5);}
		
		
	
        if (sekunde==60 && minute==59){minute=0;sekunde=0;stepeni=stepeni+1;}
        if (sekunde==-60 && minute ==-59){minute=0;sekunde=0;stepeni=stepeni-1;}
        if (sekunde==60){sekunde=0; minute=minute+1;}
        
if (sekunde>30 || sekunde<-30){
       for (j=i;j<a;j++)

		{
		  niz[j]=niz[j+1];
		}
		i--;
		a--; continue;}

		else { minute=fabs(minute);sekunde =fabs(sekunde) ; printf ("%.lf stepeni %.lf minuta %.lf sekundi \n",stepeni,minute,sekunde);}
	}













	return 0;
}
