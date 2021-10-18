#include <stdio.h>

int dva_od_tri(int niz1[], int vel_1, int niz2[], int vel_2, int niz3[], int vel_3){
	
	int i=0, j=0, k=0;
	int brojac=0;
	while( (i<vel_1) && (j<vel_2) && (k<vel_3)){
		
		if((niz1[i]==niz2[j] && niz2[j]==niz3[k]))
			brojac++;
		if(niz2[j]==niz1[i] && niz1[i]==niz3[k])
			brojac++;
		if(niz3[k]==niz2[j] && niz1[i]==niz2[j])
			brojac++;
		if(niz1[i]==niz1[i]){	
			break;}
		if(niz2[j]==niz2[j]){	
			break;}
		if(niz3[k]=niz3[k]){
			break;}
		i++;
		j++;
		k++;
		
		
		
	}
	
	return brojac;
}

int main() {
	
	return 0;
	
	
}