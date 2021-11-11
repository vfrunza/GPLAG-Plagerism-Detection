#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define EPS 0.00000000001
int main() {
	int n,A=0,B=0,i,j;
	double C=0,niz[500]={0},min=0,minute=0,stepeni=0,sekunde=0,sec=0;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);

  for(i=0;i<n;i++){
   scanf("%lf",&niz[i]);}
     printf("Uglovi su: \n");
 
 for(i=0;i<n;i++){
     
if(niz[i]>=0){ 
   stepeni=niz[i]*180/PI;
   A=(int)stepeni;
   
   minute=stepeni-A;
   min=1./60;
   B=(int)(minute/min);
   
   
   sekunde=minute/min-B;
   sec=1./60;
   C=round(sekunde/sec);
   if(fabs(C-60)<EPS){C=0;
   B++;}
   if(B==60){B=0;
   A++;}
   
   
   if (C>30) {
      for(j=i;j<n;j++)
        { niz[j]=niz[j+1];}
         n--;
         i--;
         }
   else
       
       printf("%d stepeni %d minuta %.0f sekundi \n",A,B,C);}
else {
   niz[i]=niz[i]*(-1);
   stepeni=niz[i]*180/PI;
   A=(int)stepeni;
   
   minute=stepeni-A;
   min=1./60;
   B=(int)(minute/min);
   
   sekunde=minute/min-B;
   sec=1./60;
   C=round(sekunde/sec);
   if(fabs(C-60)<EPS){C=0;
   B++;}
   if(B==60){B=0;
   A++;}
  
   
    if (C>30) {
      for(j=i;j<n;j++)
        { niz[j]=niz[j+1];}
         n--;
         i--;
         }
     else
          printf("-%d stepeni %d minuta %.0f sekundi \n",A,B,C);
       
       }
 }
	return 0;
}
