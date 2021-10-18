#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int a, nula=0, cifra=0, duzina=0, c, x=0, zc, pzc, broj=0, eksp=0, i, prepis=0;
	printf ("Unesite broj: ");
	scanf("%d", &a);
	if (a< 10 && a>-10) {printf ("0"); return 0;}
	if (a < 0){
		a = abs(a);
	}
	prepis=a;
	do{
		prepis=prepis/10;
		duzina++;}
	while (prepis!=0);
	
		zc=a%10;
		for(i=0; i<duzina-1; i++){
		a=a/10;
		pzc=a%10;
		
		if(zc<pzc){ 
		
		c= zc - pzc;
		c=abs(c);}
		
		else c= zc - pzc;
		
		if (c==0){ nula++;
		goto skip;}
		else {
			
		if (nula == 1)
		x= pow(10, eksp+1);
		
		else{
		x= pow(10, eksp);}
		
		cifra = c * x;
		broj= broj + cifra;
		
		skip:
		
		zc=pzc;
		eksp++;
		if (nula==1) nula--;
		
		}
		}
		printf("%d", broj);

	return 0;
}
