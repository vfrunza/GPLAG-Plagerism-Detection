#include <stdio.h>
#define PI 3.1415926
int main() {

int n,i;
double niz[500];
int stepen,minut,sekund;
int Flag=0; /*bool  kaze je li negativan ili nije*/
printf("Unesite broj uglova: ");
scanf("%d", &n);
while(n<=0 || n>=500) {
printf("Unesite broj uglova: ");
scanf("%d", &n);
} 
for(i=0; i<n; i++) {
scanf("%lf", &niz[i]);
}
printf("Uglovi su:\n");
for(i=0; i<n; i++)
{
  Flag=0;
  if(niz[i]<0){niz[i]*=-1;Flag=1;}
  
  niz[i]*=180/PI;
  
  stepen=(int)niz[i];
  niz[i]-=stepen;
  niz[i]*=60;
  minut=(int)niz[i];
  niz[i]-=minut;
  niz[i]=niz[i]*60+0.5;
  sekund=(int)niz[i];
  
  if(sekund>59) {sekund=0;minut+=1;}
  if(minut>59){minut=0;stepen+=1;}
 
 
  if(Flag==1) stepen*=-1;
  
  
  if(sekund<=30) 
  
  printf("%d stepeni %d minuta %d sekundi\n",stepen,minut,sekund);
}
	return 0;
}