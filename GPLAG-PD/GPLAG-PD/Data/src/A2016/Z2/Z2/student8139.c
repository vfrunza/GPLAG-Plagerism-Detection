#include <stdio.h>
#define PI 3.1415926

int main() {
	int n, i, j;
	float niz[500];
	do{
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
	} while(n<1 || n>500);
	for(i=0; i<n; i++){
		scanf("%f", &niz[i]);
	}
	printf("Uglovi su: \n");
	for(i=0; i<n; i++){
		float deg = niz[i]*180/PI;
		int stepen = niz[i]*180/PI;
		float minute = (deg-stepen)*60;
		if(minute<0) minute=-1*minute;
		if((int)minute==60){ minute=0; stepen+=1;}
		float sekunde = (minute-(int)minute)*60;
		if(sekunde<0) sekunde=-1*sekunde;
		if((sekunde-(int)sekunde)<0.5) sekunde = sekunde;
		if((sekunde-(int)sekunde)>0.5) sekunde+=1;
		//printf("%d\n", (int)sekunde);
		if((int)sekunde==60){ sekunde=0; minute+=1;}
		if((int)minute==60){ minute=0; stepen+=1;}
		int sec = sekunde;
		//printf("%d\n", (int)sekunde);
		if(sec>30){
			for (j=i; j<n-1; j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
			//printf("%d stepeni %d minuta %d sekundi\n", stepen, (int)minute, (int)sekunde);
		}
	//printf("%d stepeni %d minuta %d sekundi\n", stepen, (int)minute, (int)sekunde);
		//printf("%d\n", sec);
		//printf("%f\n", niz[i]);
	}
	for(i=0; i<n; i++){
		float deg = niz[i]*180/PI;
		int stepen = niz[i]*180/PI;
		float minute = (deg-stepen)*60;
		if(minute<0) minute=-1*minute;
		if((int)minute==60){ 
			minute=0; 
			if(stepen<0) stepen-=1;
			else stepen+=1;}
		float sekunde = (minute-(int)minute)*60;
		if(sekunde<0) sekunde=-1*sekunde;
		if((sekunde-(int)sekunde)<0.5) sekunde = sekunde;
		if((sekunde-(int)sekunde)>0.5) sekunde+=1;
		if((int)sekunde==60){ sekunde=0; minute+=1;}
		if((int)minute==60){ 
			minute=0; 
			if(stepen<0) stepen-=1;
			else stepen+=1;}
		int sec = sekunde;
		
		printf("%d stepeni %d minuta %d sekundi\n", stepen, (int)minute, (int)sekunde);
	}
	//printf("%f\n", niz[i]);
	
	return 0;
}
