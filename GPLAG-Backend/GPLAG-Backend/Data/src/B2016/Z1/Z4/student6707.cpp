#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
/*B 2016/2017, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
std::string IzmijeniUPigLatin(std::string recenica, std::vector<std::string> vektor)
{
	int brojrijeci=0;

	std::string pomocni,k;
	int provjera=0;
	
	for(int i=0; i<vektor.size();i++)
	{
		
			for(int j=0; j<vektor[i].size(); j++)
		{
			if((j==0 && vektor[i][j]!=' ') || (j!=0 && vektor[i][j]!=' ' && vektor[i][j-1]==' ')) brojrijeci++;
		}
	if(brojrijeci>1) throw 	std::domain_error("Izuzetak: Nekorektan izbor rijeci");
	
	brojrijeci=0;
	
		int j=0;
		while(j<vektor[i].size())
		{
			k.push_back(vektor[i][j]);
		
			j++;
		}
		
		for(int j=0; j<recenica.size(); j++)
		{
			if((j==0 && recenica[0]==k[0] && recenica[j+k.size()]==' ') || (j!=0 && recenica[j]==k[0] && recenica[j-1]==' ' && recenica[j+k.size()]==' ') )
			{
				pomocni=recenica.substr(j, k.size());
				provjera=1;
			}
			
			if(pomocni==k && provjera==1)
			{
				pomocni=pomocni.substr(1,k.size()-1) + pomocni[0] + "ay";
				std::string pomocni2=recenica.substr(0,j);
				int vel= recenica.size() - pomocni2.size()- (k.size());
				recenica=pomocni2 + pomocni + recenica.substr(j+k.size(), vel );
			}
		
			
		}
	
		k.resize(0);
	}
	
	return recenica;
}

std::string ObrniFraze(std::string recenica, std::vector<std::string> vektor)
{
	int provjera=0;
	std::string pomocni;
	std::string pomocni2,k;
	
	
	for(int i=0; i<vektor.size();i++)
	{
		int j=0;
		while(j<vektor[i].size() )
		{
			k.push_back(vektor[i][j]);
		
			j++;
		}
		
		for(int j=0; j<recenica.size(); j++)
		{
			if((j==0 && recenica[0]==k[0]) || (j!=0 && recenica[j]==k[0]) )
			{
				pomocni=recenica.substr(j, k.size());
				provjera=1;
			}
			
			if(pomocni==k && provjera==1)
			{
				
				for(int m=k.size()-1; m>=0; m--) pomocni2.push_back(k[m]);
				
				int vel= recenica.size() - k.size()- j;
				recenica=recenica.substr(0,j) + pomocni2 + recenica.substr(j+k.size(), vel );
			
			
			}
		
		
			pomocni2.resize(0);
			provjera=0;
		}
		pomocni2.resize(0);
		k.resize(0);
	}
	
	return recenica;
}
int main ()

{
	std::string s,recenica;
	std::vector<std::string> vektor;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	for(int i=0; i>-1; i++)
	{
		std::getline(std::cin,s);
		vektor.push_back(s);
		if(vektor[i].size()==0) break;
	}
	
	try{
	s=IzmijeniUPigLatin(recenica,vektor);
	std::cout<<"Recenica nakon PigLatin transformacije: ";
	for(int i=0; i<s.size(); i++) std::cout<<s[i];
	std::cout<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<< izuzetak.what() << std::endl;
		
	}
	s=ObrniFraze(recenica,vektor);
	std::cout<<"Recenica nakon obrtanja fraza: " ;
	for(int i=0; i<s.size(); i++) std::cout<<s[i];
	
	
	
	
	return 0;
}