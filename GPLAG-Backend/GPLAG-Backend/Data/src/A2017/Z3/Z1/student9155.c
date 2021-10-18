#include <stdio.h>

int dva_od_tri(int a[], int vel1, int b[], int vel2, int c[], int vel3){
	int br1[100]={0}, br2[100]={0}, br3[100]={0}, i, brojac=0;
	for(i=0; i<vel1; i++){
		br1[a[i]]++;
	}
	for(i=0; i<100; i++){
		if(br1[i]>1){
			br1[i]=1;
		}
	}
	for(i=0; i<vel2; i++){
		br2[b[i]]++;
	}
	for(i=0; i<100; i++){
		if(br2[i]>1){
			br2[i]=1;
		}
	}
	for(i=0; i<vel3; i++){
		br3[c[i]]++;
	}
    for(i=0; i<100; i++){
    	if(br3[i]>1){
    		br3[i]=1;
    	}
    }
    for(i=0; i<100; i++){
    	br1[i]=br1[i]+br2[i]+br3[i];
    }
	for(i=0; i<100; i++){
		if(br1[i]==2){
			brojac++;
		}
	}
	return brojac;
} 

int main() {
	printf("Zadaća 3, Zadatak 1");
	
		
		
	return 0;
}
