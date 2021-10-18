#include <stdio.h>
#define PI 3.1415926

int main() {
	int n,i,j,sek,min=0,br=0;
	float niz[500],step=0,usek;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%f",&niz[i]);}
	for(i=0;i<n;i++){
	float usek=(niz[i]*180/PI)*3600;
		usek=(int)(usek+0.5);
	int	step=usek/3600;
	int	min=(usek-step*3600)/60;
	int	sek=usek-step*3600-min*60;
	}
if (sek>=60) {
	min++; 
sek=sek-60;
}
if (min>=60) {
	step++;
min=min-60;
}
if(sek>30){
	for(j=i;j<n-1;j++) {
		niz[j]=niz[j+1];
		

	}
	br--;
	i--;
}




}
	
	return 0;
}
