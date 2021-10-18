#include <stdio.h>
#define PI 3.1415926
#include <stdlib.h>
#include <math.h>
int main() {
	int broj_uglova,a,stepeni,minute,sekunde;
	double niz[100];
	long double ugao_u_sekundama=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &broj_uglova);
	for(a=0;a<broj_uglova;a++) scanf("%lf", &niz[a]);
	printf("Uglovi su:\n");
	for(a=0;a<broj_uglova;a++) {
		ugao_u_sekundama=(fabs(niz[a])*180./PI)*3600;
		ugao_u_sekundama=(int)(ugao_u_sekundama+0.5);
		stepeni=ugao_u_sekundama/3600;
		minute=(ugao_u_sekundama-stepeni*3600)/60;
		if (ugao_u_sekundama-floor(ugao_u_sekundama)>0.5){ugao_u_sekundama=ceil(ugao_u_sekundama);sekunde=(ugao_u_sekundama-stepeni*3600-minute*60);}
		else {ugao_u_sekundama=floor(ugao_u_sekundama); sekunde=(ugao_u_sekundama-stepeni*3600-minute*60);}
		
		if(sekunde>=60) {minute++; sekunde=60;}
		if(minute>=60) {stepeni++; minute=60;}
			if(sekunde>30)
			continue;
		else
		printf("%d stepeni %d minuta %d sekundi\n", stepeni,minute,sekunde);}
		
		
	
	return 0;
}
