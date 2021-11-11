#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define vel 500

int main() {
	int n,i,j;
	float st,min,sec,ostatak,ostatak2;
	float niz[vel];
	printf("Unesite broj uglova: ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
	
		scanf("%f",&niz[i]);}
		
printf("Uglovi su: ");
for(i=0;i<n;i++){
		st=niz[i]*180/PI;
		ostatak=st-(int)st;
		st=st-ostatak;
		min=ostatak*60;
		ostatak2=min-(int)min;
		min=min-ostatak2;
		sec=ostatak2*60;
	
	if(sec>=59.5 ){
		min++;
		sec=0;
	}
	if(sec<=-59.5){
		min--;
		sec=0;
	}
	if(min>=59.5 ){
		st++;
		min=0;
	}
	if(min<=-59.5){
		st--;
		min=0;
	}
	if(sec>30 || sec<-30){
		for(j=i;j<n;j++){
			niz[j]=niz[j+1];
		}
		i--;
		n--;
		continue;
	}
	
if(min<0){
	min=-min;
}
if(sec<0){
	sec=-sec;
}

		printf("\n%.f stepeni %.f minuta %.f sekundi",st,min,sec);

}
	
	return 0;
}
