#include <stdio.h>
#define PI 3.1415926
int main(){
	double niz[500], a, b, c, d[500];
	int stepeni, minute, sekunde, br_uglova, i, j;
	
	printf("Unesite broj uglova: ");
	scanf("%d", &br_uglova);
	for(i=0; i<br_uglova; i++){
		scanf("%lf", &niz[i]);
		d[i]=niz[i];
		if(niz[i]<0)niz[i]*=-1;
	}
	printf("Uglovi su: \n");
	for(i=0; i<br_uglova; i++){
	a=niz[i]*(180/PI);
		stepeni=(int)a;
		b=(a-stepeni)*60;
		minute=(int)b;
		c=(b-minute)*60;
		sekunde=(int)(c+0.5);
		if(sekunde>=60){ 
			minute++;
			sekunde-=60;
		}
		
		if(minute>=60) {
			stepeni++;
			minute-=60;
		}
		if(sekunde>30){
			for(j=i; j<br_uglova-1; j++){
				niz[j]=niz[j+1];
			}
			br_uglova--;
			i--;
		}
		else{
			
		    if(d[i]>=0) printf("%d stepeni %d minuta %d sekundi\n", stepeni, minute, sekunde);
		    else {
				
				printf("%d stepeni %d minuta %d sekundi\n", stepeni*=-1, minute, sekunde);
			}
		}
		}
	return 0;
	
}