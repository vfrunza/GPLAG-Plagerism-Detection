#include <stdio.h>

int main() {
	int  brojauta=0, brcrnih=0,brcrvenih=0, brplavih=0,brbijelih=0,brsivih=0, maksi=0;
	float postotak=0;
	char slovo, najboja;
		printf("Unesite vozila: ");
		
	for (;;) 
	{	
		scanf("%c",&slovo);
		if(slovo>='a' && slovo<='z') slovo-=('a'-'A'); 
		switch (slovo)
		{
			case 'C' : brcrnih++; brojauta++; if(brcrnih>maksi){maksi=brcrnih; najboja='C';}break;
			case 'B' : brbijelih++; brojauta++; if(brbijelih>maksi){ maksi=brbijelih; najboja='B';}break;
			case 'S' : brojauta++; brsivih++; if(brsivih>maksi){ maksi=brsivih; najboja='S';}break;
			case 'V' : brojauta++; brcrvenih++; if(brcrvenih>maksi){ maksi=brcrvenih; najboja='V';}break;
			case 'P' : brojauta++; brplavih++; if(brplavih>maksi){ maksi=brplavih; najboja='P';}break;
			case 'K' : break;
			default : printf ("Neispravan unos\n"); break;
		}
		if(slovo == 'K')break;
		
	}
	
	if(brcrnih==maksi) najboja='C';
	else if(brbijelih==maksi) najboja='B';
	else if(brsivih==maksi) najboja='S';
	else if(brcrvenih==maksi) najboja='V';
	else if(brplavih==maksi) najboja='P';
	if(brojauta==0) postotak = 0;
	else {postotak =(maksi*1.0/brojauta*100);}
	printf("Ukupno evidentirano %d vozila.\n",brojauta);
	if(najboja=='C') printf("Najpopularnija boja je crna (%.2f%%).\n",postotak);
	if(najboja=='B') printf("Najpopularnija boja je bijela (%.2f%%).\n",postotak);
	if(najboja=='S') printf("Najpopularnija boja je siva (%.2f%%).\n",postotak);
	if(najboja=='V') printf("Najpopularnija boja je crvena (%.2f%%).\n",postotak);
	if(najboja=='P') printf("Najpopularnija boja je plava (%.2f%%).\n",postotak);
	
	return 0;
}
