#include <stdio.h>

int main() {
	char boja;
	int u;
	float br1,br2,br3,br4,br5,p;
	br1=0;
	br2=0;
	br3=0;
	br4=0;
	br5=0;
	printf("Unesite vozila: ");
	scanf("%c",&boja);
	while (boja!='k' || boja!='K'){
		if(boja=='c' || boja=='C')
		br1++;
		else if(boja=='b' || boja=='B')
		br2++;
		else if(boja=='s' || boja=='S')
		br3++;
		else if(boja=='v' || boja=='V')
		br4++;
		else if(boja=='p' || boja=='P')
		br5++;
		else if(boja=='k' || boja=='K' || boja=='\n')
		break;
	    else
		printf("Neispravan unos\n");
		scanf("%c",&boja);
	}
	u=br1+br2+br3+br4+br5;
	printf("Ukupno evidentirano %d vozila.\n", u);
	if(br1>=br2 && br1>=br3 && br1>=br4 && br1>=br5){
		if(u==0)
	    p=0;
		else
	    p=(br1/u)*100;
		printf("Najpopularnija boja je crna (%.2f%%).", p);
	}
	else if(br2>=br1 && br2>=br3 && br2>=br4 && br2>=br5){
		p=(br2/u)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).", p);
	}
	else if(br3>=br1 && br3>=br2 && br3>=br4 && br3>=br5){
		p=(br3/u)*100;
		printf("Najpopularnija boja je siva (%.2f%%).", p);
	}
	else if(br4>=br1 && br4>=br2 && br4>=br3 && br4>=br5){
		p=(br4/u)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).", p);
	}
    else if(br5>=br1 && br5>=br2 && br5>=br3 && br5>=br4){
		p=(br5/u)*100;
		printf("Najpopularnija boja je plava (%.2f%%).", p);
	}
	return 0;
}