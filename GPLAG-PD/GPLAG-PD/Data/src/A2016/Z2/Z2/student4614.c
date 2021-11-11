#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define vel 500
#define epsilon 0.1

int main() {
	int br_ugl,i,step,min,sec;
	double  niz[vel];
	double n,m,pomocna;
	int pomocnija;

	printf("Unesite broj uglova: ");
	scanf("%d",&br_ugl);
	printf("Uglovi su: \n");
	for(i=0;i<br_ugl;i++){
    scanf("%lf",&niz[i]);
	}
	for(i=0;i<br_ugl;i++){
        n=niz[i];
        n=n*180/ PI;
        step=(int)n;
        m=(n-step)*60;
        min=(int)m;
        if(step >= 0){
            pomocna=3600*(n-step)-min*60;
            pomocnija = pomocna*10;
            pomocna = (double)pomocnija/10;
            pomocna+=0.5;
        }
        else {
            pomocna=3600*(n-step)-min*60;
            pomocnija = pomocna*10;
            pomocna = (double)pomocnija/10;
            pomocna-=0.5;
        }
        if(fabs(pomocna - 60) < epsilon)
        {
            sec = 0;
            min++;
            if(min > 59){
            min = 0;
            step++;
            }
        }
        else if(pomocna <= -59.9){
            sec = 0;
            min--;
            if(min <= -60){
                min = 0;
                step--;
            }
        }
        else sec = pomocna;
        if(sec>30 || sec < -30) continue;
            printf("%d stepeni %d minuta %d sekundi\n",step,(abs(min)),(abs(sec)));
	}

	return 0;
}