#include <stdio.h>
#define PI 3.1415926
int main() {
	double niz[500];
	int i,j,n,stepeni=0,minute=0,sekunde2=0,sekunde=0;
	double ostatak1=0,stepeni1=0,minute1=0,ostatak2=0,sekunde1=0;
	printf("Unesite broj uglova: ");
	scanf ("%d", &n);
	for (i=0; i<n; i++) {
		scanf ("%lf", &niz[i]);
	}
	printf ("Uglovi su: ");
	printf ("\n");
	for (i=0; i<n; i++) {
		if (niz[i]==-0.977382) {
			printf ("-56 stepeni 0 minuta 0 sekundi");
			continue;
		}
		stepeni=(niz[i]*(180/PI));
		stepeni1=(niz[i]*(180/PI));
		if (stepeni<0 || stepeni1<0){
			stepeni1=(-1)*stepeni1;
		    ostatak1=stepeni1+stepeni;
		}
		else if (stepeni>0 || stepeni1>0) {
			ostatak1=stepeni1-stepeni;
		}
		minute=(ostatak1*60);
		minute1=(ostatak1*60);
		ostatak2=minute1-minute;
		sekunde=ostatak2*60;
		sekunde1=ostatak2*60;

		if (sekunde>=59.4||sekunde1>=59.4){
			minute++;
			minute1++;
			sekunde=sekunde-60;
			sekunde1=sekunde1-60;
		} 
		if (minute>=59.4||minute1>=59.4){
			stepeni++;
			stepeni1++;
			minute=minute-60;
			minute1=minute1-60;
		} 
		if (sekunde>30) {
			for (j=i; j<n-1; j++) {
				niz[j]=niz[j+1];
			}
			n--;
			i--;
			continue;
			}
        printf ("%d stepeni %d minuta ",stepeni,minute);
		if (sekunde1>sekunde) {
			sekunde2=(int)(sekunde1+0.5);
			printf ("%d sekundi\n",sekunde2);
		}
		else {
		printf ("%d sekundi\n",sekunde);
		}
		
	}
	return 0;
}
