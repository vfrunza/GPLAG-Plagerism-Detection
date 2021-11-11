#include <stdio.h>
#define pi 3.1415926
#include <stdlib.h>
int main() {
	int n,i,j,stepeni,minute,sekunde,nizstepeni[500],nizminute[500], nizsekunde[500]; float niz[500],ukupno;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%f", &niz[i]);


	} for(i=0;i<n;i++){
		ukupno=niz[i]*(180/pi)*3600;
		if(niz[i]>0){
		ukupno=(int)(ukupno+0.5);}
		else if(niz[i]<0){
			ukupno=(int)(ukupno-0.5);
		}
		stepeni=(int)(ukupno/3600);
		minute=(int)(ukupno-stepeni*3600)/60;
		sekunde=(int)(ukupno-stepeni*3600-minute*60);
		while(sekunde>=60 || sekunde<=-60 || minute>=60 || minute<=-60) {
			if(sekunde>=60) {
				minute++;
			sekunde=sekunde-60;}
			else if(sekunde<=-60){
			minute--;
			sekunde+=60;}
			if(minute>=60) {
				stepeni++;
			minute=minute-60;}
			else if(minute<=-60) {
				stepeni--;
			minute+=60; }
			}
		nizstepeni[i]=stepeni;
		nizminute[i]=minute;
		nizsekunde[i]=sekunde;
		if(sekunde>30 || sekunde<-30) {
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			} n--;i--;
		}
	} printf("Uglovi su: \n");
	   for(i=0;i<n;i++){
	   	if(nizminute[i]<0) nizminute[i]=abs(nizminute[i]);
	   	if(nizsekunde[i]<0) nizsekunde[i]=abs(nizsekunde[i]);
		printf("%d stepeni %d minuta %d sekundi\n", nizstepeni[i],nizminute[i],nizsekunde[i]);
	}
	
	return 0;
}
