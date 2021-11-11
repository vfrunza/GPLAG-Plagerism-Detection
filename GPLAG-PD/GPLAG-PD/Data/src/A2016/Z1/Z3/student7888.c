#include <stdio.h>

int main() {

	char color=' ';
	int c=0,b=0,v=0,s=0,p=0,u=0;
	float pr;
	printf("Unesite vozila: ");

	do {
	scanf("%c", &color);

	if((color=='C') || (color=='c')) {
		c++;
		u++;
	}
	
	else if((color=='P') || (color=='p')) {
		p++;
		u++;
	}
	else if((color=='B') || (color=='b')) {
		b++;
		u++;
	}
	else if((color=='S') || (color=='s')) {
		s++;
		u++;
	}
	else if((color=='V') || (color=='v')) {
		v++;
		u++;
	}
		
	else if(color!='V' && color!='v' && color!='B' && color!='b' && color!='S' && color!='s' && color!='P' && color!='p' && color!='C' && color!='c' && color!='k' && color!='K' && color!='\n')	{
		 	printf("Neispravan unos\n");
		 	continue;
	}	
	}while(color!='k' && color!='K');
		
		


	printf("Ukupno evidentirano %d vozila.\n" , u);
	
	
	if(u==0) {
	
		printf("Najpopularnija boja je crna (0.00%%).");
		return 1;
	}
	
	if(c>b && c>s && c>p && c>v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(b>c && b>s && b>p && b>v) {
		pr=(float)b*100/u;
		printf("Najpopularnija boja je bijela (%.2f%%).",pr);
		return 1;
	}
	if(s>c && s>b && s>p && s>v) {
		pr=(float)s*100/u;
		printf("Najpopularnija boja je siva (%.2f%%).",pr);
		return 1;
	}
	if(p>c && p>b && p>s && p>v) {
		pr=(float)p*100/u;
		printf("Najpopularnija boja je plava (%.2f%%).",pr);
		return 1;
	}
	if(v>b && v>s && v>p && v>c) {
		pr=(float)v*100/u;
		printf("Najpopularnija boja je crvena (%.2f%%).",pr);
		return 1;	
		
	}
	if(s==c && s>b && s>p && s>v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(s>c && s==b && s>p && s>v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je bijela (%.2f%%).",pr);
		return 1;
	}
	if(s>c && s>b && s==p && s>v) {
		pr=(float)s*100/u;
		printf("Najpopularnija boja je siva (%.2f%%).",pr);
		return 1;
	}
	if(s>c && s>b && s>p && s==v) {
		pr=(float)s*100/u;
		printf("Najpopularnija boja je siva (%.2f%%).",pr);
		return 1;
	}

	if(b==c && b>s && b>p && b>v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(b>c && b>s && b==p && b>v) {
		pr=(float)b*100/u;
		printf("Najpopularnija boja je bijela (%.2f%%).",pr);
		return 1;
	}
	if(b>c && b>s && b>p && b==v) {
		pr=(float)b*100/u;
		printf("Najpopularnija boja je bijela (%.2f%%).",pr);
		return 1;
	}
	if(c>b && c>s && c==p && c>v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(c>b && c>s && c>p && c==v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(v>b && v>s && v==p && v>c) {
		pr=(float)v*100/u;
		printf("Najpopularnija boja je crvena (%.2f%%).",pr);
		return 1;	
		
	}
	if(b==c && b==s && b==p && b>v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(b==c && b==s && b>p && b==v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(b==c && b>s && b==p && b==v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(s>c && b==s && b==p && b==v) {
		pr=(float)b*100/u;
		printf("Najpopularnija boja je bijela (%.2f%%).",pr);
		return 1;
	}

	if(b==c && b==s && b==p && b==v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(b>c && b==s && b==p && b>v) {
		pr=(float)b*100/u;
		printf("Najpopularnija boja je bijela (%.2f%%).",pr);
		return 1;
	}
	if(b>c && b>s && b==p && b==v) {
		pr=(float)b*100/u;
		printf("Najpopularnija boja je bijela (%.2f%%).",pr);
		return 1;
	}
	if(b==c && b>s && b==p && b>v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}

	if(b==c && b>s && b>p && b==v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(b>c && b==s && b>p && b==v) {
		pr=(float)b*100/u;
		printf("Najpopularnija boja je bijela (%.2f%%).",pr);
		return 1;
	}
	if(b==c && b>s && b==s && b>v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	
	if(s>c && s>b && s==p && s==v) {
		pr=(float)s*100/u;
		printf("Najpopularnija boja je siva (%.2f%%).",pr);
		return 1;
	}
	if(s==c && s>b && s==p && s>v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(s==c && s>b && s>p && s==v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	if(c>s && c>b && c==v && p==v) {
		pr=(float)c*100/u;
		printf("Najpopularnija boja je crna (%.2f%%).",pr);
		return 1;
	}
	
	return 0;
	
}
