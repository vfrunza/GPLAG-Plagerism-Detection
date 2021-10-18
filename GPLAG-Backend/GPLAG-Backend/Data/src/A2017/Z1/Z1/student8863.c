#include <stdio.h>
#define procjena 0.00001

int main() {
	char tarik, bojan, mirza, nr;
	int pica, ham, cev;
	float min, kkk, trovac, max;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &nr);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &nr);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &nr);
	pica = (tarik % 'P' == 0) + (bojan % 'P' == 0) + (mirza % 'P' == 0);
	ham = (tarik % 'H' == 0) + (bojan % 'H' == 0) + (mirza % 'H' == 0);
	cev = (tarik % 'C' == 0) + (bojan % 'C' == 0) + (mirza % 'C' == 0);
	min = ham * 5. + pica * 5.3 + cev * 6.;
	trovac = ham * 3. + pica * 8. + cev * 3.9;
	if(trovac < min) min = trovac;
	kkk = ham * 3.3 + pica * 6.8 + cev * 5.;
	if(kkk < min) min = kkk;
	if(min == trovac) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", trovac);
	else if(min == kkk) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", kkk);
	else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min);
	max = pica * 6.8;
	if(max < ham * 3.3) max = ham * 3.3;
	if(max < cev * 5.) max = cev * 5.;
	if(kkk != min && kkk - max*0.1 < min - procjena) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", kkk - max*0.1);
	return 0;
}
