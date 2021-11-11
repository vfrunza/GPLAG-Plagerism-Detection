#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main(){
	int i,j,stepen,minuta,sekundi,brojuglova;
    double ugao[500];
    //zbog preciznosti zaokruživanja, pada 3. autotest. Koristiti long double.
 double  ugaosekunda=0;
	//Sprjecavanje unosa negativnog broja uglova i 0.
	do{
		printf ("Unesite broj uglova: ");
		scanf ("%d",&brojuglova);
		}while(brojuglova<1);
	//Unos uglova.
	for(i=0;i<brojuglova;i++){
		scanf ("%lf",&ugao[i]);
	}
	//Prikazivanje i računanje uglova.
		printf ("Uglovi su:\n");
	for(j=0;j<brojuglova;j++){
	//ugaosekunda pretvara čitav ugao u sekunde
		ugaosekunda=(fabs(ugao[j])*180./PI)*3600.;
		ugaosekunda=(int)(ugaosekunda+.5);
	//	printf("Sekunde %f",ugaosekunda);
		stepen=ugaosekunda/3600;
		minuta=(ugaosekunda-stepen*3600)/60;
	//	sekundi=(ugaosekunda-stepen*3600-minuta*60);
		if (ugaosekunda-floor(ugaosekunda)>0.5){ugaosekunda=ceil(ugaosekunda);sekundi=(ugaosekunda-stepen*3600-minuta*60);}
		else {ugaosekunda=floor(ugaosekunda); sekundi=(ugaosekunda-stepen*3600-minuta*60);}
	if (sekundi>=60){
		minuta++;
		sekundi=60;
	}
	if(minuta>=60){
		stepen++;
		minuta=60;
	}
	//Ako je ugao negativan...
		if(ugao[j]<0){
			if(sekundi>30) continue;
			else printf("-%d stepeni %d minuta %d sekundi\n",stepen,minuta,sekundi);
		}
	//Ako nije ...
	    if(ugao[j]>=0){
	    	if(sekundi>30) continue;
	   else  printf("%d stepeni %d minuta %d sekundi\n",stepen,minuta,sekundi);
	
	    }
	    }
return 0;
}