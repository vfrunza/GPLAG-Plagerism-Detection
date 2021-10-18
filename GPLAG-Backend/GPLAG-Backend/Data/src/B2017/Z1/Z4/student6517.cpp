/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <string>
#include <vector>
std:: string FrazaNaopako(std::string rijec)
{
	std::string naopako;
	
	for(int i=rijec.size()-1; i>=0; i--)
	{
		naopako.push_back( rijec.at(i) );
	}
	return naopako;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze)
{
	std::string rijec, polindrom, pomocni;
	pomocni=recenica;
	bool tacno_netacno(false);
	
	for(int i=0; i<fraze.size(); i++)
	{
		rijec=fraze.at(i);
		
		
			for(int k=0; k<recenica.size(); k++)
			{
				if(recenica.at(k)!=rijec.at(0) || ( (k-1)>=0 && recenica.at(k-1)>'A' && recenica.at(k-1)<'Z') || ( (k-1)>=0 && recenica.at(k-1)>'a' && recenica.at(k-1)<'z') )
				continue;
				else 
				{
					for(int l=0; l<rijec.size(); l++)
					{
						if((k+l)==recenica.size() || recenica.at(k+l)!=rijec.at(l))
						{
							tacno_netacno=true;
							break;
						}
					}
					if(tacno_netacno==false && ( recenica.size()==(k+rijec.size()) || recenica.at(k+rijec.size())<'A' || ( recenica.at(k+rijec.size())<'Z' && recenica.at(k+rijec.size())<'a' ) || recenica.at(k+rijec.size())>'z'))
					{
						recenica=recenica.substr(0,k+rijec.size() )+FrazaNaopako(rijec)+recenica.substr(k+rijec.size(),recenica.size());
						k+=rijec.size()*2;
					}
				}
				tacno_netacno=false;
			}
		rijec.resize(0); //ne znam je l neophodno
	}
	
	polindrom=recenica;
	recenica=pomocni;
	return polindrom;
}


std::string PolaNaopako(std::string rijec)
{
	std::string pola_naopako;
	
	if(rijec.size()%2==0)
	{
		for(int i=(rijec.size()/2)-1; i>=0; i--)
		{
			pola_naopako.push_back(rijec.at(i));
		}
	}
	else
	{
		for(int i=(rijec.size()/2); i>=0; i--)
		{
			pola_naopako.push_back(rijec.at(i));
		}
	}
	return pola_naopako;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze)
{
	std::string rijec;
	bool tacno_netacno(false);
	
	for(int i=0; i<fraze.size(); i++)
	{
		rijec=fraze.at(i);
		
		
			for(int k=0; k<recenica.size(); k++)
			{
				if(recenica.at(k)!=rijec.at(0) || ( (k-1)>=0 && recenica.at(k-1)>'A' && recenica.at(k-1)<'Z') || ( (k-1)>=0 && recenica.at(k-1)>'a' && recenica.at(k-1)<'z'))
				continue;
				else 
				{
					for(int l=0; l<rijec.size(); l++)
					{
						if( (k+l)==recenica.size() || recenica.at(k+l)!=rijec.at(l))
						{
							tacno_netacno=true;
							break;
						}
					}//ovaj ispod uslov da li je hard kodiranje??
					if(tacno_netacno==false && ( recenica.size()==(k+rijec.size()) || recenica.at(k+rijec.size())<'A' || ( recenica.at(k+rijec.size())<'Z' && recenica.at(k+rijec.size())<'a' ) || recenica.at(k+rijec.size())>'z'))
					{
						recenica=recenica.substr(0,k+(rijec.size()/2) )+PolaNaopako(rijec)+recenica.substr(k+rijec.size(),recenica.size());
						k+=rijec.size();
					}
				}
				tacno_netacno=false;
			}
		rijec.resize(0); //ne znam je l neophodno
	}
	return recenica;
}

int main ()
{
	std::cout<<"Unesite recenicu: ";
	std::string recenica;
	
	std::getline(std::cin, recenica);
	
	std::cout<<"Unesite fraze: ";
	
	std::vector<std::string> fraze;
	std::string izraz;
	
	do{
		std::getline(std::cin, izraz);
		if(izraz.size()==0)   /////
		break;
		
		fraze.push_back(izraz);
	}while(true);
	
	
	std::cout<<"Recenica nakon Palindrom transformacije: "<<NapraviPalindrom(recenica,fraze)<<std::endl;
	std::cout<<"Recenica nakon PoluPalindrom transformacije: "<< NapraviPoluPalindrom(recenica, fraze);
	
	return 0;
}