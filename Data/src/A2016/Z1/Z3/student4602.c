#include <stdio.h>

int main() {
	char a,max_slovo='c';
	int bc=0, bb=0, bs=0, bv=0, bp=0, max=0; 
	float b=0,xc, xb, xv, xs, xp;
	printf("Unesite vozila: ");
	while(2==2){ 
	    scanf("%c", &a);
	    if(a<97) a+=32; 
	    if(a=='k') break;
	if(a=='c'){
	    b++;bc++;if(bc>max) {max=bc;max_slovo='c';}continue; 
	}
	else if(a=='b'){
	    b++;bb++;if(bb>max) {max=bb;max_slovo='b';}continue;
	}
	else if(a=='s'){
	    b++;bs++;if(bs>max) {max=bs;max_slovo='s';}continue;
	}
	else if(a=='v'){
	    b++;bv++;if(bv>max) {max=bv;max_slovo='v';}continue;
	}
	else if(a=='p'){
	    b++;bp++;if(bp>max) {max=bp;max_slovo='p';}continue;
	}
	if(a!='c' && a!='p' && a!='v' && a!='b' && a!='s') printf("Neispravan unos\n");
	}
	printf("Ukupno evidentirano %.0f vozila.\n", b);
	if(b==0) printf("Najpopularnija boja je crna (0.00%%)."); 
	else if(max_slovo=='c'){
		xc=(bc*100)/b;
	    printf("Najpopularnija boja je crna (%.2f%%).", xc);
	   
	}
	else if(max_slovo=='s'){
		xs=(bs*100)/b;
	    printf("Najpopularnija boja je siva (%.2f%%).", xs);
	}
	else if(max_slovo=='b'){
		xb=(bb*100)/b;
	    printf("Najpopularnija boja je bijela (%.2f%%).", xb);
	}
	else if(max_slovo=='v'){
		xv=(bv*100)/b;
	    printf("Najpopularnija boja je crvena (%.2f%%).", xv);
	}
	else if(max_slovo=='p'){
		xp=(bp*100)/b;
	    printf("Najpopularnija boja je plava (%.2f%%).", xp);
	}


	return 0;
}
