#include <stdio.h>

int main() {
	char a;
	int br1=0, br2=0, br3=0, br4=0, br5=0, max=0, ukupno=0;
	float pr1, pr2, pr3, pr4, pr5;
	printf("Unesite vozila: ");
	a=getchar();
	while(a!='k' && a!='K'){
		if(a=='c' || a=='C')
			br1++;
		else if(a=='b' || a=='B')
			br2++;
		else if(a=='s' || a=='S')
			br3++;
		else if(a=='v' || a=='V')
			br4++;
		else if(a=='p' || a=='P')
			br5++;
		else printf("Neispravan unos\n");
	
		a=getchar();
	}
	ukupno=br1+br2+br3+br4+br5;
	printf("Ukupno evidentirano %d vozila.\n", ukupno);
	
	max=br1;
	if(max<br2)
		max=br2;
	if(max<br3)
		max=br3;
	if(max<br4)
		max=br4;
	if(max<br5)
		max=br5;
	if(max==0){ 
		printf("Najpopularnija boja je crna (0.00%).");
	return;
	}
	
	
	if(max==br1){
		pr1=((float)br1/ukupno)*100;
		printf("Najpopularnija boja je crna (%.2f%).", pr1);
	}
	else if(max==br2){
		pr2=((float)br2/ukupno)*100;
		printf("Najpopularnija boja je bijela (%.2f%).", pr2);
	}
	else if(max==br3){
		pr3=((float)br3/ukupno)*100;
		printf("Najpopularnija boja je siva (%.2f%).", pr3);
	}
	else if(max==br4){
		pr4=((float)br4/ukupno)*100;
		printf("Najpopularnija boja je crvena (%.2f%).", pr4);
	}
	else if(max==br5){
		pr5=((float)br5/ukupno)*100;
		printf("Najpopularnija boja je plava (%.2f%).", pr5);
	}
	

	return 0;
}
