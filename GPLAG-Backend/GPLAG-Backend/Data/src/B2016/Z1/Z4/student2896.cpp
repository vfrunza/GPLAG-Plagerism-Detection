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

std::string ObrniFraze(std::string s, std::vector<std::string> fraze)
{
	for(int i=0; i<fraze.size(); i++)
	{
		for(int j=0; j<s.length(); j++)
		{
			if(j+fraze.at(i).length() > s.length())
			{
				break;
			}
			bool jeste =  true;
			for(int k=0; k<fraze.at(i).length(); k++)
			{
				if(fraze.at(i).at(k) != s.at(j+k))
				{
					jeste = false;
				}
			}
			if(jeste)
			{
				for(int k=0; k<fraze.at(i).length()/2; k++)
				{
					char pomocna;
					int duzina = fraze.at(i).length();
					pomocna = s.at(j+k);
					s.at(j+k) = s.at(j+duzina-1-k);
					s.at(j+duzina-1-k) = pomocna;
				}
			}
		}
	}
	return s;
}

bool slovo(char znak)
{
	if(znak<'A' || (znak>'Z' && znak<'a') ||znak>'z')
	{
		return false;
	}
	else return true;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> rijeci)
{
	if(rijeci.size() > 0)
	{
		for(int i=0; i<rijeci.size(); i++)
		{
			for(int j=0; j<rijeci.at(i).length(); j++)
			{
				char znak = rijeci.at(i).at(j);
				if(slovo(znak) == false) throw std::domain_error("Nekorektan izbor rijeci");
			}
		}
		int duzina = 0;
		int pocetak = 0;
		int i=0;
		int duz = s.length();
		while(i<duz)
		{
			if(slovo(s.at(i)))
			{
				duzina++; //hgsdssssssss
			}
			if(!slovo(s.at(i)) || i==duz-1)
			{
				if(duzina > 0)
				{
					for(int j=0; j<rijeci.size(); j++)
					{
						if(rijeci.at(j).length() != duzina) continue;
						int isti=1;
						for(int k=0; k<duzina; k++)
						{
							if(s.at(pocetak+k) != rijeci.at(j).at(k))
							{
								isti = 0;
							}
						}
						if(isti == 1)
						{
							s.resize(s.size()+2);
							duz+=2;
							int k;
							for(k=s.length()-1; k>pocetak+duzina+2; k--)
							{
								s.at(k) = s.at(k-2);
							}
						    if(k!=duz-1) {
						    	s.at(k) = s.at(k-2); k--;
						    }
							s.at(k) = 'y'; k--;
							s.at(k) = 'a'; k--;
							char prvo = s.at(pocetak);
							for(k = pocetak; k<pocetak+duzina-1; k++)
							{
								s.at(k) = s.at(k+1);
							}
							s.at(k) = prvo;
							break;
						}
					}
				}
				duzina = 0;
				pocetak = i+1;
			}
			i++;
		}
	}
	else
	{
		int duzina=0;
		int pocetak=0;
		int i=0;
		int duz=s.length();
		while(i<duz)
		{
			if(slovo(s.at(i)))
			{
				duzina++;
			}
			if(!slovo(s.at(i)) || i==duz-1)
			{
				if(duzina > 0)
				{
					s.resize(s.size()+2);
					duz+=2;
					int k;
					for(k=s.length()-1; k>pocetak+duzina+2; k--)
					{
						s.at(k) = s.at(k-2);
					}
					if(k!=duz-1) {
						s.at(k) = s.at(k-2); k--;
					}
					s.at(k) = 'y'; k--;
					s.at(k) = 'a'; k--;
					char prvo = s.at(pocetak);
					for(k=pocetak; k<pocetak+duzina-1; k++)
					{
						s.at(k) = s.at(k+1);
					}
					s.at(k) = prvo;
					i = i + 2; // fggsssdggllfs
				}
				duzina = 0;
				pocetak = i+1;
			}
			i++;
		}
	}
	
	return s;
}

int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s);
	std::cout << "Unesite fraze: ";
	std::vector<std::string> fraze(0);
	for(;;)
	{
		std::string unos;
		std::getline(std::cin, unos);
		if(unos.length() > 0)
		{
			fraze.push_back(unos);
		}
		else
		{
			break;
		}
			
	}
	std::string obrnuti = ObrniFraze(s,fraze);
	try
	{
		std::string pig = IzmijeniUPigLatin(s,fraze);
		std::cout << "Recenica nakon PigLatin transformacije: ";
		std::cout << pig;
	}
	catch(std::domain_error &e)
	{
		std::cout << "Izuzetak: " << e.what();
	}
	std::cout << "\nRecenica nakon obrtanja fraza: ";
	std::cout << obrnuti; //gdgfefhdhfss
	return 0;
}