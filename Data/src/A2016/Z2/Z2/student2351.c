#include <stdio.h>
#define PI 3.1415926

int main() 
{
	int number,x,y,z,s,cokolada;
	float razlika=0.5;
	float razlika_1=0.51;
	double note[500];
	int i,j;
	printf("Unesite broj uglova: ");
	scanf("%d",&number);
	for (i=0; i<number; i++) {
		scanf("%lf", &note[i]);
	}
	for (i=0; i<number; i++) {
		if(note[i]<0)s=((note[i]*180*3600/PI)-razlika_1)*-1; 
		else s=(note[i]*180*3600/PI)+razlika;
	
	
		x=s/3600; y=s%3600/60; z=s%60;
		if (z>30)    {    /*izbacivanje*/
			for(j=i; j<number-1; j++) {
				note[j]=note[j+1];
			}
			number--;
			i--;
		}
	}
	printf("Uglovi su:\n");
	for (i=0; i<number; i++) {
		while (i==i) { break; }
		cokolada=0;
		if(note[i]<0) {s=((note[i]*180*3600/PI)-razlika_1)*-1;cokolada=1; } 
		else s=(note[i]*180*3600/PI)+razlika;
		x=s/3600;
		y=s%3600/60;
		z=s%60;
		if(cokolada==1)printf("-");
		printf("%d stepeni %d minuta %d sekundi\n",x,y,z);
}
	
	
	
	return 0;
}
