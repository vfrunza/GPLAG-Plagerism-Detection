#include <stdio.h>

int main() {
	char boja;
	int c=0, b=0, s=0, v=0, p=0, br=0, max=0;
	float x, br1;
	boja='W';
	printf("Unesite vozila: ");
	while(boja!='k' && boja!='K'){
		scanf("%c", &boja);
		if(boja!='c' && boja!='b' && boja!='s' && boja!='v' && boja!='p' && boja!='C' && boja!='B' && boja!='S' && boja!='V' && boja!='P' && boja!='\n' && boja!='k' && boja!='K') printf("Neispravan unos\n");
		else{
		if(boja=='\n') continue;
	    if(boja=='c' || boja=='C') c++;
		 else if(boja=='b' || boja=='B') b++;
		  else if(boja=='s' || boja=='S') s++;
	       else if(boja=='v' || boja=='V') v++;
		    else if(boja=='p' || boja=='P') p++;
		if (boja!='k' && boja!='K') br++;
		}
	}
	if(c>=b && c>=s && c>=v && c>=p) {max=c;}
	 else if(b>c && b>=s && b>=v && b>=p) {max=b;}
	  else if(s>c && s>b && s>=v && s>=p) {max=s;}
	   else if(v>c && v>b && v>s && v>=p) {max=v;}
	    else if(p>c && p>b && p>s && p>v) {max=p;}
	x=(((float)max)/br)*100;
	printf("Ukupno evidentirano %d vozila.", br);
	br1=0.0;
	if(br==0) printf("\nNajpopularnija boja je crna (%.2f%%).", br1);
	else{
	if(c>=b && c>=s && c>=v && c>=p) printf("\nNajpopularnija boja je crna (%.2f%%).", x);
	 else if(b>c && b>=s && b>=v && b>=p) printf("\nNajpopularnija boja je bijela (%.2f%%).", x);
	  else if(s>c && s>b && s>=v && s>=p) printf("\nNajpopularnija boja je siva (%.2f%%).", x);
	   else if(v>c && v>b && v>s && v>=p) printf("\nNajpopularnija boja je crvena (%.2f%%).", x);
	    else if(p>c && p>b && p>s && p>v) printf("\nNajpopularnija boja je plava (%.2f%%).", x);
	}
	return 0;
}
