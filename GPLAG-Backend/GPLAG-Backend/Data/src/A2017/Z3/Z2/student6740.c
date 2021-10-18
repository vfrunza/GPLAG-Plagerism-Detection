#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPSILON 0.0001
	
void zaokruzi1(float niz1[], int vel1){
	int i;
	for(i=0;i<vel1;i++){
		niz1[i]=round(niz1[i]*10)/10;
	}
}
void preslozi(float niz2[],int vel2, int k){
	int i, suma=0, vel3=0, m, n, c, x;
	double niz3[1000];
	zaokruzi1(niz2,vel2);
	for(i=0;i<vel2;i++){
		suma = 0;
		x=niz2[i]*10;
		while(x!=0){
			c=x%10;
			if(c<0)
			c*=-1;
			suma+=c;
			x=x/10;
		}
		if(suma>=k){
			niz3[vel3]=niz2[i];
			vel3++;
		}
	}
	
	m=vel3;
	for(i=0;i<vel2;i++){
		suma=0;
		x=niz2[i]*10;
		while(x!=0){
			c=x%10;
			if(c<0)
			c*=-1;
			suma+=c;
			x=x/10;
		}
		if(suma<k){
			niz3[m]=niz2[i];
			m++;
		}
	}
	n=m;
	for(i=0;i<n;i++){
		niz2[i]=niz3[i];
	}
}

int main(void){
	int i, vel2, k;
	float niz2[1000];
	printf("Unesite broj: ");
	scanf("%d", &k);
	printf("Unesite clanove niza(-1 za kraj): ");
	for(i=0;i<1000;i++){
		scanf("%f", &niz2[i]);
		if(fabs(niz2[i]+1)<EPSILON)
		break;
	}
	vel2=i;
	preslozi(niz2,vel2,k);
	for(i=0;i<vel2;i++){
		printf("%g ", niz2[i]);
	}
	return 0;
}
