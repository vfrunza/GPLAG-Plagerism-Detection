#include <stdio.h>
#include <stdlib.h>

int dva_od_tri(int niz1[], int vel1, int niz2[], int vel2, int niz3[], int vel3){
    int rezultat = 0;
    
    int i, j, k, m;
    
    int vec_provjerio_brojeve_niz1[1000];
    
    int brojac = 0;
    
    for(i = 0; i < vel1; i++) {
    	int vec_provjerio = 0;
    	
    	for(m = 0; m < brojac; m++) {
    		if(vec_provjerio_brojeve_niz1[m] == niz1[i]) {
    			vec_provjerio = 1;
    			break;
    		}
    	}
    	
    	if(vec_provjerio == 1) {
    		continue;
    	}
    	
    	vec_provjerio_brojeve_niz1[brojac] = niz1[i];
    	brojac += 1;
    	
        int koliko_puta_sam_nasao = 0;
        
        for(j = 0; j < vel2; j++) {
            if(niz1[i] == niz2[j]) {
                koliko_puta_sam_nasao += 1;
                break;
            }
        }
        
        for(k = 0; k < vel3; k++) {
            if(niz1[i] == niz3[k]) {
                koliko_puta_sam_nasao += 1;
                break;
            }
        }
        
        if(koliko_puta_sam_nasao == 1) {
            rezultat += 1;
        }
    }
    
    int vec_provjerio_brojeve_niz2[1000];
    
    brojac = 0;
    
    for(j = 0; j < vel2; j++) {
    	int vec_provjerio = 0;
    	
    	for(m = 0; m < brojac; m++) {
    		if(vec_provjerio_brojeve_niz2[m] == niz2[j]) {
    			vec_provjerio = 1;
    			break;
    		}
    	}
    	
    	if(vec_provjerio == 1) {
    		continue;
    	}
    	
    	vec_provjerio_brojeve_niz2[brojac] = niz2[j];
    	brojac += 1;
    	
        int nasao = 0;
        int vec_nasao = 0;
        
        for(k = 0; k < vel3; k++) {
            if(niz2[j] == niz3[k]) {
                nasao = 1;
                break;
            }
        }
    
        for(i = 0; i < vel1; i++) {
            if(niz2[j] == niz1[i]) {
                vec_nasao = 1;
                break;
            }
        }
    
        if(nasao == 1 && vec_nasao == 0) {
            rezultat += 1;
        }
    }
    
    return rezultat;
}

int main()
{
    int niz1;
    int niz2 ;
    int niz3 ;

    int vel1, vel2, vel3;

    int broj_clanova = dva_od_tri(niz1, vel1, niz2, vel2, niz3, vel3);
}


