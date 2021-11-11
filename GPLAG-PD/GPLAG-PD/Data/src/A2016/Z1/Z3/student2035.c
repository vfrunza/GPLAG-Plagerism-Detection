#include <stdio.h>

int main() {
	int  j, b =0, c=0, s=0, v=0, p=0;
	char boja=0, prvaboja='a';
	double procenat;
	for( printf("Unesite vozila: "); ; ) {
		scanf("%c",&boja);
        if ( !(prvaboja=='c') && !(prvaboja=='C') && !(prvaboja=='b') && !(prvaboja=='B') && !(prvaboja=='s') && !(prvaboja=='S') && !(prvaboja=='V') && !(prvaboja=='v') && !(prvaboja=='p') && !(prvaboja=='P')) 
        {
        	prvaboja=boja;
        }
		if (boja=='B' || boja=='b')
		{
			b=b+1;
		}
		
		else if(boja=='C' || boja=='c') {
			c=c+1;
		}
		
		else if (boja=='S' || boja=='s') {
			s=s+1;
		}
		
		else if (boja=='V' || boja=='v') {
			v=v+1;
		}
		
		else if (boja=='P' || boja=='p') {
			p=p+1;
		}
		
		else if ( boja=='K' || boja=='k') {
			break;
		}
		
		else { printf("Neispravan unos\n"); continue; }
		
	}
	j=b+c+s+v+p;
	
 
	
	printf("Ukupno evidentirano %d vozila.", j);
	
	if (b>c && b>s && b>v && b>p) {
		procenat=(b*100./j);
		printf("\nNajpopularnija boja je bijela (%.2f%%).", procenat);
		
	}
	
	else if (c>b && c>s && c>v && c>p)  {
		procenat=(c*100./(b+c+v+s+p));
		printf("\nNajpopularnija boja je crna (%.2f%%).", procenat);
	}
	else if (s>b && s>c && s>v && s>p) {
		procenat=(s*100./j);
		printf("\nNajpopularnija boja je siva (%.2f%%).", procenat);
	}
	
    else if (v>b && v>c && c >s && v>p) {
    	procenat=(v*100./j);
    	printf("\nNajpopularnija boja je crvena (%.2f%%).", procenat);
    }
    else if (p>c && p>b && p>s && p>v) {
    	procenat=(p*100./j);
    	printf("\nNajpopularnija boja je plava (%.2f%%).", procenat);
    }
    else if ((prvaboja=='b' || prvaboja=='B') && b>=c && b>=s && b>=p && b>=v )
    {
    	procenat=b*100./j;
    	printf("\nNajpopularnija boja je bijela (%.2f%%).", procenat);
    }
    else if ((prvaboja=='c' || prvaboja=='C') && c>=b && c>=s && c>=p && c>=v)
    {
    	procenat=c*100./j;
    	printf("\nNajpopularnija boja je crna (%.2f%%).", procenat);
    }
    else if ((prvaboja=='s' || prvaboja=='S') && s>=b && s>=c && s>=v && s>=p)
    {
    	procenat=s*100./j;
    	printf("\nNajpopularnija boja je siva (%.2f%%).", procenat);
    }
    else if ((prvaboja=='v' || prvaboja=='V') && v>=b && v>=c && v>=p && v>=s)
    {
    	procenat=v*100./j;
    	printf("\nNajpopularnija boja je crvena (%.2f%%).", procenat);
    }
    else if ((prvaboja=='p' || prvaboja=='P') && p>=b && p>=c && p>=s && p>=v)
    {
    	procenat=p*100./j;
    	printf("\nNajpopularnija boja je plava (%.2f%%).", procenat);
    }
    
    else if (b==0 && c==0 && p==0 && v==0 && s==0) {
    	procenat=0;
    	printf("\nNajpopularnija boja je crna (%.2f%%).", procenat);
    }
    
    
    
	return 0;
}
