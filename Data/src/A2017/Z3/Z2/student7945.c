#include <stdio.h>
#include <math.h>

void zaokruzi1(float niz[], int vel){
	int i;
	
	for(i=0; i<vel; i++){
		niz[i]=niz[i]*10;
		niz[i]=round(niz[i]);
		niz[i]=niz[i]/10;
	}
}

void preslozi(float niz[], int vel, int k){
	int i,j, suma[100]={0};
	float temp=0;
	zaokruzi1(niz,vel);
	
	for(i=0; i<vel; i++){
		niz[i]*=10;
		suma[i]+=niz[i]/100;
		suma[i]+=(int) (niz[i]/10)%10;
		suma[i]+=(int) niz[i]%10;
		niz[i]/=10;
	}
	
	
}


int main() {
	int i,k,vel;
	float niz[100];
	
	printf("Unesite niz: ");
	for(i=0; i<100; i++){
		scanf("%f", &niz[i]);
		if(niz[i]==-1){
			break;
		}
	}
	vel=i;
	
	printf("Unesite k: ");
	scanf("%d", &k);
	
	preslozi(niz, vel, k);
	printf("\nNakon preslaganja niz glasi: \n");
	for(i=0; i<vel; i++){
		printf("%g ", niz[i]);
	}

	return 0;
}