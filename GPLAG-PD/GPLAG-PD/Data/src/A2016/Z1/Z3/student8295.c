#include <stdio.h>

int main() {
	char f;
    double c,b,s,v,p,k;
    double c1,b1,s1,v1,p1;
    c=0;
    b=0;
    s=0;
    v=0;
    p=0;
    k=0;
    printf("Unesite vozila: ");
    do{
    	scanf("%c",&f);
    	if(f!='c' && f!='C' && f!='b' && f!='B' && f!='s' && f!='S' && f!='v' && f!='V' && f!='p' && f!='P' && f!='k' && f!='K'){
    printf("Neispravan unos\n"); }
    else {
    	if(f=='c' || f=='C' ){ c++;k++;}
    	else if(f=='b' || f=='B' ){ b++;k++;}
    	else if(f=='s' || f=='S' ){ s++;k++;}
    	else if(f=='v' || f=='V' ){ v++;k++;}
    	else if(f=='p' || f=='P' ){ p++;k++;}
    	}
        }
    	while(f!='k' && f!='K');
    	c1=(c/k)*100;
    	b1=(b/k)*100;
    	s1=(s/k)*100;
    	v1=(v/k)*100;
    	p1=(p/k)*100;
    	printf("Ukupno evidentirano %g vozila.\n",k);
    	if(k==0){
    		printf ("Najpopularnija boja je crna (0.00%%).");}
    		else if(c>=b && c>=s && c>=v & c>=p){
    		printf("Najpopularnija boja je crna (%.2f%%).",c1);}
    		else if(b>=c && b>=s && b>=v & b>=p){
    		printf("Najpopularnija boja je bijela (%.2f%%).",b1);}
    		else if(s>=c && s>=b && s>=v & s>=p){
    		printf("Najpopularnija boja je siva (%.2f%%).",s1);}
    		else if(v>=c && v>=b && v>=s & v>=p){
    		printf("Najpopularnija boja je crvena (%.2f%%).",v1);}
    		else if(p>=c && p>=b && p>=s & p>=v){
    		printf("Najpopularnija boja je plava (%.2f%%).",p1);}			
    				
    	return 0;}
