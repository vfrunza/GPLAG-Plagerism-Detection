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


#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string Obrni(std::string fraza)
{
	int temp;
	
	for (unsigned int i = 0; i < fraza.length() / 2; i++)
	{
		temp = fraza.at(i);
		
		fraza.at(i) = fraza.at(fraza.length() - 1 - i);
		
		fraza.at(fraza.length() - 1 - i) = temp;
	}
	
	return fraza;
}

std::string PoluPalindrom(std::string fraza)
{
	
	
	for (unsigned int i = 0; i <= fraza.length() / 2; i++)
		
		fraza.at(fraza.length() - 1 - i) = fraza.at(i);
		
	return fraza;	
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze)

{
	for (unsigned int i = 0; i < fraze.size(); i++)
	
	{
		for (unsigned int j = 0; j < recenica.length(); j++)
		
		{
			if (fraze.at(i) == recenica.substr(j, fraze.at(i).length()) && recenica.substr(j + fraze.at(i).length(), 1) == " ")
			
			{
				recenica = recenica.substr(0, j) + PoluPalindrom(fraze.at(i))
				
					+ recenica.substr(j + fraze.at(i).length(), recenica.length() - j);
				
				j += fraze.at(i).length();	
				
			}
		}
	}
	
	return recenica;
	
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze)

{
	for (unsigned int i = 0; i < fraze.size(); i++)
	
	{
		for (unsigned int j = 0; j < recenica.length(); j++)
		
		{
			if (fraze.at(i) == recenica.substr(j, fraze.at(i).length()) && recenica.substr(j + fraze.at(i).length(), 1) == " ")
			
			{
				recenica = recenica.substr(0, j + fraze.at(i).length()) + Obrni(fraze.at(i))
				
					+ recenica.substr(j + fraze.at(i).length(), recenica.length() - j);
				
				j += fraze.at(i).length();	
				
			}
		}
	}
	
	return recenica;
	
}

int main()

{
	std::string recenica;
	
	std::cout << "Unesite recenicu: ";
	
	std::cin.clear();
	
	std::getline(std::cin, recenica);
	
	
	
	
	std::vector<std::string> fraze;
	
	std::string rijec;
	
	
	std::cout << "Unesite fraze: " << std::endl;
	
	while (1)
	
	{
		std::cin.clear();
		
		std::getline(std::cin, rijec);
		
		
		if (rijec == "")
			break;
			
		fraze.push_back(rijec);	
	}
	
	
	std::cout << "\r";
	
	std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(recenica, fraze);
	
	std::cout << "\r";
	
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(recenica, fraze);
	
	return 0;
	
	
}



