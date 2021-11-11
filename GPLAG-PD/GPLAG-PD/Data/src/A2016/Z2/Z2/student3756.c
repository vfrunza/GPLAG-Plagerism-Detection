#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	int i, j, x, sstepeni[500], mminute[500], ssekunde[500];
	double rad [500], stepeni[500], minute[500], sekunde[500];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &x);
	printf("Uglovi su:\n");
	for(i=0; i<x; i++)
	{
		scanf("%lf", &rad[i]);
	stepeni[i] = rad[i] * ( 180 / PI );
	minute[i] = ( stepeni[i] - (int)stepeni[i] ) * 60;
	sekunde[i] = ( minute[i] - (int)minute[i] ) * 60;
	sstepeni[i] = stepeni[i];
	mminute[i] = minute[i];
	ssekunde[i] = round(sekunde[i]);
	if(ssekunde[i] == 60)
	{
		ssekunde[i] = 0;
		mminute[i]++;
	}
	else if(ssekunde[i] == -60)
	{
		ssekunde[i] = 0;
		mminute[i]--;
	}
	if(mminute[i] == 60)
	{
		mminute[i] = 0;
		sstepeni[i]++;
	}
	else if(mminute[i] == -60)
	{
		mminute[i] = 0;
		sstepeni[i]--;
	}
	
	if(ssekunde[i] > 30 || ssekunde[i] < -30)
	{
		for(j=i; j<x-1; j++)
		{
			ssekunde[j] = ssekunde [j+1];
			mminute[j] = mminute [j+1];
			sstepeni[j] = sstepeni [j+1];
		}
		x--;
		i--;
	}
	}

	for(i=0; i<x; i++)
	printf("%d stepeni %d minuta %d sekundi\n", sstepeni[i], abs(mminute[i]), abs(ssekunde[i]));
	
	return 0;
}
