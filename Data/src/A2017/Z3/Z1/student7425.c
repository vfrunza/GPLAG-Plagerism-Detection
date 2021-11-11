#include <stdio.h>
int dva_od_tri(int *a,int a1,int *b, int b1, int *c,int c1){
	int niz[10]={0,0,0,0,0,0,0,0,0,0};
	int niz1[10]={0,0,0,0,0,0,0,0,0,0};
	int i,j,k;
	int brojac=0;
	for(i=0;i<a1;i++){
		for(j=0;j<10;j++){
			if(a[i]==j && niz1[j]==0){ 
			niz[j]++;
			niz1[j]++;
				break;
			}
		}
	}
	for(i=0;i<10;i++) niz1[i]=0;
	for(i=0;i<b1;i++){
		for(j=0;j<10;j++){
			if(b[i]==j && niz1[j]<1){ 
			niz[j]++;
			niz1[j]++;
			break;	
			}
		}
	}
	for(i=0;i<10;i++) niz1[i]=0;
	for(i=0;i<c1;i++){
		for(j=0;j<10;j++){
			if(c[i]==j && niz1[j]<1){
			niz[j]++;
			niz1[j]++;
				break;
			}
		}
	}
	for(k=0;k<10;k++){
		if(niz[k]==2) brojac++;
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
}
