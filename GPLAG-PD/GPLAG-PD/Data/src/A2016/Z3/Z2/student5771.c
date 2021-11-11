#include <stdio.h>
#include <stdlib.h>
/*funkcija za izbacivanje*/
int izbaci(int niz[], int velicina){
	 long int i,niz3[10000]={0},j,duzinaniza=velicina,k;
	 /*max broj clanova novoformiranog niza3 je 50 jer na 46 se premasuje opseg integera*/
	 int max=50;
	 /*prva dva clana po definiciji 1*/
	niz3[0]=1;
	niz3[1]=1;
	/*broj clanova do 50 da smo trazili max standardnim putem program bi se krahirao ovako ce stati int na 46-tom clanu 
	fibonacijevom*/
	for(i=2; i<max; i++)
	{
	/*i-ti clan jednak sumi prethodna dva to su clanovi s indekisma i-1 i i-2, formiramo fibonacijev niz*/
		niz3[i]=niz3[i-1]+niz3[i-2];
	} 
	/*pravimo petlju koja svaki od tih clanova fibonacijevog niza uporedjuje sa clanovima naseg niza iz maina*/
	for(i=0; i<max; i++)
	{
		for(j=0; j<duzinaniza; j++)
		{
	/*ako je neki clan fibonacijevog niza jednak clanu naseg niza iz maina vrsi se izbacivanje*/
			if(niz[j]==niz3[i])
			{
	/*od tog j-tog clana, indeks svakog clana bude zamjenjen s indeksom njegovog sljedbenika*/
				for(k=j; k<duzinaniza-1; k++)
				{
				niz[k]=niz[k+1];	
				}
	/*smanjimo max broj indeksa i max broj redova nakon izbacivanja*/
			     j--; 
			     duzinaniza--;
			}
		}
	}
	return duzinaniza;
    }
   /*funkcija za ubacivanje*/
void ubaci(int niz[], int velicina){
	long int i,b,f,suma=0,niz2[200000]={0};
	/*formiramo neki novi niz ciji su clanovi s indeksima i*2 jednaki clanovima niza iz maina s indeksom i*/
	for(i=0; i<velicina; i++)
	{
	/*ovako ostavljamo prazan prostor za clanove jednake sumi cifara*/
		niz2[i*2]=niz[i];
	}
	/*ubacujemo clanove u taj "medjuprostor"*/
	for(i=0; i<velicina; i++)
	{
	/*moguce unijeti i negativne brojeve pa to rijesi fja abs*/
		b=abs(niz[i]);
		do{
	/*prva cifra ostatak dijeljenja broja s 10*/
		f=b%10;
	/*nadodamo na sumu pocetne vrijednosti nula*/
		suma=suma+f;
	/*"pripremimo" za ponovni ulazak u petlju i uslov u while dijeljenjem s 10*/
		b=b/10;
	/*provjerimo da broj nije nula ako jeste izlaz iz petlje*/
		}while(b!=0);
	/*clan tog novo formiranog niza s indeksima u ostavljenom medjuprostoru tj indeks 1 3 5 itd je ta suma*/
		niz2[i*2+1]=suma;
	/*sumu vratimo na nulu*/
		suma=0;
	   }
	 /*sad vrijednosti tog novog niza dodijelimo nasem nizu iz maina*/
	for(i=0; i<velicina*2; i++){
		niz[i]=niz2[i];
	}
}
int main() {
	printf("Unesite niz od 10 brojeva: ");
	int i, niz[100]={0},duzina;
	/*unos clanova niza*/
	for(i=0; i<10; i++)
	{
		scanf("%d", &niz[i]);
	}
	/*pozivanje funkcija*/
	ubaci(niz, 10);
    duzina=izbaci(niz, 20);
    /*ispis clanova*/
	printf("Modificirani niz glasi: ");
	for(i=0; i<duzina; i++)
	{
	/*zbog autotestova uslovi s ispisom sa tackom i sa zarezom*/
		if(i!=(duzina-1))
		{
			printf("%d, ", niz[i]);}
		else {
			printf("%d.", niz[i]);
		}
	}
	return 0;
}
