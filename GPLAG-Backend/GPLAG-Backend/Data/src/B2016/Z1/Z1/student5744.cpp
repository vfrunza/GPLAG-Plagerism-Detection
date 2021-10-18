/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.*/
#include <iostream>
#include <vector>

int DaLiJeGadan(unsigned int x)
{
	int nule=0,jedinice=0,dvice=0;
	if(x==0) return 1;
	while(x!=0)
	{
		if(x%3==0)nule++;				// broji koliko ima kojih cifara u ternarnom sistemu
		else if(x%3==1)jedinice++;
		else if(x%3==2)dvice++;
		x/=3;
	}
	if(nule%2==0 && jedinice%2==0 && dvice%2==0) return 2;											// vraca dvicu ako ima paran broj cifara, jedinicu ako je neparan , nulu ako nije ni jedno ni drugo 
	if((nule%2==1||nule==0) && (jedinice%2==1||jedinice==0)&& (dvice%2==1||dvice==0)) return 1;
	else return 0;
	
}

std::vector<int> IzdvojiGadne(const std::vector<int> &niz, bool opaki )
{
	std::vector<int> trazeni ;
	for(int x: niz)
	{
		for(int z:trazeni) if(z==x) goto isti;	//ako je trenutni clan niza isti kao neki dosadasnji preskace provjeravnje gadnosti
		if(DaLiJeGadan(abs(x))-1==opaki)
		{														// ako je gadan i trazene parnosti cifara onda ga obacuje u niz
			trazeni.push_back(x);
		}
		isti:;
	}
	return trazeni;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int a;
	std::vector<int> x;
	while(std::cin >> a, a!=0)
	{
		x.push_back(a);
	}
	std::vector<int> opaki=IzdvojiGadne(x,true);
	std::vector<int> odvratni=IzdvojiGadne(x,false);
	std::cout << "Opaki: " ;
	for(int i:opaki) std::cout << i << " ";
	std::cout << "\nOdvratni: " ;
	for(int i:odvratni) std::cout << i << " ";
	return 0;
}