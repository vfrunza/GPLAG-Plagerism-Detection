#include <stdio.h>

int main() {
	int brc=0,brb=0,brs=0,brv=0,brp=0,br=0;
	float y;
    char x;

printf("Unesite vozila: ");
do
{   scanf("%c",&x);  
	if(x=='k' || x=='K') break;
	
	else if(x=='C' || x=='c') { br++;  brc++;}
	else if(x=='B' || x=='b') { br++;  brb++; }
	else if(x=='S' || x=='s') { br++;  brs++; }
	else if(x=='V' || x=='v') { br++; brv++; }
	else if(x=='P' || x=='p') { br++; brp++; }

	else if(x!='C' && x!='c' && x!='B' && x!='b'&& x!='S' && x!='s' && x!='V' && x!='v' && x!='P' && x!='p' && x!='K' && x!='k')
	{ printf("Neispravan unos\n"); }

} 
while(x!='k');

printf("Ukupno evidentirano %d vozila.\n",br);
if(br!=0)
{
	if(brc>=brs && brc>=brv && brc>=brp && brc>=brb)
	{ 	y=(float)brc*100/br;
		printf("Najpopularnija boja je crna (%.2f%%).",y); }
else if(brb>=brc && brb>=brs && brb>=brv && brb>=brp)
	{ 	y=(float)brb*100/br;
		printf("Najpopularnija boja je bijela (%.2f%%).",y); }
else if(brs>=brc && brs>=brv && brs>=brb && brs>=brp)
	{	y=(float)brs*100/br;
		printf("Najpopularnija boja je siva (%.2f%%).",y);  }
else if(brv>=brc && brv>=brb && brv>=brs && brv>=brp)
	{ 	y=(float)brv*100/br;
		printf("Najpopularnija boja je crvena (%.2f%%).",y); }
else if(brp>=brc && brp>=brb && br>=brs && brp>=brv)
	{	y=(float)brp*100/br;
		printf("Najpopularnija boja je plava (%.2f%%).",y);}
}
else printf("Najpopularnija boja je crna (0.00%).");

	return 0;
}

