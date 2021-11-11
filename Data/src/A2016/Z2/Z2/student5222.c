#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main()
{
	int n, i, j, ugao;
	float polje[500];
	int step=0, min=0, sec=0;

	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%f", &polje[i]);
	}
	printf("Uglovi su: ");
	for(i=0; i<n; i++) {
		if(polje[i]>=0)
			ugao=((polje[i]*180*3600/PI)+0.5);
		else
			ugao=((polje[i]*648000/PI)-0.5);
		step=ugao/3600;
		if(ugao<0)
			ugao=ugao*-1;
		sec=ugao%60;
		ugao=ugao/60;
		min=ugao%60;
		if(sec<=30) {
			printf("\n%d stepeni", step);
			printf(" %d minuta", min);
			printf(" %d sekundi", sec);
		}
	}
	return 0;
}
