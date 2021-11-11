#include <stdio.h>

double zaokruzi1 (double niz[], int vel)
{
	int i, ostatak, temp;
	double zaokruzen_niz[100];
	for(i=0;i<vel;i++){
		
		niz[i]=niz[i]*100;
		niz[i]=(int)niz[i];
		temp=niz[i];
		ostatak=temp%10;
		temp=temp/10;
		niz[i]=temp;
		niz[i]=niz[i]/10.;
		if(ostatak>=5){
			niz[i]=niz[i]+0.1;
		}
		zaokruzen_niz[i]=niz[i];
	}
	
	return zaokruzen_niz[i];
}

int main() {
	int i, vel=0;
	double niz[100];
	for(i=0;i<100;i++){
		scanf("%lf",&niz[i]);
		vel++;
	}
	for(i=0;i<vel;i++){
		printf("Niz glasi: %lf ", zaokruzi1(niz, vel));
	}
	return 0;
}
