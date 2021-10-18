#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() 
{
	double rad[1000],S;
	int N,i,st,min,sek,vel = 0;
	printf("Unesite broj uglova: ");
	scanf("%d",&N);
	for(i=0;i<N;i++) scanf("%lf",rad+i);
	for(i = 0;i<N;i++)
	{
		S = fabs(rad[i] * (180/PI));
		st = (int)S;
		S = S - st;
		S*=60;
		min = (int)S;
		S = S - min;
		S*=60;
		sek = (int)(S + 0.5);
		if(sek==60) {sek=0;min++;};
		if(min==60) {min = 0;st++;}
		if(sek<=30) rad[vel++] = rad[i];
	//	printf("%f - %d stepeni %d minuta %d sekundi\n",rad[i],st,min,sek);
	}
	N = vel;
	printf("Uglovi su: \n");
	for(i = 0;i<N;i++)
	{
		S = fabs(rad[i] * (180/PI));
		st = (int)(S);
		S = S - st;
		S*=60;
		min = (int)(S);
		S = S - min;
		S*=60;
		sek = (int)(S + 0.5);
			if(sek==60) {sek=0;min++;};
		if(min==60) {min = 0;st++;}
		printf("%d stepeni %d minuta %d sekundi\n",rad[i]>0?st:-st,min,sek);
	}
	
	return 0;
}
