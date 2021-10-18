#include <stdio.h>
#define PI 3.1415926



int main() {
	int i,j,n;
	double niz[500], D, minpom, secpom, step, min, sec;
		do {
		printf("Unesite broj uglova: ");
		scanf("%d",&n);
		if(n<0 || n>500) printf("Pogresan unos.\n");
	} while(n<0 || n>500);
	for(i=0; i<n; i++){
		scanf("%lf", &niz[i]);

	}
			printf("Uglovi su:\n ");

	    for(i=0; i<n; i++){

	    D = niz[i] * 180. / PI;
		step = (int) D;
	    minpom = (D - step)*60;
        if(minpom<0) minpom*=-1;
	    min = (int)minpom;
	    secpom = (minpom-min)*60;
	    sec = (int)secpom;

	    if(secpom-sec>0.5)sec++;
        if(sec==60) {sec=0; min++;}
		if(min==60 && step>0) {min=0; step++;}
		if(min==60 && step<0) {min=0; step--;}

	    if(sec>30){
	    		for(j=i;j<n-1;j++){
	    			niz[j] = niz[j+1];
	    		}
	    		n--;
	    		i--;

	    	}
        else printf("\n%g stepeni %g minuta %g sekundi",step,min,sec);

	    }


	return 0;
}
