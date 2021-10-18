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

bool notslovo(char c);
std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze);
std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze);

int main ()
{
	std::string recenica,temp;
	std::cout<<"Unesite recenicu: ";
	std::getline(std::cin,recenica);
	std::cout<<"Unesite fraze: ";
	std::vector<std::string> fraze;
	for(;;)
	{
		std::getline(std::cin,temp);
		if(temp=="")break;
		fraze.push_back(temp);
	}
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	std::cout<<NapraviPalindrom(recenica,fraze);
	std::cout<<"\nRecenica nakon PoluPalindrom transformacije: ";
	std::cout<<NapraviPoluPalindrom(recenica,fraze);
	return 0;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> fraze)
{
	std::string temp {""};
	for(auto x : fraze)
	{
		for(int i=0; i<recenica.length(); i++)
		{
			temp="";
			if(recenica.at(i)==x.at(0))
			{
				for(int k=i; k<i+x.length() && k<recenica.length(); k++)
				{
					temp+=recenica.at(k);
				}
				if(
					(
						(i+x.length()<recenica.length() && notslovo(recenica.at(i+x.length()) ) )
						||
						(i+x.length()>=recenica.length())
					)
					&&
					
					(  
						i==0 || notslovo(recenica.at(i-1))
					) 
					
				  )
					if(temp==x)
					{
						for(int q(0),z(temp.length()-1); q<z; q++,z--)
						{
							temp.at(z)=temp.at(q);
						}
						for(int q=0; q<temp.length(); q++)
						{
							recenica.at(i)=temp.at(q);
							i++;
						}
						i--;
					}
			}
			if(i==recenica.length()-1)break;
		}
	}

	return recenica;
}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> fraze)
{

	std::string temp {""};
	for(auto x : fraze)
	{
		for(int i=0; i<recenica.length(); i++)
		{
			temp="";
			if(recenica.at(i)==x.at(0))
			{
				///std::cout<<i<<std::endl;
				for(int k=i ; k<i+x.length() && k<recenica.length() ; k++)
				{
					temp+=recenica.at(k);
				}
			
				if( 
					( 
						(i+x.length()<recenica.length() && notslovo(recenica.at(i+x.length())) )||i+x.length()>=recenica.length()
					)
						&&
					(
						i==0 ||notslovo( recenica.at(i-1) )///pocetak recenice ili neslovo prije 
					)  
				  )
					if(temp==x)
					{
						//to je ta
						//sad slijedi krampa
						i+=x.length();
						std::string ostatak {""};
						for(int k=i; k<recenica.length(); k++)
						{
							ostatak+=recenica.at(k);
						}
						recenica.resize(i);
						for(int k=x.length()-1; k>=0; k--)
						{
							recenica+=x.at(k);
						}
						i=recenica.length();
						recenica+=ostatak;

					}
			}
			if(i==recenica.length()-1)break;
		}
	}
	return recenica;
}

bool notslovo(char c)
{
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))return false;
	return true;
}