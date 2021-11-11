#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int i,j,sati,minute,k=0,sekunde,brugl;
	float uglovi[500],temp,stepeni,min,sekk,novo;
	int z=0;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &brugl);
	
	for(i=0;i<brugl;i++){
		scanf("%f", &uglovi[i]);
	}
	
	for(i=0;i<brugl;i++){
		stepeni=(uglovi[i]*180)/PI;
		if(stepeni<0) stepeni=stepeni*(-1);
		sati=(int)stepeni;
		min=(stepeni-sati)*60;
		minute=(int)min;
		sekk=(min-minute)*60;
		sekunde=(int)sekk;
		novo=sekk-sekunde;
		if(novo>=0.5) sekunde++;
		if(sekunde==60) {
			sekunde=0;
			minute++;
		}
		if(minute==60) {
			sati++;
			minute=0;
		} 
		if(sekunde>30) {
			for(j=i;j<brugl;j++){
				temp=uglovi[j+1];
				uglovi[j+1]=uglovi[j];
				uglovi[j]=temp;
			}
			brugl--;
			i--;
		} k++; k*10;

	}
	
	printf("Uglovi su:\n");
	for(i=0;i<brugl;i++){
		stepeni=(uglovi[i]*180)/PI;
		if(stepeni<0){
			stepeni=stepeni*(-1);
			z=1;
		}
		sati=(int)stepeni;
		min=(stepeni-sati)*60;
		minute=(int)min;
		sekk=(min-minute)*60;
		sekunde=(int)sekk;
		novo=sekk-sekunde;
		if(novo>=0.5)sekunde++;
		if(sekunde==60){
			sekunde=0;
			minute++;
		}
		if(minute==60){
			sati++;
			minute=0;
		}
		
		k--; k/=10;
		if(z==1) sati=sati*(-1);
		if(sati==0 && z==1) printf("-");
		printf("%d stepeni %d minuta %d sekundi\n", sati,minute,sekunde);
		z=0; k--;
	}
	k=2;
	return 0;
}
