#include <stdio.h>

int dva_od_tri(int *pok1, int v1, int *pok2, int v2, int *pok3, int v3){
	int i,x=0;
	int nizbr1[10000]={0};
	int nizbr2[10000]={0};
	int nizbr3[10000]={0};
	int niznegbr1[10000]={0};
	int niznegbr2[10000]={0};
	int niznegbr3[10000]={0};
	int rezniz[10000]={0};
	int reznizneg[10000]={0};
	if(pok1!=NULL && v1!=0){
	for(i = 0 ; i < v1 ; i++){
		if(*pok1 < 0){
			*pok1 *= -1;
			if(niznegbr1[*pok1] == 1) pok1++;
		else{
			niznegbr1[*pok1] += 1;
			pok1++;
			}		
		}
		else{
		if(nizbr1[*pok1] == 1) pok1++;
		else{
			nizbr1[*pok1] += 1;
			pok1++;
		}
		}
	}
	}
	if(pok2!=NULL && v2!=0) {
for(i = 0 ; i < v2 ; i++){
		if(*pok2 < 0){
			*pok2 *= -1;
			if(niznegbr2[*pok2] == 1) pok2++;
		else{
			niznegbr2[*pok2] += 1;
			pok2++;
			}		
		}
		else{
		if(nizbr2[*pok2] == 1) pok2++;
		else{
			nizbr2[*pok2] += 1;
			pok2++;
		}
		}
	}
	}
	if(pok3!=NULL && v3!=0) {
for(i = 0 ; i < v3 ; i++){
		if(*pok3 < 0){
			*pok3 *= -1;
			if(niznegbr3[*pok3] == 1) pok3++;
		else{
			niznegbr3[*pok3] += 1;
			pok3++;
			}		
		}
		else{
		if(nizbr3[*pok3] == 1) pok3++;
		else{
			nizbr3[*pok3] += 1;
			pok3++;
		}
		}
	}
	}
	for(i = 0 ; i < 10000 ; i++){
		rezniz[i] = nizbr1[i] + nizbr2[i] + nizbr3[i];
		if(rezniz[i] == 2) x++;
	}
	for(i = 0 ; i < 10000 ; i++){
		reznizneg[i] = niznegbr1[i] + niznegbr2[i] + niznegbr3[i];
		if(reznizneg[i] == 2) x++;
	}
	
	return x;
}

int main() {
	int niz1[10]={-2,0,4,-7,8,-9,-1};
	int niz2[10]={4,7,2,8,10,-1};
	int niz3[10]={7,0,2,9};
	int *pok1=niz1;
	int *pok2=niz2;
	int *pok3=niz3;
	int v1 = sizeof(niz1) / sizeof(niz1[0]);
	int v2 = sizeof(niz2) / sizeof(niz2[0]);
	int v3 = sizeof(niz3) / sizeof(niz3[0]);
	int x = dva_od_tri(pok1, v1, pok2, v2 ,pok3 ,v3);
	printf("%d", x);
	return 0;
}
