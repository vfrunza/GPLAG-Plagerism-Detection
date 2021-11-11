#include <stdio.h>

int main() {
	int c=0,b=0,s=0,p=0,v=0,boja=0;
	char a='a';
	float procenat;
	printf("Unesite vozila: ");
	do
	{
		scanf("%c", &a);
		if(a=='c' || a=='C')
		c++;
	    else if (a=='b' || a=='B')
	    b++;
	    else if(a=='s' | a=='S')
	    s++;
	    else if(a=='p' || a=='P')
	    p++;
	    else if(a=='v' || a=='V')
	    v++;
	    else if(a=='k' || a=='K')
	    break;
	    else printf("Neispravan unos\n");
	}
	while(1);
	boja=c+b+p+s+v;
	printf("Ukupno evidentirano %d vozila.\n", boja);

	

	if(c>=b && c>=p && c>=v && c>=s)
	{
	procenat=(c*100)/(float)boja;
	if(boja==0)
	procenat=0.;
	printf("Najpopularnija boja je crna (%.2f%%).", procenat);
    return 0;
	}
	else

	if(b>=c && b>=p && b>=v && b>=s)
	{
	procenat=(b*100)/(float)boja;
		if(boja==0)
	procenat=0.;
	printf("Najpopularnija boja je bijela (%.2f%%).", procenat);
	return 0;
	}
	
	else

	if(s>=c && s>=b && s>=p && s>=v)
	{
	procenat=(s*100)/(float)boja;
		if(boja==0)
	procenat=0.;
	printf("Najpopularnija boja je siva (%.2f%%).", procenat);
    return 0;
	}
	
	else
	
	if(v>=c && v>=b && v>=p && v>=s)
	{
	procenat=(v*100)/(float)boja;
		if(boja==0)
	procenat=0.;
	printf("Najpopularnija boja je crvena (%.2f%%).", procenat);
	return 0;
	}
	else
	
	if(p>=c && p>=b && p>=v && p>=s)
	{
	procenat=(p*100)/(float)boja;
		if(boja==0)
	procenat=0.;
    printf("Najpopularnija boja je plava (%.2f%%).", procenat);
    return 0;
    }

return 0;
}
