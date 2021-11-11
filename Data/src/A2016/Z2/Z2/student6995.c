#include <stdio.h>
#define PI 3.1415926
int main() {
	int n ;
	printf("Unesite broj uglova: ");
	scanf ("%d", &n);
	float niz[500];
	int i;
	float ugao ;
	for (i=0; i<n; i++) {
	//	printf("Unesi %d. ugao", i+1);
		scanf("%f",&ugao);
		niz[i]=ugao ;
	}
	int j=0;
	 int min, sek, step;
	 double pok ;
	for (i=0; i<n ;i++) {
		pok=(niz[i]*180/PI);
		step=(int)pok;
		if (pok<0) pok=pok*(-1);
		pok=pok-step;
	//	if (pok<0) pok=pok*(-1);
		min=(int)(pok*60);
	//	if (min<0) min=min*(-1);
	//	pok*=60;
	//	sek=pok-(step*60+min*60);
		pok=pok*60-min;
	//	if (pok<0) pok=pok*(-1);
		sek=(int)(pok*60+0.5);
	//	if (sek<0) sek=sek*(-1);
		if (sek == 60) {
			sek=0; 
			min++;
		}
		if (min == 60){
			min=0;
			step++;
		}
		//if (i==n-1 && (int)sek>30){n--; break;}
		if (sek>30){
			if(i==n-1){n--;continue;}
			for (j; j<n;j++){
				niz[j]=niz[j+1];
			}
			n--;
			//if(i==n-1)n--;
		}
		j++;
		//if ((int)sek>30 && i==n-1){n--;continue;}
	}
	printf ("Uglovi su: ");
	for (i=0;i<n; i++) {
		pok=(niz[i]*180/PI);
	step=(int)pok;
		pok=pok-step;
		if (pok<0) pok=pok*(-1);
		min=(int)(pok*60);
	//	if (min<0) min=min*(-1);
	//	sek=pok-(step*60+min*60);
		pok=pok*60-min;
	//	if (pok<0) pok=pok*(-1);
		sek=(int)(pok*60+0.5);
	//	if (sek<0) sek=sek*(-1);
		if (sek == 60) {
			sek=0; 
			min++;
		}
		if (min == 60){
			min=0;
			step++;
		}
 		if (sek<=30) printf("\n%d stepeni %d minuta %d sekundi", step, min, sek);
	}
	return 0;
}
