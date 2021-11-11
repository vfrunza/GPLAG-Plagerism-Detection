#include <stdio.h>

int dva_od_tri(int niz_jedan[],int n_jedan,int niz_dva[],int n_dva,int niz_tri[],int n_tri) {
	int i,x,j,k,brojac;
for (i=0; i<n_jedan; i++) 
	for (x=i; x>0; x--) {
		if (niz_jedan[x]==niz_jedan[i]) {
			i++;
			break;
		}
	}
	for (j=0; j<n_dva; j++) {
		for (x=j; x>0; x--) {
			if (niz_dva[x]==niz_dva[i]) {
				i++;
				break;
			}
		}
		if (niz_jedan[i]==niz_dva[j]) {
			brojac++;
			for (k=0; k<n_tri; k++) 
				if (niz_jedan[i]==niz_tri[k]) { brojac--; break;};
		}
	}


for (i=0; i<n_jedan; i++) 
	for (x=i; x>0; x--) {
		if (niz_jedan[x]==niz_jedan[i]) {
			i++;
			break;
		}
	}
	for (j=0; j<n_tri; j++) {
		for (x=j; x>0; x--) {
			if (niz_tri[x]==niz_tri[i]) {
				i++;
				break;
			}
		}
		if (niz_jedan[i]==niz_tri[j]) {
			brojac++;
			for (k=0; k<n_dva; k++) 
				if (niz_jedan[i]==niz_dva[k]) { brojac--; break;};
		}
	}

for (i=0; i<n_dva; i++) 
	for (x=i; x>0; x--) {
		if (niz_dva[x]==niz_dva[i]) {
			i++;
			break;
		}
	}
	for (j=0; j<n_tri; j++) {
		for (x=j; x>0; x--) {
			if (niz_tri[x]==niz_tri[i]) {
				i++;
				break;
			}
		}
		if (niz_dva[i]==niz_tri[j]) {
			brojac++;
			for (k=0; k<n_jedan; k++) 
				if (niz_dva[i]==niz_jedan[k]) { brojac--; break;};
		}
	}
	
	return brojac;
}

int main() {
	int niz_jedan[50], niz_dva[50], niz_tri[50],i,j,k,n_jedan,n_dva,n_tri;
	printf("Unesite broj elemenata prvog niza: ");
	scanf("%d",&n_jedan);
    printf("Unesite elemente prvog niza: ");
	for(i=0; i<n_jedan; i++){
		scanf("%d", &niz_jedan[i]);
		if(niz_jedan[i]==-1) break;
	}
	
	printf("Unesite broj elemenata drugog niza: ");
	scanf("%d",&n_dva);
	printf("Unesite elemente drugog niza: ");
	for(j=0; j<n_dva; j++){
		scanf("%d", &niz_dva[i]);
		if(niz_dva[i]==-1) break;
	}
	
	printf("Unesite broj elemenata treceg niza: ");
	scanf("%d",&n_tri);
	printf("Unesite elemente treceg niza: ");
	for(k=0; k<n_tri; k++){
		scanf("%d", &niz_tri[i]);
		if(niz_tri[i]==-1) break;
	}
	
	
	dva_od_tri(niz_jedan[n_jedan],n_jedan, niz_dva[n_dva],n_dva, niz_tri[n_tri],n_tri);
	
	return 0;
}