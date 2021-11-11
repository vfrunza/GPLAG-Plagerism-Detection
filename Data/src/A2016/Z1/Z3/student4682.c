#include <stdio.h>

int main() {
	char a;
	int uv,bc=0,bb=0,bs=0,bv=0,bp=0,max=0;
	float proc;
	printf("Unesite vozila: ");
	do {
	scanf("%c",&a);
		if (a=='C' || a=='c'){
	bc++;
	}
		else if (a=='B' || a=='b'){
	bb++;

	}
		else if (a=='S' || a=='s'){
	bs++;
	}
		else if (a=='V' || a=='v'){
	bv++;		
   
	}
    	else if (a=='P' || a=='p'){
	bp++;	

	}
	else if(a=='K' || a=='k') 
	break;
	else { 
    printf("Neispravan unos\n"); 
	}
	uv=bc+bb+bs+bv+bp;
	} while (1); 
    printf("Ukupno evidentirano %d vozila. \n", uv);
    max=bc;
    if(bb>max) max=bb;
    if(bs>max) max=bs;
    if(bv>max) max=bv;
    if(bp>max) max=bp;
   proc=((float)max/uv)*100;
   if (uv==0)
   proc=0;
  		 if(max==bc) {
  	
  		printf("Najpopularnija boja je crna (%.2f%%).",proc);	}
  		else if(max==bb) {
  	
  		printf("Najpopularnija boja je bijela (%.2f%%).",proc);	}
  		else if(max==bs) {
  		
		printf("Najpopularnija boja je siva (%.2f%%).",proc);	}
  		else if(max==bv) {
  		
		printf("Najpopularnija boja je crvena (%.2f%%).",proc);	}
  		else if(max==bp) {
  		
		printf("Najpopularnija boja je plava (%.2f%%).",proc);	}
	return 0;
}
