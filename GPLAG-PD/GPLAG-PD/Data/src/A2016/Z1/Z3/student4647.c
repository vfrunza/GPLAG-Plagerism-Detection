#include <stdio.h>


int main() {
	char vo;
	int brojac_c, brojac_b, brojac_s, brojac_v, brojac_p, z, brojac;
	float bc, bb, bs, bv, bp; 
	brojac_c=0;
	brojac_b=0; 
	brojac_s=0; 
	brojac_v=0;
	brojac_p=0;
	brojac=0;
	printf("Unesite vozila: ");
	do {
 	scanf("%c",&vo);
	if (vo==(char)'k' || vo==(char)'K') brojac--;
		else if (vo==(char)'c' || vo==(char)'C') brojac_c++;
		else if (vo==(char)'b' || vo==(char)'B') brojac_b++;
		else if (vo==(char)'s' || vo==(char)'S') brojac_s++;
		else if (vo==(char)'v' || vo==(char)'V') brojac_v++;
		else if (vo==(char)'p' || vo==(char)'P') brojac_p++;
		else printf("Neispravan unos\n");}
	while (vo!=(char)'k' && vo!=(char)'K');
	z=brojac_c+brojac_b+brojac_s+brojac_v+brojac_p;	
	printf("Ukupno evidentirano %d vozila.\n", z);
	if (z!=0){
	bc=((float)brojac_c*100)/(float)z;
	bb=((float)brojac_b*100)/(float)z;
	bs=((float)brojac_s*100)/(float)z;
	bv=((float)brojac_v*100)/(float)z;
	bp=((float)brojac_p*100)/(float)z;
		if (brojac_c>=brojac_b && brojac_c>=brojac_s && brojac_c>=brojac_v && brojac_c>=brojac_p) printf("Najpopularnija boja je crna (%.2f%%).",bc);
		else if (brojac_b>brojac_c && brojac_b>=brojac_s && brojac_b>=brojac_v && brojac_b>=brojac_p) printf("Najpopularnija boja je bijela (%.2f%%).",bb);
		else if (brojac_s>brojac_c && brojac_s>brojac_b && brojac_s>=brojac_v && brojac_s>=brojac_p) printf("Najpopularnija boja je siva (%.2f%%).",bs);
		else if (brojac_v>brojac_c && brojac_v>brojac_b && brojac_v>brojac_s && brojac_v>=brojac_p) printf("Najpopularnija boja je crvena (%.2f%%).",bv);
		else  printf("Najpopularnija boja je plava (%.2f%%).",bp);}
	if (z==0) printf("Najpopularnija boja je crna (0.00%%).");
	
	return 0;
}
