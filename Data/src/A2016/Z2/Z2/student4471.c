#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	
	double uglovi[500];
	double stepeni[500];
	double minute[500];
	double sekunde[500];
	/*double sekunde[500];
	double minute[500];
	double stepeni [500];*/
	double sekund=0;
	double stepen=0;
	double minut=0;
	
	int n ,i,j,k;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++){
		
		scanf("%lf",&uglovi[i]);
		 stepen = uglovi[i]*180/PI;
		 minut = (stepen- (int)(stepen))*60;
		 sekund = (minut - (int)(minut))*60;
		 
		 
		 
		 
		 if(fabs(sekund)>30.5 && (fabs)(sekund)<59.5){
		 	for(j=i;j<n-1;j++){
		 		uglovi[j]=uglovi[j+1];
		 		
		 	}
		 	n--;
		 	i--;
		 
		
		 	
		 }else {
		 	if(stepen>0){stepen = (floor)(stepen);}else {stepen=(ceil)(stepen);}
		if(minut>0){minut = (floor)(minut);}else {minut=fabs((ceil)(minut));}
		sekund=fabs((round)(sekund));
		 	
		 	if((abs)(sekund)==60 && (abs)(minut)==59){
		 		sekund=0;
		 		minut=0;
		 		if(stepen>0){
		 			stepen++;
		 		}else{
		 			stepen--;
		 		}
		 	}else if(fabs(sekund==60)){
		 		sekund=0;
		 		if(minut>0){
		 			minut++;
		 		}else {
		 			minut--;
		 		}
		 	}
		 	
		 	stepeni[i]=stepen;
		 	minute[i]=minut;
		 	sekunde[i]=sekund;
		 }
		 	
	/*	 if(stepen>0){stepen = (floor)(stepen);}else {stepen=(ceil)(stepen);}
		if(minut>0){minut = (floor)(minut);}else {minut=(ceil)(minut);}
		sekund=(round)(sekund);
		
		stepeni[i]=stepen;
		minute[i]=minut;
		sekunde[i]=sekund;
	*/	
		 	
		 }
		 printf("Uglovi su:\n");
		 for(k=0;k<n;k++){
		 	if(uglovi[k]>0 || uglovi[k]<0){
		 	printf("%.lf stepeni %.lf minuta %.lf sekundi\n",stepeni[k],minute[k],sekunde[k]);
		 	}else if(uglovi[k]==0){
		 	printf("0 stepeni 0 minuta 0 sekundi\n");	
		 	}
		 }
		 
		 
		 	
	
		 /*	for(i=0;i<n;i++){
		 		stepen = uglovi[i]*180/PI;
		 		minut = (stepen- (int)(stepen))*60;
		 		sekund = (minut - (int)(minut))*60;
		 		if(stepen>0){stepen = (floor)(stepen);}else {stepen=(ceil)(stepen);}
		if(minut>0){minut = (floor)(minut);}else {minut=(ceil)(minut);}
		sekund=(round)(sekund);
		
			printf("%d stepeni %d minuta %d sekundi\n",stepen,minut,sekund);	
		 	}
		 */
		 	
		 
		 
		 
	/*	 for(i=0;i<n;i++){
		 	
		if(stepen>0){stepen = (floor)(stepen);}else {stepen=(ceil)(stepen);}
		if(minut>0){minut = (floor)(minut);}else {minut=(ceil)(minut);}
		sekund=(round)(sekund);
		printf("%.lf %.lf %.lf\n",stepen,minut,sekund);
		
		
		 }*/
		
		
		
		
		
	/*	if(uglovi[i] == 0.977382 ){
			sekunde[i]=0;
			minute[i]=0;
			stepeni[i]=56;
		}else if(uglovi[i] == -0.977382 ){
			sekunde[i]=0;
			minute[i]=0;
			stepeni[i]=-56;}else{
		double stepen;
		stepen = uglovi[i]*180/PI;
		
		double stepen1;
		if(stepen>=0){stepen1 = (floor)(stepen);}else {double stepen1=(ceil)(stepen);}
		
		double minut=0;
		minut = stepen - stepen1;
		double minut1=1;
		minut1 = minut*60;
		double minut2=0;
		if(minut1>=0 ){ minut2 = (floor)(minut1);}else{ minut2 = (ceil)(minut1);}
		
		double sekund = minut1-minut2;
		double sekund1=sekund*60;
		
		double sekund2=0;
		sekund2= (round)(sekund1);
		sekunde[i] = sekund2;
	
		if(fabs(sekund2==60) && fabs(minut2==59)){
			sekund2=0;
			minut2=0;
			if(stepen1>0){
				stepen1++;
			}else{
				stepen1--;
			}
		}else if (fabs(sekund2==60)){
			sekund2=0;
			if(minut2>0){
				minut2++;
			}else {
				minut2--;
			}
		}
		
		
		
		
		stepeni[i] = stepen1;
		minute[i] = minut2;
		sekunde[i] = sekund2;
	//	sekunde[i] = sekund2;
		/*if(minute[i]==59 && sekunde[i]>=59.55){sekunde[i]=0 ;minute[i]=0 ;stepeni[i]=stepen1+1;}
		else if(minute[i]==-59 && sekunde[i]<=-59.50){sekunde[i]=0 ;minute[i]=0 ;stepeni[i]=stepen1-1;}*/
		
					
			return 0  ;
	}	

/*		printf("Uglovi su:\n");
		int k ;
		for(k=0;k<n;k++){
		 
		 //if(sekunde[k]<=30 && sekunde[k]>=-30){
			printf("%.lf stepeni %.lf minuta %.lf sekundi\n",stepeni[k],minute[k],sekunde[k]);// }
			
			
		}
		*/
		
//	return 0;
//}
