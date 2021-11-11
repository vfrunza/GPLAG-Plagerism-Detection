#include <stdio.h>
#include <math.h>
#define E 0.000000001
int main() {
	char a='u';
	double c=0,b=0,v=0,s=0,p=0,g=-1;
	printf("Unesite vozila: ");
	while(a!='k' && a!='K'){
		scanf("%c",&a);
		g++;
		if(a=='c' || a== 'C')c++;
		else if(a=='b'|| a=='B')b++;
		else if(a=='v'|| a=='V')v++;
		else if(a=='s'|| a=='S')s++;
		else if(a=='p'|| a=='P')p++;
		else if(a!='k' && a!='K')
		{g--;printf("Neispravan unos\n");}
	}
	printf("Ukupno evidentirano %.0f vozila.\n",g);
	if(fabs(g)<E)printf("Najpopularnija boja je crna (0.00%%).");
	else if(c>=b && c>=v && c>=s && c>=p)printf("Najpopularnija boja je crna (%.2f%%).",c/g*100);
	else if(b>=c && b>=v && b>=s && b>=p)printf("Najpopularnija boja je bijela (%.2f%%).",b/g*100);
	else if(s>=c && s>=v && s>=b && s>=p)printf("Najpopularnija boja je siva (%.2f%%).",s/g*100);
	else if(v>=c && v>=s && v>=b && v>=p)printf("Najpopularnija boja je crvena (%.2f%%).",v/g*100);
	else if(p>=c && p>=v && p>=s && p>=b)printf("Najpopularnija boja je plava (%.2f%%).",p/g*100);
	return 0;
}
