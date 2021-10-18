#include <stdio.h>
#include <stdlib.h>
#define duzina 100
int dva_od_tri(int niza[], int a, int nizb[], int b, int nizc[], int c){
	int i,j,brojac1[duzina]={0},brojac1n[duzina]={0},brojac2[duzina]={0},brojac2n[duzina]={0},brojac3[duzina]={0},brojac3n[duzina]={0},brojac=0;
	 for(i=0; i<a; i++){
	 	if(niza[i]>=0)
	 	brojac1[niza[i]]=1;
	 	else{
	 		brojac1n[abs(niza[i])]=1;
	 	}
	 }
	 for(i=0; i<b; i++){
	 	if(nizb[i]>=0){
	 		brojac2[nizb[i]]=1;
	 	}
	 	else{
	 		brojac2n[abs(nizb[i])]=1;
	 	}
	 }
	 for(i=0; i<c; i++){
	 	if(nizc[i]>=0){
	 		brojac3[nizc[i]]=1;
	 	}
	 	else{
	 		brojac3n[abs(nizc[i])]=1;
	 	}
	 }
	for(i=0; i<100; i++){
		if(brojac1[i]+brojac2[i]+brojac3[i]==2){
			brojac++;
		}
		if(brojac1n[i]+brojac2n[i]+brojac3n[i]==2){
			brojac++;
		}
	}
	return brojac;
	
}

int main() {
	
	return 0;
}
