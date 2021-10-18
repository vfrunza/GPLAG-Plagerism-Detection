/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniRijec(std::string rijec)
{
	for(int i = 0; i < rijec.length() / 2; i++)
	{
		char temp = rijec[i];
		rijec[i] = rijec[rijec.length() - i - 1];
		rijec[rijec.length() - i - 1] = temp;
	}
	return rijec;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze)
{
	for(int i = 0; i < fraze.size(); i++)
		for(int j = 0; j < recenica.length() - fraze[i].length() + 1; j++)
		{
			std::string fraza = recenica.substr(j, fraze[i].length());
			if(fraza == fraze[i])
			{
				std::string obrnuto = ObrniRijec(fraze[i]);
				for(int k = j; k < j + fraze[i].length(); k++)
					recenica[k] = obrnuto[k - j];
			}
		}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> fraze)
{
	if (fraze.size()==0) {
		for(int i=0; i<fraze.size(); i++) {
			fraze[]
		}
	}
	for(int i = 0; i < fraze.size(); i++)
		for(int j = 0; j < fraze[i].length(); j++)
			if(!((fraze[i][j] >= 'a' && fraze[i][j] <= 'z') || (fraze[i][j] >= 'A' && fraze[i][j] <= 'Z')))
				throw std::domain_error("Nekorektan izbor rijeci");
	return recenica;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::vector<std::string> fraze;
	std::cout << "Unesite fraze ";
	for(;;)
	{
		std::string fraza;
		std::getline(std::cin, fraza);
		if(fraza.length() == 0)
			break;
		fraze.push_back(fraza);
	}
	std::string pigLatin, obrnuta;
	try
	{
		pigLatin = IzmijeniUPigLatin(recenica, fraze);
	}
	catch(std::domain_error greska)
	{
		std::cout << "Izuzetak: " << greska.what() << std::endl;
	}
	obrnuta = ObrniFraze(recenica, fraze);
	std::cout << "Recenica nakon PigLatin transformacije: " << pigLatin << std::endl;
	std::cout << "Recenica nakon obrtanja fraza: " << obrnuta << std::endl;
	return 0;
}