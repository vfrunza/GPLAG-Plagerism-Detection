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

bool DaLiJeSlovo(char a)
{
	return (a<'A' || (a>'Z' && a<'a') || a>'z');
}
std::string ObrniFraze(std::string recenica, std::vector<std::string> rijec)
{
	for(int i=0; i<rijec.size(); i++)
		for(int j=0; j<recenica.length(); j++)
			if(rijec[i]==recenica.substr(j,rijec[i].length()))
			{
				int temp=j;
				for(int k=rijec[i].length()-1; k>=0; k--)
					recenica[j++]=rijec[i][k];
				j=temp;
			}
	return recenica;
}
std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> rijec)
{
	for(int i=0; i<rijec.size(); i++)
		for(int j=0; j<rijec[i].length(); j++)
			if(DaLiJeSlovo(rijec[i][j]))
				throw std::domain_error("Nekorektan izbor rijeci");
	if(rijec.size()!=0)
		for(int i=0; i<rijec.size(); i++)
			for(int j=0; j<recenica.length(); j++)
			{
				if(rijec[i]==recenica.substr(j, rijec[i].length()) && (j==0 || DaLiJeSlovo(recenica[j-1])) && (j+rijec[i].length()==recenica.length() || DaLiJeSlovo(recenica[j+rijec[i].length()])))
				{
					recenica.insert(recenica.begin()+j+rijec[i].length(), recenica[j]);
					recenica.insert(recenica.begin()+j+rijec[i].length()+1, 'a');
					recenica.insert(recenica.begin()+j+rijec[i].length()+2, 'y');
					recenica.erase(recenica.begin()+j);
					if(j==recenica.length()-3)	break;
				}
			}
	else
		for(int i=0; i<recenica.length(); i++)
			{
				if((i==0 || DaLiJeSlovo(recenica[i-1])) && !DaLiJeSlovo(recenica[i]))
				{
					int j(i);
					while(!DaLiJeSlovo(recenica[i++]))
						if(i==recenica.length())
						{
							i++;
							break;
						}
					i--;
					recenica.insert(recenica.begin()+i, recenica[j]);
					recenica.insert(recenica.begin()+i+1, 'a');
					recenica.insert(recenica.begin()+i+2, 'y');
					recenica.erase(recenica.begin()+j);
					
				}
			}
	return recenica;
}
int main ()
{
	std::string s;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, s);
	
	std::vector<std::string> rijec;
	std::cout<<"Unesite fraze: ";
	for(;;)
	{
		std::string r;
		std::getline(std::cin, r);
		if(r.size()==0)	break;
		rijec.push_back(r);
	}
	try
	{
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s, rijec)<<std::endl;
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s, rijec)<<std::endl;
	return 0;
}