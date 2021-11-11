#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int c, k, b,n, naopako = 0,brojac=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	 if(n<10 && n>=0) { printf("0"); return 0; } 
     
	while(n != 0)
	{
		naopako = naopako*10;
		naopako = naopako+n%10;
		n = n/10;
	}
	
    while(naopako != 0)
	   {
	      c = naopako%10;
	      naopako = naopako/10;
	      b = naopako%10;
	      if(b == 0) break;
	      k = fabs(c-b);
	      if (k==0) brojac++;
	      if (brojac>1) { brojac=0; continue; }
	      printf("%d", k);
	   }
	

	return 0;
}
