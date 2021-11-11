#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define BROJ_EL 500
int main() {
	double niz[BROJ_EL], m;
	int b, i, j, k, stepeni, minute, sekunde;
	printf("Unesite broj uglova: ");
	scanf("%d", &b);
	
	for(i=0; i<b; i++){
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su: \n");
	for(j=0; j<b; j++){
		niz[j] *= (double) 180 / PI;
		stepeni = ((int) niz[j]);
		
		if(niz[j] >= 0){
			
		m = (niz[j] - ((int) niz[j]))*60;
		minute = (int) (m);
		
		
		sekunde =  (int) ((m -(int) m)*60+ 0.5);
		
		if(sekunde > 59){
			sekunde -= 60;
			minute++;
		}
		
		if(minute > 59){
			minute -= 60;
			stepeni++;
		}
		}else{
			m = (niz[j] - ((int) niz[j]))*60;
		    minute = abs((int)(m));
		    
		    sekunde = abs((int) ((m -(int) m)*60 - 0.5));
		    
		    if(sekunde > 59){
		    	sekunde -= 60;
		    	minute++;
		    }
		    
		    if(minute > 59){
		    	minute -=60;
		    	stepeni--;
		    }
		}
		
		if(sekunde > 30){
			for(k=j; k<b-1; k++){
				niz[k] = niz[k+1];
			}
			b--;
			j--;
		}else{
		printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);
		}
	}
	return 0;
}
