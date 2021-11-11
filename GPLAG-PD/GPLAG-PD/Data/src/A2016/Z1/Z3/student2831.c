#include <stdio.h>

int main()
{
	
	int brojac=0,c=0,b=0,s=0,v=0,p=0,k=0,K=0,max;
	float procenat=0,m=0;
	char a='a';
	
	printf("Unesite vozila: ");
 while(1){
 	scanf("%c",&a);

	
		if(a=='C' || a=='c')
		{brojac++;c++;}
		else if(a=='B' || a=='b')
		{brojac++;b++;}
		else if(a=='S' || a=='s')
		{brojac++;s++;}
		else if(a=='V' || a=='v')
		{brojac++;v++;}
		else if(a=='P' || a=='p')
		{brojac++;p++;}
		else if(a=='K' || a=='k') break;
		else {printf("Neispravan unos\n");}
 }
		
		max=0;
		if(max<c) max=c;
		if(max<b) max=b;
		if(max<s) max=s;
		if(max<v) max=v;
		if(max<p) max=p;
	
	
printf("Ukupno evidentirano %d vozila.",brojac);
m=brojac;
if(max>=1) {
	if(max==c){
		procenat=(100*c)/m;
		if(max == 0) procenat = 0.00;
		printf("\nNajpopularnija boja je crna (%.2f%%).",procenat);
		return 0;
	}
	if(max==b){
		procenat=(100*b)/m;
		printf("\nNajpopularnija boja je bijela (%.2f%%).",procenat);
		return 0;
	}
	if(max==s){
		procenat=(100*s)/m;
		printf("\nNajpopularnija boja je siva (%.2f%%).",procenat);
		return 0;
	}
	if(max==v){
		procenat=(100*v)/m;
		printf("\nNajpopularnija boja je crvena (%.2f%%).",procenat);
		return 0;
	}
	if(max==p){
		procenat=(100*p)/m;
		printf("\nNajpopularnija boja je plava (%.2f%%).",procenat);
		return 0;
	}
}
else 
printf("\nNajpopularnija boja je crna (0.00%%)."); 
	
	return 0;
}