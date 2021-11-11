#include <stdio.h>

int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2){
	int i, c, niz3[1000], vel3=0, j, k, m, s, br, minus;
	
	for(i=0;i<vel2;i++){
		if(niz2[i]<0 || niz2[i]>9)
			return 0;
	}
	
	for(i=0; i<vel2-1; i++) {
		for(j=i+1; j<vel2; j++) {
			if(niz2[i] == niz2[j]) {
				return 0;
			}
		}
	}
	
	for(i=0;i<vel1;i++) {
		if(niz1[i] < 0) {
			minus = 1;
		}
		else {
			minus = 0;
		}
		
		vel3 = 0; // reset
		while(niz1[i]!=0){
			c=niz1[i]%10;
			if(c < 0)
			c *=-1;
			niz3[vel3]=c;
			vel3++;
			niz1[i]=niz1[i]/10;
		}
		
		for(j=0; j<vel2; j++){
			for (m=0; m<vel3; m++) {
				if(niz3[m]==niz2[j]) {
					for(k=m; k<vel3-1; k++){
						niz3[k]=niz3[k+1];
					}
					vel3--;
					m--;
				}
			}
		}
		
		
		if(vel3 == 0) {
			niz1[i] = 0;
		}
		else {
			
			br = 0;
			for(s=vel3-1; s>=0; s--) {
				br = br*10 + niz3[s];
			}
			
			if(minus) {
				niz1[i] = br*(-1);
			}
			else {
				niz1[i] = br;
			}
		}
	}
	return 1;
}

int main(void){
	int i, vel1, vel2, niz1[10000], niz2[10];
	printf("Unesite clanove prvog niza(-1 za kraj unosa): ");
	for(i=0;i<10000;i++){
		scanf("%d", &niz1[i]);
		if(niz1[i]==-1)
		break;
	}
	vel1=i;
	printf("Unesite cifre drugog niza: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz2[i]);
		if(niz2[i]==-1)
		break;
	}
	vel2=i;
	printf("%d", izbaci_cifre(niz1,vel1, niz2, vel2));
	return 0;
}
