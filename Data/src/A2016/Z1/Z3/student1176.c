#include <stdio.h>

int main() 
{
	char c;
	int brc=0, brb=0, brs=0, brv=0, brp=0;
	float suma=0; 
	float pc, pb, ps, pv, pp; 
	printf("Unesite vozila: "); 
	scanf("%c", &c);
	while(c!='k' || c!='K'){ 
	     if(c=='c' || c=='C') brc++;
	     else if(c=='b' || c=='B') brb++;
	     else if(c=='s' || c=='S') brs++;
	     else if(c=='v' || c=='V') brv++;
	     else if(c=='p' || c=='P') brp++;  
	     else if(c=='k' || c=='K') break;
	     else printf("Neispravan unos\n");
	     scanf("%c", &c);
	     while(c=='\n') scanf("%c", &c); 
	}
	suma=brc+brb+brs+brv+brp;
	if(suma==0) printf("Ukupno evidentirano 0 vozila. \nNajpopularnija boja je crna (0.00%%)."); 
	else{
	printf("Ukupno evidentirano %.f vozila.", suma); 
	if(brc>=brp && brc>=brb && brc>=brv && brc>=brs){ 
		pc=((float)brc/suma)*100;
		printf("\nNajpopularnija boja je crna (%.2f%%).", pc);
	} 
	else if(brb>=brc && brb>=brs && brb>=brv && brb>=brp){
		pb=((float)brb/suma)*100;
		printf("\nNajpopularnija boja je bijela (%.2f%%).", pb);
	} 
	else if(brs>=brc && brs>=brb && brs>=brv && brs>=brp){
		ps=((float)brs/suma)*100;
		printf("\nNajpopularnija boja je siva (%.2f%%).", ps);
	} 
	else if(brv>=brc && brv>=brb && brv>=brp && brv>=brs){
		pv=((float)brv/suma)*100;
		printf("\nNajpopularnija boja je crvena (%.2f%%).", pv);
	} 
	else if(brp>=brc && brp>=brs && brp>=brb && brp>=brv){
		pp=((float)brp/suma)*100;
		printf("\nNajpopularnija boja je plava (%.2f%%).", pp);
	} 
	}
	return 0;
}
