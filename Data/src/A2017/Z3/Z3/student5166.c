#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int vrati_broj (int n, int cifra){ /* f-ja koja izbacuje iz broja n cifru koja je proslijedjena */ 
	int broj = n, novi_br = 0, i=1, c;
	while (broj != 0){
		c = broj % 10;
		if (abs(c) != cifra){
		    novi_br += i*c;
		    i*=10;
		}
		broj /= 10;
	}
    return novi_br;
}

int izbaci_cifre (int *niz_brojeva, int vel1, int *niz_cifara, int vel2){
    int i,j;
    for (i=0; i<vel2; i++){
   	    if (niz_cifara[i] < 0 || niz_cifara[i] > 9) return 0;
   	      for (j=i+1; j<vel2; j++){
   	         if (niz_cifara[j] == niz_cifara[i]) return 0;
          } 
    }
    
    for (i=0; i<vel1; i++){
        for (j=0; j<vel2; j++)
           niz_brojeva[i] = vrati_broj(niz_brojeva[i], niz_cifara[j]); /* prepisujemo u niz_brojeva[i]
           broj koji vrati f-ja vrati_broj */ 
    }
    return 1;
}
   
int main (){
    

	return 0;
}