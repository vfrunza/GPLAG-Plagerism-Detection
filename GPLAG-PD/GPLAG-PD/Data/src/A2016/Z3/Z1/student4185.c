#include <stdio.h>

int daj_prost()
{
	
	int i = 1, brojac = 0;
	static int pocetak = 2;                            
	
	for ( i = 1; i <= pocetak; i++ ) {
		if ( pocetak % i == 0 ) {                                      /*Trazenje prostih brojeva*/
			brojac++;                                  
		}
		if ( brojac > 2 ) {                           
			pocetak++;                                
			brojac = 0;
			i = 0;
		}
	}                
		pocetak++;                                     
	
  return (pocetak - 1);                              
}


int main() {
	
	int a,b,i,j,suma = 0;
	
    do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a,&b);
		if ( a < 1 ) {                                               /*Provjeravamo da li a i b zadovoljavaju uslove zadatka*/
			printf("A nije prirodan broj.\n");
		}
		 if ( a >= b ) {
			printf("A nije manje od B.\n");
		}
}  while( a < 1 || a >= b );                                         
	

    for( i = 0; i <= b; i++ ){                                      /*suma*/
		j=daj_prost();                                              
	    if ( j >= b ) break;
	    if (j > a ){                                                   
		   suma = suma + j;
	}
}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);
	
	return 0;
}
