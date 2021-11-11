#include <stdio.h>
#include <math.h>
#define pi 3.1415926


int main() {
	
	int br_u,i;
	double rad[502],stepeni[502],minute[502],sekundi[502];

	do{
		printf("Unesite broj uglova: ");
		scanf("%d", &br_u);
	}while(br_u<1 || br_u>500);
	
	for(i=0;i<br_u;i++)	{
		scanf("%lf",&rad[i]);
			
		stepeni[i]=rad[i]*180/pi;
		minute[i]=(((int)(stepeni[i])-stepeni[i])*60);
		sekundi[i]=(((int)(minute[i])-minute[i])*60);
		
		if(sekundi[i]>=0)
			sekundi[i]+=0.5;
		else sekundi[i]-=0.5;
		
		sekundi[i]=fabs((int)(sekundi[i]));
		minute[i]=fabs((int)(minute[i]));
		stepeni[i]=(int)(stepeni[i]);
		
	
		if(sekundi[i]==60){
			minute[i]++;
			sekundi[i]=0;
		}
			
			
		if(minute[i]>=60){
			minute[i]=0;
			if(stepeni[i]>=0)
				stepeni[i]++;
			else stepeni[i]--;
			
		}
			
		if (sekundi[i]>30) {
			
			br_u--;
			i--;
		}
		
	}
			
		printf("Uglovi su: \n");
		for(i=0;i<br_u;i++){
			printf("%g stepeni %g minuta %g sekundi\n",stepeni[i],minute[i],sekundi[i]);
		}
		
	
	
	
	return 0;
}

