#include <stdio.h>

int main() {
	char a='O';
	int c=0,b=0,s=0,v=0,p=0,uk;
	float pc,pb,ps,pv,pp;
	printf("Unesite vozila: ");
	while(a!='K' && a!='k'){
		scanf("%c",&a);
		if(a!='c' && a!='C' && a!='B' && a!='b' && a!='S' && a!='s' && a!='V' && a!='v' && a!='K' && a!='P' && a!='p' && a!='k')
		printf("Neispravan unos\n");
		else if(a=='c' || a=='C')
		c=c+1;
		else if(a=='b' || a=='B')
		b=b+1;
		else if(a=='S' || a=='s')
		s=s+1;
		else if(a=='V' || a=='v')
		v=v+1;
		else if(a=='p' || a=='P')
		p=p+1;
	}
	uk=c+b+s+v+p;
	if(uk==0){
		printf("Ukupno evidentirano 0 vozila.");
      	printf("\nNajpopularnija boja je crna (0.00%%).");
	}
	else{
	pc=((float)c/uk)*100;
	pb=((float)b/uk)*100;
	ps=((float)s/uk)*100;
	pv=((float)v/uk)*100;
	pp=((float)p/uk)*100;
	printf("Ukupno evidentirano %d vozila.",uk);
	if(c>=b && c>=s && c>=v && c>=p)
	printf("\nNajpopularnija boja je crna (%.2f%%).",pc);
	else if(b>=s && b>=v && b>=p && b>c)
	printf("\nNajpopularnija boja je bijela (%.2f%%).",pb);
	else if(s>c && s>b && s>=v && s>=p)
	printf("\nNajpopularnija boja je siva (%.2f%%).",ps);
	else if(v>c && v>b && v>s && v>=p)
	printf("\nNajpopularnija boja je crvena (%.2f%%).",pv);
	else if(p>c && p>b && p>v && p>s)
	printf("\nNajpopularnija boja je plava (%.2f%%).",pp);
	}
	return 0;
}
