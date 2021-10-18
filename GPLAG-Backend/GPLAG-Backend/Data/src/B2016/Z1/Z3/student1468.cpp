#include <iostream>
#include <vector>
#include <deque>
#include <limits>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double>niz)
{
	int q(1);
	bool a(true);
	bool b(false);
	int n(niz.size());
	std::vector <double> pomocni;
	Matrica rastuci;
	
	//ubacujemo podnizove u matricu

	for (int i=0; i<n; i++) 
	{
	    if (i==n-2) niz.push_back(std::numeric_limits<double>::lowest());
		if (niz[i]<=niz[i+1]) q++;
		if (niz[i]>niz[i+1] && q>1)
		{
			pomocni.resize(0);
		
			for (int j=(i-q+1); j<=i; j++) 
			{
				pomocni.push_back(niz[j]);
			
			
 			} 
			q=1; rastuci.push_back(pomocni);
		}
	} 	
	return rastuci;
}


Matrica OpadajuciPodnizovi (std::vector<double>niz)
{

	int q(1);
	bool a(true);
	bool b(false);
	int n(niz.size());
	std::vector <double> pomocni;
	Matrica opadajuci;
	

	//ubacujemo podnizove u matricu


	for (int i=0; i<n; i++) 
	{
	    if (i==n-2) niz.push_back(std::numeric_limits<double>::max());
		if (niz[i]>=niz[i+1]) q++;
		if (niz[i]<niz[i+1] && q>1)
		{
			pomocni.resize(0);
		
			for (int j=(i-q+1); j<=i; j++) 
			{
				pomocni.push_back(niz[j]);
			
			
 			} 
			q=1; opadajuci.push_back(pomocni);
		}
	} 	
	return opadajuci;
}



int main ()
{

	double element;
	int broj_elemenata;
	std::deque<double> d ;
	std::vector<double> niz;

	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> broj_elemenata;
	std::cout << "Unesite elemente vektora: ";

	for (int i=0; i<broj_elemenata; i++) 
	{
		std::cin>> element;
		niz.push_back(element);

	}


Matrica rastuci_podnizovi(RastuciPodnizovi(niz));
Matrica opadajuci_podnizovi (OpadajuciPodnizovi(niz));

std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
for (std::vector<double> rast : rastuci_podnizovi)
{
	for (double x: rast)
	{
		std::cout << std::setprecision(12)<< x << " ";
	}
	std::cout << std::endl;
	
}

std::cout << "Maksimalni opadajuci podnizovi:"<<std::endl;
for (std::vector<double> opad : opadajuci_podnizovi)
{
	for (double y: opad)
	  {
	  	std::cout << std::setprecision(12) << y << " ";
	  	
	  }
	  std::cout << std::endl;
}


return 0;
}