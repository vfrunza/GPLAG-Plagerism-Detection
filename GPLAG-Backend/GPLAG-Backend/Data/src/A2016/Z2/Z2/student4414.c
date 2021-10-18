#include <stdio.h>
#define PI 3.1415926
#define BROJ_EL 500

int main() {
	int i,n,cdio,cdiomin,nizA[500],nizB[500],nizC[500];
	double niz[BROJ_EL],stepeni,minute,sekunde,real,realmin,csek,csekreal,csekint;
	
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
		
	for(i=0; i<n; i++) 
	    
	    {
	    	scanf("%lf", &niz[i]);
	    }
	
	for(i=0; i<n; i++)
	   {
	   	 stepeni=niz[i]*(180./PI);
	   	 cdio=(int)stepeni;
	   	 nizA[i]=cdio;
	   	 real=stepeni-cdio;
	   	 minute=real*60;
	   	 cdiomin=(int)minute;
	   	 nizB[i]=cdiomin;
	   	 realmin=minute-cdiomin;
	   	 sekunde=realmin*60;
	   	 
	   	 
	   	 if((sekunde>=59.50) && (cdiomin=59))
	   	 {
	   	 	sekunde=0;
	   	 	nizC[i]=sekunde;
	   	 	minute=0;
	   	 	nizB[i]=minute;
	   	 	cdio++;
	   	 	nizA[i]=cdio;
	   	 } 
	   	 else if((sekunde<=-59.50) && (cdiomin=-59)) {
	   	 	sekunde=0;
	   	 	nizC[i]=sekunde;
	   	 	minute=0;
	   	 	nizB[i]=minute;
	   	 	cdio--;
	   	 	nizA[i]=cdio;
	   	 	
	   	 }
	   	 
	   	 else {
	   	 csekint=(int)sekunde;
	   	 csekreal=sekunde-csekint;
	   	 csek=(int)sekunde;
	   	 if(csekreal>=0.5) csek++;
	   	 nizC[i]=csek;
	   	 }
	   	 
	   	
	   }
	
	
	printf("Uglovi su:\n");
	for(i=0; i<n; i++) {
		if(nizA[i]<0) { nizB[i]=nizB[i]*(-1); nizC[i]=nizC[i]*(-1); } 
	if((nizC[i]<=30) && (nizC[i]>=-30))
	printf("%d stepeni %d minuta %d sekundi\n", nizA[i],nizB[i],nizC[i]);
	}
	
	return 0;
}
