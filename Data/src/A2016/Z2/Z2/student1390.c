#include <stdio.h>
#define PI 3.1415926


int main() {
	float niz[500],sek;
	int i,n,step,s,m=0;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%f\n", &niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++){
		niz[i]=niz[i]*(180/PI);
		if(niz[i]<0){
			step=(int)niz[i];
			sek=niz[i]-step;
			
			s=(int)(-0.5+sek*3600);
			m=s/60;
			while(s<=-60){
				s+=60;
			}
			
			if(m==-60){step--;
			m=0;}
			if(s<0)s*=-1;
			if(m<0)m*=-1;
			
		}
		
		else {
			step=(int)niz[i];
		sek=niz[i]-step;
		s=(int)(0.5+sek*3600);
		m=s/60;
		while(s>=60){
			s-=60;
		}
		if(m==60){step++;
		m=0;}
		}
		if(s>30 || s<-30)continue;
		
		printf("%d stepeni %d minuta %d sekundi\n", step,m,s);
	}
	return 0;
}
