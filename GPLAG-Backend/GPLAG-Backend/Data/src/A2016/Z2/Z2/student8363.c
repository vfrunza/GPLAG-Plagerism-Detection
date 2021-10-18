#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
int main(){
	int n,deg[500],min[500],sec[500],i;
	double rad,dg,dm,ds;
	printf("Unesite broj uglova: ");
	scanf("%i", &n);
	for(i=0;i<n;i++)
	{
		scanf("%lf", &rad);
		if(rad>0)
		{
			
		rad=rad*180/PI;
		dg=rad-(int)rad;
		dm=dg*60;
		ds=(dm-(int)dm)*60+0.5;
		deg[i]=(int)rad;
		min[i]=(int)dm;
		sec[i]=(int)ds;
		if(min[i]==60){min[i]=0;deg[i]++;}
		if(sec[i]==60){sec[i]=0;min[i]++;}
		if(min[i]==60){min[i]=0;deg[i]++;}
		if(sec[i]>30){i--;n--;}
		}
		else{
		rad=rad*180/PI;
		dm=(rad-(int)rad)*60;
		ds=(dm-(int)dm)*60-0.5;
		deg[i]=(int)rad;
		min[i]=(int)dm;
		sec[i]=(int)ds;
		if(min[i]==-60){min[i]=0;deg[i]--;}
		if(sec[i]==-60){sec[i]=0;min[i]--;}
		if(min[i]==-60){min[i]=0;deg[i]--;}
		min[i]=abs(min[i]);
		sec[i]=abs(sec[i]);
		if(sec[i]>30){i--;n--;}
		}
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++)
		printf("%i stepeni %i minuta %i sekundi\n",deg[i],min[i],sec[i]);
	return 0;
}