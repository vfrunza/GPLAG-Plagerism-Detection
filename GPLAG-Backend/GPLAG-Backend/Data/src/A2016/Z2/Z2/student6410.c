#include <stdio.h>
#include <math.h>
#define br_elem 500
#define PI 3.1415926
int main() { int n;
     double niz[br_elem] ;
     int stepeni, minute, sekunde;
    double x;
    int i,j;
     printf("Unesite broj uglova: ");
     scanf("%d", &n);
     
         
         for (i=0; i<n; i++) {
         	
              scanf("%lf", &niz[i]);
              
          x=niz[i]*(180./PI);
		stepeni=(int) x;
		x=x-stepeni;
		x=x*60;
		minute=(int) x; 
		x=x-minute; 
		x=x*60;
		sekunde=(int) round(x); 
		if (sekunde==60) 
		{ 
			sekunde=0;
			minute++;
			if (minute==60)
			{
				minute=0;
				stepeni++;
			}
		}
		if(sekunde==-60 && minute<0) {
		     sekunde=0;
		     minute++;
		     if(minute==-60 && stepeni<0){
		          minute=0;
		          stepeni--;
		     }
		}
          
          if(sekunde>30 || sekunde<-30) { 
               for(j=i; j<n-1; j++){
                    niz[j]=niz[j+1];
               
               } 
               n--;
               i--;
          }
     }
     printf("Uglovi su:");
     for(i=0; i<n; i++){
     	 
     	x=niz[i]*(180./PI);
		stepeni=(int) x;
		x=x-stepeni;
		x=x*60;
		minute=(int) x; 
		x=x-minute; 
		x=x*60;
		sekunde=(int) round(x); 
		if (sekunde==60) 
		{
			sekunde=0;
			minute++;
			if (minute==60)
			{
				minute=0;
				stepeni++;
			}
		}
		if(sekunde==-60) {
		     sekunde=0;
		     minute=minute-1;
		     if(minute==-60){
		          minute=0;
		          stepeni=stepeni-1;
		     }
		}
		if (x<0) printf("\n%d stepeni %d minuta %d sekundi", stepeni, -minute, -sekunde);
          else
         printf("\n%d stepeni %d minuta %d sekundi", stepeni, minute, sekunde);}
	
	return 0;
}
