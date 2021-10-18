/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

std::string ObrniFraze(std::string recenica, std::vector<std::string> vFraze)
{
	for(auto fraza: vFraze)
	{
		int i=0;
		while(i < recenica.length())
		{
			int duzina = fraza.length();
			std::string pomocni_string = recenica.substr(i,duzina);
			if(pomocni_string == fraza)
			{
				int tmp = pomocni_string.length();
				for(int j(0);j<tmp/2;j++)
				{
					char t = pomocni_string[j];
					pomocni_string[j]= pomocni_string[tmp-j-1];
					pomocni_string[tmp-1-j] = t;
				}
				for(int j(0);j<tmp;j++)
				{
					recenica[i] = pomocni_string[j];
					i++;
				}
				i-=tmp;
			}
			i++;
		}
	}
	return recenica;
}

std::vector<std::string> podijeliNaRijeci(std::string recenica)
{
	std::vector<std::string> hepek;
	std::string hrkljus;
	for(int i(0);i<recenica.length();i++)
	{
		if(recenica[i] == ' ')
		{
			hepek.push_back(hrkljus);
			hrkljus = "";
		}
		else hrkljus+= recenica[i];
	}
	hepek.push_back(hrkljus);
	return hepek;
}

std::string spojiRecenicu(std::vector<std::string> pomocna_recenica)
{
	std::string nova_recenica;
	for(int i(0);i<pomocna_recenica.size();i++)
	{
		if(i!=pomocna_recenica.size()-1)
			nova_recenica += (pomocna_recenica[i] + " ");
		else nova_recenica += pomocna_recenica[i];
	}
	return nova_recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> vRijeci)
{
	std::string nova_recenica;
	for(auto rijec: vRijeci)
	{
		for(auto karakter: rijec)
		{
			if( !((karakter>='A' && karakter<='Z') || (karakter>='a' && karakter<='z')) )
				throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	std::vector<std::string> pomocna_recenica = podijeliNaRijeci(recenica);
	if(vRijeci.size()>0)
	{
		for(auto rijec: vRijeci)
		{
			for(int i(0);i<pomocna_recenica.size();i++)
			{
				if(rijec == pomocna_recenica[i])
					pomocna_recenica[i] = pomocna_recenica[i].substr(1, pomocna_recenica[i].length()-1) + pomocna_recenica[i][0] + "ay";
			}
		}
		nova_recenica = spojiRecenicu(pomocna_recenica);
	}
	else
	{
		for(int i(0);i<pomocna_recenica.size();i++)
		{
			pomocna_recenica[i] = pomocna_recenica[i].substr(1,pomocna_recenica[i].length()-1) + pomocna_recenica[i][0] + "ay";
		}
		nova_recenica = spojiRecenicu(pomocna_recenica);
	}
	return nova_recenica;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::string str;
	std::vector<std::string> frazone;
	while(true)
	{
		std::getline(std::cin, str);
		if(str=="") break;
		frazone.push_back(str);
	}
	try
	{
		std::cout<<"Recenica nakon PigLatin transformacije: "<< IzmijeniUPigLatin(recenica, frazone)<<std::endl;
		std::cout<<"Recenica nakon obrtanja fraza: "<< ObrniFraze(recenica, frazone);
	}
	catch(std::domain_error belaj)
	{
		std::cout<<"Izuzetak: "<<belaj.what()<<std::endl;
		std::cout<<"Recenica nakon obrtanja fraza: "<< ObrniFraze(recenica,frazone);
	}
	return 0;
}