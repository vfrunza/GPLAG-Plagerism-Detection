#include <stdio.h>
#include<math.h>

int n, rezervna, cifre=0, ostatak2, ostatak1, a, maxo, pamti, preskok=0, remember_me, isti=0, koliko;


int main() {
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if(n<0) n=-n;
	rezervna=n;
	
	
	while(n!=0)	{	
			
			n=n/10;
			if(remember_me==n) isti=1;
			remember_me=n;
			cifre++;
		}
		if(cifre==1){printf("%d", 0); return 0;}
		if(isti==1) {printf("0"); return 0;}
	n=rezervna;
	maxo=cifre;
	ostatak2=n/pow(10, cifre-1);
	
	while(cifre>1){
		
		ostatak1=n/pow(10, cifre-2);
		ostatak1=ostatak1%10;
		a=ostatak1-ostatak2;
		
		if(preskok==1 && pamti==0  && a==0) { cifre--; ostatak2=ostatak1; pamti=a;continue;}
		if(cifre==maxo && a==0){ preskok=1; cifre--; ostatak2=ostatak1; pamti=a; continue; }
		if(a<0) a=-a;
		koliko=printf("%d", a); 
	pamti=a;
		cifre--;
		ostatak2=ostatak1;
	}
	if(koliko==0) printf("0");
	return 0;
}
		
		

