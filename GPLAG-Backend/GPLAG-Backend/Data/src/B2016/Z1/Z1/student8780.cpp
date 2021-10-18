/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

std::vector <int> IzdvojiGadne (std::vector <int> v,bool a)
{
	
	std::vector <int> parni ;
	std::vector <int> neparni ;
    std::deque  <int> cifre;

	int cifra,kolicnik,ostatak;


	for (int x: v) {
		kolicnik=x;
		cifra=0;
	

  cifre.resize(0); //  brišemo elemente iz deka
		while (kolicnik!=0) {

			ostatak = kolicnik%3;
			kolicnik=kolicnik/3;
			cifra++;
          
			cifre.push_front (ostatak); 
		}

		int brn(0); // brojimo 0
		int brj(0); // brojimo 1
		int brd(0); // brojimo 2

		// ternarni broj sistem ima tri cifre: 0,1,2
		
		for (int i=0; i<cifra; i++) 
		{
			if (cifre[i]==0) brn++;
			if (cifre[i]==1) brj++;
			if (cifre[i]==2) brd++;
		}
		
		if (brn%2==0 && brj%2==0 && brd%2==0) 
	    	parni.push_back(x);

		if (brn%2==0 && brj==0 && brd%2!=0)
		neparni.push_back(x);
		if (brn==0 && brj%2!=0 && brd==0)
		neparni.push_back(x);
		if (brn==0 && brj%2!=0 && brd%2!=0)
		neparni.push_back(x);
		if (brn%2!=0 && brj==0 && brd==0)
		neparni.push_back(x);
		if (brn%2!=0 && brj==0 && brd%2!=0)
		neparni.push_back(x);
		if (brn%2!=0 && brj%2!=0 && brd==0)
		neparni.push_back(x);
		if (brn%2!=0 && brj%2!=0 && brd%2!=0)
		neparni.push_back(x);
		
		
		
	}
	
	for (int i=0;i<parni.size();i++)
	{
		for (int j=i+1;j<parni.size();j++)
		{
		if (parni[i]==parni[j])
		  parni.erase(parni.begin() + j);
	    }
	}
	for (int i=0;i<neparni.size();i++)
	{
		for (int j=i+1;j<neparni.size();j++)
		{
		if (neparni[i]==neparni[j])
		 { neparni.erase(neparni.begin() + j);
	    j--;}}
	}
	if (a==true) return parni;
	 else return neparni;

}


int main ()
{
	std::vector<int> brojevi ; // vektor koji unosimo i saljemo u funkciju
	int broj;
	bool a (true);
	bool b (false);


	std::cout << "Unesite brojeve (0 za prekid unosa): ";
do {
	
		std::cin >> broj;
	if (broj!=0) brojevi.push_back(broj);
	}
	while (broj!=0);

	std::vector<int> parni (IzdvojiGadne(brojevi,a));
	std::vector<int> neparni (IzdvojiGadne(brojevi,b));
std::cout << "Opaki: ";
	for (int x: parni) 
	{
		std::cout << x  << " ";
	}
	std::cout << std::endl << "Odvratni: ";

	for (int y: neparni) 
	{
		std::cout << y << " ";
	}

	return 0;
}