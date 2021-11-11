#include <stdio.h>


int main() {
	
	char c;
	float c1=0,b1=0,s1=0,v1=0,p1=0;
	int a=0;
	float c2,b2,s2,v2,p2;
	
	printf("Unesite vozila: ");
	do{
		
		scanf("%c", &c);
		if(c=='c' || c=='C'){ c1++; a++;}
		else if(c=='b' || c=='B'){ b1++; a++;}
		else if(c=='s' || c=='S'){ s1++; a++;}
		else if(c=='v' || c=='V'){ v1++; a++;}
		else if(c=='p' || c=='P'){ p1++; a++;}
		else if (c!='k' && c!='K' || c== ' ' || c==" ")  {printf("Neispravan unos\n");} 
		
		
	}
	while(c!='k' && c!='K');

	if(a==0){printf("Ukupno evidentirano 0 vozila.\nNajpopularnija boja je crna (0.00%).");}
	else {
	printf("Ukupno evidentirano %d vozila.",a);
	c2=(c1/a)*100;
	b2=(b1/a)*100;
	s2=(s1/a)*100;
	v2=(v1/a)*100;
	p2=(p1/a)*100;
	
	printf("\n");
	
	if (c2>=b2 && c2>=s2 && c2>=v2 && c2>=p2 ){printf("Najpopularnija boja je crna (%.2f%%).",c2);}
	else if (b2>=c2 && b2>=s2 && b2>=v2 && b2>=p2){printf("Najpopularnija boja je bijela (%.2f%%).",b2);}
	else if (s2>=c2 && s2>=b2 && s2>=v2 && s2>=p2){printf("Najpopularnija boja je siva (%.2f%%).",s2);}
	else if (v2>=c2 && v2>=s2 && v2>=b2 && v2>=p2){printf("Najpopularnija boja je crvena (%.2f%%).",v2);}
	else if (p2>=c2 && p2>=s2 && p2>=v2 && p2>=b2){printf("Najpopularnija boja je plava (%.2f%%).",p2);}
	}
	
	return 0;
}
