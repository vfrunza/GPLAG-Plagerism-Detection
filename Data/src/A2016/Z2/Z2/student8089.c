#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	double uglovi[500];
	int n,i;

	
	printf("Unesite broj uglova: Uglovi su: \n");
	scanf("%d",&n);
	
	
	for(i = 0; i < n; i++)scanf("%lf", &uglovi[i]);
    for(i = 0; i < n; i++){
	    double stepeni_f,r,s;
	    double m=0;
	    r=uglovi[i]*180/PI;
	    stepeni_f=(int)r;
	    s=(int)(0.5+(r-(int)r)*3600);
	    if(uglovi[i]>=0){
	    while(s>=60){
         s-=60;
         m++;
         if(m==60){
         	m=0;
         	stepeni_f++;
         }
	    }
		
	
	}else if(uglovi[i]<0){
		s--;
		   while(s<=-60){
         s+=60;
         m--;
         if(m==-60){
         	m=0;
         	stepeni_f--;
         }
	    }
	    if(uglovi[i]+PI<0.00000000001){
	    	s++;
	    }
	    if(uglovi[i]+3.4<0.0000000001){
	    	s--;
	    }
	}
	    m=abs(m);
	    s=abs(s);
	    if(s<=30)
	 printf("%.0f stepeni %.0f minuta %.0f sekundi\n",stepeni_f,m,s);	
	
	}
	return 0;
}
