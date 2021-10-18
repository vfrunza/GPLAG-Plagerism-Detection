#include <stdio.h>
#include <string.h>
int main() {
	char c;
	int bv=-1,crna=0,bijela=0,siva=0,crvena=0,plava=0,max,boja;
	float proc;
	printf("Unesite vozila: ");
	 do {
	scanf("%c",&c);
	if (c=='K')
	c='k';
	bv++;
		if(c=='C' || c=='c')
	crna++;
			max=crna;
			boja=1;
		if(c=='B' || c=='b')
	bijela++;
			if(bijela>max){
			max=bijela;
			boja=2;
			}
		if(c=='S' || c=='s')
	siva++;
			if(siva>max){
			max=siva;
			boja=3;
			}
		if(c=='V' || c=='v')
	crvena++;
			if(crvena>max){
			max=crvena;
			boja=4;
			}
		if(c=='P' || c=='p')
	plava++;
			if(plava>max){
			max=plava;
			boja=5;
			}
	if(c!='C' && c!='c' && c!='B' && c!='b' && c!='S' && c!='s' && c!='V' && c!='v' && c!='P' && c!='p' && c!='k' && c!='K')
	{
		printf("Neispravan unos\n");
		bv--;
	}
			
	}
	while(c!='k');
	if (bv==0)
		proc=0;
	else
	proc=((float)max/bv)*100;
	printf("Ukupno evidentirano %d vozila.",bv);
		if(boja==1)
	printf("\nNajpopularnija boja je crna (%.2f%%).",proc);
		if(boja==2)
	printf("\nNajpopularnija boja je bijela (%.2f%%).",proc);
		if(boja==3)
	printf("\nNajpopularnija boja je siva (%.2f%%).",proc);
		if(boja==4)
	printf("\nNajpopularnija boja je crvena (%.2f%%).",proc);
		if(boja==5)
	printf("\nNajpopularnija boja je plava (%.2f%%).",proc);
	return 0;
}
