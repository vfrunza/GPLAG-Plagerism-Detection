#include <stdio.h>

int main() {
	int c=0,p=0,b=0,s=0,v=0,uk=0;
	float procenat;
	char boja=' ';
	printf("Unesite vozila: ");
	while(boja!='k' || boja!='K'){
		scanf("%c",&boja);
			if(boja=='c' || boja=='C'){
				c++;
				uk++;
			}
			if(boja=='b' || boja=='B'){
				b++;
				uk++;
			}
			if(boja=='s' || boja=='S'){
				s++;
				uk++;
			}
			if(boja=='v' || boja=='V'){
				v++;
				uk++;;
			}
			if(boja=='p' || boja=='P'){
				p++;
				uk++;
			}
			if(boja!='c' && boja!='C' && boja!='b' && boja!='B' && boja!='s' && boja!='S' && boja!='v' && boja!='V' && boja!='p' && boja!='P' && boja!='k' && boja!='K'){
				printf("Neispravan unos\n");
			}
			if(boja=='k' || boja=='K'){
				goto l1;
			}
	}
l1:
printf("Ukupno evidentirano %d vozila.\n",uk);
if(uk==0){
		printf("Najpopularnija boja je crna (0.00%%).");
		return 0;
}
if(c>=b  && c>=s  && c>=v  && c>=p){
	procenat=((float)c/uk)*100;
	printf("Najpopularnija boja je crna (%.2f%%).",procenat);
}
if(c<b  && b>=s  && b>=v  && b>=p){
	procenat=((float)b/uk)*100;
	printf("Najpopularnija boja je bijela (%.2f%%).",procenat);	
}
if(c<s  && b<s  && s>=v  && s>=p){
	procenat=((float)s/uk)*100;
	printf("Najpopularnija boja je siva (%.2f%%).",procenat);	
}
if(c<v  && b<v  && s<v  && v>=p){
	procenat=((float)v/uk)*100;
	printf("Najpopularnija boja je crvena (%.2f%%).",procenat);	
}
if(c<p  && b<p  && s<p  && v<p){
	procenat=((float)p/uk)*100;
	printf("Najpopularnija boja je plava (%.2f%%).",procenat);	
}
	return 0;
}
