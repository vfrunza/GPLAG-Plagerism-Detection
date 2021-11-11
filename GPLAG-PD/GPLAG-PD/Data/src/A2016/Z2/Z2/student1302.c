#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	
	int n, i;
	double ugao[500],ugao1[500], ugao2[500], minute[500],sekunde[500];
//	int minus=0;
	//double privremeni[500];
	printf("Unesite broj uglova: ");
		scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%lf", &ugao[i]);
	//	if(ugao<0) { minus=1; ugao[i]=ugao[i]*(-1); }
		ugao1[i]=(ugao[i]*180)/PI; //stepeni decimalni
		ugao2[i]=(int)ugao1[i]; //stepeni pravi
	//	privremeni[i]=ugao1[i]-ugao2[i];
	//	privremeni[i]=privremeni[i]*60;
	//	minute[i]=(int)privremeni[i];
	//	privremeni[i]=privremeni[i]-minute[i];
	//	privremeni[i]=privremeni[i]*60;
	//	sekunde[i]=privremeni[i];
		minute[i]=(int)((ugao1[i]-ugao2[i])*60);
		sekunde[i]=(ugao1[i]-ugao2[i]-((minute[i]/60)))*3600;
		//printf("%f \n", sekunde[i]);
		//printf("%f \n", minute[i]);
		//printf("%f \n", ugao2[i]);
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
	//	printf("%d   ",i);
		if(sekunde[i]<31 && sekunde[i]>30 && (sekunde[i] - (int)sekunde[i])<= 0.5) sekunde[i] = (int)sekunde[i];
		if((sekunde[i]<=30 && sekunde[i]>=0) || (sekunde[i]>=-30 && sekunde[i]<=0))  printf("%.0f stepeni %.0f minuta %.0f sekundi\n", ugao2[i], fabs(minute[i]), fabs(sekunde[i]));
	
		 if((int)sekunde[i]>=59 && (sekunde[i]-(int)sekunde[i]>0.5) || (sekunde[i]<=-59 && sekunde[i]-(int)sekunde[i]<-0.5)){
			sekunde[i]=0;
			if(minute[i]<0) minute[i]--;
		else	minute[i]++;
			if(minute[i]>=59){
				ugao2[i]++;
				minute[i]=0;
			}
			if(minute[i]<=-59){
			ugao2[i]--;
			minute[i] = 0;}
			
	printf("%.0f stepeni %.0f minuta %.0f sekundi\n", ugao2[i], fabs(minute[i]), fabs(sekunde[i]));
	  }
	  	
		}
		
	
	return 0;
}
