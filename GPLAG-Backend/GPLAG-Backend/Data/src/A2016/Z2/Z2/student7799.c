#include <stdio.h>
#include <math.h>
#define BR 500
#define PI 3.1415926
int main() {
	double niz[BR];
	int st[BR],min[BR],sec[BR];
	int n,j,znak,sekunde;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(j=0;j<n;j++){
	scanf("%lf",&niz[j]);
	}
	
	printf("Uglovi su: \n");
	for(j=0;j<n;j++)
	    {
	    znak=0;
	    sekunde=((niz[j]*180)/PI)*3600;
	    if(sekunde<0){sekunde*=-1; znak=1;}
		if((fabs(((niz[j]*180)/PI)*3600)-sekunde)>0.5)sekunde++;
		st[j]=sekunde/3600;
		min[j]=sekunde%3600/60;
		sec[j]=sekunde%60;
		if(sec[j]>30) continue;
		if(znak==1)printf("-");
		printf("%d stepeni %d minuta %d sekundi\n",st[j],min[j],sec[j]);
	    }
	return 0;
}
