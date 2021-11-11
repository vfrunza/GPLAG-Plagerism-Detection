#include <stdio.h>

int main() {
	char f;
	double c,b,s,v,p,k;
	double a,d,e,h,g;
	c=0;
	b=0;
	s=0;
	v=0;
	p=0;
	k=0;
	printf("Unesite vozila: ");
	do {
		scanf("%c",&f);
		if(f!='c' && f!='C' && f!='b' && f!='B' && f!='s' && f!='S' && f!='v' && f!='V' && f!='p' && f!='P' && f!='k' && f!='K'){
	      printf("Neispravan unos\n");}
	    else {
	    if(f=='c' || f=='C'){c++;k++;}
	    else if(f=='b' || f=='B'){b++;k++;}
	    else if(f=='s' || f=='S'){s++;k++;}
	    else if(f=='v' || f=='V'){v++;k++;}
	    else if(f=='p' || f=='P'){p++;k++;}}}
	    while(f!='k' && f!='K');
	    a=(c/k)*100;
	    d=(b/k)*100;
	    e=(s/k)*100;
	    h=(v/k)*100;
	    g=(p/k)*100;
	    printf("Ukupno evidentirano %g vozila.\n",k);
	    if(k==0) {
	    	printf("\nNajpopularnija boja je crna (0.00%%)." );}
	    
	    else if(c>=b && c>=s && c>=v && c>=p) {
	    	printf("\nNajpopularnija boja je crna (%.2f%%).",a);}
	    else if(b>=c && b>=s && b>=v && b>=p) {
	    	printf("\nNajpopularnija boja je bijela (%.2f%%).",d);}
	    else if(s>=b && s>=c && s>=v && s>=p) {
	    	printf("\nNajpopularnija boja je siva (%.2f%%).",e);}
	    else if(v>=b && v>=c && v>=s && v>=p) {
	    	printf("\nNajpopularnija boja je crvena (%.2f%%).",h);}
	    else if(p>=b && p>=s && p>=v && p>=c) {
	        printf("\nNajpopularnija boja je plava (%.2f%%).",g);}
	        
	        return 0;
}
	    
	    
	    
	
	
