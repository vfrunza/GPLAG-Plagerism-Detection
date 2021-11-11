#include <stdio.h>
#include <math.h>

int main() {
	int n, p, z; /*p predzadnja cifra   */
	             /*   */
	int novibr=0,brojac1=0,brojac2=0;
    int novibrNaopako=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if(n>=0 && n<10) {  
		printf("0");
	    return 0;
	}
	else if(n<0) n=fabs(n);
	
	z=n%10;
	n/=10;
	while(n!=0){
		p=n%10;
		
		novibr=novibr*10;
		novibr+=fabs(z-p);
	    z=p;
	    brojac1++;
		n/=10;
	};
	
	while(novibr!=0)
	{
		z=novibr%10;
		novibrNaopako=novibrNaopako*10;
		novibrNaopako+=z;
		brojac2++;
		novibr/=10;
	};

    while(brojac2<brojac1) {novibrNaopako*=10; brojac2++;}
	printf("%d", novibrNaopako);
	return 0;
}
