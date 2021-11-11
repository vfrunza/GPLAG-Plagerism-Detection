#include <stdio.h>

int main() {
	int cb=0, sb=0, pb=0, bb=0, vb=0, M;
	char X;
	double procenat, zbir;
	printf ("Unesite vozila: ");
	do {
		scanf ("%c", &X);
		
		if ((X=='B') || (X=='b') || (X=='P') || (X=='p') || (X=='C') || (X=='c') || (X=='S') || (X=='s') || (X=='V') || (X=='v') || (X=='K') || (X=='k')) {
			if (X=='C' || X=='c') {
				(cb=cb+1);
			}
			else if (X=='P' || X=='p') {
				(pb=pb+1);
			}
			else if (X=='B' || X=='b') {
				(bb=bb+1);
			}
			else if (X=='S' || X=='s') {
				(sb=sb+1);
			}
			else if (X=='V' || X=='v') {
				(vb=vb+1);
		    }
		    }
		    else if (X!='V' && X!='v' && X!='C' && X!='c' && X!='S' && X!='s' && X!='B' && X!='b' && X!='P' && X!='p' && X!='K' && X!='k') {
			printf ("Neispravan unos\n");
		}
	}
		while (X!='K' && X!='k'); 
		
		zbir=cb+pb+sb+bb+vb;
		M=cb;
		if (bb>M) {
			M=bb;
		}
		if (vb>M) {
			M=vb;
		}
		if (sb>M){
			M=sb;
		}
		if (pb>M){
			M=pb;
		}
		
		procenat=M*100/zbir;
		
		if (zbir==0) {
			printf ("Ukupno evidentirano 0 vozila.\n");
			printf ("Najpopularnija boja je crna (0.00%).");
		}
		else { 
			printf ("Ukupno evidentirano %g vozila.\n", zbir );
			
		}
		if (cb==M && cb!=0) {
			printf ("Najpopularnija boja je crna (%.2lf%%). \n", procenat );
		}
		else if (bb==M && bb!=0) {
			printf ("Najpopularnija boja je bijela (%.2lf%%). \n", procenat );
		}
		else if (sb==M && sb!=0) {
			printf ("Najpopularnija boja je siva (%.2lf%%). \n", procenat );
		}
		else if (pb==M && pb!=0) {
			printf ("Najpopularnija boja je plava (%.2lf%%). \n", procenat );
		}
		else if (vb==M && vb!=0) {
			printf ("Najpopularnija boja je crvena (%.2lf%%). \n", procenat );
		}
       
       return 0;
}
