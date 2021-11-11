#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double niz[500],ugao=0,min=0,sek=0;
	int n,i,ugaoS,minS,sekS;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lf", &niz[i]);}

printf("Uglovi su:\n");
for(i=0;i<n;i++){
/*Ekstrakcija ugla*/	
	ugao=niz[i]*(180/PI);
	ugaoS=(int)ugao;

/*Ekstrakcija minuta*/	
	min=ugao-ugaoS;
	min=min*60;
	minS=(int)min;
/*Ekstrakcija sekundi i zaokruzivanje*/
	sek=min-minS;
	sek=sek*60;
	sekS=round(sek);
	
	if(sekS<=30 && sekS>=-30)
		printf("%d stepeni %d minuta %d sekundi\n", ugaoS,minS,sekS);
	else
		continue;
}
	return 0;
}