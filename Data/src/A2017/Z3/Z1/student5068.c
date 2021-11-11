#include <stdio.h>
#include <math.h>

int dva_od_tri(int *prvi_niz, int vel1, int *drugi_niz, int vel2, int *treci_niz, int vel3) {
	int logicki_niz1[1000]={0}, logicki_niz2[1000]={0}, logicki_niz3[1000]={0}, logicki_neg1[1000]={0}, logicki_neg2[1000]={0}, logicki_neg3[1000]={0}, i, brojac=0, abs_value;
	
	//logicki nizovi (pozitivni i negativni) - da li se broj pojavio u tom nizu?, brojac - koliko se elemenata ponovilo tacno 2 puta
	
	for(i=0; i<vel1; i++) {
		if(*(prvi_niz+i)>=0) logicki_niz1[*(prvi_niz+i)]=1;
		else {
			abs_value=round(fabs(*(prvi_niz+i)));
			logicki_neg1[abs_value]=1;
		}
	}
	for(i=0; i<vel2; i++) {
		if(*(drugi_niz+i)>=0) logicki_niz2[*(drugi_niz+i)]=1;
		else {
			abs_value=round(fabs(*(drugi_niz+i)));
			logicki_neg2[abs_value]=1;
		}
	}
	for(i=0; i<vel3; i++) {
		if(*(treci_niz+i)>=0) logicki_niz3[*(treci_niz+i)]=1;
		else {
			abs_value=round(fabs(*(treci_niz+i)));
			logicki_neg3[abs_value]=1;
		}
	}
	
	for(i=0; i<1000; i++) {
		if(logicki_niz1[i]+logicki_niz2[i]+logicki_niz3[i]==2) {
			brojac++;
		}
		if(logicki_neg1[i]+logicki_neg2[i]+logicki_neg3[i]==2) {
			brojac++;
		}
	} 
	
	return brojac;
}
int main() {
	int i, vel1, vel2, vel3, prvi_niz[100]={0}, drugi_niz[100]={0}, treci_niz[100]={0};
	
	printf("Unesite velicinu prvog niza: ");
	scanf("%d", &vel1);
	
	printf("Unesite prvi niz: ");
	for(i=0; i<vel1; i++) {
		scanf("%d", &prvi_niz[i]);
	}
	
	printf("Unesite velicinu drugog niza: ");
	scanf("%d", &vel2);
	
	printf("Unesite drugi niz: ");
	for(i=0; i<vel2; i++) {
		scanf("%d", &drugi_niz[i]);
	}
	
	printf("Unesite velicinu treceg niza: ");
	scanf("%d", &vel3);
	
	printf("Unesite treci niz: ");
	for(i=0; i<vel3; i++) {
		scanf("%d", &treci_niz[i]);
	}
	
	printf("%d", dva_od_tri(prvi_niz, vel1, drugi_niz, vel2, treci_niz, vel3));
	return 0;
}
