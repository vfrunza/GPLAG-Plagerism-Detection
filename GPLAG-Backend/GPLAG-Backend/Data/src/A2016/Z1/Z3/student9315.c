#include <stdio.h>
#include <math.h>


int main() {
	int c, b, s, v, p, suma, working;
	double procc, procb, procs, procv, procp;
	char slovo;
	c=0;
	b=0;
	s=0;
	v=0;
	p=0;
	procc =0;
	procb= 0;
	procs =0;
	procv =0;
	procp =0;
	suma =0;
	
	
	working =1;
	printf("Unesite vozila: ");
	while(working){
		scanf("%c", &slovo);
		if(slovo =='K' || slovo=='k')
		working =0;
		else if(slovo == 'C' || slovo == 'c')
		c++;
		else if(slovo == 'B' || slovo == 'b')
		b++;
		else if(slovo == 'S' || slovo == 's')
		s++;
		else if(slovo == 'V' || slovo == 'v')
		v++;
		else if(slovo == 'P' || slovo == 'p')
		p++;
		else
		printf("Neispravan unos\n");
	}
	
	suma = c+b+s+v+p;

	
	printf("Ukupno evidentirano %d vozila.\n", suma);
	
	if(suma == 0)
	suma = 1;
	
	procc = floor((int)((((double)c/suma)*100*100)+0.5)) /100;
	procb = floor((int)((((double)b/suma)*100*100)+0.5)) /100;
	procs = floor((int)((((double)s/suma)*100*100)+0.5)) /100;
	procv = floor((int)((((double)v/suma)*100*100)+0.5)) /100;
	procp = floor((int)((((double)p/suma)*100*100)+0.5)) /100;
	
	if(c >=b && c>=s && c>=v && c>=p)
	printf("Najpopularnija boja je crna (%.2f%%).",procc);
	else if(b>=c && b>=s && b>=v && b>=p)
	printf("Najpopularnija boja je bijela (%.2f%%).",procb);
	else if(s>= c && s>=b && s>= v && s>=p)
	printf("Najpopularnija boja je siva (%.2f%%).",procs);
	else if(v>= c && v>= b && v>= s && v>=p)
	printf("Najpopularnija boja je crvena (%.2f%%).",procv);
	else
	printf("Najpopularnija boja je plava (%.2f%%).",procp);
	
	return 0;
}
