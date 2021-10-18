#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
#define BROJ_UGLOVA 500
int main() {
  double niz[BROJ_UGLOVA];
  int stepeni[BROJ_UGLOVA]={0},minute[BROJ_UGLOVA]={0},sekunde[BROJ_UGLOVA]={0},i,j,n;
  printf("Unesite broj uglova:");
  scanf("%d",&n);
  for(i=0;i<n;i++){
  	 scanf("%lf",&niz[i]);
  }
  	 for(i=0;i<n;i++){
  	 niz[i]*=(180/PI);
     if(niz[i]>0){
  	    stepeni[i]=(int)niz[i];
  	    minute[i]=(int)((niz[i]-(int)(niz[i]))*60);
  	    sekunde[i]=(int)(((((niz[i]-(int)(niz[i]))*60)-(int)((niz[i]-(int)(niz[i]))*60))*60)+0.5);
  	}
      else {
  	   if(niz[i]<0){
  	      stepeni[i]=(int)niz[i];
  	      minute[i]=(int)((niz[i]-(int)(niz[i]))*60);
  	      sekunde[i]=(int)(((((niz[i]-(int)(niz[i]))*60)-(int)((niz[i]-(int)(niz[i]))*60))*60)-0.5);
  	   }
      }
      	if(sekunde[i]>=60){
    sekunde[i]=sekunde[i]%60;
    minute[i]++;
    }
    if(minute[i]>=60){
     minute[i]=minute[i]%60;
    stepeni[i]++;
  	 }
  	   if(sekunde[i]<=-60){
  	   sekunde[i]=sekunde[i]%60;
  	   minute[i]--;
  	 }
  	 if(minute[i]<=-60){
  	   minute[i]=minute[i]%60;
  	   stepeni[i]--;
  	 }
  	 if(stepeni[i]>360){
  	 stepeni[i]=stepeni[i]%360;
}
}
   for(i=0;i<n;i++){
  if((sekunde[i]>30 || sekunde[i]<-30) && i<n-1){
    for(j=i;j<n;j++){
     stepeni[j]=stepeni[j+1];
    minute[j]=minute[j+1];
    sekunde[j]=sekunde[j+1];
  }
  i--;
  n--;
}
else {
  if((sekunde[i]>30 || sekunde[i]<-30) && i==n-1){
     stepeni[i]=stepeni[i];
    minute[i]=minute[i];
    sekunde[i]=sekunde[i];
    n--;
}
  }
}

printf(" Uglovi su:");
for(i=0;i<n;i++){
  printf("\n%d stepeni %d minuta %d sekundi",stepeni[i],abs(minute[i]),abs(sekunde[i]));
}

	return 0;
}
