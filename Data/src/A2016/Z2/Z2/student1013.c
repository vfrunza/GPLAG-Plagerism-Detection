#include <stdio.h>
#include <math.h>
#define PI 3.1415926


double KonverzijaRS (double x) {
x=x*180/PI;
return x;
}


int main() {
	
int n,i,j,stepeni[500], sekunde[500], minute[500],minut,stepen,sekund;	
double niz[500],x[500];	
	
printf("Unesite broj uglova: ");
scanf("%d", &n);

for(i=0;i<n;i++) {
scanf("%lf", &niz[i]);
niz[i]=KonverzijaRS(niz[i]);
x[i]=niz[i];
}

for(i=0;i<n;i++) {
stepen=(int) niz[i];
niz[i]-=stepen;
niz[i]*=60;
minut=(int)niz[i];
niz[i]-=minut;
niz[i]*=60;
if(niz[i]>=0) sekund=(int) (niz[i] + 0.5);
else if (niz[i]<0) sekund=(int) (niz[i] - 0.5) ;

if(sekund==60) {
sekund=0;
minut++;

if(minut==60) {
minut=0;
stepen++;
}
}

else if(sekund==-60) {
sekund=0;
minut--;

if(minut==-60) {
minut=0;
stepen--;
}
}

stepeni[i]=stepen;
if(stepen!=0 ||(stepen==0 && x[i]>0)) {
minut=fabs(minut);
minute[i]=minut;
}
else minute[i]=minut;
if( (stepen!=0 || minut!=0) || (minut==0 && x[i]>0)) {
sekund=fabs(sekund);
sekunde[i]=sekund;
}
else sekunde[i]=sekund;
}



for(i=0;i<n;i++) {
if(sekunde[i]<-30 || sekunde[i]>30) {
for(j=i;j<n-1;j++) {
sekunde[j]=sekunde[j+1];
minute[j]=minute[j+1];
stepeni[j]=stepeni[j+1];
}
n--;
i--;
}
}

printf("Uglovi su:");

for(i=0;i<n;i++) {
printf("\n%d stepeni %d minuta %d sekundi",stepeni[i], minute[i], sekunde[i]);
}


return 0;
}
