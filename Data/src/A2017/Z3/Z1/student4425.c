#include <stdio.h>
#include <math.h>

int dva_od_tri(int *niz1, int vel1, int *niz2, int vel2, int *niz3, int vel3){
	int *pok1=niz1;
	int *pok2=niz2;
	int *pok3=niz3;
	int brojaci1[10000]={0}, i; 
	int minusi1[10000]={0};
	int minusi2[10000]={0};
	int minusi3[10000]={0};
	int brojaci2[10000]={0};
	int brojaci3[10000]={0};
	int nule1=0;
	int nule2=0;
	int nule3=0;
	int udva=0;
	if((vel1==0 && vel2==0) || (vel2==0 && vel3==0) || (vel1==0 && vel3==0) || (vel1==0 && vel2==0 && vel3==0)) return 0;
	
	
	while(pok1<niz1+vel1){
		if(*pok1<0) minusi1[*pok1]++;
		else if(*pok1==0) nule1++;
		else brojaci1[*pok1]++;
		pok1++;
	}
	
	while(pok2<niz2+vel2){
		if(*pok2<0) minusi2[*pok2]++;
		else if(*pok2==0) nule2++;
		brojaci2[*pok2]++;
		pok2++;
	}
	while(pok3<niz3+vel3){
		if(*pok3<0) minusi3[*pok3]++;
		else if(*pok3==0) nule3++;
		brojaci3[*pok3]++;
		pok3++;
	}
	
	for(i=0;i<10000;i++){
		if(brojaci1[i]==brojaci2[i] && brojaci3[i]==0 && brojaci1[i]!=0 && brojaci2[i]!=0) udva=udva+1;
		else if(brojaci1[i]>brojaci2[i] && brojaci3[i]==0 && brojaci1[i]!=0 && brojaci2[i]!=0) udva=udva+1;
		else if(brojaci1[i]<brojaci2[i] && brojaci3[i]==0 && brojaci1[i]!=0 && brojaci2[i]!=0) udva=udva+1;
		else if(brojaci1[i]==brojaci3[i] && brojaci2[i]==0 && brojaci1[i]!=0 && brojaci3[i]!=0) udva=udva+1;
		else if(brojaci1[i]>brojaci3[i] && brojaci2[i]==0 && brojaci1[i]!=0 && brojaci3[i]!=0) udva=udva+1;
		else if(brojaci1[i]<brojaci3[i] && brojaci2[i]==0 && brojaci1[i]!=0 && brojaci3[i]!=0) udva=udva+1;
		else if(brojaci2[i]==brojaci3[i] && brojaci1[i]==0 && brojaci2[i]!=0 && brojaci3[i]!=0) udva=udva+1;
		else if(brojaci2[i]>brojaci3[i] && brojaci1[i]==0  && brojaci2[i]!=0 && brojaci3[i]!=0) udva=udva+1;
		else if(brojaci2[i]<brojaci3[i] && brojaci1[i]==0  && brojaci2[i]!=0 && brojaci3[i]!=0) udva=udva+1;
		if(minusi1[i]==minusi2[i] && minusi3[i]==0 && minusi1[i]!=0 && minusi2[i]!=0) udva=udva+1;
		else if(minusi1[i]>minusi2[i] && minusi3[i]==0 && minusi1[i]!=0 && minusi2[i]!=0) udva=udva+1;
		else if(minusi1[i]<minusi2[i] && minusi3[i]==0 && minusi1[i]!=0 && minusi2[i]!=0) udva=udva+1;
		else if(minusi1[i]==minusi3[i] && minusi2[i]==0 && minusi1[i]!=0 && minusi3[i]!=0) udva=udva+1;
		else if(minusi1[i]>minusi3[i] && minusi2[i]==0 && minusi1[i]!=0 && minusi3[i]!=0) udva=udva+1;
		else if(minusi1[i]<minusi3[i] && minusi2[i]==0 && minusi1[i]!=0 && minusi3[i]!=0) udva=udva+1;
		else if(minusi2[i]==minusi3[i] && minusi1[i]==0 && minusi2[i]!=0 && minusi3[i]!=0) udva=udva+1;
		else if(minusi2[i]>minusi3[i] && minusi1[i]==0  && minusi2[i]!=0 && minusi3[i]!=0) udva=udva+1;
		else if(minusi2[i]<minusi3[i] && minusi1[i]==0  && minusi2[i]!=0 && minusi3[i]!=0) udva=udva+1;
	}
	if((nule1>=nule2 || nule2>=nule1) && nule3==0 && nule1!=0 && nule2!=0) udva++;
	if((nule2>=nule3 || nule3>=nule2) && nule1==0 && nule2!=0 && nule3!=0) udva++;
	if((nule1>=nule3 || nule3>=nule1) && nule2==0 && nule1!=0 && nule3!=0) udva++;
	
	
	return udva;
}
int main() {
//	printf("Zadaća 3, Zadatak 1");
    int niz1[] = {111, -456, 456};
int niz2[] = {-456, 7, 890};
int niz3[] = {145, 457, 4345};
int rez;
rez = dva_od_tri(niz1, 0, niz2, 0, niz3, 3);
printf("%d ", rez);


	return 0;
}
