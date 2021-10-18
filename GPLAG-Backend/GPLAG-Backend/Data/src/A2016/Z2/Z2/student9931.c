#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define q 500
int main() {
	int n=0,i=0,y=0;
    double niz[q],h=0,m=0,a=0,j=0,e=0,w=0;
	printf("Unesite broj uglova: ");
do{scanf("%d",&n);
}	while(n<=0 || n>=500);
do{scanf("%lf",&niz[i]);
		i++;
	}while(i<n);
		printf("Uglovi su: ");
    for(i=0;i<n;i++){
    j=fabs(niz[i]);
    m=floor(j*180/PI);
    h=j*180/PI;
    e=floor((h-m)*60);
    a=(h-m)*60;
    w=round((a-e)*60);
  if(w>=60){
   w-=60;
   e+=1;
   if(e>=60){
    e-=60;
    m+=1;}}
     if(w>30){
       for(y=i;y<n-1;y++){
        niz[y]=niz[y+1];
    }
    n--;
    i--;
   }
   else{
   	if(niz[i]<0) {printf("\n-%.0f stepeni %.0f minuta %.0f sekundi",m,e,w);}
    else {printf("\n%0.f stepeni %0.f minuta %0.f sekundi",m,e,w);}
    } }
	return 0;
}