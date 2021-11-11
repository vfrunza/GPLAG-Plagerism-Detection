#include <stdio.h>
#define PI 3.1415926
#define MAXIMUM 100
#include <math.h>
int main() {
		float s1, niz[MAXIMUM]; 
		int stepen[MAXIMUM], minute[MAXIMUM]={0}, sekunde[MAXIMUM];
		int n, i, j;
		printf("Unesite broj uglova: Uglovi su: \n");
		scanf("%d", &n);
		if(n<500 && n>0){
			//UNOS NIZA
		for(i=0;i<n;i++){
			scanf("%f", &niz[i]);
		}
		}
		//RAŠČLANJIVANJE SVE SE DOGODILO TU IZBRISI RASCLANJIVANJE
		for(i=0;i<n;i++){
			stepen[i]=(int)(niz[i]*180/PI);
			s1=(niz[i]*180/PI)-(int)((niz[i]*180/PI));
			sekunde[i]=(int)(0.5+(s1-(int)s1)*3600);
			if(niz[i]<0){
				sekunde[i]--;
			while(sekunde[i]<-59){
				sekunde[i]+=60;
				minute[i]--;
				if(minute[i]<-59){
					minute[i]+=60;
					stepen[i]--;
				}
			}
				if(niz[i]+3.1415926<0.000000000000000000001){
				sekunde[i]++;
			}
			if(niz[i]+3.16<0.000000000000000000001){
				sekunde[i]--;
			}
			}
			else{
			while(sekunde[i]>59){
				sekunde[i]-=60;
				minute[i]++;
				if(minute[i]>59){
					minute[i]-=60;
					stepen[i]++;
				}
			}
			
		}
		}
		//IZBACIVANJE ČLANOVA
		for(i=0;i<n;i++){
		
		
			if(sekunde[i]>30 || sekunde[i]<-30){
				for(j=i;j<n-1;j++){
					minute[j]=minute[j+1];
					sekunde[j]=sekunde[j+1];
					stepen[j]=stepen[j+1];
				}
				n--;
				i--;
			}
		}
		
		for(i=0;i<n;i++){
			minute[i]=fabs(minute[i]);
			sekunde[i]=fabs(sekunde[i]);
			printf("%d stepeni %d minuta %d sekundi \n", stepen[i], minute[i], sekunde[i]);
				
		}
		
	return 0;
}
