#include <stdio.h>

int DaLiSeBrojNalaziUNizu(int niz[], int vel, int broj){
	int i, NalaziSe=0;
	for (i = 0; i < vel; i++) {
		if (niz[i]==broj) {
			NalaziSe=1;
			break;
		} 
	}
	if (NalaziSe==1) return 1;
	else return 0;
}
int dva_od_tri (int niz1[],int vel1,int niz2[], int vel2, int niz3[], int vel3){
	int br=0, i,j, pon=0;
	for (i = 0; i < vel1; i++) {
		pon=0;
		for(j=0; j<i; j++) 
			if(niz1[j]==niz1[i]) 
				pon++;
		if(pon==0)
			if((DaLiSeBrojNalaziUNizu(niz2,vel2,niz1[i])==1 && DaLiSeBrojNalaziUNizu(niz3,vel3,niz1[i])==0 || DaLiSeBrojNalaziUNizu(niz2,vel2,niz1[i])==0 && DaLiSeBrojNalaziUNizu(niz3,vel3,niz1[i])==1))
				br++;
	}
	for (i = 0; i < vel2; i++) {
		pon=0;
		for(j=0; j<i; j++) 
			if(niz2[j]==niz2[i]) 
				pon++;
		if(pon==0)
			if((DaLiSeBrojNalaziUNizu(niz3,vel3,niz2[i])==1 && DaLiSeBrojNalaziUNizu(niz1,vel1,niz2[i])==0))
				br++;
	}
	return br;
}


int main() {
	int i, vel1, niz1[100], vel2, niz2[100], vel3, niz3[100];
	printf("Unesite velicinu niza1: ");
	scanf("%d", &vel1);
	printf("Unesite niz1: ");
	for (i = 0; i < vel1; i++) {
		scanf("%d", &niz1[i]);
	}
	printf("Unesite velicinu niza2: ");
	scanf("%d", &vel2);
	printf("Unesite niz2: ");
	for (i = 0; i < vel2; i++) {
		scanf("%d", &niz2[i]);
	}
	printf("Unesite velicinu niza3: ");
	scanf("%d", &vel3);
	printf("Unesite niz3: ");
	for (i = 0; i < vel3; i++) {
		scanf("%d", &niz3[i]);
	}
	//printf("%d", dva_od_tri(niz1, niz2, niz3, vel1, vel2, vel3));
	return 0;
}
