#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
#define BREL 500

int main() {	
	int bruglova, i, j,y,m,s,S;
	double uglovi[BREL];
	
	printf("Unesite broj uglova: ");
	scanf("%d", &bruglova);

	
	for(i=0;i<bruglova;i++){
		scanf("\n%lf", &uglovi[i]);
	}
	
	
	for(i=0;i<bruglova;i++){
		
		y=(uglovi[i]*180*3600/PI)+0.5;
		S=y/3600;
		m=(y%3600)/60;
		s=(y%3600)%60;
		
		if(s>=60){
			m++;
			s=s-60;
		}
		
		if(m>=60){
			S++;
			m=m-60;
		}
		
		if (s>30) {
			for(j=i;j<bruglova-1;j++){
				uglovi[j]=uglovi[j+1];
				
			}
			bruglova--;
			i--;
		}
		
			
		}
	
	
	printf("Uglovi su: ");
		
	for(i=0;i<bruglova;i++){
		
		y=(uglovi[i]*180*3600/PI)+0.5;
		S=y/3600;
		m=(y%3600)/60;
		s=(y%3600)%60;
		
		if(s>=60){
			m++;
			s=s-60;
		}
		
			if(m>=60){
				S++;
			m=m-60;
		}
		
		
		if (s>30) {
			for(j=i;j<bruglova-1;j++){
				uglovi[j]=uglovi[j+1];
				
			}
			bruglova--;
			i--;
		}
		
			printf("\n%d stepeni %d minuta %d sekundi", S, m, s);
		}
	
	
	
	
	
	
	return 0;
}


