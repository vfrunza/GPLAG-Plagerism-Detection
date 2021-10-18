#include <stdio.h>
#define PI 3.1415926
#define M 60
#define S 3600

int main() {
	float broj,b;
	int n;
	int stepeni[500];
	int minute [500];
	int sekunde[500];
	int i;
	int stepen,minut,sekund;
	float m,k;
	double s;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%f",&broj);
		b=(broj*180)/PI;
		broj=b;
		stepen=(int) broj;
		m=(broj-stepen)*60;
	
		minut=(int) m;
		
		
		k=(minut)/60.;
		s=(broj-stepen-k)*3600;
		
		if(minut>=60){
			minut=0;stepen++;
		}
		if(s<0)s*=-1;
			if(s>0) s=s+0.5;
			if(minut<0)minut*=-1;
			sekund=(int)s;
			 if(sekund>=60){
			 	sekund=0;minut++;
			 	if(minut>=60){minut=0;
			 	if(stepen>0)stepen++;
			 		if(stepen<0) stepen--;
			 	}
			 }
			if(sekund<=30) {
			sekunde[i]=sekund;
			minute[i]=minut;
			stepeni[i]=stepen;
			}
		
		if(sekund>30){n--;i--;}
		
		
	}
	printf("Uglovi su: \n");
	
	for(i=0;i<n;i++){
	
			
		printf("%d stepeni %d minuta %d sekundi\n",stepeni[i],minute[i],sekunde[i]);
		}
	
	return 0;
}
