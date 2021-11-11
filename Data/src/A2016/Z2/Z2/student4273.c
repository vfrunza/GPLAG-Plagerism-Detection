#include <stdio.h>
#define PI 3.1415926

int main() {
	double niz[500];

	 int stepen[500], minuta[500], sekunda[500];
	 int broj,i,j;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&broj);
	
	
	for(i=0;i<broj;i++){
		scanf("%lf",&niz[i]);
		}

	for(i=0;i<broj;i++){
		if(niz[i]>0){
		int ukupnoSekundi=(int)((((niz[i]*180)/PI)*3600)+0.5);
			stepen[i]=ukupnoSekundi/3600;
		minuta[i]=(ukupnoSekundi-stepen[i]*3600)/60;
		sekunda[i]=ukupnoSekundi-stepen[i]*3600-minuta[i]*60;
		if(sekunda[i]>=60) {
			minuta[i]++;
			sekunda[i]-=60;
			}
			if(minuta[i]>=60){
				stepen[i]++;
				minuta[i]-=60;
}
	if(sekunda[i]>30){
			for(j=i;j<broj-1;j++){
				niz[j]=niz[j+1];
			}
			broj--;
			i--;
		}
		}
		else if(niz[i]<0){
				int ukupnoSekundi=(int)((((niz[i]*180)/PI)*3600*(-1))+0.5);
			stepen[i]=ukupnoSekundi/3600;
		minuta[i]=(ukupnoSekundi-stepen[i]*3600)/60;
		sekunda[i]=ukupnoSekundi-stepen[i]*3600-minuta[i]*60;
		if(sekunda[i]>=60) {
			minuta[i]++;
			sekunda[i]-=60;
			}
			if(minuta[i]>=60){
				stepen[i]++;
				minuta[i]-=60;
				
				
}
stepen[i]*=-1;
	if(sekunda[i]>30){
			for(j=i;j<broj-1;j++){
				niz[j]=niz[j+1];
			}
			broj--;
			i--;
		}

		}
}
		
		
	printf("Uglovi su:\n");
	for(i=0;i<broj;i++){
	printf("%d stepeni %d minuta %d sekundi\n",stepen[i],minuta[i],sekunda[i]);
	}
	
	return 0;
}
