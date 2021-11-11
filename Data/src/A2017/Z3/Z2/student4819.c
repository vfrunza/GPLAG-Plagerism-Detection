#include <stdio.h>
#include <math.h>


void zaokruzi1( float niz[], int vel) {
	int i,x;
	while(vel>0) {
	  *niz=round(*niz*10)/10;
	  niz++;
	  vel--;
   }
}

int suma_cif(int x) {
	int suma = 0;
	while(x!=0) {
		suma+=x%10;
		x/= 10;
	}
	return fabs(suma);
}

 void  preslozi(float niz[], int vel, int k){
 	int i=0,j,y,suma;
 	float temp;
 	   zaokruzi1(niz, vel);
 	    for(j=0; j<vel;j++){
 	    	if(suma_cif((int)(niz[j]*10)) < k) {
 	    		temp = niz[j];
 	    	
 	    	for(j=i+1; j<vel; j++) {
 	    		niz[j-1] = niz[j];
 	    		niz[j-1] = temp;
 	    		j--;
 	    
 	    	}
 	    }
 	    			
 	    }
 	    
 }


int main() {
    int i,j,suma,vel;
    float niz[100];
	printf("Unesite velicinu");
	scanf("%d", &vel);
	printf("Upisite niz: ");
	for(i=0; i<vel; i++) {
	     scanf("%f", &niz[i]);
	}
	printf("Nakon zaokruzivanja niz glasi: ");
	zaokruzi1( niz,vel);
	
	for(i=0; i<vel; i++) {
	     printf("%f", niz[i]);
	}

	
	return 0;
}
