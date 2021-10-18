#include <stdio.h>
#include <math.h>
#define E 0.00001

int main() {
	char unos;
	int c=0,b=0,s=0,v=0,p=0,svi;
	float pc,pb,ps,pv,pp,max=0;
	printf("Unesite vozila: ");
	while((unos=getchar())!='K' && unos!='k') {

		if(unos=='c' || unos=='C')
		c++; 
		else if(unos=='b' || unos=='B')
		b++;
		else if(unos=='s' || unos=='S')
		s++;
		else if(unos=='v' || unos=='V')
		v++;
		else if(unos=='p' || unos=='P')
		p++;
	 else {
		printf("Neispravan unos\n");
	}
	}
	svi=c+b+s+v+p;
	printf("Ukupno evidentirano %d vozila.\n", svi);
	
	pc=(c/(float)svi)*100;
	pb=(b/(float)svi)*100;
	ps=(s/(float)svi)*100;
	pv=(v/(float)svi)*100;
	pp=(p/(float)svi)*100;
	
	if (svi==0) 
	{
	printf("Najpopularnija boja je crna (0.00%). ");
	}
	else {
		if(pc>max)
		max=pc;
		if(pb>max)
		max=pb;
		if(ps>max)
		max=ps;
		if(pv>max)
		pv=max;
		if(pp>max)
		max=pp;
	}
	if (fabs(max-pc)<E)
	printf("Najpopularnija boja je crna (%.2f%%).", pc);
	else if(fabs(max-pb)<E)
	printf("Najpopularnija boja je bijela (%.2f%%).", pb);
	else if(fabs(max-ps)<E)
	printf("Najpopularnija boja je siva (%.2f%%).", ps);
	else if(fabs(max-pv)<E)
	printf("Najpopularnija boja je crvena (%.2f%%).", pv);
	else if(fabs(max-pp)<E)
	printf("Najpopularnija boja je plava (%.2f%%).", pp);
	return 0;
}
















