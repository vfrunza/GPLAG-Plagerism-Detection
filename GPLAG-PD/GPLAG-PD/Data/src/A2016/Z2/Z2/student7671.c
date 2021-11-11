#include <stdio.h>
#include <math.h>
#define  PI 3.1415926

int main() {
	float niz[500], Stepeni, Minute, Sekunde, minute;
	int a, i, j, sekunde;
	printf ("Unesite broj uglova: ");
	scanf ("%d", &a);
	for(i=0;i<a;i++) {
		scanf ("%f", &niz[i]);
	}
	printf ("Uglovi su: ");
	for(i=0;i<a;i++) {
		Stepeni=niz[i]*180/PI;
		Minute=(Stepeni-(int)Stepeni)*60;
		Sekunde=(Minute-(int)Minute)*60;
		if(Sekunde>=0) 
		sekunde=(int)(Sekunde+0.5); 
		else if (Sekunde<0)
		sekunde=(int)(Sekunde-0.5);
		minute=Minute;
		if (sekunde==60) {
				Minute++;
				sekunde=0;
				if ((int)Minute==60) {
					Minute=0;
					Stepeni++;
				}
				else if((int)Minute>60) {
					Stepeni++;
					minute=0;
					for(j=0;j<Minute-59;j++) {
						minute++;
					}
					Minute=minute;
				}
		}
		else if (sekunde==-60) {
				Minute--;
				sekunde=0;
			if ((int)Minute==-60) {
				Minute=0;
				Stepeni--;
			}
			else if ((int)Minute<-60){
				Stepeni--;
				minute=0;
				for(j=0;j<Minute+59;j++){
					minute++;
				}
				Minute=minute;
			}
		}
		if (fabs(sekunde)<=30) {
			if(sekunde>=0)
			printf ("\n%d stepeni %d minuta %d sekundi", (int)Stepeni, (int)Minute, sekunde);
			else if(sekunde<0)
			printf ("\n%d stepeni %d minuta %d sekundi", (int)Stepeni, -(int)Minute, -sekunde);
		}
		else continue;
	}
return 0;
}

		