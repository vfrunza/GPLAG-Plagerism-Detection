#include <stdio.h>

int main() 
{
	int c=0, b=0, s=0, v=0, p=0, br_slova=0; 
	char slovo;
	float c1, b1, s1, v1, p1;
	
	printf ("Unesite vozila: ");
	
	do
	{
		scanf ("%c", &slovo);
		
		if (slovo=='c' || slovo=='C' ) c++;
		if (slovo=='b' || slovo=='B') b++;
		if (slovo=='s' || slovo=='S') s++;
		if (slovo=='v' || slovo=='V') v++;
		if (slovo=='p' || slovo=='P') p++;
		
        if (!((slovo=='c' || slovo=='C') || (slovo=='b' || slovo=='B') || (slovo=='s' || slovo=='S') || (slovo=='v' || slovo=='V') || (slovo=='p' || slovo=='P') || (slovo=='k' || slovo=='K'))) 
        {
        	printf ("Neispravan unos\n");
        	scanf ("%c", &slovo);
        	if (slovo=='k' || slovo=='K') break;
        }
	}while (slovo!='k' && slovo!='K');
	
	br_slova=c+b+s+v+p;
	
	 c1=((float)c/br_slova)*100;
	 b1=((float)b/br_slova)*100;
	 s1=((float)s/br_slova)*100;
	 v1=((float)v/br_slova)*100;
	 p1=((float)p/br_slova)*100;
	 
	
	printf ("Ukupno evidentirano %d vozila.\n", br_slova);
	
	if (c1>b1 || c1>s1 || c1>v1 || c1>p1) { printf ("Najpopularnija boja je crna (%.2f%%).\n", c1); return 0;}
	else if (b1>c1 || b1>s1 || b1>v1 || b1>p1) { printf ("Najpopularnija boja je bijela (%.2f%%).\n", b1); return 0; }
	else if (s1>c1 || s1>b1 || s1>v1 || s1>p1) { printf ("Najpopularnija boja je siva (%.2f%%).\n", s1); return 0;}
	else if (v1>c1 || v1>b1 || v1>s1 || v1>p1) { printf ("Najpopularnija boja je crvena (%.2f%%).\n", v1); return 0;}
	else if (p1>c1 || p1>b1 || p1>s1 || p1>v1) { printf ("Najpopularnija boja je plava (%.2f%%).\n", p1); return 0; }
	else if (!(slovo=='c' || slovo=='C') || (slovo=='b' || slovo=='B') || (slovo=='s' || slovo=='S') || (slovo=='v' || slovo=='V') || (slovo=='p' || slovo=='P')) { printf ("Najpopularnija boja je crna (0.00%%).\n"); return 0; }
	
	return 0;
}

