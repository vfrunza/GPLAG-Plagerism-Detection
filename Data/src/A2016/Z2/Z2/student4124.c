#include <stdio.h>
#include <math.h>

static double const PI = 3.1415926;

int main() {
	int n,i;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	double uglovi[500];
	for(i = 0; i < n; i++)
	{
		scanf("\n %la", &uglovi[i]);
	}
	int totalSeconds,seconds,minutes,degrees,j;
	for(i=0; i<n; i++)
	{
		totalSeconds = (int)round(uglovi[i] * 360 * 60 * 60 / (2 * PI));
		seconds = totalSeconds % 60;
		if(seconds>30 || seconds<-30)
		{
			for(j=i;j<n-1;j++)
			{
				uglovi[j] = uglovi[j+1];
			}
			n--;
			i--;
		}
	}
	printf("Uglovi su:");
	for(i=0; i<n; i++)
	{
		totalSeconds = (int)round(uglovi[i] * 360 * 60 * 60 / (2 * PI));
		seconds = totalSeconds % 60;
		minutes = (totalSeconds / 60) % 60;
		degrees = totalSeconds / (60 * 60);
		printf("\n%d stepeni %d minuta %d sekundi",degrees,minutes,seconds);
	}
	
	return 0;
}
