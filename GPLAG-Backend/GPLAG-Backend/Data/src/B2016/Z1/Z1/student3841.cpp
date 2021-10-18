/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
	
	okiiiiii
*/

#include<iostream>
#include<vector>
#include<cmath>

std::vector<int> IzdvojiGadne (std::vector<int> vektor, bool t)
{
	std::vector<int> opaki;
	std::vector<int> gadni; 
	int brojac0(0), brojac1(0), brojac2(0);
	
	for(int i : vektor) //prolazak kroz elemente vektora
	{
		int a = i;
		brojac0 = 0;
		brojac1 = 0;
		brojac2 = 0;
		int b(0);

		do
		{	
			b = a % 3;  // ostatak pri modularnom dijeljenju sa 3
			a /= 3;		//dijeljenje kopije elementa vektora sa 3 (zbog ternarnog zapisa)
			
			if(b == 0) brojac0++;
			else if(std::abs(b) == 1) brojac1++;
			else brojac2++;
		}
		while(a != 0);
		
		//ukoliko su brojaci parni tj ukoliko ima paran broj pojavljivanja u ternarnom zapisu broja
		//provjeravamo da li se ispitivani broj nalazi u vektoru, ukoliko nalazi ne ubacujemo ga 
		//ukoliko se ne pojavljuje ubacujemo element u vektor koji vracamo
		if(brojac0 % 2 == 0 && brojac1 % 2 == 0 && brojac2 % 2 == 0)
		{
			bool ima = false;
			
			for(int idk: opaki)
				if(idk == i)
					ima = true;
						
			if(ima == false)
				opaki.push_back(i);
		}
		
		//ponavljamo istu stvar kao i ranije, samo ovaj put za neparan broj pojavljivanja cifri u ternarnom zapisu
		if((brojac0 % 2 != 0 || brojac0 == 0) && (brojac1 % 2 != 0 || brojac1 == 0) && (brojac2 % 2 != 0 || brojac2 == 0))
		{
			bool ima = false;
			
			for(int idk: gadni)
				if(idk == i)
					ima = true;
						
			if(ima == false)
				gadni.push_back(i);
		}
	}
	
	if(t)
		return opaki;
		
	if(t == false)
		return gadni;
}

int main()
{
	std::vector<int> vek;
	
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	
	for(; ;)
	{
		int x;
		std::cin >> x;
		if(x == 0)
			break;
		
		vek.push_back(x);
	}
	
	std::vector<int> novi(IzdvojiGadne(vek, true));
	std::cout << "Opaki: ";
	for(int i = 0; i < novi.size(); i++)
		std::cout << novi.at(i) << " ";
		
	std::vector<int> opetnovi(IzdvojiGadne(vek, false));
	std::cout << "\nOdvratni: ";
	for(int i = 0; i < opetnovi.size(); i++)
		std::cout << opetnovi.at(i) << " ";
	return 0;
}