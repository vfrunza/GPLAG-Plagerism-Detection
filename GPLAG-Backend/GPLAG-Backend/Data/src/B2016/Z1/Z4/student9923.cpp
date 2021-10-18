#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string ObrniFraze (std::string recenica, std::vector<std::string> fraze)
{
	
	for (int i{};i<fraze.size();i++)
		{
			std::string pomocni = fraze[i];
			int velicina_fraze = pomocni.size();
			for (int j{};j<recenica.length();j++)
				{
					if (recenica.substr(j,velicina_fraze) == pomocni)
						{
							int l = velicina_fraze-1;
							for (int k{j};k<recenica.length();k++)
								{
									if (l == -1)
										break;
									else
										recenica[k] = pomocni[l--];
								}
						}
				}
		}
	
	
	return recenica;
}

std::string IzmijeniUPigLatin (std::string recenica, std::vector<std::string> rijeci)
{
	for (int i{};i<rijeci.size();i++)
		{
			std::string pomocni = rijeci[i];
			
			for (int j{};j<pomocni.length();j++)
				{
					bool provjera = false;
					if ((pomocni[j]>='A' && pomocni[j]<='Z') || (pomocni[j]>='a' && pomocni[j]<='z'))
						provjera = true;
						
					if (provjera == false)
						throw std::domain_error ("Nekorektan izbor rijeci");
				}
		}
		
	std::string rezultat;
	bool rijec = false;
	
	bool prazan = false;
	if (rijeci.size() == 0)
		prazan = true;
		
	for (int i{};i<recenica.length();i++)
		{
			if (recenica[i]!=' ' && rijec == false)
				{
					rijec = true;
					
					std::string testna_rijec;
					for (int j{i};j<recenica.length();j++)
						{
							if (recenica[j] == ' ')
								break;
							testna_rijec.push_back(recenica[j]);
						}
					
					bool provjera = false;	
					for (int j{};j<rijeci.size();j++)
						{
							if (rijeci[j] == testna_rijec)
								provjera = true;
						}
						
					if (provjera == true || prazan == true)
						{
							for (int j{1};j<testna_rijec.length();j++)
								rezultat.push_back(testna_rijec[j]);
								
							rezultat.push_back(testna_rijec[0]);
							rezultat.push_back('a');
							rezultat.push_back('y');
							
							i = i + testna_rijec.length() - 1;
						}
					else
						{
							for (int j{};j<testna_rijec.length();j++)
								rezultat.push_back(testna_rijec[j]);
								
							i = i + testna_rijec.length() - 1;
						}
				}
				
			else if (recenica[i] == ' ' && rijec == true)
				{
					rijec = false;
					rezultat.push_back(recenica[i]);
				}
			else if (recenica[i] == ' ' && rijec == false)
				rezultat.push_back(recenica[i]);
			
		}
	
	return rezultat;
}




int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s);
	
	std::cout<<"Unesite fraze: ";
	
	std::vector<std::string> v;
	while (true)
		{
			std::string upis;
			std::getline(std::cin, upis);
			
			if (upis.length() == 0)
				break;
			else
				v.push_back(upis);
		}
		
		
		try
		{
			std::string ispis = IzmijeniUPigLatin(s,v);
			std::cout<<"Recenica nakon PigLatin transformacije: "<<ispis<<std::endl;;
		}
		catch(std::domain_error e)
		{
			std::cout<<"Izuzetak: "<<e.what()<<std::endl;
		}
	
		std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,v);
	
	
	
	
	
	
	
	return 0;
}