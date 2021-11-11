#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
int main() {
	int broj_uglova,i,j,stepeni=0,minute=0,sekundi=0,minuti=0,sekunde[500],nova;
	double niz[500];
	printf("Unesite broj uglova: ");
		scanf("%d",&broj_uglova);
		if(broj_uglova<=500){
			for(i=0;i<broj_uglova;i++){
				scanf("%lf",&niz[i]);
				nova=niz[i];
				if(niz[i]<0) niz[i]=-niz[i];
				stepeni=(niz[i]*180/PI);
				minute=abs((((niz[i]*180/PI)-(stepeni))*60));
				sekunde[i]=abs(((((((niz[i]*180/PI)-(stepeni))*60)-minute)*60)+0.5));
				if(sekunde[i]>=59.5){
					minute+=1;
					sekunde[i]=0;
				}
				if(minute>=59.5){
					stepeni+=1;
					minute=0;
				}
			}
			for(i=0;i<broj_uglova;i++){
				if(sekunde[i]>30){
					for(j=i;j<broj_uglova-1;j++){
						niz[j]=niz[j+1];
						sekunde[j]=sekunde[j+1];
					}
					broj_uglova--;
					i--;
				}
			}
			printf("Uglovi su:\n");
			for(i=0;i<broj_uglova;i++){
				stepeni=(niz[i]*180/PI);
				if(stepeni<0) stepeni=-stepeni;
				minuti=abs((((niz[i]*180/PI)-(stepeni))*60));
				sekundi=abs(((((((niz[i]*180/PI)-(stepeni))*60)-minuti)*60)+0.5));
				if(sekundi>=59.5){
					minuti+=1;
					sekundi=0;
				}
				if(minuti>=59.5){
					stepeni+=1;
					minuti=0;
				}
				if(nova<0){
					printf("-%d stepeni %d minuta %d sekundi\n",stepeni,minuti,sekundi);
				}
				else{
					printf("%d stepeni %d minuta %d sekundi\n",stepeni,minuti,sekundi);
				}
			}
		
	}
	return 0;
}