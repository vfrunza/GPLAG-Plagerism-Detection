#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double uglovi [500], u_stepenima; 
	int broj_elemenata;
	int i, j, stepeni, min, sec, znak;
	printf("Unesite broj uglova: ");
	scanf("%d",&broj_elemenata);
	for(i=0; i<broj_elemenata; i++)
		scanf("%lf", &uglovi[i]);
	for(i=0; i<broj_elemenata; i++) {
		if(uglovi[i] >= 0)
			znak = 1;
		else
			znak = -1;
		u_stepenima = 180/PI*uglovi[i];
		stepeni = (int)u_stepenima;
		min = (int)((u_stepenima-(int)u_stepenima)*60);
		sec = (int)(((u_stepenima-(int)u_stepenima)*60 - (int)((u_stepenima-(int)u_stepenima)*60))*60 + znak*0.5);
		if(abs(sec) == 60) sec = 0;
		if(abs(sec)>30) {
			for(j=i; j<broj_elemenata-1; j++) 
				uglovi[j] = uglovi[j+1];
			broj_elemenata--;
			i--;
		}
	} 
	printf("Uglovi su:\n");
	for(i=0; i<broj_elemenata; i++) {
		u_stepenima = 180/PI*uglovi[i];
		stepeni = (int)u_stepenima;
		if(uglovi[i] >= 0)
			znak = 1;
		else
			znak = -1;
		min = (int)((u_stepenima-(int)u_stepenima)*60);
		sec = (int)(((u_stepenima-(int)u_stepenima)*60 - (int)((u_stepenima-(int)u_stepenima)*60))*60 + znak*0.5);
		min = abs(min);
		sec = abs(sec);
		/*korekcija*/
		if(sec == 60) {
			min = min + sec/60;
			sec = 0;
			if(min == 60) {
				stepeni = stepeni + znak*min/60;
				min = 0;
			}
		}
		printf("%d stepeni %d minuta %d sekundi\n", stepeni, min, sec);
	}
	return 0;
}
