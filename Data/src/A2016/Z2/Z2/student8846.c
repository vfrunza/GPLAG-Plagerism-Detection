#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int n, i,stepeni,minute,sekunde,brojilica=0;
	int stepenii[500], minutee[500], sekundee[500];
	double unos,ostatak,stepeni_dec,minute_dec,sekunde_dec;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%lf", &unos);
		stepeni_dec=unos*180.0/PI;
		ostatak=fabs(stepeni_dec-(int)stepeni_dec);
		stepeni=(int)stepeni_dec; 
		minute_dec=ostatak*60;
		ostatak=fabs(minute_dec-(int)(minute_dec));
		minute=(int)(minute_dec);
		sekunde_dec=ostatak*60;
		sekunde=(int)(sekunde_dec+0.5);
		if(sekunde>=60)
		{
			sekunde-=60;
			minute++;
		}
		if(minute>=60)
		{
			if(stepeni>0)
			stepeni++;
			else
			stepeni--;
			minute-=60;
		}
		if(sekunde<=30)
		{
			brojilica++;
			stepenii[i]=stepeni;
			minutee[i]=minute;
			sekundee[i]=sekunde;
		}
		else
		{
			i--;
			n--;
		}
		
	}
	printf("Uglovi su: \n");
	for(i=0; i<brojilica; i++)
	printf("%d stepeni %d minuta %d sekundi\n", stepenii[i], minutee[i], sekundee[i]);

	return 0;
}
