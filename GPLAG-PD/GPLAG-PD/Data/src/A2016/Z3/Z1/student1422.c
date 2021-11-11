#include <stdio.h>
/*funkcija daj_prost, koja nema parametara. sadrzi staticku varijablu, jer svaki put kada se pozove 
treba da vrati sljedeci prost broj. prva petlja radi dok broj nije prost. u njoj se prvo poveca broj
koji se ispituje (krece se od 1, pa se odmah na pocetku poveca). zatim se pretpostavi da je taj broj prost.
ako je on jednak dvici, sto ce se desiti samo jednom, jer pri svakom pozivu ispisuje se sljedeci prost broj,
nikada se ne vraca na pocetak, petlja se prekida i vraca se vrijednost 2. u suprotnom, pomocu for petlje
se broj koji se ispituje dijeli sa svakim brojem koji je manji od njega samog, i ako je pri tom dijeljenju
nema ostatka, odnosno ako je on jednak nuli, znaci da taj broj nije prost, petlja se prekida i broj koji
se ispituje se poveca za 1, i tako sve dok broj ne bude prost.*/
int daj_prost(){
	static int a=1;
	int i,prost;
	do{
		a++;
		prost=1;
		if(a==2)
		break;
		else{
		for(i=2;i<a;i++){
			if(a%i==0){
			prost=0;
			break;
			}
		}
		}
	}while(prost==0);
	return a;
}

int main(){
	int a=0,b=0,suma=0,y=0;
	/*Unos brojeva a i b, pri cemu oba broja moraju biti prirodna tj. veca od nule, i a mora biti manje od
	b. Ukoliko se unese nesto drugo, program mora ispisati u cemu je greska prilikom unosa. Unosi se pomocu
	do-while petlje, jer se ona izvrsi bar 1, a unos treba da se ponovi vise puta ukoliko se pravilno ne
	unesu vrijednosti*/
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if(a>0 && b>0 && a<b)
		break;
		else if(a<0 || a==0)
		printf("A nije prirodan broj.\n");
		else if(a==b || b<a)
		printf("A nije manje od B.\n");
	}while(1);
	/*while(1) je beskonacna petlja. U njoj se poziva funkcija daj_prost() i ukoliko je vrijednost koju
	vraca ta funkcija izmedju a i b, treba je dodati na sumu. Ako je ta vrijednost manja od a, treba se 
	nastaviti pozivati, medjutim cim ta vrijednost postane veca ili jednaka od broja b, petlja se prekida*/
	while(1){
		y=daj_prost();
		if(y<=a)
		continue;
		else if(y>=b)
		break;
		else if(y>a && y<b)
		suma+=y;
	}
	/*Ispis sume*/
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}