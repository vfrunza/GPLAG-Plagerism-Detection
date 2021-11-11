#include <stdio.h>

int main() {
	int c,b,s,v,p;
	c=b=s=v=p=0;
	char x;
	printf("Unesite vozila: ");
	for(;;)
		{
			scanf("%c", &x);
			if(x=='C' || x=='c') c++;
				else if(x=='B' || x=='b') b++;
					else if(x=='S' || x=='s') s++;
						else if(x=='V' || x=='v') v++;
							else if(x=='P' || x=='p') p++;
								else if(x=='K' || x=='k') break;
									else	
										{
											printf("Neispravan unos\n");
											continue;
										}
			
		}
			int suma = c+b+s+v+p;
			int max =0;
			char m;
			if ( c>=b && c>=s && c>=v && c>=p) max=c, m='C';
			else if ( b>=c && b>=s && b>=v && b>=p) max=b, m='B';
			else if ( s>=c && s>=b && s>=v && s>=p) max=s, m='S';
			else if ( v>=b && v>=s && v>=c && v>=p) max=v, m='V';
			else if ( p>=b && p>=s && p>=v && p>=c) max=p, m='P';
	printf("Ukupno evidentirano %d vozila.\n", suma);
	double procenat;
	if(suma!=0) procenat = ((double)max/suma)*100;
	else procenat=0;
	if(m=='C') printf("Najpopularnija boja je crna (%.2f%%).", procenat);
	else if(m=='B') printf("Najpopularnija boja je bijela (%.2f%%).", procenat);
	else if(m=='S') printf("Najpopularnija boja je siva (%.2f%%).", procenat);
	else if(m=='V') printf("Najpopularnija boja je crvena (%.2f%%).", procenat);
	else if(m=='P') printf("Najpopularnija boja je plava (%.2f%%).", procenat);
	return 0;
}
