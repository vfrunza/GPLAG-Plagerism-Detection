#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    
	int n , broj , prvacifra , drugacifra , i=0 , rezultat=0 , razlika ;
	
	printf("Unesite broj: ");
	
	scanf("%d", &n);

    	if (n<0) n=n*(-1);
    
    	while (n>9) {
	   
	    prvacifra=n%10;
	    n=n/10;
	   
	    drugacifra=n%10;
	    razlika = fabs(prvacifra-drugacifra);
	  
	    rezultat+=razlika*pow(10,i);
	    i++;
	}
	printf("%d", rezultat);
	return 0;
}
