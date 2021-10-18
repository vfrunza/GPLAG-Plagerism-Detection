#include <stdio.h>
#define PI 3.1415926

int main()
{
	int i,j,br_uglova;
	double stepeni,minuta,sekundi,niz[500];
	do {
		printf("Unesite broj uglova: ");
		scanf("%d",&br_uglova);
		if(br_uglova<0 || br_uglova>500) printf("Pogresan unos.\n");
	} while(br_uglova<0 || br_uglova>500);

	for(i=0; i<br_uglova; i++)
		scanf("%lf",&niz[i]);
	printf("Uglovi su: \n");
	for(i=0; i<br_uglova; i++) {
		stepeni=niz[i]*180/PI;
		int s=stepeni;
		minuta=(stepeni-s)*60;
		if(minuta<0) minuta*=-1;
		int m=minuta;
		sekundi=(minuta-m)*60;
		int sec=sekundi;
		

		if(sekundi-sec>0.5)sec++;
		if(sec==60) {sec=0; m++;}
		if(m==60 && s>0) {m=0; s++;}
		if(m==60 && s<0) {m=0; s--;}



		if(sec>30) {
			for(j=i; j<br_uglova-1; j++)
				niz[j]=niz[j+1];
			br_uglova--;
			i--;

		}else
		printf("%d stepeni %d minuta %d sekundi\n",s,m,sec);
	}



	return 0;
}
