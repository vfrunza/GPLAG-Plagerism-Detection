#include <stdio.h>
#define PI 3.1415926
#define EPS 1e-5
#include <math.h>
double round(double sek);

int main() {
	int broj_el, i, j;
	double niz[500], r, step, min, sek;
	printf("Unesite broj uglova: ");
	scanf("%d", &broj_el);
	for(i=0; i<broj_el; i++) {
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su:\n");
	for(i=0;i<broj_el;i++) {
		r=niz[i];
		step=(r*180./PI);
		min=fabs((step-(int)(step))*60);
		sek=round((min-(int)(min))*60);
		sek=fabs(sek);
		step=(int)step;
		min=(int)min;
			if(fabs(sek-60)<=EPS) {
				min++;
				sek=0;
				if(fabs(min-60)<=EPS) {
					if(step<0) {
						step--;
					}
					else {
						step++;
					}
					min=0;
				}
				
			}
		if(fabs(sek)>30 && fabs(sek)<60) {
		
			for(j=i;j<broj_el-1;j++) {
				niz[j]=niz[j+1];
			}
			broj_el--;
			i--;
		}
		else
		printf("%g stepeni %g minuta %g sekundi\n", step, min, sek);
	}
	
	
	return 0;
}
