#include <stdio.h>

int dva_od_tri(int niz1[], int d1, int niz2[], int d2, int niz3[], int d3){
	int brojac=0,i,j,k,ii,jj,kk;
	for(i=0; i<d1;i++){
		for(ii=0;ii<i; ii++){
			if(niz1[ii]==niz1[i]) {
				break; }
		}
		if(ii!=i) continue;
		for(j=0;j<d2;j++){
			for(jj=0;jj<j; jj++){
				if(niz2[jj]==niz2[j]) break;
			}
			if(jj!=j) continue;
			if(niz1[i]==niz2[j]){
				for (k=0; k<d3; k++){
					if(niz1[i]==niz3[k]){
						break;
					}
				}
				if(k==d3) brojac++;
			}
				
		}
	}
	for(i=0; i<d1;i++){
		for(ii=0;ii<i; ii++){
			if(niz1[ii]==niz1[i]) break;
		}
		if(ii!=i) continue;
		for(k=0;k<d3;k++){
			for(kk=0;kk<k; kk++){
				if(niz3[kk]==niz3[k]) break;
			}
			if(kk!=k) continue;
			if(niz1[i]==niz3[k]){
				for (j=0; j<d2; j++){
					if(niz1[i]==niz2[j]){
						break;
					}
				}
				if(j==d2) brojac++;
			}
				
		}
	}
	for(j=0; j<d2;j++){
		for(jj=0;jj<j; jj++){
			if(niz2[jj]==niz2[j]) break;
		}
		if(jj!=j) continue;
		for(k=0;k<d3;k++){
			for(kk=0;kk<k; kk++){
				if(niz3[kk]==niz3[k]) break;
			}
			if(kk!=k) continue;
			if(niz2[j]==niz3[k]){
				for(i=0; i<d1;i++){
					if(niz1[i]==niz2[j]){
						break;
					}
				}
				if(i==d1) brojac++;
				
			}
		}
	}
	return brojac;
}


int main() {
	int niz1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	int niz2[] = {3, 3, 3, 2, 2};
	int niz3[] = {1, 3, 4};
	int rez = dva_od_tri(niz1, 11, niz2, 5, niz3, 3);
	printf("%d ", rez);
	rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 3);
	printf("%d ", rez);
	rez = dva_od_tri(niz1, 11, niz1, 11, niz1, 11);
	printf("%d ", rez);
	
	return 0;

}