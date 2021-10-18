#include <stdio.h>

int main() {
	char ch;
	float post_c, post_b, post_s, post_v, post_p;
	float c=0, b=0, s=0, v=0, p=0;
	int ukupno=0;
	printf("Unesite vozila: ");
	do{
	    scanf("%c", &ch);
	    if(ch=='C' || ch=='c') c++;
	    else if(ch=='B' || ch=='b') b++;
	    else if(ch=='S' || ch=='s') s++;
	    else if(ch=='V' || ch=='v') v++;
	    else if(ch=='P' || ch=='p') p++;
	    else if(ch=='K' || ch=='k') break;
	    else printf("Neispravan unos\n");
	}
	while(1);
	
	ukupno=c+b+s+v+p;
	printf("Ukupno evidentirano %d vozila.", ukupno);
	if(ukupno == 0)
	    post_c = post_b = post_s = post_v = post_p = 0;
	else{
	post_c=(c/ukupno)*100;
	post_b=(b/ukupno)*100;
	post_s=(s/ukupno)*100;
	post_v=(v/ukupno)*100;
	post_p=(p/ukupno)*100;
	}
	
	if(c>=b && c>=s && c>=v && c>=p)
	    printf("\nNajpopularnija boja je crna (%.2f%%).", post_c);    
	else if(b>=c && b>=s && b>=v && b>=p)
        printf("\nNajpopularnija boja je bijela (%.2f%%).", post_b);
	else if(s>=c && s>=b && s>=v && s>=p)
	    printf("\nNajpopularnija boja je siva (%.2f%%).", post_s);
	else if(v>=c && v>=s && v>=b && v>=p)
	    printf("\nNajpopularnija boja je crvena (%.2f%%).", post_v);
	else if(p>=c && p>=s && p>=v && p>=b)
	    printf("\nNajpopularnija boja je plava (%.2f%%).", post_p);
	return 0;
}
