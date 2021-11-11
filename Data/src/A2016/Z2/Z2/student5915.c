#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int n, i, j, sec,min,step;
	double niz[500];
	double sek;
    printf("Unesite broj uglova: ");
	scanf("%d", &n);
	printf("Uglovi su:\n");
	for(i = 0; i < n; i++){
		scanf("%lf", &niz[i]);
		niz[i] *= (180 / PI) * 60;
		sek= (niz[i] - (int) (niz[i])) *60;
		if(fabs(sek) >=30.5 && fabs(sek)< 59.5){
			for(j = i; j < n - 1; j++){
				niz[j] = niz[j + 1];
			}
			n--; 
			i--;
		}
		
    }
    for(i = 0; i < n; i++){
    	if(niz[i] > 0)
    	sec = (int)((niz[i] - (int)(niz[i])) * 60 + 0.5);
    	else sec = abs((int)((niz[i] - (int)(niz[i]))*60 - 0.5));
    	min = abs((int)((niz[i]/60 - (int)(niz[i]/60))*60));
    	step = (int)(niz[i]/60);
    	if(abs(sec) == 60 && abs(min) == 59){
    		sec = 0;
    		min = 0;
    		if(niz[i] > 0) step++;
    		else step--;
    		}
       else if(abs(sec) == 60){
       	sec = 0;
       	min++;
       }
      printf("%d stepeni %d minuta %d sekundi\n", step, min, sec);
    }
	  return 0;
}
