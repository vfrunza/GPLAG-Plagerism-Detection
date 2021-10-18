/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

bool EngleskiAlfabet (char znak)
{
	if ((znak>='a' && znak<='z')||(znak>='A' && znak<='Z'))
		return true;
	return false;
}

bool NeSlovo (char znak)
{
	if (!(znak>='a' && znak<='z') && !(znak>='A' && znak<='Z'))
		return true;
	return false;
}

std::string ObrniFraze (std::string s, std::vector<std::string> v)
{
	for (int i=0; i<v.size(); i++)
	{
		for (int j=0; j<s.length(); j++)
		{
			if(j+int(v[i].length())>s.length())
				break;
			std::string podstring=s.substr(j, int(v[i].length()));
			if(v[i]==podstring) 
			{
				for (int k=j; k<j+int(v[i].length())/2; k++)
				{
					char znak=s[k];
					s[k]=s[2*j+int(v[i].length())-1-k];
					s[2*j+int(v[i].length())-1-k]=znak;
				}
			}
		}
	}
	return s;
}

std::string IzmijeniUPigLatin (std::string s, std::vector<std::string> v)
{
	for (int i=0; i<v.size(); i++)
		for (int j=0; j<v[i].length(); j++)
			if (!EngleskiAlfabet(v[i][j]))
				throw std::domain_error ("Nekorektan izbor rijeci");
				
	for (int i=0; i<v.size(); i++)
	{
		for (int j=0; j<s.length(); j++)
		{
			if(j+int(v[i].length())>s.length())
				break;
			std::string podstring=s.substr(j, int(v[i].length()));
			if(v[i]==podstring && NeSlovo(s[j-1]) && (NeSlovo(s[j+int(v[i].length())]) || j+int(v[i].length())-1==int(s.length())-1)) 
			{
				char znak=s[j];
				for (int k=j; k<j+int(v[i].length()); k++)
					s[k]=s[k+1];
				s[j+int(v[i].length())-1]=znak;
				s.insert(s.begin()+j+int(v[i].length()), 'a');
				s.insert(s.begin()+j+int(v[i].length())+1, 'y');
			}
		}
	}
	return s;
}

int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	std::vector<std::string> v;
	std::string pomocni;
	std::cout<<"Unesite fraze: ";
	for(;;)
	{
		std::getline(std::cin, pomocni);
		if (pomocni.length()!=0)
			v.push_back(pomocni);
		else
			break;
	}
	
	try{
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,v);
	}
	catch (std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	std::cout<<std::endl<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,v);
	return 0;
	// poslani prazan vektor stringova znaci da treba izmijeniti sve rijeci u recenici
}