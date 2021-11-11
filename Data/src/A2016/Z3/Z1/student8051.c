#include <stdio.h>

int daj_prost(){
	static int p=1;
	//p je staticka varijabla kojoj je pocetna vrijednost 1, jer se  u liniji 9 ona automatski povecava, tako da nece uvrstavati jedinicu u proste brojeve.
	int i,logik=0;
	//logik je jedna logicka varijabla koja nam sluzi da oznacimo slozene brojeve sa 0, a proste sa 1.
	while(logik==0){
		p++;
		logik=1;
		//for petlja koja ispituje da li je varijabla p prost ili slozen broj.
		for(i=2;i<p;i++)
		{
			if(p%i==0)
				{
					logik=0;
					break;
				}
		}
		if(logik==1)
		return p;
		//Ukoliko je p prost broj, odnosno logik=1, funkcija daj_prost() prosljedjuje vrijednost p u main funkciju.
	}
}


int main() {
	int pitaj=0,suma=0;
	int a,b;
	do{
		pitaj=0;
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a>=b){
		pitaj=1;
		printf("A nije manje od B.\n");}
		else if(a<1||b<1)
		{
			pitaj=1;
			printf("A nije prirodan broj.\n");
		}
		}while(pitaj==1);
		//Naime, logicka varijabla "pitaj" ustvari ispituje da li su varijable a i b ispravno unesene. Ukoliko jesu, pitaj=0, u suprotnom pitaj=1.
		int k;
		k=daj_prost();
		//K je varijabla koja poziva funkciju daj_prost().
		suma=0;
		while(k<b)
		{
			//Ova petlja se izvrsava sve dok funkcija daj_prost ne daje prost broj koji je veci od varijable b.
			if(k>a&&k<b)
			{
				//U slucaju ako je prost broj izmedju a i b on se stavlja u sumu.
				suma+=k;
			}
			k=daj_prost();
			if(k>=b)
				break;
				//Automatski izlazi iz petlje ukoliko je prost broj veci ili jednak od b.
		}
		printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}