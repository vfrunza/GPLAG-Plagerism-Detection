#include <stdio.h>

int dva_od_tri(int *N1,int *N2,int *N3,int vel1,int vel2,int vel3)
{
	int ukupnoBrojac=0,i,j;
	for(i=0;i<vel1;i++) {
		int brojac=1;
		for( j=0; j<vel2; j++) {
			if(N1[i]== N2[j]) brojac++;
		}
		for(j=0; j<vel3; j++) {
			if(N1[i]==N3[j]) brojac++;
		}
		if(brojac==2) {
			ukupnoBrojac++;
		}
	}

for( i=0; i<vel2; i++) {
	int brojac=1;
	for(j=0; j<vel1; j++) {
		if(N2[i]==N1[j]) brojac++;
	}
	for(j=0; j<vel3; j++) {
	   if(N3[i]==N1[j]) brojac++;
	}
	if(brojac==2) {
		ukupnoBrojac++;
	}
	}
	return ukupnoBrojac/2;
}
void main () {
	int niz1[]={1,2,3,5};
	int niz2[]={1,2,4,6,7};
	int niz3[]={1,3,4,8,9,10};
	int vel1=sizeof(niz1)/sizeof(niz1[0]);
	int vel2=sizeof(niz2)/sizeof(niz2[0]);
	int vel3=sizeof(niz3)/sizeof(niz3[0]);
	printf("%d", dva_od_tri(niz1,niz2,niz3,vel1,vel2,vel3));
}