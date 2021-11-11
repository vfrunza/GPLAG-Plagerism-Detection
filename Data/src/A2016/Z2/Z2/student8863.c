#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main() {
	int l, i;
	double u, m, s, b, niz[1000], a;
	
	printf("Unesite broj uglova: ");
	
	do{
		scanf("%d", &l);
	}while(l<1 || l>500);
	
	for(i=0;i<l;i++){
		scanf("%lf", &niz[i]);
	}
	
	printf("Uglovi su:\n");
	for(i=0;i<l;i++){
		a=niz[i];
		if(a<0){
			a=a*(-1);
			u=floor(a*180/PI);
			m=floor((a*180/PI-u)*60);
			b=floor(m);
			s=floor(((a*180/PI-u)*60-b)*60+0.5);
			
			if(s>=60){
				if(m==60)
					s=s-60;
				else{
					m=m+1;
					s=s-60;
				}
			}
			if(m>=60){
				u=u+1;
				m=m-60;
			}
			u=u*(-1);
		}
		else{
			u=floor(a*180/PI);
			m=floor((a*180/PI-u)*60);
			b=floor(m);
			s=floor(((a*180/PI-u)*60-b)*60+0.5);
		
		
			if(s>=60){
				if(m==60)
					s=s-60;
				else{
				m=m+1;
				s=s-60;
			}
		}
		if(m>=60){
			u=u+1;
			m=m-60;
		}
		}
		if(s<=30 && s>=0)
		printf("%.0lf stepeni %.0lf minuta %.0lf sekundi\n", u,m,s);
	}
	
	return 0;
}