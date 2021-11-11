#include <stdio.h>

int main() {
	/* Crna, Bijela, Siva, crVena, Plava, Kraj */
	char inp;
	double cp, bp, sp, vp, pp, c=0, v=0, b=0, s=0, p=0, k=0, ev=0;
	
	
	printf("Unesite vozila: ");
	while (k==0) {

		scanf("%c", &inp);
		
		/* Skeniranje inputa */
		if ((inp == 'c')||(inp == 'C')) {
			c++;
		} else if ((inp == 'v')||(inp == 'V')) {
			v++;
		} else if ((inp == 'b')||(inp == 'B')) {
			b++;
		} else if ((inp == 's')||(inp == 'S')) {
			s++;
		} else if ((inp == 'p')||(inp == 'P')) {
			p++;
		} else if ((inp == 'k')||(inp == 'K')) {
			k=1;
		} else printf("Neispravan unos\n");
	}
	
	ev=c+v+b+s+p;
	printf("Ukupno evidentirano %g vozila.\n", ev);
	
	
	/* Konverzija u postotke */
	cp = (c/ev) * 100;
	bp = (b/ev) * 100;
	sp = (s/ev) * 100;
	vp = (v/ev) * 100;
	pp = (p/ev) * 100;
	
	/* Provjera uslova */
	if ((cp>=bp)&&(cp>=sp)&&(cp>=vp)&&(cp>=pp)) {
		if ((cp==bp)||(cp==sp)||(cp==vp)||(cp==pp)) {
			printf("Najpopularnija boja je crna (%.2lf%%).", cp);
		}
		else printf("Najpopularnija boja je crna (%.2lf%%).", cp);
	} else if ((bp>=cp)&&(bp>=sp)&&(bp>=vp)&&(bp>=pp)) {
		if ((bp==cp)||(bp==sp)||(bp==vp)||(bp==pp)) {
			printf("Najpopularnija boja je bijela (%.2lf%%).", bp);
		}
		else printf("Najpopularnija boja je bijela (%.2lf%%).", bp);
	} else if ((sp>=bp)&&(sp>=cp)&&(sp>=vp)&&(sp>=pp)) {
		if ((sp==bp)||(sp==cp)||(sp==vp)||(sp==pp)) {
			printf("Najpopularnija boja je siva (%.2lf%%).", sp);
		}
		else printf("Najpopularnija boja je siva (%.2lf%%).", sp);
	} else if ((vp>=bp)&&(vp>=sp)&&(vp>=cp)&&(vp>=pp)) {
		if ((vp==bp)||(vp==sp)||(vp==cp)||(vp==pp)) {
			printf("Najpopularnija boja je crvena (%.2lf%%).", vp);
		}
		else printf("Najpopularnija boja je crvena (%.2lf%%).", vp);
	} else if ((pp>=bp)&&(pp>=sp)&&(pp>=cp)&&(pp>=vp)) {
		if ((pp==bp)||(pp==sp)||(pp==cp)||(pp==vp)) {
			printf("Najpopularnija boja je plava (%.2lf%%).", pp);
		}
		else printf("Najpopularnija boja je plava (%.2lf%%).", pp);
	} else printf("Najpopularnija boja je crna (0.00%).");
	
	return 0;
}