#include <stdio.h>
#include <math.h>
int daj_prost(){
	static int l=2;
	int i,provjera;
	do {
		provjera=1;	
		for(i=2; i<=(sqrt(l)); i++) {
			if(l==2){ 
				break; 
			}
			else if(l%i==0) { 
				provjera=0;
			}
		}
		if(provjera==0) {
			l++;
		}
		else break;
		
	} while(1==1);
	l++;
	return l-1;
}	

int main() {
	int A,B,i,y=0,suma=0;
		
	do {
		
		printf ("Unesite brojeve A i B: ");
		scanf (" %d %d ",&A, &B); 
		if (A<=0) printf ("A nije prirodan broj.\n");
	    else if (A>=B)  printf ("A nije manje od B.\n");
	    else break;
	    
	} while(1==1);
	
	
	for (i=1; i<B; i++) {
		y=daj_prost();
		if((y>A) && (y<B)) 
			suma+=y; 
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma); 

return 0;
} 
