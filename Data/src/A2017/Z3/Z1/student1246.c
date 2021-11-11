#include <stdio.h>

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
	int brU2Niza = 0;
	int i, j;
	int brBr;
	int flag;
	
	/*1 sa 2 i 3*/
	for(i = 0; i < vel1; i++){
		/*Provjeri jel' se vec provjerio trenutni clan*/
		flag = 0;
		for(j = 0; j < i; j++){
			if(niz1[j] == niz1[i]){
				flag = 1;
				break;
			}
		}
		
		if(flag) continue;
		
		brBr = 1;

		for(j = 0; j < vel2; j++){
			/*Provjeri ako se provjerio vec trenutni clan*/
			if( (j > 0) && (niz2[j] == niz2[j-1]) ) continue;
			
			if(niz1[i] == niz2[j]){
				brBr++;
				break;
			}
		}
		
		for(j = 0; j < vel3; j++){
			/*Provjeri ako se provjerio vec trenutni clan*/
			if( (j > 0) && (niz3[j] == niz3[j-1]) ) continue;
			
			if(niz1[i] == niz3[j]){
				brBr++;
				break;
			}
		}
		
		if(brBr == 2) brU2Niza++;
	}
	
	/*2 sa 3 bez 1*/
	for(i = 0; i < vel2; i++){
		/*Provjeri ako se provjerio vec trenutni clan*/
		flag = 0;
		for(j = 0; j < i; j++){
			if(niz2[j] == niz2[i]){
				flag = 1;
				break;
			}
		}
		
		if(flag) continue;
		
		brBr = 1;
		
		for(j = 0; j < vel3; j++){
			/*Provjeri ako se provjerio vec trenutni clan*/
			if( (j > 0) && (niz3[j] == niz3[j-1]) ) continue;
			
			if(niz2[i] == niz3[j]){
				brBr++;
				break;
			}
		}
		
		for(j = 0; j < vel1; j++){
			/*Provjeri ako se provjerio vec trenutni clan*/
			if( (j > 0) && (niz1[j] == niz1[j-1]) ) continue;
			
			if(niz2[i] == niz1[j]){
				brBr--;
				break;
			}
		}
		
		if(brBr == 2) brU2Niza++;
	}
	
	return brU2Niza;
}

int main() {
	
	int niz2[] = {3, 2, 3}, n2 = sizeof niz2 / sizeof *niz2;
	int niz1[] = {1, 2, 3}, n1 = sizeof niz1 / sizeof *niz1;
    int niz3[] = {2, 2}, n3 = sizeof niz3 / sizeof *niz3;
    
    printf ("%d ", dva_od_tri(niz1, n1, niz2, n2, niz3, n3));
    printf ("%d ", dva_od_tri(niz2, n2, niz3, n3, niz1, n1));
    printf ("%d ", dva_od_tri(niz2, n2, niz1, n1, niz3, n3));
    printf ("%d ", dva_od_tri(niz3, n3, niz2, n2, niz1, n1));
    printf ("%d\n", dva_od_tri(niz2, n2, niz2, n2, niz3, n3));
	
	return 0;
}
