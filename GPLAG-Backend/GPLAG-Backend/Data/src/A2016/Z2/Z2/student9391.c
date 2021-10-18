#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define BROJ_EL 500
int main()
{
	double uglovi[BROJ_EL], ugao;
	int n, minus=0, stepeni, minute, sekunde, i;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	printf ("Uglovi su: ");
	for(i=0; i<n; i++) {
		scanf("%lf", &uglovi[i]);
		if (uglovi[i]<0) {
			uglovi[i]=-uglovi[i];
			minus=1;
		}
		ugao=(180./PI)*uglovi[i];
		stepeni= (int) (ugao);
		minute= (int) (((ugao-stepeni)*3600+0.5)/60);
		sekunde= ((int)((ugao-stepeni)*3600+0.5)%60);
		if (minute==60) {
			stepeni++;
			minute=0;
		}
		if(sekunde<=30) {
			if (minus) printf ("\n-%d stepeni %d minuta %d sekundi",stepeni,minute,sekunde);
			else printf ("\n%d stepeni %d minuta %d sekundi",stepeni,minute,sekunde);
		}
		minus=0;
	}
	return 0;
}
