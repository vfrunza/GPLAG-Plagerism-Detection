#include <stdio.h>

int main() {
	int c=0,p=0,b=0,s=0,v=0,uk=0;
	float pr;
	char boja=' ';
	printf("Unesite vozila: ");
	while(boja!='k' || boja!='K'){
		scanf("%c",&boja);
			if(boja=='c' || boja=='C'){
				c=c+1;
				uk=uk+1;
			}
			if(boja=='b' || boja=='B'){
				b=b+1;
				uk=uk+1;
			}
			if(boja=='s' || boja=='S'){
				s=s+1;
				uk=uk+1;
			}
			if(boja=='v' || boja=='V'){
				v=v+1;
				uk=uk+1;
			}
			if(boja=='p' || boja=='P'){
				p=p+1;
				uk=uk+1;
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
if(c>b  && c>s  && c>v  && c>p){
	pr=((float)c/uk)*100;
	printf("Najpopularnija boja je crna (%.2f%%).",pr);
}
if(c<b  && b>s  && b>v  && b>p){
	pr=((float)b/uk)*100;
	printf("Najpopularnija boja je bijela (%.2f%%).",pr);	
}
if(c<s  && b<s  && s>v  && s>p){
	pr=((float)s/uk)*100;
	printf("Najpopularnija boja je siva (%.2f%%).",pr);	
}
if(c<v  && b<v  && s<v  && v>p){
	pr=((float)v/uk)*100;
	printf("Najpopularnija boja je crvena (%.2f%%).",pr);	
}
if(c<p  && b<p  && s<p  && v<p){
	pr=((float)p/uk)*100;
	printf("Najpopularnija boja je plava (%.2f%%).",pr);	
}
	return 0;
}
