#include <stdio.h>
#include <string.h>

int main() {
	float cr, bi, si, cv, pl, i, c, b, s, v, p;
	char x;
	cr=0;
	bi=0;
	si=0;
	cv=0;
	pl=0;
	printf("Unesite vozila: ");
	i=0;
	do {
		scanf("%c", &x);
		if ((x!='0' && x!='1') && (x!=' ') && (x!=',') && (x=='c' || x=='C' || x=='b' || x=='B' || x=='s' || x=='S' || x=='v' || x=='V' || x=='p' || x=='p' || x=='P' || x=='k' || x=='K')){
		i++;}
		if (x!='k' && x!='K' && x!='c' && x!='C' && x!='b' && x!='B' && x!='s' && x!='S' && x!='v' && x!='V' && x!='p' && x!='P')
		printf("Neispravan unos\n");
        if((x=='c') || (x=='C'))
	    cr=cr+1;
	    if((x=='b') || (x=='B'))
	    bi=bi+1;
	    if((x=='s') || (x=='S'))
	    si=si+1;
	    if((x=='v') || (x=='V'))
	    cv=cv+1;
	    if((x=='p') || (x=='P'))
	    pl=pl+1;
	}
	while(x!='k' && x!='K');
	if (i-1!=0) {
	c=cr/(i-1)*100;
	b=bi/(i-1)*100;
	s=si/(i-1)*100;
	v=cv/(i-1)*100;
	p=pl/(i-1)*100;
	}
	else {
		c=0;
		b=0;
		s=0;
		v=0;
		p=0;
	}
    printf("Ukupno evidentirano %1.f vozila.\n", i-1);
	if (cr>=bi && cr>=si && cr>=cv && cr>=pl)
	printf("Najpopularnija boja je crna (%3.2f%%).", c);
	if(bi>cr && bi>=si && bi>=cv && bi>=pl)
	printf("Najpopularnija boja je bijela (%3.2f%%).", b);
	if(si>cr && si>bi && si>=cv && si>=pl)
	printf("Najpopularnija boja je siva (%3.2f%%).", s);
	if(cv>cr && cv>bi && cv>si && cv>=pl)
	printf("Najpopularnija boja je crvena (%3.2f%%).", v);
	if(pl>cr && pl>bi && pl>si && pl>cv)
	printf("Najpopularnija boja je plava (%3.2f%%).", p);
	return 0;
}
