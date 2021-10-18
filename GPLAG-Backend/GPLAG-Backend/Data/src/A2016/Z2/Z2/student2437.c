#include <stdio.h>
#include <stdlib.h>
#define PI 3.14
#define x 500

int main() {
	int j,i,br;
	float niz[x],sekunda[x],minuta[x],stepen[x];
	
printf("Unesite broj uglova: ");
scanf("%d", &br);
for(i=0;i<br;i++){
	scanf("%f", &niz[i]);
float uksek=(niz[i]*180./PI)*3600;
 uksek=(int)(uksek+0.5);
 	minuta[i]=(uksek-stepen[i]*3600)/60;
	sekunda[i]=uksek-stepen[i]*3600-minuta[i]*60;

	if(sekunda[i]>=60) 
	{minuta[i]++;sekunda[i]-=60;}
	if(minuta[i]>=60)
	{stepen[i]++;minuta[i]-=60;}
		if(sekunda[i]>30)
		{for(j=i; j<br-1 ; j++);
           niz[j] = niz[j+1];
	}
			br--;
			i--;
		}
		printf("Uglovi su: \n");
		for(i=0;i<br;i++)
		printf("%.0f stepeni %.0f minuta %.0f sekundi\n",stepen[i] ,minuta[i], sekunda[i]);
		
	return 0;
}
