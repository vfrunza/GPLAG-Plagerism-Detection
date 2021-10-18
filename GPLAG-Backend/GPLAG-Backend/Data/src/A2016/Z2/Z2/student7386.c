#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926
 int main(){
 	double ugao[500],ugaosekunda=0;
 	int i,j,stepen,minuta,sekundi,brojuglova;
 	do{
 		printf("Unesite broj uglova: ");
 		scanf("%d",&brojuglova);
 	}while(brojuglova<1);
 	for(i=0;i<brojuglova;i++){
 		scanf("%lf",&ugao[i]);
 	}
 	printf("Uglovi su:\n");
 	for(j=0;j<brojuglova;j++){
 		ugaosekunda=(fabs(ugao[j])*180./PI)*3600.;
 		ugaosekunda=(int)(ugaosekunda+.5);
 		stepen=ugaosekunda/3600;
 		minuta=(ugaosekunda-stepen*3600)/60;
 	
 


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
		if(ugao[j]<0){
			if(sekundi>30) continue;
			else printf("-%d stepeni %d minuta %d sekundi\n",stepen,minuta,sekundi);
		}
	    if(ugao[j]>=0){
	    	if(sekundi>30) continue;
	   else  printf("%d stepeni %d minuta %d sekundi\n",stepen,minuta,sekundi);
	    }
	    }
return 0;
}