#include <stdio.h>
#include <math.h>
float zaokruzi1(float* niz,int y)
{
	if(y<=0) {
		return 0;
	}
	float zaokruzeno=0;
	int i;
	float x;
	for(i=0; i<y; i++) {
		x=niz[i];
		if ((int)(x*100)-((int)(x*10)*10)<5) {
			zaokruzeno=(x*100-5)/100;
		} else {
			zaokruzeno=x;
		}
		zaokruzeno=ceil(zaokruzeno*10)/10;
		if(zaokruzeno==0) {
			niz[i]=0;
		} else {
			niz[i]=zaokruzeno;
		}
	}
	return zaokruzeno;
}
void preslozi(float*niz,int x,int k)
{
	int i,suma=0,clan=0,Min;
	float PrivremeniNiz[1000];
	float PomocniNiz[1000];
	if(x>0 || k>0) {
		for(i=0; i<x; i++) {
			PomocniNiz[i]=niz[i];
		}
		zaokruzi1(PomocniNiz,x);
		for(i=0; i<x; i++) {
			clan=(int)((fabs)(PomocniNiz[i]*10));
			suma=0;
			while(clan!=0) {
				suma=(fabs)(suma+(fabs)(clan%10));
				clan=(fabs)(clan/10);
			}
			if(suma==0 || suma==-0) {
				PrivremeniNiz[i]=suma;
			} else {
				PrivremeniNiz[i]=suma;
			}
		}
		Min=0;
		for(i=0; i<x; i++) {
			if(PrivremeniNiz[i]>=k) {
				niz[Min]=PomocniNiz[i];
				Min++;
			}
		}
		for(i=0; i<x; i++) {
			if(PrivremeniNiz[i]<k) {
				niz[Min]=PomocniNiz[i];
				Min++;
			}
		}

	}
}
int main()
{
	int i;
	float niz[] = { 14.09, -15.1, -1.57, -0.06, 13.999991 };
	preslozi(niz, 5, 14);
	printf("Niz glasi: ");
	for (i=0; i<5; i++)
		printf("%g ", niz[i]);

}
