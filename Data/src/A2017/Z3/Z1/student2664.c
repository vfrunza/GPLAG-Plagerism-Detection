#include <stdio.h>

int dva_od_tri (int niz1[],int vel1,int niz2[],int vel2,int niz3[],int vel3){
    int brojac = 0,novibr = 0 ;
    int i , j , k ,n,m;
    int pomocni[100];
    int finalni[100];
    int varijabla = 0 ;
    
    for(i = 0 ; i < vel1; i++){
    	for(j = 0 ; j < vel2; j++){
    		for( n = 0 ; n < 100 ; n++){
    		if(niz1[i] == niz2[j] || niz1[i] == niz2[j+1]) pomocni[n] = niz1[i];
    		brojac++;
    		}
    	}
    }
    
    for(j = 0 ; j < vel2; j++){
    	for(k = 0 ; k < vel3; k++){
    		for(n = 0 ; n < 100 ; n++){
    			if(niz2[j] == niz3[k] || niz2[j] == niz3[k+1]) pomocni[n] = niz2[j];
    			brojac++;
    		}
    	}
    }
    
    
    for(i = 0 ; i < vel1; i++){
    	for(k = 0 ; k < vel3; k++){
    		for(n = 0 ; n < 100; n++){
    			if(niz1[i] == niz3[k] || niz1[i] == niz3[k+1]) pomocni[n] = niz1[i];
    			brojac++;
    		}
    	}
    }
    
    for(n = 0 ; n < brojac ; n++){
    	for(m = n ; m < brojac; m++){
    		if(pomocni[n] == pomocni[n+1]) continue;
    		else {
    			finalni[m] = pomocni[m];
    		novibr++;
    	}
    	}
    }
    
    for( i = 0 ; i < novibr ; i++){
    	varijabla = finalni[i];
    }
    return varijabla;
}
int main() {
	
	int niz1[100],niz2[100],niz3[100];
	int vel1,vel2,vel3;
	
	int i , j , k ;
	
	printf("Unesite velicinu prvog niza: \n");
	scanf("%d",&vel1);
	printf("\nUnesite elemente prvog niza: \n");
	for( i = 0 ; i < vel1 ; i++)
	return 0;
}
