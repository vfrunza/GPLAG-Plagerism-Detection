#include <stdio.h>
int main() 
{
	char znak;
	float broj_vozila=0,suma_crna=0,suma_bijela=0,suma_siva=0,suma_crvena=0,suma_plava=0;
	float suma_crna1,suma_bijela1,suma_siva1,suma_crvena1,suma_plava1,procenat;
	printf("Unesite vozila: ");
	do
	{
		scanf("%c",&znak);
		if(znak=='C' || znak=='c') { broj_vozila=broj_vozila+1; suma_crna=suma_crna+1;}
		else if(znak=='B' || znak=='b') { broj_vozila=broj_vozila+1; suma_bijela=suma_bijela+1;}
		else if(znak=='S' || znak=='s') { broj_vozila=broj_vozila+1; suma_siva=suma_siva+1;}
		else if(znak=='V' || znak=='v') { broj_vozila=broj_vozila+1; suma_crvena=suma_crvena+1;}
		else if(znak=='P' || znak=='p') { broj_vozila=broj_vozila+1; suma_plava=suma_plava+1;}
		else if(znak=='A' || znak=='a') printf("Neispravan unos\n");
		else if(znak=='D' || znak=='d') printf("Neispravan unos\n");
		else if(znak=='E' || znak=='e') printf("Neispravan unos\n");
		else if(znak=='F' || znak=='f') printf("Neispravan unos\n");
		else if(znak=='G' || znak=='g') printf("Neispravan unos\n");
		else if(znak=='H' || znak=='h') printf("Neispravan unos\n");
		else if(znak=='I' || znak=='i') printf("Neispravan unos\n");
		else if(znak=='J' || znak=='j') printf("Neispravan unos\n");
		else if(znak=='L' || znak=='l') printf("Neispravan unos\n");
		else if(znak=='M' || znak=='m') printf("Neispravan unos\n");
		else if(znak=='N' || znak=='n') printf("Neispravan unos\n");
		else if(znak=='O' || znak=='o') printf("Neispravan unos\n");
		else if(znak=='R' || znak=='r') printf("Neispravan unos\n");
		else if(znak=='T' || znak=='t') printf("Neispravan unos\n");
		else if(znak=='U' || znak=='u') printf("Neispravan unos\n");
		else if(znak=='Z' || znak=='z') printf("Neispravan unos\n");
		else if(znak=='Q' || znak=='q') printf("Neispravan unos\n");
		else if(znak=='W' || znak=='w') printf("Neispravan unos\n");
		else if(znak=='Y' || znak=='y') printf("Neispravan unos\n");
		else if(znak=='X' || znak=='x') printf("Neispravan unos\n");
		else if(znak=='0' || znak=='1' || znak =='2' || znak=='3' || znak=='4' || znak=='5' || znak=='6' || znak=='7' || znak=='8' || znak=='9' ) printf("Neispravan unos \n");
        else if(znak=='.' || znak==' ' || znak==',' ) printf("Neispravan unos\n");
		
	}
	while(znak!='K' && znak!='k');
	printf("Ukupno evidentirano %g vozila.\n",broj_vozila);
	if(broj_vozila==0)
	{
		procenat=0;
		printf("Najpopularnija boja je crna (%.2f%%).",procenat);
	}
	else
	{
	suma_crna1=suma_crna;
	suma_bijela1=suma_bijela;
	suma_siva1=suma_siva;
	suma_crvena1=suma_crvena;
	suma_plava1=suma_plava;
	if(suma_crna1>=suma_bijela1 && suma_crna1>=suma_siva1 && suma_crna1>=suma_crvena1 && suma_crna1>=suma_plava1)
	{
		procenat=(suma_crna1/broj_vozila)*100;
		printf("Najpopularnija boja je crna (%.2f%%).",procenat);
	}
	else if(suma_bijela1>=suma_crna1 && suma_bijela1>=suma_siva1 && suma_bijela1>=suma_crvena1 && suma_bijela1>=suma_plava1)
	{
		procenat=(suma_bijela1/broj_vozila)*100;
		printf("Najpopularnija boja je bijela (%.2f%%).",procenat);
	}
	else if(suma_siva1>=suma_crna1 && suma_siva1>=suma_bijela1 && suma_siva1>=suma_crvena1 && suma_siva1>=suma_plava1)
	{
		procenat=(suma_siva1/broj_vozila)*100;
		printf("Najpopularnija boja je siva (%.2f%%).",procenat);
	}
	else if(suma_crvena1>=suma_crna1 && suma_crvena1>=suma_bijela1 && suma_crvena1>=suma_siva1 && suma_crvena1>=suma_plava1)
	{
		procenat=(suma_crvena1/broj_vozila)*100;
		printf("Najpopularnija boja je crvena (%.2f%%).",procenat);
	}
	else if(suma_plava1>=suma_crna1 && suma_plava1>=suma_bijela1 && suma_plava1>=suma_siva1 && suma_plava1>=suma_crvena1)
	{
		procenat=(suma_plava1/broj_vozila)*100;
		printf("Najpopularnija boja je plava (%.2f%%).",procenat);
	}
	}
	return 0;
}
		
	
