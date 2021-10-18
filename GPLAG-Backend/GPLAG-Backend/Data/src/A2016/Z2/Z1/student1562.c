#include <stdio.h>
#include <math.h>

int main() {
	int cifra,a,b,brojac=0,brojc=0,dodaj=0;
	long long int broj,br,rezultat=0,rez=0;
	printf("Unesite broj: ");
	scanf("%lld",&broj);
	
	if(broj<0){
		broj=fabs(broj);
	}
	br=broj;
    while(br!=0){
		brojac++;
		br=br/10;
	}
	br=broj;
	if(brojac==1)rez=0;
	else{
	while(broj!=0){
		a=broj%10;
	    brojc++;
		broj=broj/10;
		
		if(broj!=0)b=broj%10;
		
	if(brojc==1 && (a-b)==0)dodaj=1;
		if((a-b)<0) {rezultat=rezultat*10+fabs(a-b);}
		else rezultat=rezultat*10+(a-b);
	}
	while(rezultat!=0){
		cifra=rezultat%10;
		rez=rez*10+cifra;
		rezultat=rezultat/10;
	}
	if(dodaj==1)rez=rez*10;
	}
	printf("%lld",rez);
	return 0;
}
