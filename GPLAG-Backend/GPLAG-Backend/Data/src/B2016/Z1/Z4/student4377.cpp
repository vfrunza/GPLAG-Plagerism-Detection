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

bool AlfabetProvjera(std::vector<std::string> rijeci)
{
	for(int i=0; i<rijeci.size(); i++)
	for(int j=0; j<rijeci[i].size(); j++)
	if(!((rijeci[i][j] >= 'A' && rijeci[i][j] <= 'Z') || (rijeci[i][j] >= 'a' && rijeci[i][j] <= 'z'))) return false;

	return true;
}

int Trazi(std::string recenica, std::string rijec, int pos)
{
	for(int i = pos; i<=recenica.size()-rijec.size(); i++)
	{
		int j (0);
		while(j < rijec.size() && recenica[i+j] == rijec[j]) j++;
		if(j == rijec.size()) return i;
	}
	return -1;
}

int Trazi2(std::string recenica, std::string rijec)
{
	for(int i = 0; i<=recenica.size()-rijec.size(); i++)
	{
		int j (0);
		while(j < rijec.size() && recenica[i+j] == rijec[j]) j++;
		if(j == rijec.size() && ((!(((recenica[i+j] >= 'A') && (recenica[i+j] <= 'Z')) || ((recenica[i+j] >= 'a') && (recenica[i+j] <= 'z')))) 
		
		|| recenica.size() == i+j) && (i==0 ||       (!(((recenica[i-1] >= 'A') && (recenica[i-1] <= 'Z')) || ((recenica[i-1] >= 'a') && (recenica[i-1] <= 'z'))))  )) return i;
	}
	
	return -1;
}

std::string ObrniRijec(std::string rijec)
{
	std::string nova_rijec;
	for(int i = rijec.size()-1; i >= 0; i--)
	{
		nova_rijec.push_back(rijec[i]);
	}
	return nova_rijec;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> fraze)
{
	int pos(0);
	for(int x=0; x<fraze.size(); x++)
	{
		int vel (fraze[x].size()); 
		if(vel != 1)
		{
			pos = Trazi(recenica, fraze[x] , pos);
		
			if (pos != -1)
			{
				std::string rijec(recenica.substr(pos,vel));
				rijec = ObrniRijec(rijec);
		
				for(int i=0; i<vel; i++)
				{
					recenica.erase(recenica.begin() + pos);
				}
				for(int i =0; i < rijec.size(); i++)
				{
					recenica.insert(recenica.begin() + pos+i, rijec[i]);
				}
				pos = rijec.size()+pos;
				x--;
			}	
			else
			{
				pos = 0;
			}
		}
	}
	return recenica;
}

std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijeci)
{
	if(!AlfabetProvjera(rijeci)) throw std::domain_error("Nekorektan izbor rijeci");
	if(rijeci.size() == 0)
	{
		bool znak (false);
		int broj_rijeci(0);
		for(int x=0; x<=recenica.size(); x++)
		{
			if( (((recenica[x] >= 'A') && (recenica[x] <= 'Z')) || ((recenica[x] >= 'a') && (recenica[x] <= 'z')))  && recenica.size() != x)
			{
				if(znak == false)
				{
					rijeci.resize(broj_rijeci+1);
				}
				znak = true;
				rijeci[broj_rijeci].push_back(recenica[x]);
			}
			else if(znak == true)
			{
				broj_rijeci++;
				znak = false;
			}
		}
	}
	
	for(int x=0; x<rijeci.size(); x++)
	{
		int vel (rijeci[x].size()); 
		int pos(Trazi2(recenica, rijeci[x]));
		
		if (pos != -1)
		{
			std::string rijec(recenica.substr(pos,vel));
			if(rijec.size() == 1)
			{
				rijec += "ay";
			}
			else
			{
				char prvo_slovo(rijec[0]);
				rijec.erase(rijec.begin());
				rijec += prvo_slovo;
				rijec += "ay";
			}
			
			for(int i=0; i<vel; i++)
			{
				recenica.erase(recenica.begin() + pos);
			}
			for(int i =0; i < rijec.size(); i++)
			{
				recenica.insert(recenica.begin() + pos+i, rijec[i]);
			}
			x--;
		}
	}
	return recenica;
}


int main ()
{

	std::cout << "Unesite recenicu: ";
	std::string recenica;
	std::getline(std::cin, recenica);
	
	std::vector<std::string> rijeci;
	std::string rijec;
	std::cout << "Unesite fraze: ";
	for(;;)
	{
		if(std::cin.peek() == '\n') break;
		else
		{
			std::getline(std::cin, rijec);
			rijeci.push_back(rijec);
		}
	}
  	
  	try
  	{
  		std::string nova_recenica (IzmijeniUPigLatin(recenica, rijeci));
  		std::cout << "Recenica nakon PigLatin transformacije: ";
  		std::cout << nova_recenica << std::endl;
  	}
  	catch(std::domain_error izuzetak) 
	{
 		std::cout << "Izuzetak: "<<izuzetak.what() << std::endl;
	}
	
  	std::cout << "Recenica nakon obrtanja fraza: ";
  	std::cout << ObrniFraze(recenica, rijeci);
	
	return 0;
}