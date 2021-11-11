#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main() {
	double uglovi[501]={0}, step, min, sec, temp;
	int n, i, j, neg;
	

	/* Input */
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for (i=0; i<n; i++) {
	    scanf("%lf", &uglovi[i]);
	}
	
	printf("Uglovi su:\n");
	/* Konverzija radijana u stepene, minute, sekunde */
	for (i=0; i<n; i++) {
	    step = uglovi[i] * 180/PI;
	    
	    /* Negiranje stepena, jer minute i sekunde ne mogu biti negativne */
	    if (step<0) neg = -1;
	    else neg = 1;
	    
	    step = fabs(step);
	    min = (step - (int)step) * 60;
	    sec = (min - (int)min) * 60;
	    
	    /* Zaokruživanje */
	    step = (int)step * neg;
	    min = (int)min;
	    sec = (int)(sec + 0.5);
	    
	    /* Provjera za inkrement stepena, minute */
	    if (sec==60) {
	    	min++;
	    	sec=0;
	    }
	    if (min==60) {
	    	if (step<0) step--;
	    	else step++;
	    	min=0;
	    }
	    
	    /* Provjera pripadnosti intervalu u brisanje clana u protivnom */
	    if (sec<-30 || sec>30) {
	        for (j=i; j<=n; j++) {
	            temp = uglovi[j+1];
	            uglovi[j+1] = uglovi[j];
	            uglovi[j] = temp;
	        }
	        /* Smanjenje ukupnog broja clanova za 1 ako se obrise clan koji nije u intervalu */
	        n--;
	        i--;
	        continue;
	    }
	}
	
	for (i=0; i<n; i++) {
	    step = uglovi[i] * 180/PI;
	    
	    /* Negiranje stepena, jer minute i sekunde ne mogu biti negativne */
	    if (step<0) neg = -1;
	    else neg = 1;
	    
	    step = fabs(step);
	    min = (step - (int)step) * 60;
	    sec = (min - (int)min) * 60;
	    
	    /* Zaokruživanje za pritanje */
	    step = (int)step * neg;
	    min = (int)min;
	    sec = (int)(sec + 0.5);
	    
	    /* Provjera za inkrement stepena, minute */
	    if (sec==60) {
	    	min++;
	    	sec=0;
	    }
	    if (min==60) {
	    	if (step<0) step--;
	    	else step++;
	    	min=0;
	    }
	    /* Ispis */
	    printf("%g stepeni %g minuta %g sekundi\n", step, min, sec);
	}
	
	return 0;
}