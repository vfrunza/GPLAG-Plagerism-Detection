#include <stdio.h>

int main() {
	int c=1,crvenih=0,crnih=0,bijelih=0,sivih=0,plavih=0;
	char k='0';
	printf("Unesite vozila: ");
	while(k!='k' || k!='K' )
	{
		scanf("%c",&k);
	    if(k=='k' || k=='K')break;
	    if(k=='C' || k=='c'){c++;crnih++;}
	    else if(k=='B' || k=='b'){c++;bijelih++;}
	    else if(k=='S' || k=='s'){c++;sivih++;}
	    else if(k=='V' || k=='v'){c++;crvenih++;}
	    else if(k=='P' || k=='p'){c++;plavih++;}
	    else printf("Neispravan unos\n");
	    
	}
	printf("Ukupno evidentirano %i vozila.\n", --c);if(c==0)c++;
	printf("Najpopularnija boja je ");
	if(crnih>=crvenih && crnih>=bijelih && crnih>=sivih &&crnih>=plavih)printf("crna (%.2f%%).",(double)crnih/(double)c*100);
	else if(bijelih>crnih && bijelih>=crvenih && bijelih>=sivih && bijelih>=plavih)printf("bijela (%.2f%%).",(double)bijelih/(double)c*100);
	else if(sivih>crnih && sivih>bijelih && sivih >= crvenih && sivih>=plavih)printf("siva (%.2f%%).",(double)sivih/(double)c*100);
	else if(crvenih>crnih && crvenih>bijelih && crvenih>sivih && crvenih>=plavih)printf("crvena (%.2f%%).",(double)crvenih/(double)c*100);
	else printf("plava (%.2f%%).",(double)plavih/(double)c*100);
	
	return 0;
}
