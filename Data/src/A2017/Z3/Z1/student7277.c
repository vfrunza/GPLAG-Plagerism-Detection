#include <stdio.h>

int dva_od_tri(int niz1[],int vel1,int niz2[], int vel2, int niz3[], int vel3){
	int i,j,l, velpom1=0, velpom2=0, velpom3=0, brpon=0;
	int pomocni1[100], pomocni2[100], pomocni3[100];
	for(i=0;i<vel1-1; i++){
		for(j=i+1;j<vel2;j++){
			if(niz1[i]==niz2[i]){
				pomocni1[velpom1]=niz1[i];
				velpom1++;
			}
		}
	}
		for(i=0;i<vel2-1; i++){
		for(j=i+1;j<vel3;j++){
			if(niz2[i]==niz3[i]){
				pomocni2[velpom2]=niz2[i];
				velpom2++;
			}
		}
	}
		for(i=0;i<vel1-1; i++){
		for(j=i+1;j<vel3;j++){
			if(niz1[i]==niz3[i]){
				pomocni3[velpom3]=niz1[i];
				velpom3++;
			}
		}
	}
	for(i=0;i<velpom1-1;i++){
		for(j=i+1;j<velpom2;j++){
			if(pomocni1[i]==pomocni2[j]){
				for(l=0;l<velpom3;l++){
					if(pomocni3[l]==pomocni1[i] || pomocni3[l]==pomocni2[j]){
					break;
					}
				}
			}
			brpon++;
		}
	}
	for(i=0;i<velpom2-1;i++){
		for(j=i+1;j<velpom3;j++){
			if(pomocni2[i]==pomocni3[j]){
				for(l=0;l<velpom1;l++){
					if(pomocni1[l]==pomocni2[i] || pomocni1[l]==pomocni3[j]){
					break;
					}
				}
			}
		brpon++;
		}
	}
	for(i=0;i<velpom1-1;i++){
		for(j=i+1;j<velpom3;j++){
			if(pomocni1[i]==pomocni3[j]){
				for(l=0;l<velpom2;l++){
					if(pomocni2[l]==pomocni1[i] || pomocni2[l]==pomocni3[j]){
					break;
					}
				}	
			}
		brpon++;
		}
	}
	
	return brpon;
}

int main(void){
	int i, niz1[1000], niz2[1000],niz3[1000], vel1, vel2, vel3;
	printf("Unesite clanove prvog niza: ");
	for(i=0;i<1000;i++){
		scanf("%d", &niz1[i]);
		if(niz1[i]==-1)
		break;
	}
	vel1=i;
	printf("Unesite clanove drugog niza: ");
	for(i=0;i<1000;i++){
		scanf("%d", &niz2[i]);
		if(niz2[i]==-1)
		break;
	}
	vel2=i;
	printf("Unesite clanove treceg niza: ");
	for(i=0;i<1000;i++){
		scanf("%d", &niz3[i]);
		if(niz3[i]==-1)
		break;
	}
	vel3=i;
	
	printf("%d", dva_od_tri(niz1, vel1, niz2, vel2, niz3, vel3));
	return 0;
}
