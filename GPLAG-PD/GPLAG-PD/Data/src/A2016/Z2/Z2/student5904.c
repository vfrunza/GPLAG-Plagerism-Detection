#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define NIZ 500

int main() {
    
    int n, i, j;
    long int stepen[NIZ], minuta[NIZ], sekunda[NIZ];
    long int ukupne_sekunde;
    double rad[NIZ];
    
    printf("Unesite broj uglova: ");
    scanf("%d", &n);
    
    for (i=0; i<n; i++) {
        scanf("%lf", &rad[i]);
        
        if(rad[i] >= 0)
            ukupne_sekunde=rad[i]*180/PI*3600 + 0.5;
        else
            ukupne_sekunde=rad[i]*180/PI*3600 - 0.5;
            
        stepen[i] = ukupne_sekunde/3600;
        minuta[i] = (ukupne_sekunde%3600)/60;
        minuta[i] = abs(minuta[i]);
        sekunda[i] = ukupne_sekunde%60;
        sekunda[i] = abs(sekunda[i]);
             
            
        
    }
    
   
    for (i=0; i<n; i++) {
       // printf("%ld stepeni %ld minuta %ld sekundi", stepen[i], minuta[i], sekunda[i]);
        if (sekunda[i]>30){
         //   printf(" IZBACEN %d",i);
             for(j=i; j<n-1; j++){
                stepen[j] = stepen[j+1];
                minuta[j] = minuta[j+1];
                sekunda[j] = sekunda[j+1]; 
             }
             n--;
             i--;
        }
        //printf("\n");
    }
    
    
    printf("Uglovi su:\n");
    for (i=0; i<n; i++) {
        //if (sekunda[i]<=30){
            printf("%ld stepeni %ld minuta %ld sekundi\n", stepen[i], minuta[i], sekunda[i]);
        //}
    }
	
	return 0;
}
