#include <stdio.h>
#include <math.h>


int main() {
	int c, b, s, v, p, suma=0;
	float cc, bb, ss, vv, pp;
	char boja;	 
	c=0; b=0; s=0; v=0; p=0;
	printf("Unesite vozila: ");
while(1){
	
	scanf("%c", &boja);
	if(boja=='k' || boja=='K'){
		break;
	}
	else if(boja!='b' && boja!='B' && boja!='p' && boja!='P' && boja!='V' && boja!='v' && boja!='s' && boja!='S' && boja!='c' && boja!='C'){
		printf("Neispravan unos\n");
	}
	
	else if(boja=='C' || boja=='c'){
	c++; 
	}
	else if(boja=='B' || boja=='b'){
		b++; 
	}
	else if(boja=='S' || boja=='s'){
		s++;
	}
	else if(boja=='V' || boja=='v'){
		v++;
	}
	else if(boja=='P' || boja=='p'){
		p++;
	}
}
	
	suma=c+b+v+s+p;
	printf("Ukupno evidentirano %d vozila.", suma);
	
	cc=(float)(c*100)/suma;
	bb=(float)(b*100)/suma;
	ss=(float)(s*100)/suma;
	vv=(float)(v*100)/suma;
	pp=(float)(p*100)/suma;
	if(suma==0){
		printf("\nNajpopularnija boja je crna (0.00%%).\n", c);
	}
	else if((c>=s) && (c>=b) && (c>=v) && (c>=p)){
		printf("\nNajpopularnija boja je crna (%.2f%%).\n", cc);
	}
	else if((b>=c) && (b>=s) && (b>=v) && (b>=p)){
		printf("\nNajpopularnija boja je bijela (%.2f%%).\n", bb);
	}
	else if((s>=c) && (s>=b) && (s>=v) && (s>=p)){
		printf("\nNajpopularnija boja je siva (%.2f%%).\n", ss);
	}
	else if((v>=c) && (v>=b) && (v>=s) && (v>=p)){
		printf("\nNajpopularnija boja je crvena (%.2f%%).\n", vv);
	}
	else if((p>=c) && (p>=b) && (p>=s) && (p>=v)){
		printf("\nNajpopularnija boja je plava (%.2f%%).\n", pp);
	}
	
	

	return 0;
}
