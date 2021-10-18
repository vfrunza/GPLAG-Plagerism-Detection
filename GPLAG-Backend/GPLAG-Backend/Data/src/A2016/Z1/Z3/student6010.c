#include <stdio.h>

int main() {
	int r;
    int	h=0;
	char boja, a1='C', a2='c', b1='b', b2='B', c1='s', c2='S', d1='v', d2='V', e1='p', e2='P';
	double p1, p2, p3, p4, p5, a=0, b=0, c=0, d=0, e=0, f=0;
	printf("Unesite vozila: ");
	for( ; ; ) {
		scanf("%c", &boja);
		if(boja=='K' || boja=='k') {
			break;
			}
			if(boja!=a1 && boja!=a2 && boja!=b1 && boja!=b2 && boja!=c1 && boja!=c2 && boja!=d1 && boja!=d2 && boja!=e1 && boja!=e2){
			printf("Neispravan unos\n"); 
			}
		if(boja==a1 || boja==a2 || boja==b1 || boja==b2 || boja==c1 || boja==c2 || boja==d1 || boja==d2 || boja==e1 || boja==e2) {h++;}
	
		if(boja==a1 || boja==a2) {a=a+1;}
		if(boja==b1 || boja==b2) {b=b+1;}
		if(boja==c1 || boja==c2) {c=c+1;}
		if(boja==d1 || boja==d2) {d=d+1;}
		if(boja==e1 || boja==e2) {e=e+1;}
		
	
		}
		p1=(a/h)*100;
        p2=(b/h)*100;
        p3=(c/h)*100;
        p4=(d/h)*100;
        p5=(e/h)*100;
if(h==0) {
	printf("Ukupno evidentirano 0 vozila.\n");
	 printf("Najpopularnija boja je crna (0.00%%).");
}
if(h>0) {
	 printf("Ukupno evidentirano %d vozila.", h);

	 	 
if(p1>=p2 && p1>=p3 && p1>=p4 && p1>=p5) {
	printf("\nNajpopularnija boja je crna (%.2f%%).", p1);
} else if(p2>p1 && p2>=p3 && p2>=p4 && p2>p5) {
	printf("\nNajpopularnija boja je bijela (%.2f%%).", p2);
} else if(p3>p1 && p3>p2 && p3>=p4 && p3>=p5) {
	printf("\nNajpopularnija boja je siva (%.2f%%).", p3);
} else if(p4>p1 && p4>p2 && p4>p3 && p4>=p5) {
	printf("\nNajpopularnija boja je crvena (%.2f%%).", p4);
} else if(p5>p1 && p5>p2 && p5>p3 && p5>p4) {
	printf("\nNajpopularnija boja je plava (%.2f%%).", p5);
}		
}
		
return 0;
}
