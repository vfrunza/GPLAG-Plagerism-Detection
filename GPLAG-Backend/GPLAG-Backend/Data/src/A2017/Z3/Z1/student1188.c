#include <stdio.h>
										
int binarni_brojac(int broj, int niz[], int vel){ /* ima li "broj"-a u nizu*/
	int i;
	for(i=0; i<vel; i++){
		if(broj==niz[i]) return 1;
	}
	return 0;
}

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
	int brojac=0, broj;
	int i, j, k, br1, br2, br3;
	
	for(i=0; i<vel1; i++){
		for(j=i+1; j<vel1; j++){
			if(niz1[i]==niz1[j]){
				for(k=j+1; k<vel1; k++)
					niz1[k-1]=niz1[k]; 		
				vel1--;
				j--;
			}
		}
	}
		
	for(i=0; i<vel2; i++){
		for(j=i+1; j<vel2; j++){
			if(niz2[i]==niz2[j]){
				for(k=j+1; k<vel2; k++)
					niz2[k-1]=niz2[k];
				vel2--;
				j--;
			}
		}
	}
		
	for(i=0; i<vel3; i++){
		for(j=i+1; j<vel3; j++){
			if(niz3[i]==niz3[j]){
				for(k=j+1; k<vel3; k++)
					niz3[k-1]=niz3[k];
				vel3--;
				j--;
			}
		}
	}
		
	for(i=0; i<vel1; i++){
		broj=niz1[i];
		br2=binarni_brojac(broj, niz2, vel2);
		br3=binarni_brojac(broj, niz3, vel3);
		if((br2==1 && br3==0) || (br2==0 && br3==1)) brojac++;
	}
	
	for(i=0; i<vel3; i++){
		broj=niz3[i];
		br1=binarni_brojac(broj, niz1, vel1);
		br2=binarni_brojac(broj, niz2, vel2);
		if(br1==0 && br2==1) brojac++;
		
	}

	return brojac;
	
}


int main() {
	int niz1[11]={2,2,2,2,2,2,2,2,2,2,2}, niz2[5]={3,3,3,2,2}, niz3[3]={1,3,4};
	printf("%d", dva_od_tri(niz1, 11, niz2, 5, niz3, 3));
	return 0;
}
