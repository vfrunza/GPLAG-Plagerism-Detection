/*  E'UZU BILLAHI MINESHEJ-TANIRRADZIM
	BISMILLA-HIRRAHMA-NIRRAHIM
	ALLAHU LA-ILAHE ILLA-HU, EL-HAJJUL-KAJUM.
	LA TE'HUZUHU SINETUN VE-LA NEVM.
	LEHU MA FISSEMAVATI VE MA FIL-ERD.
	MEN ZELLEZI JESHFE-U INDEHU ILLA BI IZNIH.
	J'ALEMU MA BEJNE EJDIHIM VE MA HELFEHUM.
	VE LA JUHITUNE BI SEJ-IN MIN ILMIHI ILLA BI-MA SAE.
	VESIA KURSIJJU-HUSSEMAVATI VE-ERDA,
	VE-LA JE-UDUHU HIF-ZUHUMA,
	VE HUVEL-ALIJJUL-AZIM.
*/

#include <vector>
#include <iostream>
#include <deque>

enum Smjer{Rastuci = 1, Opadajuci};

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s);
bool Stepen2(int broj);

int main()
{
	int brElem;
	
	std::cout << "Unesite broj elemenata vektora: ";
	
	while (std::cin >> brElem, brElem <= 0);
	
	
	std::vector<int> v(brElem);
	
	std::cout << "Unesite elemente vektora: ";
	
	for (int i = 0; i < brElem; i++)
	
		std::cin >> v.at(i);
		
		
	int izbor;
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	
	while (std::cin >> izbor, izbor != 1 && izbor != 2);
	
	
	Smjer s;
	
	s = Smjer(izbor);
	
	
	auto d = MaksimalniPodnizoviStepenaDvojke(v, s);
	
	if (!d[0].size())
	
	{
		if (s == Rastuci)
			
			std::cout << "Nema rastucih podnizova";
			
		else
		
			std::cout << "Nema opadajucih podnizova";
			
	}
	
	else
	
	{
		if (s == Rastuci)
		
			std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
			
		else
		
			std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
			
			
		for (unsigned int i = 0; i < d.size(); i++)
		
		{
			
			for (unsigned int j = 0; j < d[i].size(); j++)
			
				std::cout << d[i][j] << " ";
				
				
			std::cout << std::endl;	
				
		}
			
	}
	
	
	
	system("pause>0");
	
	return 0;
	
	
	
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s)

{
	
	std::deque<std::vector<int>> d;
	
	
	unsigned int k(0);
	
	for (unsigned int i = 0; i < v.size(); i++)
	
	{
		
		if (k >= d.size()) d.push_back(std::vector<int>());
		
		
		if (Stepen2(v.at(i)))
		
		{
			
			if (s == Rastuci)
			
				if (i + 1 < v.size() && (Stepen2(v.at(i + 1)) && v.at(i) < v.at(i + 1) || (!Stepen2(v.at(i + 1)) && d[k].size() >= 1)))
				
					d[k].push_back(v.at(i));
					
				else if (d[k].size() >= 1 && i + 1 < v.size() && v.at(i) > v.at(i + 1))
				
					d[k++].push_back(v.at(i));
				
				else if (d[k].size() >= 1 && i == v.size() - 1)
				
					d[k].push_back(v.at(i));
					
				else if (d[k].size() != 0)
				
					k++;
					
			if (s == Opadajuci) 
			
				if (i + 1 < v.size() && (Stepen2(v.at(i + 1)) && v.at(i) > v.at(i + 1) || (!Stepen2(v.at(i + 1)) && d[k].size() >= 1)))
				
					d[k].push_back(v.at(i));
					
				else if (d[k].size() >= 1 && i + 1 < v.size() && v.at(i) < v.at(i + 1))
				
					d[k++].push_back(v.at(i));
				
				else if (d[k].size() >= 1 && i == v.size() - 1)
				
					d[k].push_back(v.at(i));
					
				else if (d[k].size() != 0)
				
					k++;
			
			
		}
		
		if (!Stepen2(v.at(i)) && d[k].size() > 0) k++;
		
	}
	
	return d;
	
}

bool Stepen2(int broj)

{
	
	if (broj <= 0)
		return false;
	
	
	while (broj % 2 == 0)
	
		broj /= 2;
		
		
	return broj == 1;	
	
}























































