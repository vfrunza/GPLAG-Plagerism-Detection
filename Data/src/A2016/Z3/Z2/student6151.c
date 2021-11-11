#include <stdio.h>
#include <stdlib.h>

int broj(int br){
	/*funkcija 'broj' racuna zbir cifara odredjenog broja iz niza. Svi clanovi postavljeni na 0. 
	Kada odredimo cifru, ulazimo u niz na broj indexa koji je jednak toj cifri i povecavamo vrijednost za jedan. 
	Na taj nacin cemo dobiti niz koji nam govori koliko puta se neka cifra nalazi u datom broju. 
	*/
 int niz[10]={0};
 int i;
 if(br<0) br=abs(br); /*U slucaju da je broj u unesenom nizu negativan, uzima se njegova apsloutna vrijednost.*/
 while (br!=0){
 	int cifra=br%10;
 	niz[cifra]++;
 	br/=10;
 }
 int suma=0;
 /*for petljom mnozimo broj indexa(0-9) sa vrijednoscu koja se nalazi na tom indexu, 
 te to sabiramo u varijablu suma i dobijamo sumu cifara tog broja*/
 for(i=0;i<10;i++){
 	suma=suma+niz[i]*i;
 }
	return suma;
}

void ubaci (int niz[], int vel){
	int nizu[200],i;
	/*formiramo novi niz. Popunjavamo ga tako sto prvo na parne indexe upisujemo vrijednosti iz unesenog niza*/
	for(i=0;i<vel;i++){
		nizu[2*i]=niz[i];}
		/*na neparne indexe postavljamo vrijednosti zbira cifara koje povlacimo iz funkcije broj*/
	for(i=0;i<vel*2;i++){
		if(i%2!=0){
			nizu[i]=broj(nizu[i-1]);
		}}
		/*dobijeni niz prekopiramo u da bi ga mogli slati iz main-a*/
		for(i=0;i<vel*2;i++)
		niz[i]=nizu[i];
	}
	

int fib(int br){
	/*funkcija fib generise Fibonacijeve brojeve, tako sto postavimo niz sa dva ista elementa */
	int niz[2]={1,1};
	int slj=0;

	if(br==1 || br==2 || br==3 || br==5 ) return 1;
	
	/*while petljom sabiramo dva susjedna broja u nizu. 
	Svaki put se vrijednosti na indexu 0 i 1 pomjere za jedno mjesto i sabiranjem dobijamo sljedeci broj */

	while(slj<=br){
		slj=niz[0]+niz[1];
		if(slj==br || niz[0]==br)
			return 1;
	niz[0]=niz[1];
	niz[1]=slj;
	}
	return 0;
}

int izbaci (int* nizu,int vel){
	int i,j;

/*ako je broj jednak Fibonacijevom, izacujemo taj clan iz niza. 
Svi elementi iza tog broja se pomjeraju za jedno mjesto unaprijed u nizu (zapravo pokazivac se pomjera),
duzina niza se smanjuje svaki put za jedan 
i varijabla i se smanjuje da bi se ponovio postupak za novu vrijednost koja se nalazi na tom indexu*/

	for(i=0;i<vel;i++){
		if(fib(nizu[i])==1){
		
		for(j=i;j<vel-1;j++){
		/*	nizu[j]   */ *(nizu+j)=*(nizu+j+1);
		}
		vel--;
		i--;
	}}
	
	return vel;
}

int main() {
	
	int i,niz[20];
	/*unos niza*/
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
	scanf("%d", &niz[i]);
	}
	/*pozivamo funkciju ubaci pa izbaci, u koje sljemo niz, da bi mogli ispisati modificirani niz*/
	ubaci(niz,10);
	int vel=izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	/*ispis novog niza*/
	for(i=0;i<vel;i++){
		if(i==vel-1)
		printf("%d.",niz[i]);
		else printf("%d, ", niz[i]);
	
	}
	
	return 0;
}
