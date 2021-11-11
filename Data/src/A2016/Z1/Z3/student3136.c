#include <stdio.h>

int main() {
	int a=0,b=0,c=0,d=0,e=0,f=0,i;
	char m,n;
	float post;
	printf ("Unesite vozila: ");
	for(i=0;i>=0;i++)
	{
		scanf(" %c",&m);
		n=m;
		if(n=='c'||n=='C'){a++;b++;}
		else if(n=='b'||n=='B') {c++;a++;}
		else if(n=='s'||n=='S'){d++;a++;}
		else if(n=='v'||n=='V'){a++;e++;}
		else if(n=='p'||n=='P') {f++;a++;}
		else if (n=='K'|| n=='k')
		{break;a++;}
		else printf("Neispravan unos\n");
	}
	printf ("Ukupno evidentirano %d vozila. \n", a);
	if (a==0) printf("Najpopularnija boja je crna (0.00%).");
	else if( (c<b || d<b || e<b || f<b) && ( b==c || b==d || b==e || b==f)) { float b1=b ; post=b1/a ; printf("Najpopularnija boja je crna (%.2f%).",post*100) ; return 0 ; }
	else if((b<c || d<c || e<c || f<c) && (c==d || c==e || c==f)){float b2=c; post=b2/a ; printf("Najpopularnija boja je bijela (%.2f%).",post*100) ; return 0 ;}
	else if((c<d || b<d || e<d || f<d)&& (d==e || d==f )){ float b3=d ; post=b3/a ; printf("Najpopularnija boja je siva (%.2f%).",post*100) ; return 0 ; }
	else if((c<e || d<e || b<e || f<e)&& (e==f)) {float b4=e ; post=b4/a ; printf("Najpopuja boja je crvena (%.2f%).",post*100) ; return 0 ; }
	else if((c<f || d<f || e<f || b<f)) { float b5=f ; post=b5/a ; printf("Najpopularnija boja je plava (%.2f%).",post*100) ; return 0 ; }
	return 0;
}
