#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415926

int main() {
	double niz[500];
	int k=0, i=0,j =0;
	int stepeni=0, minute=0, sekunde=0;
	double pom=0; /*pomocna varijabla*/
	printf("Unesite broj uglova: ");
	scanf("%d",&k);
	for(i=0; i<k; i++) {
	    scanf("%lf",&niz[i]);    
	}
	for(i=0; i<k; i++) {
	      pom=niz[i];
	      pom=pom*180./PI;
	      stepeni = pom;
	      
	      pom = pom - stepeni;
	      pom=pom*60;
	      minute = pom;
	      
	      pom = pom - minute;
	      pom=pom*60;
	      sekunde=(int)pom;
	      
	      if(sekunde>=0)sekunde=pom + 0.5;
	      else sekunde=pom - 0.5;
	      
	      if(abs(sekunde)>=60) {
	          if(sekunde>=0) {
	              minute++;
	              sekunde-=60;
	          }
	          else {
	              sekunde+=60;
	              minute--;
	          }
	         
	      }
	      if(abs(minute)>=60) {
	          if(minute>=0){
	              stepeni++;
	              minute-=60;
	          }
	          else{
	              stepeni--;
	              minute+=60;
	          } 
	          
	      }
	      
	      
	      if(abs(sekunde)>30) {
	          for(j=i ;j<k; j++) {
	             niz[j] = niz[j + 1];
	          }
	          k--;
	          i--;
	      }
	}
	printf("Uglovi su:\n");
		for(i=0;i<k;i++) {
	      pom=niz[i];
	      pom=pom*180./PI;
	      stepeni = pom;
	      
	      pom= pom - stepeni;
	      pom=pom*60;
	      minute = pom ;
	      
	      pom= pom - minute;
	      pom=pom*60;
	      sekunde=(int)pom;
	      
	      if(sekunde>=0)sekunde=pom + 0.5;
	      else sekunde=pom - 0.5;
	      
	      if(abs(sekunde)>=60) {
	          if(sekunde>=0) {
	              minute++;
	              sekunde-=60;
	       }
	          else {
	              sekunde+=60;
	              minute--;
	          }
	   }
	      if(abs(minute)>=60) {
	          if(minute>=0){
	              stepeni++;
	              minute-=60;
	          }
	          else{
	              stepeni--;
	              minute+=60;
	          } 
	          
	      }
	      printf("%d stepeni %d minuta %d sekundi\n", stepeni, abs(minute), abs(sekunde));
    }
	
	return 0;
}
