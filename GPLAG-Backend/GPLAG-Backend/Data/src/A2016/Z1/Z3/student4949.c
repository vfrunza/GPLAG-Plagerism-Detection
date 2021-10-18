#include <stdio.h>

int main() {
	char u;
	int i=0,c=0,b=0,s=0,v=0,p=0,max;
	float H;
	printf("Unesite vozila: ");
	do{
		scanf("%c",&u);
		
		if(u=='c' || u=='C' ) c++;
		if(u=='b' || u=='B' ) b++;
		if(u=='s' || u=='S' ) s++;
		if(u=='v' || u=='V' ) v++;
		if(u=='p' || u=='P' ) p++;
		if(u!='c' && u!='C' && u!='b' && u!='B' && u!='s' && u!='S' && u!='v' && u!='V'  && u!='p' && u!='P' && u!='K' && u!='k') printf("Neispravan unos\n");
	}while(u!='K' && u!='k');
	    i=c+b+s+v+p;
		
		 printf("Ukupno evidentirano %d vozila.",i);
	max=c;
	if(b>max) max=b ;
	if(s>max) max=s ;
	if(v>max) max=v ;
	if(p>max) max=p ;
	H=(100./i)*max;
	if(i==0.00) printf("\nNajpopularnija boja je crna (0.00%%).");
	else if(max==c) printf("\nNajpopularnija boja je crna (%.2f%%).",H);
	else if(max==b) printf("\nNajpopularnija boja je bijela (%.2f%%).",H);
	else if(max==s) printf("\nNajpopularnija boja je siva (%.2f%%).",H);
	else if(max==v) printf("\nNajpopularnija boja je crvena (%.2f%%).",H);
	else if(max==p) printf("\nNajpopularnija boja je plava (%.2f%%).",H);
	

	
	return 0;
}
