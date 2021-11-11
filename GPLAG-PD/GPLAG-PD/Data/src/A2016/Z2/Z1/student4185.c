#include <stdio.h>
#include <stdlib.h>

int main() {
	int a,b,d,f,g,h,v,brojac,c,cif1,cif2,iz=0;
	printf("Unesite broj: ");
	scanf("%d", &b);
	d=abs(b);
	h=abs(b);
	brojac=1;
	if(b/10==0) {printf("0");}
	else{
		do{brojac=brojac*10; d=d/10;} while((d/10)!=0);
		do{
			g=h%brojac;
			h=h/brojac;
			brojac=brojac/10;
			cif1=g/brojac;
			if (cif1!=h) {iz=1;	}
			if (iz==1) {cif2=abs(cif1-h); printf("%d", cif2);}
			h=g;
			
		} while(brojac>9);
		
		if (iz==0) {printf("0");}
			
		}
		
	
	return 0;
}
