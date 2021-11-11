#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int n,i,j;
	double niz[500],stepeni,minute,sekunde;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	if(n>500) n=500;
	for(i=0; i<n; i++)
	scanf("%lf", &niz[i]);
	for(i=0; i<n; i++)
	{
		stepeni=niz[i]*180/PI;
		 minute=(stepeni-(int)stepeni)*60;
		 if(minute<0) minute*=-1;
		 sekunde=(minute-(int)minute)*60;
		 if(sekunde<0) sekunde*=-1;
		 sekunde=round(sekunde);
		 if((int)sekunde==60){
		 	sekunde=0;
		 	minute++;
		 	if((int)minute==60){
		 		minute=0;
		 		stepeni++;
		 	}
		 }
		 if((int)sekunde>30){
		 	for(j=i; j<n-1;j++)
		 	niz[j]=niz[j+1];
		 	i--;
		 	n--;
		 }
	}
	printf("Uglovi su:\n");
	for(i=0; i<n;i++){
		stepeni=niz[i]*180/PI;
		minute=(stepeni-(int)stepeni)*60;
		if(minute<0)minute*=-1;
		sekunde=(minute-(int)minute)*60;
		if(sekunde<0)sekunde*=-1;
		sekunde=round(sekunde);
		if((int)sekunde==60){
			sekunde=0;
			minute++;
			if((int)minute==60){
				minute=0;
				if(stepeni>0)
				stepeni++;
				else stepeni--;
			}
		}
		printf("%d stepeni %d minuta %d sekundi\n", (int)stepeni,(int)minute,(int)(sekunde));
	}
	return 0;
}
