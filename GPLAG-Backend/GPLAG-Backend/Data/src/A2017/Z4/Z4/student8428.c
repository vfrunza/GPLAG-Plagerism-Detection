#include <stdio.h>

#define vel 100

/*zadatak ce biti uradjen pomocu steka(ovdje se kao stek koristi obicni niz)*/
/*otvarajuci tag dodajemo na stek, a zatvarajuci provjeravamo, ako je isti samo skidamo zadnji sa steka, a ako ne onda nije ok html*/
int provjeri(char *html)
{
	char *p;
	/*U ovo ce s eupisivati tagovim tj. prva dva slova svakog taga. Kada se naidje na zatvarajuci tag, jednostavno ce se provjeravati zadnji upisani*/
	char stek[vel][2];
	int stek_vel = 0, i, j; /*moramo zapamtiti velicinu kako bi znali koji je zadnji*/
	int veliko_malo = 'a' - 'A';
	char prvi, drugi;

	/*inicijalizirajmo stek na nesto sto sigurno nece biti u htmlu tj. bar ne u tagovima, npr. '*' */
	for (i = 0; i < vel; i++)
		for (j = 0; j < 2; j++)
			stek[i][j] = '*';

	p = html;
	while (*p != '\0') {
		/*ako naidjemo na otvarajuci tag, sacuvamo prva dva karaktera iz naziva na zadnje mjesto u steku*/
		if (*p == '<' && *(p + 1) != '/') {
			p++; /*pomjeranje na prvi char naziva*/
			stek[stek_vel][0] = *p;
			p++; /*pomjeranje na naredni-drugi char u nazivu*/
			/*ovdje je problem ako je naziv taga jedno slovo. npr neka imamo <a href="test"> onda ce se u steku kao drugo slovo naziva zapamtiti razmak
			Kasnije pri poredjenju sa zatvarajucim tagom, poredit ce se taj razmak i '>' pa ce biti greska*/
			/*stoga, ako je p na razmaku, umjesto razmaka zapamtimo '>' kao drugi karakter*/
			if (*p == ' ')
				stek[stek_vel][1] = '>';
			else
				stek[stek_vel][1] = *p;

			stek_vel++;
		}
		/*ako se naidje na zatvarajuci tag(ne moze istovremeno i jedan i drugi pa je zato else if)*/
		else if(*p == '<' && *(p + 1) == '/') {
			/*ako smo dosli dozatvarajuceg, pomjerimo se na prvo slovo njegovog naziva, procitamo prvo i drugo slovo te uporedimo sa zadnjim u steku sacuvanim*/
			/*ako su isti, sve je ok pa samo skinemo zadnji sa steka. Ako su razliciti, zadnji na steku nije pravilno zatvoren*/
			/*pozicioniramo se na prvo slovo naziva*/
			p += 2;
			/*ako je ovdje razmak, a ne slovo, onda to nije validan tag*/
			if (*p == ' ')
				return 0;
			/* +,- 32 zbog malih velikih slova, tag je validan bez obzira malo veliko slovo */
			/*upamtimo u varijable prvi i drugi simbol zatvarajuceg taga. to cemo uraditi zbog tagova ciji je naziv jedno slovo a nakon toga slijedi razmak,
			jer smo gore u tom slucaju na drugom mjestu pamtili '>'*/
			prvi = *p;
			drugi = *(p + 1);
			if (drugi == ' ')
				drugi = '>';

			/*ako je stek_vel na nuli a petlja nije zavrsila, tj. ulazi se ovdje to je znak da imamo vise zatvarajucih tagova. Zbog toga je uvedeno
			stek_vel != 0. Bez ovoga javlja memorijske greske jer se pristupa na stek[-1] lokaciju u slucaju gdje je vise zatvarajucih od otvorenih tagova*/
			if (stek_vel != 0 && (prvi == stek[stek_vel-1][0] || prvi == stek[stek_vel-1][0] + veliko_malo || prvi == stek[stek_vel-1][0] - veliko_malo)
			        && (drugi == stek[stek_vel-1][1] || drugi == stek[stek_vel-1][1] + veliko_malo || drugi == stek[stek_vel-1][1] - veliko_malo)) {
				/*izbacivanje zadnjeg sa steka*/
				stek[stek_vel-1][0] = stek[stek_vel-1][1] = '*';
				stek_vel--;
			} else {
				/*nije ok pa vracamo 0*/
				return 0;
			}
		}
		p++;
	}
	/*ako je velicina steka na kraju veca od nule, imamo vise otvorenih tagova nego zatvorenih*/
	if (stek_vel > 0)
		return 0;
	/*ako je prosla ova petlja iznad, sve je u redu pa vratimo 1*/
	return 1;
}

int main()
{
	char a[] = "<p   >i ovo je validno, razmaci NAKON p</p    >";
	printf("String a, ocekivano 1: %d\n", provjeri(a));


	return 0;
}
