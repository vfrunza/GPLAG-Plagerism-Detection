#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

bool JeLiFraza(std::string recenica, int i, std::string fraza)
{
	int j = 0;
	int brojac = 0;
	
	while(i < recenica.length() && j < fraza.length())
	{
		if(recenica[i] == fraza[j]) brojac++;
		i++;
		j++;
	}
	if(brojac != fraza.length()) return false;
	return true;
}

bool JeLiFrazaPIG(std::string recenica, int i, std::string fraza)
{
	int j = 0;
	int brojac = 0;
	
	if(i != 0 && ((recenica[i-1] >= 'A' && recenica[i-1] <= 'Z') || (recenica[i-1] >= 'a' && recenica[i-1] <= 'z'))) return false;
	while(i < recenica.length() && j < fraza.length() && ((recenica[i] >= 'a' && recenica[i] <= 'z') || (recenica[i] >= 'A' && recenica[i] <= 'Z')))
	{
		if(recenica[i] == fraza[j]) brojac++;
		i++;
		j++;
	}
	

	if(brojac != fraza.length()) return false;
	return true;
}
std::string Obrni(std::string recenica, std::string fraza, int i)
{
	int j = 0;
	char pomocni;
	int duzina;
	duzina = fraza.length();
	while(j < duzina/2)
	{
		pomocni = recenica[i+j];
		recenica[i+j] = recenica[i+duzina-1-j];
		recenica[i+duzina-1-j] = pomocni;
		j++;
	}
	
	return recenica;
}

std::vector<std::string> RecenicaUVektor(std::string recenica, std::vector<std::string> baza)
{
	int i = 0;
	baza.resize(0);
	
	while(i < recenica.length())
	{
		std::string rijec;
		if(!((recenica[i] >= 'a' && recenica[i] <= 'z')||(recenica[i] >= 'A' && recenica[i]<='Z')))
			while(!((recenica[i] >= 'a' && recenica[i] <= 'z') || (recenica[i] >= 'A' && recenica[i] <= 'Z')) && i < recenica.length())
				i++;
		
		if(i == recenica.length()) break;
		
		while(i < recenica.length() && ((recenica[i] >= 'a' && recenica[i] <= 'z') || (recenica[i] >= 'A' && recenica[i] <= 'Z')))
		{
			rijec.push_back(recenica[i]);
			i++;
		}
		baza.push_back(rijec);
		if(i == recenica.length()) break;
		i++;
	}
	
	return baza;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> baza)
{
		
	for(int j = 0; j < baza.size(); j++)
	{
		int i = 0;
		std::string fraza;
		fraza = baza[j];
		
		while(i < recenica.length())
		{
			
			if(recenica[i] == fraza[0])
			{
				
				int index = i;
				
				if(JeLiFraza(recenica, i, fraza))
					recenica = Obrni(recenica, fraza, index);
			}
			if(i >= recenica.length()) break;
			i++;
		}
	}
	
	return recenica;
}


std::string Izmijeni(std::string recenica, std::string rijec, int i)
{
	char pomocni;
	
	int n;
	
	pomocni = recenica[i];
	recenica.erase(recenica.begin() + i);
	n = rijec.length() + i - 1;
	recenica.insert(recenica.begin() + n, pomocni);
	
	
	n = rijec.length() + i;
	recenica.insert(recenica.begin() + n, 'a');
	n++;
	recenica.insert(recenica.begin() + n, 'y');
	
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> baza)
{
	if(baza.size() == 1 && baza[0].length() == 0)
		baza = RecenicaUVektor(recenica, baza);
	

	for(int j = 0; j < baza.size(); j++)
	{
		int i = 0;
		std::string fraza;
		fraza = baza[j];
	
		while(i < recenica.length())
		{
			
			if((recenica[i] < 'a' && recenica[i] > 'Z') || (recenica[i] < 'A') || recenica[i] > 'z')
				while(i < recenica.length() && ((recenica[i] < 'a' && recenica[i] > 'Z') || (recenica[i] < 'A') || recenica[i] > 'z'))
					i++;
		
			if(i == recenica.length()) break;		
			if(recenica[i] == fraza[0])
			{
				int index = i;
				
				if(JeLiFrazaPIG(recenica, i, fraza))
				{
					recenica = Izmijeni(recenica, fraza, index);
					i += fraza.length() + 2;
				
				}
			
			}
			if(i >= recenica.length()) break;
			i++;
		}
	}


	return recenica;
}

void IzborRijeci(std::vector<std::string> baza)
{
	for(int i{0}; i < baza.size(); i++)
	{
		int j = 0;
		std::string pomocni;
		pomocni = baza[i];
		while(j < pomocni.length())
		{
			if((pomocni[j] < 'a' && pomocni[j] > 'Z') || pomocni[j] < 'A' || pomocni[j] > 'z') 
				throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
			j++;
		}
	}
}


// UNOS
std::string UnesiRecenicu(std::string recenica)
{
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	return recenica;
}

std::vector<std::string> UnesiBazu(std::vector<std::string> baza)
{
	std::cout << "Unesite fraze: ";
	for(;;)
	{
		std::string fraza;
		std::getline(std::cin, fraza);
		baza.push_back(fraza);
		std::cin.clear();
		if(std::cin.peek() == '\n') break;
	}
	
	return baza;
}

int main()
{
	std::string recenica;
	recenica = UnesiRecenicu(recenica);
	
	std::vector<std::string> baza;
	baza = UnesiBazu(baza);
	
	try
	{
		IzborRijeci(baza);
		std::string novi;
		novi = IzmijeniUPigLatin(recenica, baza);
		std::cout << "Recenica nakon PigLatin transformacije: " << novi;
	}
	catch(std::domain_error izuzetak)
	{
		std::cout << izuzetak.what();
	}
	
	std::string obrnuta;
	obrnuta = ObrniFraze(recenica,baza);
	std::cout << std::endl << "Recenica nakon obrtanja fraza: " << obrnuta;


	return 0;
}