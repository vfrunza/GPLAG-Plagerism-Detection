#include <stdio.h>
#include<stdlib.h>
#define PI 3.1415926
#include<math.h>
int main() {
	int br_uglova, i, j, brojac, k;
    double niz[500]={0}, x=0, y=0;
	double stepeni=0, sekunde=0, minute_decimale=0, stepeni2=0, sekunde2, minute_decimale2=0;
	int sekunde_zaokruzene=0, sekunde_zaokruzene2=0, minute=0, minute2=0;
  
    
		printf("Unesite broj uglova: "); scanf("%d", &br_uglova);
		for(i=0; i<br_uglova; i++){
		scanf("%lf", &niz[i]);
		}
			
		printf("Uglovi su:\n");
			
			
		for(i=0; i<br_uglova; i++){
			
		stepeni= (int)(niz[i]*180/PI); 
		x=(double)niz[i]*180/PI; 
		minute= (int)((x-stepeni)*60);               
		minute_decimale= (double)((x-stepeni)*60);
	    sekunde=(double)(minute_decimale-minute)*60;
		sekunde_zaokruzene=round(sekunde);
		
		if(sekunde_zaokruzene==60){	
			sekunde_zaokruzene=0;
			minute++;
		}
		if(minute==60){			
			minute=0;
			stepeni++;
		}
		if(sekunde_zaokruzene==-60){		
			sekunde_zaokruzene=0;
			minute--;
		}
		if(minute==-60){			
			minute=0;
			stepeni--;
		}	   
		if(abs(sekunde_zaokruzene)<=30){
			if(minute>=0){
			printf("%g stepeni %d minuta %d sekundi\n", stepeni, abs(minute), abs(sekunde_zaokruzene));
			} 
			else {
			printf("%g stepeni %d minuta %d sekundi\n", stepeni,abs(minute), abs(sekunde_zaokruzene));
			
			}
				
			}
		
}
	for(i=0; i<br_uglova; i++){
		if(sekunde>30){
				for(j=i; j<br_uglova-1; j++){
				niz[j]=niz[j+1];
				br_uglova--;
				i--;
				brojac++;
				}
			
		}
	}
return 0;
}


		


			


	