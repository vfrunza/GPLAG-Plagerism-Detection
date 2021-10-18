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

typedef std::vector<std::string> VektorStringova;

std::string VratiJednuFrazu(VektorStringova fraze, int red)
{
	std::string trazena_rijec;
	for(int i(0); i<fraze.size(); i++)
	{
		if(i==red)
		{
			for(int j(0); j<fraze.at(i).size(); j++)
			{
				trazena_rijec.push_back(fraze.at(i).at(j));
				if(j==fraze.at(i).size()) break;
			}
		}
	}
	return trazena_rijec;
}

std::string ObrniFraze(std::string recenica, VektorStringova fraze)
{
	for(int i(0); i<fraze.size(); i++)
	{
		std::string s;
		s=VratiJednuFrazu(fraze,i);
		int duzina_fraze;
		duzina_fraze=s.length();
		for(int j(0); j<recenica.length(); j++)
		{
			int br(0),pom(0);
			if(recenica.at(j)==s.at(pom))
			{
				while(recenica.at(j)==s.at(pom))
				{
					j++;
					pom++;
					br++;
					if(pom==s.length()) break;   // visak
					if(j==recenica.length()) break;
				}
				if(br==duzina_fraze)
				{
					int p(j-1),k(j-br);
					while(p>k) 
					{
						char temp;
						temp=recenica.at(k);
						recenica.at(k)=recenica.at(p);
						recenica.at(p)=temp;
						k++;
						p--;
						if(p==recenica.length() || k==recenica.length()) break; // ovo nije nuzno potrebno 
					}
				}
			}
			if(j==recenica.length()) break;
		}
	    if(i==fraze.size()) break;
	}
	return recenica;
}

bool ProvjeraFraza(VektorStringova fraze)
{
	bool eng(true);
	for(int i(0); i<fraze.size(); i++)
	{
		for(int j(0); j<fraze.at(i).size(); j++)
		{
			if(fraze.at(i).at(j)<'A' || (fraze.at(i).at(j)>'Z' && fraze.at(i).at(j)<'a') || fraze.at(i).at(j)>'z')
			{
				return false;
			}
		}
	}
	return eng;
}

bool ProvjeraAlfabeta(char znak)
{
	if(znak<'A' || (znak>'Z' && znak<'a') || znak>'z') return false;
	else return true;
}

std::string IzmijeniUPigLatin(std::string recenica, VektorStringova fraze)
{
	if(fraze.size()==0)
	{
		for(int i(0); i<recenica.length(); i++)
		{
			int br(0);
			if(i<recenica.length() && ((i==0 && ProvjeraAlfabeta(recenica.at(i))==true) || (i>0 && ProvjeraAlfabeta(recenica.at(i))==true && ProvjeraAlfabeta(recenica.at(i-1))==false)))
			{
			while(i<recenica.length() && ProvjeraAlfabeta(recenica.at(i))==true)
			{
				br++;
				i++;
				if(i==recenica.length()) break;
			}
			i--;
			if((i==recenica.length()-1 && ProvjeraAlfabeta(recenica.at(i))==true) || (i<recenica.length()-1 && ProvjeraAlfabeta(recenica.at(i))==true && ProvjeraAlfabeta(recenica.at(i+1))==false))
			{
			int j(i-br+1),k(i);
			char temp;
			temp=recenica.at(j);
			while(j<k)
			{
				recenica.at(j)=recenica.at(j+1);
				j++;
			}
			recenica.at(j)=temp;
			int kraj;
			kraj=int(recenica.length()-1);
			int duzina;
			duzina=recenica.length();
			recenica.resize(duzina+2);
			while(kraj>k)
			{
				recenica.at(kraj+2)=recenica.at(kraj);
				kraj--;
			}
			recenica.at(k+1)='a';
			recenica.at(k+2)='y';
			i=k+2;
			}
			}
			if(i==recenica.length()) break;
		}
	}
	else
	{
		if(ProvjeraFraza(fraze)==false) throw std::domain_error("Nekorektan izbor rijeci");
	    for(int i(0); i<fraze.size(); i++)
	    {
		    std::string s;
		    s=VratiJednuFrazu(fraze,i);
		    int duzina_fraze;
		    duzina_fraze=fraze.at(i).size();
		    for(int j(0); j<recenica.length(); j++)
		    {
			    int br(0),pom(0);
			    if(j<recenica.length() && ((j==0 && recenica.at(j)==s.at(pom)) || (recenica.at(j)==s.at(pom) && ProvjeraAlfabeta(recenica.at(j-1))==false)))
			    {
				    while(j<recenica.length() && recenica.at(j)==s.at(pom))
				    {
					    j++;
					    pom++;
					    br++;
					    if(pom==s.length()) break;
					    if(j==recenica.length()) break;
				    }
				    j--;
				    if(br==duzina_fraze && ((j==recenica.length()-1 && ProvjeraAlfabeta(recenica.at(j))==true) || (j<recenica.length()-1 && ProvjeraAlfabeta(recenica.at(j))==true && ProvjeraAlfabeta(recenica.at(j+1))==false)))
				    {
					    int p(j),k(j-br+1);
					    char temp;
					    temp=recenica.at(k);  
					    while(k<p)
					    {
						    recenica.at(k)=recenica.at(k+1);
						    k++;
					    }
					    recenica.at(k)=temp;
					    int kraj;
					    kraj=recenica.length()-1;
					    int duzina;
					    duzina=recenica.length();
					    recenica.resize(duzina+2);
					    while(kraj>k)
					    {
						    recenica.at(kraj+2)=recenica.at(kraj);
						    kraj--;
					    }
					    recenica.at(k+1)='a';
					    recenica.at(k+2)='y';
				     }
			    }
			    if(j==recenica.length()) break;
		    }
		    if(i==fraze.size()) break;
	    }
	}
	return recenica;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);
	VektorStringova fraze(0, std::string (""));
	std::cout << "Unesite fraze: ";
	try
	{
	int i(0);
    for(;;)
    {
    	char znak=std::cin.get();
    	if(znak=='\n') break;
    	fraze.resize(i+1);
    	while(znak!='\n')
    	{
    		fraze[i].push_back(znak);
    		znak=std::cin.get();
    		if(znak=='\n') break;
    		
    	}
    	i++;
    }
	std::string s;
	s=IzmijeniUPigLatin(recenica,fraze);
	std::cout << "Recenica nakon PigLatin transformacije: " << s;
	}
	catch(std::domain_error izuzetak)
	{
		std::cout << "Izuzetak: " << izuzetak.what();
	}
	std::string s1;
	s1=ObrniFraze(recenica,fraze);
	std::cout << std::endl << "Recenica nakon obrtanja fraza: " << s1;
	return 0;
}