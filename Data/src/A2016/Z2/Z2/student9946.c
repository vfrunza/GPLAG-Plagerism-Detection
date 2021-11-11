#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1415926

int main()
{
	double ugao[500];
	double ugloviustepenima=0,dminut, sekund;
	int a,b,stepen=0,iminut,brojuglova;

	do {
		printf("Unesite broj uglova: ");
		scanf("%d",&brojuglova);

	} while(brojuglova<1);
	for(a=0; a<brojuglova; a++) {

		scanf("%lf", &ugao[a]);
	}
	printf("Uglovi su:\n");
	for(b=0; b<brojuglova; b++) {

		ugloviustepenima=(ugao[b]*180./PI);
		stepen=(int)ugloviustepenima;

		dminut=(fabs(ugloviustepenima-stepen))*60;

		iminut=floor(dminut);
		sekund=(dminut-iminut)*60;

		if (round (sekund)==60) {
			sekund=0;
			if (iminut+1==60) {
				iminut=0;
				if (stepen<0){
					stepen=stepen-1;
				}
				else{
					stepen=stepen+1;
				}
			} else {
				iminut=iminut+1;
			}
		}
		if(round(sekund)>30)
			continue;
		else
			printf("%d stepeni %d minuta %.0f sekundi\n" , stepen , iminut , round(sekund));
	}
	return 0;
}