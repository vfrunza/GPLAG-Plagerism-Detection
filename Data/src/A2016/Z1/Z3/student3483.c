#include <stdio.h>

int main() {
	char br;
	float bv, c, b, s, v, p, cp, bp, sp, vp, pp;
	bv=0;
	c=0;
	b=0;
	s=0;
	v=0;
	p=0;
	printf("Unesite vozila: ");
	do{
		scanf("%c", &br);
		switch(br){
			case 'c':
			case 'C':
				bv+=1;
				c+=1;
				break;
			case 'b':
			case 'B':
				bv+=1;
				b+=1;
				break;
			case 's':
			case 'S':
				bv+=1;
				s+=1;
				break;
			case 'v':
			case 'V':
				bv+=1;
				v+=1;
				break;
			case 'p':
			case 'P':
				bv+=1;
				p+=1;
				break;
			case 'k':
			case 'K':
				break;
			default:
				printf("Neispravan unos \n");
		}
	}
	while(br!='K' && br!='k');
	if(bv!=0){
		cp=c/bv*100;
		bp=b/bv*100;
		sp=s/bv*100;
		vp=v/bv*100;
		pp=p/bv*100;
	}
	else{
		cp=0;
		bp=0;
		sp=0;
		vp=0;
		pp=0;
	}
	
	printf("Ukupno evidentirano %g vozila. \n", bv);
	if(c>=b && c>=s && c>=v && c>=p)
		printf("Najpopularnija boja je crna (%.2f%%).", cp);
	if(b>c && b>=s && b>=v && b>=p)
		printf("Najpopularnija boja je bijela (%.2f%%).", bp);
	if(s>c && s>b && s>=v && s>=p)
		printf("Najpopularnija boja je siva (%.2f%%).", sp);
	if(v>c && v>b && v>s && v>=p)
		printf("Najpopularnija boja je crvena (%.2f%%).", vp);
	if(p>c && p>b && p>s && p>v)
		printf("Najpopularnija boja je plava (%.2f%%).", pp);
	return 0;
}
